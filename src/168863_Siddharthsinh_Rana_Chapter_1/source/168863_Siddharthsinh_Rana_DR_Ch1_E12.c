/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 26/08/2025
 * Chapter: 1
 * Exercise: 1.12
 * Description: Write a program that prints its input one word per line
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "chapter1func.h"

#define IN 1 /* Inside a word */
#define OUT 0 /* Outside a word*/

int32_t exercise1_12(){
	printf("Exe12: One word per line\n");
    
	int16_t character;
    uint16_t state = OUT;

	while ((character = getchar()) != '\n' && character != EOF);
    while((character = getchar()) != EOF){
        if(character == ' ' || character == '\t'){
            if(state == IN){
                putchar('\n');
                state = OUT;
            }
        }
        else{
            putchar(character);
            state = IN;
        }
    }
    return 0;
}
