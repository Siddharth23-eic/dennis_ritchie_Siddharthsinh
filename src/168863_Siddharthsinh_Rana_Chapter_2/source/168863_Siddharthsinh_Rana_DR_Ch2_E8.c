/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 02/09/2025
 * Chapter: 2
 * Exercise: 2.8
 * Description: Write a function rightrot(x,n) that returns the value of the integer x rotated to the right by n positions.
 */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include "chapter2func.h"

uint32_t rightrot(int32_t target, int32_t rotby, uint32_t bits){
	if(target < 0){
		printf("Error: Number must be non-negative");
		return -1;
	}
	rotby = rotby % bits;
	if(rotby < 0){
		rotby += bits;
	}
	uint32_t result = (target >> rotby) | (target << (bits - rotby));
	uint32_t mask  = (bits == 32) ? 0xFFFFFFFFu :((1u << bits) - 1);

	return result & mask;
}

int32_t exercise2_8(){
	printf("Exe8: Right rotation\n");
	uint32_t bits;
	int32_t target, rotby;

	printf("Target value: ");
	if (scanf("%d", &target) != 1) {
   		printf("Invalid input for target.\n");
    	return 1;
	}

	printf("Rotation by: ");
	if (scanf("%d", &rotby) != 1) {
    	printf("Invalid input for rotation.\n");
    	return 1;
	}

	printf("Total Bits: ");
	if (scanf("%d", &bits) != 1) {
    	printf("Invalid input for total bits.\n");
    	return 1;
	}

	int32_t result = rightrot(target, rotby, bits);
	if(result != -1)
		printf("%d", result);
	return 0;
}
