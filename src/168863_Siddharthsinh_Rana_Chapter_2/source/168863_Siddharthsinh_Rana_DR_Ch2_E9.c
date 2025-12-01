/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 02/09/2025
 * Chapter: 2
 * Exercise: 2.9
 * Description: In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x. Explain why. Use this observation to write a faster version of bitcount.
 */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include "chapter2func.h"

uint32_t bitcount(uint32_t number){
	uint32_t bitcounter = 0;
	while(number != 0){
		number = number & (number - 1);
		bitcounter++;
	}
	return bitcounter;
}

int32_t exercise2_9(){
	printf("Exe9: Count the number of 1's \n");
	uint32_t number;
	printf("Enter a number: ");
	if(scanf("%d", &number)){
		printf("Invalid input");
		return 1;
	}

	printf("Number of set bits: %d", bitcount(number));
	return 0;
}
