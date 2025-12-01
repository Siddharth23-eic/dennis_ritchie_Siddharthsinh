/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 28/08/2025
 * Chapter: 1
 * Exercise: 1.19
 * Description: Write a function reverse(s) that reverses the character string s. Use it to write a program that reverses its input a line at a time.
 */


#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "commonfunction.h"
#include "chapter1func.h"

int32_t exercise1_19() {
	printf("Exe19: Reverse a string \n");
    char line[1000];
    char words[1000];
    uint32_t count = 0;
    int len;

    while ((len = get_line(line, 1000)) > 0) {
        for (int i = 0; i < len; i++) {
                words[count++] = line[i];
        }
    }
    words[count] = '\0';

    printf("The original string is -> %s\n", words);
    printf("The reversed string is -> %s\n", reverse(words));
    return 0;
}

