/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 18/09/2025
 * Chapter: 4
 * Exercise: 4.11
 * Description: Modify getop so that it doesn't need to use ungetch. Hint: use an internal static variable.
 */


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "chapter4func.h"

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100

static int32_t sp = 0;           /* stack pointer */
static double val[MAXVAL];   /* stack array */

/* Push: push f onto value stack */
static void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can’t push %g\n", f);
}

/* Pop: pop and return top value from stack */
static double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* getop: get next operator or numeric operand (no getch/ungetch) */
static int getop(char s[])
{
    int32_t i, c;
    static int32_t lastc = ' ';   /* static variable keeps last unread char */

    /* skip whitespace */
    while ((s[0] = c = lastc) == ' ' || c == '\t')
        lastc = getchar();

    s[0] = c;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
    {
        lastc = getchar();
        return c;
    }

    i = 0;
    if (isdigit(c))    /* collect integer part */
        while (isdigit(s[++i] = c = getchar()))
            ;
    if (c == '.')      /* collect fraction part */
        while (isdigit(s[++i] = c = getchar()))
            ;

    s[i] = '\0';
    lastc = c;
    return NUMBER;
}

/* main calculator logic */
int32_t exercise4_11(void)
{
    int32_t type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push(fmod(pop(), op2));
            else
                printf("error: zero divisor\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

