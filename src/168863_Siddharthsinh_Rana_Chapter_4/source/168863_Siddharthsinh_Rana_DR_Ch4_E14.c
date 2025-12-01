/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 18/09/2025
 * Chapter: 4
 * Exercise: 4.14
 * Description: Define a macro swap(t,x,y) that interchanges two arguments of type t. (Block structure will help.)
 */

#include <stdio.h>
#include <stdint.h>
#include "stackfunction.h"
#include "chapter4func.h"

/* macro to swap two varible x and y of type t */
#define swap(t,x,y) {t temp; temp = (x); (x) = (y); (y) = temp;}

int32_t exercise4_14() {
	char a, b;
	a = 'X';
	b = 'Y';
	printf("Befor swap a = %c, b = %c\n", a, b);
	swap(char,a,b);
	printf("After swap a = %c, b = %c", a, b);
    return 0;
}                                                                                       

