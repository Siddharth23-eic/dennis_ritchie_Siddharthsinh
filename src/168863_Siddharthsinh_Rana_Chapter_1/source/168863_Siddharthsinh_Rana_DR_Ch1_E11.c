/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 26/08/2025
 * Chapter: 1
 * Exercise: 1.11
 * Description: How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any?
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "chapter1func.h"

#define IN 1 /* Inside a word */
#define OUT 0 /* Outside a word*/

int32_t exercise1_11(){
	printf("Exe11: Word Count\n");

    uint16_t count = 0, space = 0,newline = 0, tab = 0;
    int16_t character;

	while ((character = getchar()) != '\n' && character != EOF);
    while((character = getchar()) != EOF){
        if(character == ' ')
			space++;

		else if(character == '\n')
			newline++;

		else if(character == '\t')
			tab++;

        count++;
    }
    printf("%d %d %d", newline, space, tab);
    return 0;
}
