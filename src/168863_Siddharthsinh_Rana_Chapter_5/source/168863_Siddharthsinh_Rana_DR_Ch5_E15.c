/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 29/10/2025
 * Chapter: 5
 * Exercise: 5.15
 * Description: Add the option -f to foldupper and lower case togather, do that case distinctions are not made during sorting; for example, a and A compare equal.
 */

#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "chapter5func.h"
#include "flagfunc.h"

int32_t exercise5_15(int32_t argc, char *argv[]){
    int32_t numlines;
    int32_t num = 0;
    int32_t reverse = 0;
    int32_t fold = 0;

    char *lineptr[MAXLINES];

    if(argc <= 1){
        printf("Error: use at least one flag -r/-f\n");
        return 1;
    }

    /* To detect the flags -r -f */
    while(--argc > 0 && (*++argv)[0] == '-'){
        char *flag = *argv + 1;
        while(*flag != '\0'){
            if(*flag == 'r')
                reverse = 1;
            else if(*flag == 'f')
                fold = 1;
            else{
                printf("sort: illegal option %c\n", *flag);
                return 1;
            }
            flag++;
        }
    }

    /* Reading the lines */
    if((numlines = readlines_5(lineptr, MAXLINES)) < 0)
        return 1;

    /* Compare(function pointer) to choose function */
    int32_t (*compare)(void *, void *);

    if(fold){
        compare = (int32_t (*)(void *, void *))foldcmp_5;
    }
    else{
        compare = (int32_t (*)(void *, void *))strcmp;
    }

    /* Sorting the lines */
    myqsort_5((void **)lineptr, 0, numlines - 1, compare, reverse);

    /* Writing final output */
    writelines_5(lineptr, numlines);
    return 0;
}
