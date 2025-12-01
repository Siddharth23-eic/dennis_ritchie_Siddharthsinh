/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 29/10/2025
 * Chapter: 5
 * Exercise: 5.14
 * Description: Modify the sort program to handle a -r flag, which indicates sorting in reverse (decreasing) order. Be sure that -r works with -n.
 */

#include <stdio.h>
#include <stdint.h>
#include "chapter5func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flagfunc.h"

static char *lineptr[MAXLINES];

int32_t exercise5_14(int32_t argc, char *argv[]){
    int32_t nlines;
    int32_t num = 0;
    int32_t reverse = 0;

    while (--argc > 0 && (*++argv)[0] == '-') {
        char *p = *argv + 1;
        while (*p) {
            if (*p == 'n') num = 1;
            else if (*p == 'r') reverse = 1;
            else{
                printf("sort: illegal option %c\n", *p);
                return 1;
            }
            p++;
        }
    }

    if ((nlines = readlines_5(lineptr, MAXLINES)) < 0)
        return 1;
    
    int (*compare)(void *, void *);
    if (num)
        compare = (int32_t (*)(void *, void *)) numcmp_5;
    else
        compare = (int32_t (*)(void *, void *)) strcmp;
    
    myqsort_5((void **) lineptr, 0, nlines - 1, compare, reverse);

    writelines_5(lineptr, nlines);
    return 0;
}
