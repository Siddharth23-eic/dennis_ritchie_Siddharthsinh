/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 18/09/2025
 * Chapter: 4
 * Exercise: 4.6
 * Description: Add commands for handling variables. (It's easy to provide twenty-six variables with single-letter names.) Add a variable for the most recently printed value.
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "stackfunction.h"

#define MAXOP 100

int32_t exercise4_6(){
    int32_t type;
    double op2;
    char s[MAXOP];
	double vars[26] = {0};
	double lastval = 0.0;
    int32_t var = -1;

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;

        case VARIABLE:
            var = s[0] - 'A';
            push(vars[var]);
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
                printf("error: zero divisor for %%\n");
            break;
        
		case '=': 
            pop();
            vars[var] = pop();
            push(vars[var]);
            break;
        
		case '\n':
            lastval = pop();
            printf("\t%.8g\n", lastval);
            break;
        
		default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}
