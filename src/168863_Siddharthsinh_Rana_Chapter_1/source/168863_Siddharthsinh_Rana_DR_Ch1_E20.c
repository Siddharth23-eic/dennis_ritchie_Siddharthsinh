/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 28/08/2025
 * Chapter: 1
 * Exercise: 1.20
 * Description: Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "commonfunction.h"
#include "chapter1func.h"

#define TABSTOP 4


int32_t exercise1_20(){
	printf("Exe20: Detab\n");
	char line[1000];
	uint32_t length;
	uint32_t prevspace = 0;
	while((length = get_line(line,1000)) > 0){
		uint32_t position = 0;
		for(int index = 0; index < length; index++){
			if(line[index] == '\t'){
				int space = TABSTOP - (position % TABSTOP);
				for(int sp = 0; sp < space; sp++){
					putchar(' ');
					position++;
				}
				prevspace = 0;
			}
			else if(line[index] == ' '){
				if(!prevspace){
					putchar(' ');
					position++;
				}
				prevspace = 1;
			}
			else if(line[index] == '\n'){
				putchar('\n');
				position = 0;
				prevspace = 0;
			}
			else{
				putchar(line[index]);
				position++;
				prevspace = 0;
			}
		}
	}
	return 0;
}
