/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 01/09/2025
 * Chapter: 2
 * Exercise: 2.7
 * Description: Write a function invert(x,p,n) that returns x with the n bits that begin at position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
 */

#include <stdio.h>
#include <stdint.h>
#include "chapter2func.h"

int32_t invert(int32_t targetval, int32_t Position, int32_t nBits){
	if(targetval < 0 || Position < 0 || nBits < 0){
		printf("Enter positive value");
		return -1;
	}
	else if(nBits >= Position + 1){
		printf("Invalid: Insufficient bits nBits shouldn't be >= Position + 1");
		return -1;
	}
	int32_t mask = (1 << nBits) - 1;

	return targetval ^ (mask << (Position - nBits + 1));
}

int32_t exercise2_7(){
	 printf("Exe7: inverting nbits from specific position \n");
	int32_t targetval, Position, nBits;
	
	printf("Target value: ");
	if (scanf("%d", &targetval) != 1) {
    	printf("Invalid input for target value.\n");
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


	int32_t result = invert(targetval, Position, nBits);
	if(result != -1){
		printf("%d", result);
	}
	return 0;
}
