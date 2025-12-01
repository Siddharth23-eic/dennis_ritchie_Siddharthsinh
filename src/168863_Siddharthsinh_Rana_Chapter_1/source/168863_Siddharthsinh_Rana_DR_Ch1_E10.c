/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 26/08/2025
 * Chapter: 1
 * Exercise: 1.10
 * Description: Write a program to copy its input to its output, replacing each tab by \t, each backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in an unambiguous way.
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "chapter1func.h"

int32_t exercise1_10(){
	printf("Exe10: Replacing tabs and newline and backspace and backslash with it's escape character\n");

    int16_t character;
	while ((character = getchar()) != '\n' && character != EOF);
    while((character = getchar()) != EOF){
        if(character == '\t'){
            putchar('\\');
            putchar('t');
        }
        else if(character == '\b'){
            putchar('\\');
            putchar('b');
        }
        else if(character == '\\'){
            putchar('\\');
            putchar('\\');
        }
        else
            putchar(character);
    }
    return 0;

}
