/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 01/09/2025
 * Chapter: 2
 * Exercise: 2.6
 * Description: Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged.
 */

#include <stdio.h>
#include <stdint.h>
#include "chapter2func.h"

int32_t setbits(int32_t targetval, int32_t sourceval, uint16_t Position, uint16_t nBits){
	if(targetval < 0 || sourceval < 0 || Position < 0 || nBits < 0){
		printf("Enter positive values");
		return -1;
	}
	else if(nBits >= Position + 1){
		printf("Invalid: Insufficient bits. nBits shouldn't be >= position + 1");
		return -1;
	}
	int32_t mask = (1 << nBits) - 1;

	return (targetval & ~(mask << (Position - nBits + 1))) | ((sourceval & mask) << (Position - nBits + 1));
}

int32_t exercise2_6(){
	printf("Exe6: Setting specific bits in target same as last nbits in source \n");
	int32_t targetval; 
	int32_t sourceval; 
	uint32_t Position;
	uint32_t nBits;

	printf("Target value: ");
	if (scanf("%d", &targetval) != 1) {
    	printf("Invalid input for target value.\n");
    	return 1;
	}

	printf("Source value: ");
	if (scanf("%d", &sourceval) != 1) {
    	printf("Invalid input for source value.\n");
    	return 1;
	}

	printf("Bit position in target: ");
	if (scanf("%d", &Position) != 1) {
    	printf("Invalid input for position.\n");
    	return 1;
	}

	printf("Number of bits: ");
	if (scanf("%d", &nBits) != 1) {
    	printf("Invalid input for number of bits.\n");
    	return 1;
	}

	int32_t result = setbits(targetval, sourceval, Position, nBits);
	if(result != -1)
		printf("%d", result);
	return 0;
}
