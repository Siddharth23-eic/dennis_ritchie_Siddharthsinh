/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 09/09/2025
 * Chapter: 4
 * Exercise: 4.1
 * Description: Write the function strindex(s,t) which returns the position of the rightmost occurrence of t in s, or -1 if there is none.
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "chapter4func.h"

int32_t strindex(char mainstr[], char substr[]){
	int32_t occurance = 0;
	uint32_t i = 0, j = 0;
	while(mainstr[i] != '\0' && substr[j] != '\0'){
		if(mainstr[i] == substr[j]){
			occurance = i;
		}
		j++;
		if(substr[j] == '\0'){
			j = 0;
			i++;
		}
	}
	return (occurance>0) ? occurance : -1;
}

int32_t exercise4_1(){
	printf("Exe1: rightmost occurance of a substring in mainstring\n");
	char mainstr[1000];
	char substr[1000];
	uint8_t character;
	uint32_t i = 0;

	while((character = getchar()) != '\n' && character != EOF);
	printf("Enter the main string: ");
	while((character = getchar()) != '\n'){
		if(character != EOF){
			mainstr[i] = character;
			i++;
		}
	}
	mainstr[i] = '\0';

	i = 0;
	printf("Enter a sub string: ");
	while((character = getchar()) != '\n'){
		if(character != EOF){
			substr[i] = character;
			i++;
		}
	}
	substr[i] = '\0';
	int32_t result = strindex(mainstr, substr);
	if(result != -1){
		printf("Last occurance at %d",result);
	}
	else{
		printf("%d", result);
	}
	return 0;
}
