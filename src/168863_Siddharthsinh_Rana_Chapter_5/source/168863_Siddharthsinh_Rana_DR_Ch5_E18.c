/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 29/10/2025
 * Chapter: 5
 * Exercise: 5.18
 * Description: Make dcl recover from input errors.
 */

#include <stdio.h>
#include <stdint.h>
#include "chapter5func.h"
#include "parse.h"

int32_t exercise5_18(){
    while (gettoken() != EOF) {
        strcpy(datatype, token);
        out[0] = '\0';
        errflag = 0;

        dcl();

        if (!errflag && tokentype != '\n')
            printf("syntax error\n");

        if (!errflag)
            printf("%s is %s %s\n", name, out, datatype);

        /* read until newline so next declaration can start */
        while (tokentype != '\n' && tokentype != EOF)
            gettoken();
    }
    return 0;
}
