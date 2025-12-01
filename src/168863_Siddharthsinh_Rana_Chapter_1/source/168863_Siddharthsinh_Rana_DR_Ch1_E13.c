/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 26/08/2025
 * Chapter: 1
 * Exercise: 1.13
 * Description: Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "chapter1func.h"

int32_t exercise1_13(){
	printf("Exe13: Histogram of word's character \n");
    int16_t character;
    uint16_t wordcount = 0, charcount = 0;
    char word[100];
	while ((character = getchar()) != '\n' && character != EOF);
    while((character = getchar()) != EOF){
        if(character == ' ' || character == '\t' || character == '\n'){
            if(charcount>0){
                word[charcount] = '\0';
                printf("%s", word);
                for(int hist = 0; hist < charcount; hist++){
                    putchar('-');
                }printf("\n");
                wordcount++;
                charcount = 0;
            }
        }
        else{
            word[charcount] = character;
            charcount++;
        }
    }
    if (charcount > 0) {
        word[charcount] = '\0';
        printf("%s: ", word);
        for (int i = 0; i < charcount; i++)
            putchar('-');
        putchar('\n');
        wordcount++;
    }
    return 0;
}

