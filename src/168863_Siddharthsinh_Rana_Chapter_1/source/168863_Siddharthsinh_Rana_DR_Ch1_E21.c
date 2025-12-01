/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 29/08/2025
 * Chapter: 1
 * Exercise: 1.21
 * Description: Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. When either a tab or a single blank would suffice to reach a tab stop, which should be given preference?
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "commonfunction.h"
#include "chapter1func.h"

#define TABSTOP 8

int32_t exercise1_21() {
	printf("Exe21: Entab \n");
    char line[1000];
    uint32_t length = 0;

    while ((length = get_line(line, 1000)) > 0) {
        uint32_t position = 0;
        uint16_t spaces = 0;
		for (uint32_t index = 0; index < length; index++) {
            if (line[index] == ' ') {
                spaces++;
                position++;

                /* if we just reached a tabstop, emit a tab */
                if (position % TABSTOP == 0) {
                    putchar('\t');
                    spaces = 0;
                }
            } else {
                /* flush any pending spaces before printing a non-space */
                while (spaces > 0) {
                    putchar(' ');
                    spaces--;
                }

                if (line[index] == '\n') {
                    putchar('\n');
                    position = 0;
                } else {
                    putchar(line[index]);
                    position++;
                }
            }
        }

        /* flush spaces at end of line */
        while (spaces > 0) {
            putchar(' ');
            spaces--;
        }
    }
    return 0;
}
