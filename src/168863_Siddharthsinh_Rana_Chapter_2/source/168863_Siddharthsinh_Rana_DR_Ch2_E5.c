/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 01/09/2025
 * Chapter: 2
 * Exercise: 2.5
 * Description: Write the function any(s1,s2), which returns the first location in a string s1 where any character from the string s2 occurs, or -1 if s1 contains no characters from s2. (The standard library function strpbrk does the same job but returns a pointer to the location.)
 */

#include <stdio.h>
#include <stdint.h>
#include "chapter2func.h"

int16_t any(char mainstr[], char substr[]){
	uint16_t i = 0, j = 0;
	while(mainstr[i] != '\0' && substr[j] != '\0'){
		if(mainstr[i] == substr[j])
			return i;
		j++;
		if(substr[j] == '\0'){
			j = 0;
			i++;
		}
	}
	return -1;
}

int32_t exercise2_5(){
	printf("Exe5: return first location of matching character \n");
    char mainstr[1000];
    char substr[1000];
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
    printf("Enter the sub string: ");
    while((character = getchar()) != '\n'){
        if(character != EOF){
            substr[i] = character;
            i++;
        }
    }
    substr[i] = '\0';
	int16_t result  = any(mainstr, substr);
	if(result != -1)
    	printf("First matching position is: %d\n", any(mainstr, substr));
	
	else
		printf("No duplicate found");
    return 0;
}
