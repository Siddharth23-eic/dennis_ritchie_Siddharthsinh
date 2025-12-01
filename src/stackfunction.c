#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "stackfunction.h"

/* Constants */
#define MAXVAL  100
#define BUFSIZE 100

/* ------------------------ Stack ------------------------ */

static int sp = 0;          /* Stack pointer */
static double val[MAXVAL];  /* Value stack */

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void) {
    if (sp > 0)
        return val[--sp];
    printf("error: stack empty\n");
    return 0.0;
}

void print_top(void) {
    if (sp > 0)
        printf("top: %.8g\n", val[sp - 1]);
    else
        printf("stack empty\n");
}

void duplicate_top(void) {
    if (sp > 0)
        push(val[sp - 1]);
    else
        printf("stack empty, nothing to duplicate\n");
}

void swap_top(void) {
    if (sp > 1) {
        double temp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = temp;
    } else
        printf("need at least two elements to swap\n");
}

void clear_stack(void) {
    sp = 0;
}

void print_stack(void) {
    if (sp == 0) {
        printf("stack empty\n");
        return;
    }
    printf("stack: ");
    for (int i = 0; i < sp; i++)
        printf("%.8g ", val[i]);
    printf("\n");
}

/* ------------------------ Input Handling ------------------------ */

static char buf[BUFSIZE];
static int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* ------------------------ Token Parser (getop) ------------------------ */

int getop(char s[]) {
	int i = 0, c;

    /* skip whitespace */
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
	
	if(isalpha(c)){
		s[i++] = c;
		while(isalpha(c = getch()))
			s[i++] = c;
		s[i] = '\0';
		if( c != EOF)
			ungetch(c);
		if(strlen(s) == 1)
			return VARIABLE;
		else
			return FUNCTION;
	}

    if (!isdigit(c) && c != '.' && c != '-')  /* not a number */
        return c;

    i = 0;
    if (c == '-') { /* could be negative or subtraction */
        int next = getch();
        if (!isdigit(next) && next != '.') {
            ungetch(next);
            return c; /* just a minus operator */
        }
        s[++i] = next;
        c = next;
    }

    if (isdigit(c))      /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')        /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;

    s[i] = '\0';
    if (c != EOF)
        ungetch(c);

    return NUMBER;
}


/* ------------------------ Math Functions ------------------------ */

void mathfunc(char s[]) {
    double op2;

    if (strcmp(s, "sin") == 0)      
        push(sin(pop()));
    else if (strcmp(s, "exp")== 0)
        push(M_E);
    else if (strcmp(s, "pow") == 0) {
        op2 = pop();
        push(pow(pop(), op2));
	}
    else
        printf("error: %s not supported\n", s);
}
