/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 26/08/2025
 * Chapter: 1
 * Exercise: 1.8
 * Description: Write a program to count blanks, tabs, and newlines.
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "chapter1func.h"

int32_t exercise1_8() {

	printf("Exe8: Count blanks, tabs, newlines\n");

    uint32_t blanks = 0, tabs = 0, newlines = 0;
    int character;

    printf("Enter a string (Ctrl+D to end input on Linux/Mac or Ctrl+Z on Windows):");
	while((character = getchar()) != '\n' && character != EOF);
    while ((character = getchar()) != EOF) {
        if (character == ' ') blanks++;
        else if (character == '\n') newlines++;
        else if (character == '\t') tabs++;
    }

    printf("Total count of blanks are %d, tabs are %d, and newlines are %d\n", blanks, tabs, newlines);
    return 0;
}
