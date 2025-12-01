/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 29/10/2025
 * Chapter: 5
 * Exercise: 5.20
 * Description: Expand dcl to handle declarations with function argument types, qualifiers like const, and so on. 
 */

#include <stdio.h>
#include <stdint.h>
#include "chapter5func.h"
#include "parse.h"

int32_t exercise5_20(){
    printf("Enter a declaration:\n");
    while(gettoken() != EOF){
        parse_datatype();
        out[0] = '\0';

        dcl();
        if(!errflag){
            printf("%s: %s %s\n", name, out, datatype);
        }
        errflag = 0;
        printf("\nEnter a declaration:\n");
    }
    return 0;
}
