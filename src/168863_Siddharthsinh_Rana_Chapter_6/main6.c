#include "chapter6func.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


int32_t main6(){
    int32_t choice;
    int32_t ch;

    printf("Chapter 6:\n");
    printf("Enter a choice 1 or 2:\n");

    if (scanf("%d", &choice) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    while ((ch = getchar()) != '\n' && ch != EOF);

    switch(choice){
        case 1:  exercise6_1();  break;
        case 2:  exercise6_2();  break;

        default:
            printf("Invalid choice!\n");
            return 1;
    }
    return 0;
}