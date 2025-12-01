/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 10/09/2025
 * Chapter: 4
 * Exercise: 4.3
 * Description: Given the basic framework, it's straightforward to extend the calculator. Add the modulus (%) operator and provisions for negative numbers. 
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include "stackfunction.h"
#include "chapter4func.h"

int32_t exercise4_3() {
    int32_t type;
    double operand2;
    char string[MAXOP];

    while ((type = getop(string)) != EOF) {
        switch (type) {
            case NUMBER:   /* push number */
                push(atof(string));
                break;

            case '+':
                push(pop() + pop());
                break;

            case '*':
                push(pop() * pop());
                break;

            case '-':
                operand2 = pop();
                push(pop() - operand2);
                break;

            case '/':
                operand2 = pop();
                if (operand2 != 0.0)
                    push(pop() / operand2);
                else
                    printf("error: zero divisor\n");
                break;

            case '%': {
				int32_t op2 = (int32_t) pop();
				int32_t op1 = (int32_t) pop();
				if (op2 != 0) {
					int32_t result = op1 % op2;
					if (result < 0)
						result += abs(op2);
					push(result);
				} else {
        			printf("error: zero divisor not possible\n");
        			push(0);
    			}
    			break;
			}


            case '\n':
                printf("\t%.8g\n", pop());
                clear_stack(); /* reset after each line */
                break;

            default:
                printf("error: unknown command %s\n", string);
                break;
        }
    }
    return 0;
}

