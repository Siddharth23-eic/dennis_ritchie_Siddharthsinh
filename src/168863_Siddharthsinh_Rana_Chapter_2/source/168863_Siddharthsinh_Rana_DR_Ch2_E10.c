/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 02/09/2025
 * Chapter: 2
 * Exercise: 2.10
 * Description: Rewrite the function lower, which converts upper case letters to lower case, with a conditional expression instead of if-else.
 */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include "chapter2func.h"

void lower(char string[]){
	for(int itr = 0; string[itr] != '\0'; itr++){
		printf("%c", (string[itr] >= 'A' && string[itr] <= 'Z'? string[itr] + 32: string[itr]));
	}
}

int32_t exercise2_10(){
	uint8_t character;
	char string[1000];
	uint32_t itr = 0;

	while ((character = getchar()) != '\n' && character != EOF);
	printf("Enter a string: \n");
	while((character = getchar()) != EOF){
		if(character == '\n'){
			break;
		}
		else{
			string[itr++] = character;
		}
	}
	string[itr] = '\0';
	printf("Lowered case string: \n");
	lower(string);
	return 0;
}
