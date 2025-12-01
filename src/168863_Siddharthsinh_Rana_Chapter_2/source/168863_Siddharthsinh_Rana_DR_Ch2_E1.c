/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 29/08/2025
 * Chapter: 2
 * Exercise: 2.1
 * Description: Write a program to determine the ranges of char, short, int, and long variables, both signed and unsigned, by printing appropriate values from standard headers and by direct computation. Harder if you compute them: determine the ranges of the various floating-point types
 */

#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <float.h>
#include "chapter2func.h"

int32_t exercise2_1(){
	printf("Exe1: Datatype ranges\n");
	printf("--------------Ranges---------------\n");
	printf("Char range: %d to %d\n", CHAR_MIN, CHAR_MAX);
	printf("Uchar range: %d\n", UCHAR_MAX);
	printf("short:  %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("ushort: 0 to %u\n", USHRT_MAX);
    printf("int:    %d to %d\n", INT_MIN, INT_MAX);
    printf("uint:   0 to %u\n", UINT_MAX);
    printf("long:   %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("ulong:  0 to %lu\n", ULONG_MAX);
    printf("float:       %e to %e\n", FLT_MIN, FLT_MAX);
    printf("double:      %e to %e\n", DBL_MIN, DBL_MAX);
    printf("long double: %Le to %Le\n", LDBL_MIN, LDBL_MAX);
    return 0;
}
