/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 29/10/2025
 * Chapter: 5
 * Exercise: 5.19
 * Description: Modify undcl so that it does not add redundant parentheses to declarations.
 */

#include <stdio.h>
#include <stdint.h>
#include "chapter5func.h"
#include "parse.h"

int32_t exercise5_19(){
    while(gettoken() != EOF){
        undcl();
        while(tokentype != '\n' && tokentype != EOF)
            gettoken();
    }
    return 0;
}
