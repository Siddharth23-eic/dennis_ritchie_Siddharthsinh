/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 18/09/2025
 * Chapter: 4
 * Exercise: 4.9
 * Description: Our getch and ungetch do not handle a pushed-back EOF correctly. Decide what their properties ought to be if an EOF is pushed back, then implement your design.
 */

#include <stdio.h>
#include <stdint.h>
#include "chapter4func.h"

#define BUFSIZE 100

static int32_t buf[BUFSIZE];
static int32_t bufp = 0;

int32_t getch_modd(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch_modd(int32_t character) {
    if(character == EOF){
		return;
	}

	if (bufp >= BUFSIZE) {
        printf("ungetch: buffer overflow\n");
		return;
    }
	buf[bufp++] = character;
}

int exercise4_9() {
    int32_t character;

    printf("Enter text (Ctrl+D to end input):\n");

	/* Reads input */
	while((character = getch_modd()) != EOF){

		/* Skip any initial spaces/tabs/newlines */
		while(character == ' ' || character == '\t' || character == '\n'){
			character = getch_modd();
			if(character == EOF)
				break;
		}
		if(character == EOF)
			break;

		printf("%c\n",character);
		while(character != '\n' && character != EOF)
			character = getch_modd();
	}

    printf("EOF encountered.\n");
    return 0;
}
