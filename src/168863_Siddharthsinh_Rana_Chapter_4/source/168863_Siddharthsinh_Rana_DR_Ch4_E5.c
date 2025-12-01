/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 18/09/2025
 * Chapter: 4
 * Exercise: 4.5
 * Description: Add access to library functions like sin, exp, and pow. See <math.h> in Appendix B, Section 4.
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "stackfunction.h"

int32_t exercise4_5(void) {
    int32_t type;
    double operand2;
    char string[MAXOP];

    while ((type = getop(string)) != EOF) {
        switch (type) {

        case NUMBER:
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
        
		case '%':
            operand2 = pop();
            if (operand2 != 0.0) 
				push(fmod(pop(), operand2));
            else 
				printf("error: zero divisor for modulo\n");
            break;
        
		case FUNCTION:
            mathfunc(string);
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
