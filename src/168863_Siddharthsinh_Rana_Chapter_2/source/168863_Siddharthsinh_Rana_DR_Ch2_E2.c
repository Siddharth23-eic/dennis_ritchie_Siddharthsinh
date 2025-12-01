/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 29/08/2025
 * Chapter: 2
 * Exercise: 2.2
 * Description: Write a loop equivalent to the for loop above without using && or ||.
 */

#include <stdio.h>
#include <stdint.h>
#include "chapter2func.h"

int32_t exercise2_2(){
	printf("Exe2: Equivalent loop to for loop without using || or &&\n");
	uint16_t i = 0;
	uint8_t character;
	uint16_t limit = 10000;
	char string[1000];
	while ((character = getchar()) != '\n' && character != EOF);
	while(i < limit -1){
		character = getchar();
		if(character == '\n')
			break;
		if(character == EOF)
			break;
		string[i] = character;
		i++;
	}
	string[i] = '\0';
	printf("Entered string is: %s\n", string);
	return 0;
}
