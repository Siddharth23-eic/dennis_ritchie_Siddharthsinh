/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 27/08/2025
 * Chapter: 1
 * Exercise: 1.14
 * Description: Write a program to print a histogram of the frequencies of different characters in its input.
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "chapter1func.h"

int32_t exercise1_14(){
	printf("Exe14: Histogram of character frequency \n");
    int16_t character;
    uint16_t chararr[256]= {0};
	
	while ((character = getchar()) != '\n' && character != EOF);

    while((character = getchar()) != EOF){
        chararr[(unsigned char)character]++;
    }

    for (int chars = 0; chars < 256; chars++) {
        if (chararr[chars] > 0) {

            /* Handle special printable names */

            if (chars == ' ')
                printf("\\s ");
            else if (chars == '\n')
                printf("\\n ");
            else if (chars == '\t')
                printf("\\t ");
            else
                printf("%c ", chars);

            /* Print histogram with '*' */

            for (int hist = 0; hist < chararr[chars]; hist++) {
                printf("*");
            }
            printf("\n");
        }
    }
    return 0;
}
