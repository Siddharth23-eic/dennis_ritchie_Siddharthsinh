/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 16/11/2025
 * Chapter: 5
 * Exercise: 7.9
 * Description: Functions like isupper can be implemented to save space or to save time. Explore both possibilities.
 */

#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <ctype.h>
#include "chapter7func.h"

/* Custom isupper using lookup table */
static const unsigned char upper_table[128] = {
    ['A'] = 1, ['B'] = 1, ['C'] = 1, ['D'] = 1, ['E'] = 1,
    ['F'] = 1, ['G'] = 1, ['H'] = 1, ['I'] = 1, ['J'] = 1,
    ['K'] = 1, ['L'] = 1, ['M'] = 1, ['N'] = 1, ['O'] = 1,
    ['P'] = 1, ['Q'] = 1, ['R'] = 1, ['S'] = 1, ['T'] = 1,
    ['U'] = 1, ['V'] = 1, ['W'] = 1, ['X'] = 1, ['Y'] = 1,
    ['Z'] = 1
};

int32_t my_isupper(int32_t c) {
    return upper_table[(unsigned char)c];
}

int32_t exercise7_9() {
    int32_t itr;
    printf("Number of iterations to test performance: ");
    scanf("%d", &itr);

    volatile int32_t sink = 0;
    clock_t start, end;
    double t_custom, t_lib;

    /* Custom isupper */
    start = clock();
    for (int32_t i = 0; i < itr; i++)
        for (int32_t ch = 0; ch < 128; ch++)
            sink += my_isupper(ch);
    end = clock();
    t_custom = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Custom isupper time: %.9f seconds\n", t_custom);

    /* Library isupper */
    start = clock();
    for (int32_t i = 0; i < itr; i++)
        for (int32_t ch = 0; ch < 128; ch++)
            sink += isupper(ch);
    end = clock();
    t_lib = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Library isupper time: %.9f seconds\n", t_lib);

    return (int32_t)sink; /* Prevent optimization */
}