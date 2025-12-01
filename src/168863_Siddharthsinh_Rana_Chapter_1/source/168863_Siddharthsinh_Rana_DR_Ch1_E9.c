/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 26/08/2025
 * Chapter: 1
 * Exercise: 1.9
 * Description: Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "chapter1func.h"

int32_t exercise1_9(){

	printf("Exe9: Removing Multiple blanks\n");

    int32_t character;
    int32_t prev_blank = 0;
    int32_t	started = 0;

	/* Discard newlines from previous scanf*/
	while ((character = getchar()) != '\n' && character != EOF);

	/* Read and colapse multiple blanks*/
    while((character = getchar()) != EOF){
    	if (character == ' ' || character == '\t') {
        	if (started) {
            	prev_blank = 1;
        	}
    	} else {
        	if (prev_blank && started) {
            	putchar(' ');
            	prev_blank = 0;
        	}
        putchar(character);
        started = 1;
    	}
    }
    return 0;

}

