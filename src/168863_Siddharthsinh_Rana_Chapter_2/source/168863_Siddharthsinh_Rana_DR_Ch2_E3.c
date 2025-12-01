/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 01/09/2025
 * Chapter: 2
 * Exercise: 2.3
 * Description: Write a function htoi(s), which converts a string of hexadecimal digits (including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F.
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "chapter2func.h"

int32_t htoi(char string[]){
	int itr = 0, number = 0;

	if(string[0] == '0' && (string[1] == 'x' || string[1] == 'X'))
		itr = 2;
	
	while(string[itr] != '\0'){
		if(string[itr] >= '0' && string[itr] <= '9'){
			number = 16 * number + (string[itr] - '0');
		}
		else if(string[itr] >= 'a' && string[itr] <= 'f'){
			number = 16 * number + (string[itr] - 'a' + 10);
		}
		else if(string[itr] >= 'A' && string[itr] <= 'F'){
			number = 16 * number + (string[itr] - 'A' + 10);
		}
		else{
			printf("Enter valid hex number");
			return -1;
		}
		itr++;
	}
	return number;	
}

int32_t exercise2_3(){
	printf("Exe3: Hexadecimal to decimal\n");
	char str[1000];
	int8_t character; 
	uint16_t i = 0;

	while ((character = getchar()) != '\n' && character != EOF);
	printf("Enter a Hexadecimal value to convert into integer:");
	while((character = getchar()) != '\n'){
		if(character != EOF){
			str[i] = character;
			i++;
		}
	}
	str[i] = '\0';
	int32_t result = htoi(str);
	if(result != -1)
		printf("Integer value of entered hexadecimal %s is %d", str, htoi(str));
	return 0;
}
