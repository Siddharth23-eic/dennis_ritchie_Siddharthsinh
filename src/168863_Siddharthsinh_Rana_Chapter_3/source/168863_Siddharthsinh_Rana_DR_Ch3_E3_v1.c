/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 02/09/2025
 * Chapter: 3
 * Exercise: 3.3
 * Description: Write a function expand(s1,s2) that expands shorthand notations like a-z in the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally.
 */

#include <stdio.h>
#include <stdint.h>
#include "chapter3func.h"

char *expand1(char range[], char allchar[]){
    uint32_t i = 0, j = 0;

    while(range[i] != '\0'){
        if(range[i] == '-' && range[i+1] != '\0'){
            char start = range[i-1];
            char end = range[i+1];

			/* Providing valid range */

            int32_t validrange = ((range[i-1] >= 'a' && range[i-1] <= 'z' && range[i+1] >= 'a' && range[i+1] <= 'z') ||
								 (range[i-1] >= 'A' && range[i-1] <= 'Z' && range[i+1] >= 'A' && range[i+1] <= 'Z') ||
								 (range[i-1] >= '0' && range[i-1] <= '9' && range[i+1] >= '0' && range[i+1] <= '9'));
			
			/* If valid range then expand */
			if(validrange){

				/* Range expansion in ascending */
				if(start <= end){
					char cur = start + 1;
					while(cur <= end){
						allchar[j++] = cur;
						cur++;
					}
				}

				/* Range Expansion in descending */
				else{
					char cur = start - 1;
					while(cur >= end){
						allchar[j++] = cur;
						cur--;
					}
				}
				i++;
			}

			/* If not valid range then print the character '-' */

			else{
				allchar[j++] = range[i];
			}
        }

		/* any leftovers are also added */
		
		else{
			allchar[j++] = range[i];
		}
		i++;
	}
    allchar[j] = '\0';
    return allchar;
}

int32_t exercise3_3v1(){
	int32_t character;
	char range[100], allchar[10000];
	uint32_t i = 0;

	while ((character = getchar()) != '\n' && character != EOF);

    printf("Enter the range string: ");
    while ((character = getchar()) != EOF) {
    	if (character == '\n' || character == '\t' || character == ' ') {
            break;
        }
        else {
        	range[i++] = character;
    	}    	
	}
    range[i] = '\0';

    printf("%s\n", expand1(range, allchar));
    return 0;
}
