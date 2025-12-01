/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created date: 29/08/2025
 * Modified date: 
 * Description: This is 2nd chapter's main file.
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "chapter3func.h"

int32_t main3(){
	int32_t choice;
    printf("Enter a choice between 1 to 7:\n");
     if (scanf("%d", &choice) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

	switch(choice){
		case 1:
			exercise3_1();
			break;
		case 2:
			exercise3_2();
			break;
		case 3:
            exercise3_3();
            break;
		case 4:
            exercise3_3v1();
            break;
		case 5:
            exercise3_4();
            break;
		case 6:
            exercise3_5();
            break;
		case 7:
			exercise3_6();
			break;
		default:
			printf("Enter valid case");
			break;
	}
	return 0;
}
