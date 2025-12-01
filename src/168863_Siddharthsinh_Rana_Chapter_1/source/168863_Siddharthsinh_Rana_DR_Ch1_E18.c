/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 27/08/2025
 * Chapter: 1
 * Exercise: 1.18
 * Description: Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines.
 */

#include <stdio.h>
#include <stdint.h>
#include "commonfunction.h"
#include "chapter1func.h"

int32_t exercise1_18() {
	printf("Exe18: Removing trailing blanks, newlines and tabs\n");
    uint32_t currlen;
    char line[1000];
    char cleaned[10000];
    uint32_t position = 0;

    while ((currlen = get_line(line, 1000)) > 0) {
        uint16_t prevSpace = 0;

        for (int index = 0; line[index] != '\0'; index++) {
            if (line[index] == ' ' || line[index] == '\t') {
                prevSpace = 1;
            }
            else if (line[index] == '\n') {
                if (position > 0 && cleaned[position - 1] != '\n') {
                    cleaned[position++] = '\n';
                }
                prevSpace = 0;
            }
            else {
                if (prevSpace && position > 0) {
                    cleaned[position++] = ' ';
                }
                prevSpace = 0;
                cleaned[position++] = line[index];
            }
        }
    }

    cleaned[position] = '\0';
    printf("\nCleaned output ->%s\n", cleaned);

    return 0;
}

