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

char *expand(char range[], char allchar[]){
	uint32_t i = 0, j = 0;
	if(range[0] == '-'){
		i = 1;
	}
	while(range[i] != '\0'){
		if(range[i] == '-'){
			if((range[i-1] >= 'a' && range[i-1] <= 'z') && (range[i+1] >= 'a' && range[i+1] <= 'z')){
				char character = range[i-1];
				if(character <= range[i+1]){
					while(character <= range[i+1]){
						allchar[j++] = character++;
					}
				}else{
					while(character >= range[i+1]){
						allchar[j++] = character--;
					}
				}
			}
			else if((range[i-1] >= 'A' && range[i-1] <= 'Z') && (range[i+1] >= 'A' && range[i+1] <= 'Z')){
                char character = range[i-1];
                if(character <= range[i+1]){
                    while(character <= range[i+1]){
                        allchar[j++] = character++;
                    }
                }else{
                    while(character >= range[i+1]){
                        allchar[j++] = character--;
                    }
                }
			}
			else if((range[i-1] >= '0' && range[i-1] <= '9') && (range[i+1] >= '0' && range[i+1] <= '9')){
                char character = range[i-1];
                if(character <= range[i+1]){
                    while(character <= range[i+1]){
                        allchar[j++] = character++;
                    }
                }else{
                    while(character >= range[i+1]){
                        allchar[j++] = character--;
                    }
                }
			}
			i++;
		}
		else{
			allchar[j++] = range[i];  
		}
		i++;
	}
	allchar[j] = '\0';
	return allchar;
}

int32_t exercise3_3(){
	int32_t character;
	char range[100], allchar[10000];
	uint32_t i = 0;

	while ((character = getchar()) != '\n' && character != EOF);
	while((character = getchar()) != EOF){
		if(character == '\n' || character == '\t' || character == ' '){
			break;
		}
		else{
			range[i] = character;
			i++;
		}
	}
	range[i] = '\0';
	printf("%s", expand(range, allchar));
	return 0;
}
