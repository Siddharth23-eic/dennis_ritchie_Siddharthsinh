#include "parse.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int32_t tokentype;
int32_t errflag = 0;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

#define BUFSIZE 100
static char buf_dcl[BUFSIZE];
static int bufp_dcl = 0;

static int32_t getch(void) {
    return bufp_dcl ? buf_dcl[--bufp_dcl] : getchar();
}

static void ungetch(int32_t c) {
    if (bufp_dcl < BUFSIZE)
        buf_dcl[bufp_dcl++] = c;
}

/* TYPE + QUALIFIER tables */
int istype(const char *s) {
    return !strcmp(s, "int") ||
           !strcmp(s, "char") ||
           !strcmp(s, "float") ||
           !strcmp(s, "double") ||
           !strcmp(s, "void") ||
           !strcmp(s, "short") ||
           !strcmp(s, "long") ||
           !strcmp(s, "signed") ||
           !strcmp(s, "unsigned");
}

int isqual(const char *s) {
    return !strcmp(s, "const") ||
           !strcmp(s, "volatile") ||
           !strcmp(s, "restrict");
}

/* gettoken() */
int32_t gettoken(void) {
    int32_t c;
    char *p = token;

    while ((c = getch()) == ' ' || c == '\t')
        ;

    if (c == '(') {
        if ((c = getch()) == ')') {
            strcpy(token, "()");
            return tokentype = PARENS;
        }
        ungetch(c);
        return tokentype = '(';
    }
    else if (c == '[') {
        for (*p++ = c; (*p++ = getch()) != ']'; )
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    }
    else if (isalpha(c)) {
        for (*p++ = c; isalnum(c = getch()) || c=='_'; )
            *p++ = c;
        *p = '\0';
        ungetch(c);

        if (isqual(token)) return tokentype = QUALIFIER;
        if (istype(token)) return tokentype = TYPE;
        return tokentype = NAME;
    }

    return tokentype = c;
}

/* Parse full datatype: qualifiers + types */
void parse_datatype(void) {
    datatype[0] = '\0';

    while (tokentype == TYPE || tokentype == QUALIFIER) {
        if (datatype[0] != '\0')
            strcat(datatype, " ");
        strcat(datatype, token);
        gettoken();
    }
}

/* dcl() */
void dcl(void) {
    int32_t ns = 0;

    while (tokentype == '*') {
        ns++;
        gettoken();
    }

    dirdcl();

    while (ns-- > 0)
        strcat(out, " pointer to");
}

/* forward declaration for function args */
void parse_fn_args(void);

/* dirdcl() */
void dirdcl(void) {
    int32_t type;

    if (tokentype == '(') {
        gettoken();
        dcl();
        if (tokentype != ')') {
            printf("error: missing )\n");
            errflag = 1;
        } else {
            gettoken();
        }
    }
    else if (tokentype == NAME) {
        strcpy(name, token);
        gettoken();
    }
    else {
        printf("error: expected name or (dcl)\n");
        errflag = 1;
        return;
    }

    while (tokentype == PARENS || tokentype == BRACKETS || tokentype == '(') {
        type = tokentype;

        if (type == PARENS) {
            strcat(out, " function returning");
            gettoken();
        }
        else if (type == '(') {
            parse_fn_args();
        }
        else { /* brackets */
            strcat(out, " array ");
            strcat(out, token);
            strcat(out, " of");
            gettoken();
        }
    }
}

/* Parse function arguments: (int, char*, const float*) */
void parse_fn_args(void) {
    strcat(out, " function taking ");
    gettoken();

    while (tokentype != ')' && tokentype != EOF) {
        char base[256] = "";
        char full[256] = "";
        int ptr_count = 0;
        int first = 1;

        while (tokentype == TYPE || tokentype == QUALIFIER) {
            if (!first) strcat(base, " ");
            strcat(base, token);
            first = 0;
            gettoken();
        }

        while (tokentype == '*') {
            ptr_count++;
            gettoken();
        }

        for (int i = 0; i < ptr_count; i++)
            strcat(full, "pointer to ");

        strcat(full, base);
        strcat(out, full);

        if (tokentype == ',') {
            strcat(out, ", ");
            gettoken();
        }
    }

    gettoken();
    strcat(out, " and returning");
}


/* undcl: convert English back to C */
int needs_parens = 0;

void undcl(void) {
    int32_t type;
    char temp[1000];

    out[0] = '\0';
    strcpy(out, token);

    while ((type = gettoken()) != '\n' && type != EOF) {
        if (type == PARENS || type == BRACKETS) {
            needs_parens = 1;
            strcat(out, token);
        }
        else if (type == '*') {
            if (needs_parens) {
                sprintf(temp, "(*%s)", out);
                needs_parens = 0;
            } else {
                sprintf(temp, "*%s", out);
            }
            strcpy(out, temp);
        }
        else if (type == NAME) {
            sprintf(temp, "%s %s", token, out);
            strcpy(out, temp);
            needs_parens = 0;
        }
        else {
            printf("undcl: invalid input near %s\n", token);
            errflag = 1;
        }
    }

    printf("%s\n", out);
}
