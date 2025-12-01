/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 02/09/2025
 * Chapter: 3
 * Exercise: 3.4
 * Description: In a two's complement number representation, our version of itoa does not handle the largest negative number, that is, the value of n equal to -(2wordsize-1). Explain why not. Modify it to print that value correctly, regardless of the machine on which it runs.
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include "commonfunction.h"
#include "chapter3func.h"

char *itoa(int32_t number, char string[]){
	int32_t i=0, sign;

	/* Handles negative numbers */

	if((sign = number) < 0){
		/* Handles lowest negative number */
		if(sign == INT_MIN){
			number = INT_MAX;
			string[i++] = (number % 10) + '0' + '1';
			number = number/10;
		}
		else{
			number = -number;
		}
	}
	/* adding last number at first */
	do{
		string[i++] = (number % 10) + '0';
		number = number / 10;
	}while(number> 0);

	/* adding sign of the number */
	if(sign < 0)
		string[i++] = '-';
	
	string[i] = '\0';
	reverse(string);
	return string;
}

int32_t exercise3_4(){

	char buf[100];
    printf("Enter a number to convert to string: ");
    if (scanf("%99s", buf) != 1){
        printf("Invalid input\n");
        return 1;
    }

    char *endptr;
    long long val = strtoll(buf, &endptr, 10);

    /* check if entire string was consumed */

    if (*endptr != '\0'){
        printf("Invalid number format\n");
        return 1;
    }

    /* check range explicitly */

    if (val < INT_MIN || val > INT_MAX){
        printf("Entered number is not in range\n");
        return 1;
    }

    int32_t number = (int32_t)val;
    char string[1000];
    printf("Number converted to String: %s", itoa(number, string));
    return 0;
}
