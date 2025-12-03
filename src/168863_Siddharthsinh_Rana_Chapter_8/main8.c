#include "chapter8func.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


int32_t main8(int32_t argc, char *argv[]){
    int32_t choice;
    int32_t ch;

    printf("Chapter 8:\n");
    printf("Enter a choice between 1 to 8:\n");

    if (scanf("%d", &choice) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    while ((ch = getchar()) != '\n' && ch != EOF);

    switch(choice){
        case 1:  exercise8_1(argc, argv);  break;
        case 2:  exercise8_2();  break;
        case 3:  exercise8_3();  break;
        case 4:  exercise8_4();  break;
        case 5:  exercise8_5();  break;
        case 6:  exercise8_6();  break;
        case 7:  exercise8_7();  break;

        default:
            printf("Invalid choice!\n");
            return 1;
    }
    return 0;
}