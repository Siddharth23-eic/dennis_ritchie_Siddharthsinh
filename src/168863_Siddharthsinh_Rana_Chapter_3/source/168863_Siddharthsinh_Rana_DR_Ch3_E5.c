/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 03/09/2025
 * Chapter: 3
 * Exercise: 3.5
 * Description: Write the function itob(n,s,b) that converts the integer n into a base b character representation in the string s. In particular, itob(n,s,16) formats s as a hexadecimal integer in s.
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>
#include "commonfunction.h"
#include "chapter3func.h"

/*This Function is convert decimal number to a particular base*/

char *itob(int32_t number, char string[], int32_t base){
	int32_t i = 0;
	if(number < 0){

		/* To handle minimum negative value */

		if(number == INT_MIN){
			uint32_t unumber = (uint32_t)INT_MIN;
			do{
				string[i++] = ((unumber % base) < 10) 
								? (unumber % base) + '0' 
								: (unumber % base - 10) + 'A';
				unumber = unumber / base;
			}while(unumber > 0);
		}

		/* To handle other negative number */
		else{
			number = -number;
			do{
				string[i++] = ((number % base) < 10) 
								? (number % base) + '0' 
								: (number % base - 10) + 'A';
				number = number / base;
			}while(number > 0);
		}
	}

	/* To handle positive values */

	else{
		do{
			string[i++] = ((number % base) < 10) 
							? (number % base) + '0' 
							: (number % base - 10) + 'A';
			number = number / base;
		}while(number > 0);
	}
	string[i++] = '\0';
	reverse(string);
	return string;
}

int32_t exercise3_5(){
	int32_t number, base;
	char string[1000];

	printf("Enter a decimal number: ");
	if(scanf("%d", &number) != 1){
		printf("Invalid input");
		return 1;
	}

	printf("Enter a base: ");
	if(scanf("%d", &base) != 1){
		printf("Invalid input");
		return 1;
	}
	
	/* Handle invalid base values */
	if(base <= 0){
		printf("Enter a valid base value\n");
		return 1;
	}

	printf("The coverted to base %d is %s", base, itob(number, string, base));
	return 0;
}

