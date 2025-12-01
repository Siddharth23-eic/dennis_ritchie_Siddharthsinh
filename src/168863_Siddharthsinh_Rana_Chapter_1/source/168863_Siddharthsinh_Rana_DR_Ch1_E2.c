/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 20/08/2025
 * Chapter: 1
 * Exercise: 1.2
 * Description: Experiment to find out what happens when prints's argument string contains \c, where c is some character not listed above.
 */

#include <stdio.h>
#include <stdint.h>
#include "chapter1func.h"

int32_t exercise1_2(){
	printf("Exe2: different escape character\n");
    printf("Bell\a Backspace\b Tab\t Newline\n");
    printf("Single quote: \'  Double quote: \"  Backslash: \\\n");
    printf("Octal A: \101  Hex A: \x41\n");
    return 0;
}
