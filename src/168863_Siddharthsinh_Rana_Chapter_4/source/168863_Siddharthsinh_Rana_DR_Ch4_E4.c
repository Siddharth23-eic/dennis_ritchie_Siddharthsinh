/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 17/09/2025
 * Chapter: 4
 * Exercise: 4.4
 * Description: Add the commands to print the top elements of the stack without popping, to duplicate it, and to swap the top two elements. Add a command to clear the stack.
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include "stackfunction.h"
#include "chapter4func.h"

int32_t exercise4_4(){
    int32_t type;
    double operand2;
    char string[MAXOP];

    while((type = getop(string)) != EOF){

        switch(type){
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
                if(operand2 != 0.0)
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

            case 't':
    			print_top();
    			break;

			case 'd':
    			duplicate_top();
    			print_stack();
  	  			break;

			case 's':
    			swap_top();
    			print_stack();
    			break;

			case 'c':
    			clear_stack();
    			break;

            case '\n':
				printf("\t%.8g\n", pop());
				break;

            default:
                printf("error: unknown command %s\n", string);
                break;
        }
    }
    return 0;
}
