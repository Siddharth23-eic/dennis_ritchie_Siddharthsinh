#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "keyword.h"
#include "stackfunction.h"

/* keyword table */
struct key keytab[] = {
    { "auto", 0 },
    { "break", 0 },
    { "case", 0 },
    { "char", 0 },
    { "const", 0 },
    { "continue", 0 },
    { "default", 0 },
    { "do", 0 },
    { "double", 0 },
    { "else", 0 },
    { "enum", 0 },
    { "extern", 0 },
    { "float", 0 },
    { "for", 0 },
    { "goto", 0 },
    { "if", 0 },
    { "int", 0 },
    { "long", 0 },
    { "register", 0 },
    { "return", 0 },
    { "short", 0 },
    { "signed", 0 },
    { "sizeof", 0 },
    { "static", 0 },
    { "struct", 0 },
    { "switch", 0 },
    { "typedef", 0 },
    { "union", 0 },
    { "unsigned", 0 },
    { "void", 0 },
    { "volatile", 0 },
    { "while", 0 }
};

int NKEYS = sizeof keytab / sizeof keytab[0];

/* improved getword (exercise 6.1) */
int getword(char *word, int lim)
{
    int c, d;
    char *w = word;

    while (isspace(c = getch()))
        ;

    if (c == '/') {
        d = getch();
        if (d == '/') {
            while ((c = getch()) != '\n' && c != EOF)
                ;
            return getword(word, lim);
        }
        else if (d == '*') {
            int prev = 0;
            while ((c = getch()) != EOF) {
                if (prev == '*' && c == '/')
                    break;
                prev = c;
            }
            return getword(word, lim);
        }
        ungetch(d);
    }

    if (c == '#') {
        while ((c = getch()) != '\n' && c != EOF)
            ;
        return getword(word, lim);
    }

    if (c == '"') {
        while ((d = getch()) != '"' && d != EOF)
            if (d == '\\') getch();
        return getword(word, lim);
    }

    if (c == '\'') {
        while ((d = getch()) != '\'' && d != EOF)
            if (d == '\\') getch();
        return getword(word, lim);
    }

    if (c == EOF)
        return EOF;

    *w++ = c;

    if (!isalpha(c) && c != '_') {
        *w = '\0';
        return c;
    }

    for (--lim; --lim > 0; w++) {
        c = getch();
        if (!isalnum(c) && c != '_') {
            ungetch(c);
            break;
        }
        *w = c;
    }

    *w = '\0';
    return word[0];
}

/* binary search */
int binsearch(char *word, struct key tab[], int n)
{
    int low = 0, high = n - 1, mid, cond;

    while (low <= high) {
        mid = (low + high) / 2;
        cond = strcmp(word, tab[mid].word);

        if (cond < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}
