/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 29/10/2025
 * Chapter: 5
 * Exercise: 5.1
 * Description: As written getint treats a + or - not followed by a digit as a valid representation of zero. Fix it to push such a character back on the input.
 */

#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include "chapter5func.h"
#include "stackfunction.h"

int32_t getint(int32_t *pn) {
    int32_t c, sign;
    int32_t sign_char = 0;

    while (isspace(c = getch()));

    /* If not a digit, not a sign, and not EOF, it's invalid */
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-') {
        sign_char = c;
        c = getch();
        if (!isdigit(c)) {
            /* Sign not followed by digit, invalid */
            ungetch(c);
            ungetch(sign_char);
            return 0;
        }
    }

    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
    }

    *pn *= sign;

    if (c != EOF) {
        ungetch(c);
    }

    return c;
}

int32_t exercise5_1(){
    int32_t number, result;
    printf("Enter an integer: ");
    result = getint(&number);
    if(result != 0)
        printf("You entered: %d\n", number);
    else
        printf("Invalid input.\n");
    return 0;
}
