/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 09/09/2025
 * Chapter: 1
 * Exercise: 1.22
 * Description: Write a program to `fold'' long input lines into two or more shorter lines after the last non-blank character that occurs before the n-th column of input. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.
 */

#include <stdio.h>
#include <stdint.h>
#include "commonfunction.h"
#include "chapter1func.h"

char *fold(char input[], char output[], uint32_t width){
	uint16_t i = 0, j = 0;
	uint16_t column = 0;
	uint16_t last_blank = 0;

	while(input[i] != '\0'){
		output[j] = input[i];
		
		if(input[i] == ' ' || input[i] == '\t')
			last_blank = j;
		if(input[i] == '\n'){
			column = 0;
			last_blank = 0;
		}
		else if(++column >= width){
			if(last_blank != 0){
				output[last_blank] = '\n';
				column = j - last_blank;
				last_blank = 0;
			}else{
				output[j++] = '\n';
				column = 0;
			}
		}
		i++;
		j++;
	}
	output[j] = '\0';
	return output;
}

int32_t exercise1_22(){
	char input[1000];
	char folded[1000];

	while(get_line(input, 1000) > 0){
		printf("%s", fold(input, folded, 20));
	}
	return 0;
}
