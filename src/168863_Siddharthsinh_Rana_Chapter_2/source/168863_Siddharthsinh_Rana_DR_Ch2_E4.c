/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 01/09/2025
 * Chapter: 2
 * Exercise: 2.4
 * Description: Write an alternative version of squeeze(s1,s2) that deletes each character in s1 that matches any character in the string s2.
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include "chapter2func.h"

void squeeze(char mainstr[], char delstr[]){
	uint16_t i = 0, j = 0, k;
	for(; mainstr[i] != '\0'; i++){
		for(k = 0; delstr[k] != '\0'; k++){
			if(tolower(mainstr[i]) == tolower(delstr[k]))
				break;
		}
		if(delstr[k] == '\0'){
			mainstr[j] = mainstr[i];
			j++;
		}
	}mainstr[j] = '\0'; 
}

int32_t exercise2_4(){
	printf("Exe4: delete characters form mainstr that matches delstr\n");
	char mainstr[1000];
    char delstr[1000];
    int character;
    uint16_t i = 0;
	
	while ((character = getchar()) != '\n' && character != EOF);
    printf("Enter the main string: ");
    while((character = getchar()) != '\n'){
		if(character != EOF){
			mainstr[i] = character;
			i++;
		}
    }
    mainstr[i] = '\0';

    i = 0;
    printf("Enter the delete string: ");
    while((character = getchar()) != '\n'){
		if(character != EOF){
        	delstr[i] = character;
			i++;
		}
    }
    delstr[i] = '\0';

    squeeze(mainstr, delstr);

    printf("Resulting string: %s\n", mainstr);

    return 0;
}

