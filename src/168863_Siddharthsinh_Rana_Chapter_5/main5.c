/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 29/10/2025
 * Chapter: 5
 * Description: This is main file of chapter which called all the exercise function. 
 */

 #include <stdio.h>
 #include <stdint.h>
 #include <stdlib.h>
 #include "chapter5func.h"

 int32_t main5(int32_t argc, char *argv[]){
    int32_t choice;
    int32_t ch;

    printf("Chapter 5:\n");
    printf("Enter a choice between 1 to 20:\n");

    if (scanf("%d", &choice) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    while ((ch = getchar()) != '\n' && ch != EOF);

    switch(choice){
        case 1:  exercise5_1();  break;
        case 2:  exercise5_2();  break;
        case 3:  exercise5_3();  break;
        case 4:  exercise5_4();  break;
        case 5:  exercise5_5();  break;
        case 6:  exercise5_6();  break;
        case 7:  exercise5_7();  break;
        case 8:  exercise5_8();  break;
        case 9:  exercise5_9();  break;
        case 10: exercise5_10(argc, argv); break;
        case 11: exercise5_11(argc, argv); break;
        case 12: exercise5_12(argc, argv); break;
        case 13: exercise5_13(argc, argv); break;
        case 14: exercise5_14(argc, argv); break;
        case 15: exercise5_15(argc, argv); break;
        case 16: exercise5_16(argc, argv); break;
        case 17: exercise5_17(argc, argv); break;
        case 18: exercise5_18(); break;
        case 19: exercise5_19(); break;
        case 20: exercise5_20(); break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }
    return 0;
}
