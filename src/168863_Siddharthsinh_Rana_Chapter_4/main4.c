/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created date: 29/08/2025
 * Modified date:
 * Description: This is 4th chapter's main file.
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "chapter4func.h"

int32_t main4() {
    int32_t choice;
    int ch;

    printf("Chapter 4:\n");
    printf("Enter a choice between 1 to 14:\n");

    if (scanf("%d", &choice) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    /* flush stdin to remove newline left by scanf */
    while ((ch = getchar()) != '\n' && ch != EOF);

    switch (choice) {
        case 1:  exercise4_1();  break;
        case 2:  exercise4_2();  break;
        case 3:  exercise4_3();  break;
        case 4:  exercise4_4();  break;
        case 5:  exercise4_5();  break;
        case 6:  exercise4_6();  break;
        case 7:  exercise4_7();  break;
        case 8:  exercise4_8();  break;
        case 9:  exercise4_9();  break;
        case 10: exercise4_10(); break;
        case 11: exercise4_11(); break;
        case 12: exercise4_12(); break;
        case 13: exercise4_13(); break;
        case 14: exercise4_14(); break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    return 0;
}

