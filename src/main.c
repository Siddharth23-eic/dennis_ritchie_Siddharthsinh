/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created date: 08/09/2025
 * Modified date:
 * Description: This is global main file.
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int32_t main1();
int32_t main2();
int32_t main3();
int32_t main4();
int32_t main5(int32_t argc, char *argv[]);
int32_t main6();
int32_t main7(int32_t argc, char *argv[]);
int32_t main8();

int32_t main(int32_t argc, char *argv[]) {
    int32_t choice;
    int ch;

    printf("Make a choice for chapter's main function between 1 to 8:\n");
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    /* flush stdin to remove leftover newline */
    while ((ch = getchar()) != '\n' && ch != EOF);

    switch (choice) {
        case 1:
            main1();
            break;
        case 2:
            main2();
            break;
        case 3:
            main3();
            break;
        case 4:
            main4();
            break;
        case 5:
            main5(argc, argv);
            break;
        case 6:
            main6();
            break;
        case 7:
            main7(argc, argv);
            break;
        case 8:
            main8(argc, argv);
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }

    return 0;
}

