#include "chapter7func.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


int32_t main7(int32_t argc, char *argv[]){
    int32_t choice;
    int32_t ch;

    printf("Chapter 7:\n");
    printf("Enter a choice between 1 to 9:\n");

    if (scanf("%d", &choice) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    while ((ch = getchar()) != '\n' && ch != EOF);

    switch(choice){
        case 1:  exercise7_1(argc, argv);  break;
        case 2:  exercise7_2();  break;
        case 3:  exercise7_3();  break;
        case 4:  exercise7_4();  break;
        case 5:  exercise7_5();  break;
        case 6:  exercise7_6();  break;
        case 7:  exercise7_7(argc, argv);  break;
        case 8:  exercise7_8(argc, argv);  break;
        case 9:  exercise7_9();  break;

        default:
            printf("Invalid choice!\n");
            return 1;
    }
    return 0;
}