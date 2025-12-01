/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 02/09/2025
 * Chapter: 3
 * Exercise: 3.1
 * Description: Our binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside.) Write a version with only one test inside the loop and measure the difference in run-time.
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "chapter3func.h"

int32_t binarysearch(int32_t target, int32_t array[], uint32_t arrsize){
	uint32_t low = 0, high = arrsize - 1, mid;

	while(low < high){
		/* middle of the array */
		mid = (low + high) / 2;
		if(target <= array[mid])
			high = mid;
		else
			low = mid + 1;
	}
	
	/* Target found */

	if(array[low] == target)
		return low;
	else{
		printf("Target %d not found", target);
		return -1;
	}
}

int32_t exercise3_1(){
	uint32_t arrsize;
	printf("Enter size of array: ");
	if(scanf("%d", &arrsize) != 1){
		printf("Invalid input\n");
		return 1;
	}

	int32_t *array = malloc(arrsize * sizeof(uint32_t)), target;
    
	/* Taking array element */

	printf("Enter array elements: ");
	for(uint32_t itr = 0; itr < arrsize; itr++){
		if(scanf("%d", &array[itr]) != 1){
			printf("Invalid input");
			return 1;
		}
	}

	printf("Enter a target to find: ");
	if(scanf("%d", &target) != 1){
		printf("Invalid input");
		return 1;
	}

	for(uint32_t i = 0; i < arrsize - 1; i++){
		if(array[i] > array[i+1]){
			printf("Array is not sorted.");
			free(array);
			return 1;
		}
	}

	uint32_t result = binarysearch(target, array, arrsize);

	if(result != -1)
		printf("Target is at %d position.", result);
	
	free(array);
	return 0;
}
