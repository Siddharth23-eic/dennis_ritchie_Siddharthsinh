/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 27/08/2025
 * Chapter: 1
 * Exercise: 1.16
 * Description: Revise the main routine of the longest-line program so it will correctly print the length of arbitrary long input lines, and as much as possible of the text.
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "commonfunction.h"
#include "chapter1func.h"

int32_t exercise1_16(){
	printf("Exe16: Longest line and it's length \n");
    int32_t character;
	uint32_t currlen;
    uint32_t maxlen = 0;
    char line[1000];
    char longestline[1000];
	int32_t idx = 0;
	while ((character = getchar()) == EOF && character == '\n');
    while ((character = getchar()) != EOF) {
        if (character == '\n') {
            line[idx] = '\0';
            if (currlen > maxlen) {
                maxlen = currlen;
                copy(longestline, line);
            }
            currlen = 0;   
			idx = 0;
        } else {
            if (idx < sizeof(line) - 1) {
                line[idx++] = (char)character;
            }
            currlen++;
        }
    }
    if(maxlen > 0)
        printf("\nThe size of the longest line is %d which is -> %s", maxlen, longestline);
    return 0;
}
