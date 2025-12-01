/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 16/11/2025
 * Chapter: 5
 * Exercise: 7.3
 * Description:
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "chapter7func.h"
#include <stdarg.h>
#include "stdinout.h"

int32_t exercise7_3() {
    minprintf("Integer: %d\n", 10);
    minprintf("Float: %f\n", 12.54);
    minprintf("Unsigned integer: %u\n", 12U);
    minprintf("String: %s\n", "Test String");
    minprintf("Character: %c\n", 'A');
    minprintf("Octal of integer: %o\n", 10);
    minprintf("Hexadecimal of integer: %x\n", 10);
    return 0;
}