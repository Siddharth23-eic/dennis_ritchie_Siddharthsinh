/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 08/09/2025
 * Chapter: 3
 * Exercise: 3.6
 * Description: Write a version of itoa that accepts three arguments instead of two. The third argument is a minimum field width; the converted number must be padded with blanks on the left if necessary to make it wide enough. 
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>
#include "commonfunction.h"
#include "chapter3func.h"

char *itoa_width(int32_t number, char string[], int32_t width) {
    int32_t i = 0, sign;

    /* store the sign */
    if ((sign = number) < 0) {
        if (number == INT_MIN) {
            
			/* handle INT_MIN */
            
			number = INT_MAX;
            string[i++] = (number % 10) + '0' + 1;
            number = number / 10;
        } else {
            number = -number;
        }
    }

    /* convert digits into string in reverse order */
    do {
        string[i++] = (number % 10) + '0';
        number = number / 10;
    } while (number > 0);

    if (sign < 0) {
        string[i++] = '-';
    }

    int32_t pad = (width > i) ? (width - i) : 0;
    while (pad > 0) {
        string[i++] = ' ';
		pad--;
    }

    string[i] = '\0';

    reverse(string);
    return string;
}

int32_t exercise3_6() {
    int32_t number, width;
    char string[1000];

    printf("Enter a number: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    printf("Enter minimum field width: ");
    if (scanf("%d", &width) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    printf("Result: %s \n", itoa_width(number, string, width));
    return 0;
}

