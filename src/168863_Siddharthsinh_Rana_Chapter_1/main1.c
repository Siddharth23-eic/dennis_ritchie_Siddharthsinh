/* Owner: Siddharhsinh Rana
 * Topic: Dennis Ritchie
 * Created date: 22/08/2025
 * Modified date: 27/08/2025
 * Description: This is the local main file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "chapter1func.h"

int32_t main1(){
    int32_t exercise;
	printf("Enter a choice between 1 to 24:\n");
	if(scanf("%d", &exercise) != 1){
		printf("Invalid input\n");
		return 1;
	}

    switch(exercise){
        case 1:
            exercise1_1();
            break;
        case 2:
            exercise1_2();
            break;
        case 3:
            exercise1_3();
            break;
        case 4:
            exercise1_4();
            break;
        case 5:
            exercise1_5();
            break;
        case 6:
            exercise1_6();
            break;
        case 7:
            exercise1_7();
            break;
        case 8:
            exercise1_8();
            break;
        case 9:
            exercise1_9();
            break;
        case 10:
            exercise1_10();
            break;
        case 11:
            exercise1_11();
            break;
        case 12:
            exercise1_12();
            break;
        case 13:
            exercise1_13();
            break;
        case 14:
            exercise1_14();
            break;
		case 15:
			exercise1_15();
			break;
        case 16:
            exercise1_16();
            break;
        case 17:
            exercise1_17();
            break;
        case 18:
            exercise1_18();
            break;
        case 19:
            exercise1_19();
            break;
        case 20:
			exercise1_20();
			break;
        case 21:
			exercise1_21();
			break;
        case 22:
			exercise1_22();
			break;
        case 23:
			exercise1_23();
			break;
        case 24:
			exercise1_24();
    }
	return 0;
}
