/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 18/09/2025
 * Chapter: 4
 * Exercise: 4.7
 * Description: . Write a routine ungets(s) that will push back an entire string onto the input. Should ungets know about buf and bufp, or should it just use ungetch?
 */

#include <stdio.h>
#include <stdint.h>
#include "stackfunction.h"
#include "chapter4func.h"
#define MAXLINE1 1000

void ungets(const char s[]) {
    int i = 0;
    while (s[i] != '\0')
        i++;

    while (i > 0)
        ungetch(s[--i]);
}


int32_t exercise4_7() {
    char s[MAXLINE1];
    int32_t c, i = 0;

    printf("Type a string (end with newline): ");
	
	/* Read full line from stdin */
	while ((c = getchar()) != EOF && i < (int32_t)(sizeof(s) - 1)) {
        s[i++] = c;
    }
    s[i] = '\0';
    
	/* Push the string back into getch buffer */
	ungets(s);

    printf("Reading back with getch(): ");
    while ((c = getch()) != EOF)
        putchar(c);

    putchar('\n');
    return 0;
}
