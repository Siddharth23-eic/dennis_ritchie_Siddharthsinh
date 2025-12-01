/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created date: 29/08/2025
 * Modified date: 
 * Description: This is 2nd chapter's main file.
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "chapter2func.h"

int32_t main2(){
	int32_t choice;
	printf("Chapter 2:");
	printf("Enter a choice between 1 to 10:\n");
	if (scanf("%d", &choice) != 1) {
    	printf("Invalid input!\n");
    	return 1;
	}

	switch(choice){
		case 1:
			exercise2_1();
			break;
		case 2:
			exercise2_2();
			break;
		case 3:
            exercise2_3();
            break;
		case 4:
            exercise2_4();
            break;
		case 5:
            exercise2_5();
            break;
		case 6:
            exercise2_6();
            break;
		case 7:
            exercise2_7();
            break;
		case 8:
            exercise2_8();
            break;
		case 9:
            exercise2_9();
            break;
		case 10:
            exercise2_10();
            break;
		default:
			printf("Enter valid case");
			break;
	}
	return 0;
}
