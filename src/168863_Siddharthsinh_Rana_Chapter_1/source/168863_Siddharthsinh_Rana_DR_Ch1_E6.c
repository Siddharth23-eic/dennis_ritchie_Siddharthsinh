/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 20/08/2025
 * Chapter: 1
 * Exercise: 1.6
 * Description: Verify that the expression getchar() != EOF is 0 or 1.
 */

#include <stdio.h>
#include <stdint.h>
#include "chapter1func.h"

int32_t exercise1_6(){
	printf("Exe6: Print value of getchar() != EOF\n");
    printf("Type something (Ctrl+D to send EOF)\n");
    printf("getchar != EOF gives: %d\n", getchar() != EOF);

    return 0;
}
