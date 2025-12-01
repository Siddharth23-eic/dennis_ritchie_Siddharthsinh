/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 18/09/2025
 * Chapter: 4
 * Exercise: 4.8
 * Description: Suppose that there will never be more than one character of pushback. Modify getch and ungetch accordingly.
 */

#include <stdio.h>
#include <stdint.h>
#include "stackfunction.h"
#include "chapter4func.h"

/* Holds the single pushed-back character */
static int32_t buf_mod = EOF;

/* Get a character */
int32_t getch_mod(void) {
    if (buf_mod != EOF) {
        int32_t c = buf_mod;
        buf_mod = EOF;   /* Clear buffer after using it */
        return c;
    } else {
        return getchar();
    }
}


int32_t exercise4_8() {
	printf("Type a string: ");
	int32_t character;

	while((character = getch_mod()) != EOF){
		while(character == '\n' || character == ' ' || character == '\t'){
			character = getch_mod();
			if(character == EOF) return 0;
		}

		/* single charcater pushback */
		putchar(character);
		putchar('\n');

		/* Skip rest of the word */
        while ((character = getch_mod()) != EOF && character != '\n' && character != ' ' && character != '\t');

        if (character == EOF) break;
	}
	return 0;
}
