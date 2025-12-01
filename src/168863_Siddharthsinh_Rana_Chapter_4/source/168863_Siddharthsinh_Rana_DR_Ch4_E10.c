/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 18/09/2025
 * Chapter: 4
 * Exercise: 4.10
 * Description: An alternate organization uses getline to read an entire input line; this makes getch and ungetch unnecessary. Revise the calculator to use this approach
 */

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "chapter4func.h"

#define MAXOP 100
#define MAXVAL 100 /* maximum depth of the val stack */
#define NUMBER '0'

int32_t getop1(char []);
void push1(double);
double pop1(void);

/* reverse polish notation calculator */

int32_t exercise4_10(void)
{
    int32_t type;
    double op2;
    char s[MAXOP];
    
    while((type = getop1(s)) != EOF)
    {
        switch(type)
        {
            case NUMBER:
                    push1(atof(s));
                    break;
            
			case '+':
                    push1(pop1() + pop1());
                    break;
            
			case '*':
                    push1(pop1() * pop1());
                    break;
            
			case '-':
                    op2 = pop1();
                    push1(pop1() - op2);
                    break;
            
			case '/':
                    op2 = pop1();
                    if ( op2 != 0.0)
                        push1(pop1()/op2);
                    break;

			case '%': {
				int32_t op2 = (int32_t) pop1();
				int32_t op1 = (int32_t) pop1();
				if (op2 != 0) {
					int32_t result = op1 % op2;
					if (result < 0)
						result += abs(op2);
					push1(result);
				} else {
        			printf("error: zero divisor not possible\n");
        			push1(0);
    			}
    			break;
			}

            case '\n':
                    printf("\t%.9g\n",pop1());
                    break;
            default:
                    printf("error: unknown command %s\n",s);
                    break;
        }
    }
    return 0;
}


int32_t sp = 0;
double val[MAXVAL];

/* push : push f onto value stack */

void push1(double f){
    if(sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full,can't push %g\n",f);
}

/* pop: pop and return top values from stack */

double pop1(void){
    if(sp > 0)
        return val[--sp];
    else{
        printf("error: stack empty \n");
        return 0.0;
    }
}

#define MAXLINE 100

/* line buffer and current index */
static char line[MAXLINE];
static int32_t li = 0;

static int32_t get_line(char s[], int32_t lim) {
    int32_t i = 0, c;
    while (i < lim - 1 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';
    return i;
}

/* get next operator or numeric operand from input line */
int getop1(char s[]) {
    int i = 0;
    int c;

    if (line[li] == '\0') {
        if (get_line(line, MAXLINE) == 0)
            return EOF;
        li = 0;
    }

    while ((s[0] = c = line[li++]) == ' ' || c == '\t');
    s[1] = '\0';

    /* if not a number, return as operator */
    if (!isdigit(c) && c != '.' && c != '-') 
        return c;

    i = 0;

    /* handle negative numbers */
    if (c == '-') {
        int next = line[li];
        
        if (isdigit(next) || next != '.') {
            s[i++] = c;
			c = line[li++];
        }else
			return '-';
    }

    /* collect integer part */
    if (isdigit(c))
        while (isdigit(s[++i] = c = line[li++]))
            ;

    /* collect fractional part */
    if (c == '.')
        while (isdigit(s[++i] = c = line[li++]))
            ;

    s[i] = '\0';
    li--; 

    return NUMBER;
}
