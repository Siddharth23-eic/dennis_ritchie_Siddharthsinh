/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 18/09/2025
 * Chapter: 4
 * Exercise: 4.12
 * Description: Adapt the ideas of printd to write a recursive version of itoa; that is, convert an integer into a string by calling a recursive routine.
 */

#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include "stackfunction.h"
#include "chapter4func.h"

int32_t itoa_r(int32_t num, char str[], int32_t i){
	if (num == INT_MIN) {
        str[i++] = '-';
        i = itoa_r(-(num / 10), str, i);
        str[i++] = -(num % 10) + '0';
        str[i] = '\0';
        return i;
    }

	if(num < 0){
		str[i++] = '-';
		num = -num;
	}

	if(num/10){
		i = itoa_r(num/10, str, i);
	}
	str[i++] = num % 10 + '0';
	str[i] = '\0';
	return i;
}

int32_t exercise4_12() {
	char str[20];
	int32_t num;

	printf("Enter a number: ");
	scanf("%d", &num);

	itoa_r(num, str, 0);
    printf("%s\n", str);
	return 0;
}                                                                                       

