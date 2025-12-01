/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 29/10/2025
 * Chapter: 5
 * Exercise: 5.12
 * Description: Extend entab and detab to accept the shorthand
                entab -m +n
                to mean tab stops every n columns, starting at column m. Choose convenient (for the user) default behaviour.
                Here, '*' indicates spaces and '#' indicates tab stops for visualization.
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "chapter5func.h"

#define TAB_DEFAULT 8
#define M_DEFAULT   0

int32_t exercise5_12(int32_t argc, char *argv[]);
void entab_5_12(int32_t m, int32_t n);
void detab_5_12(int32_t m, int32_t n);
static inline int next_tabstop(int col, int m, int n);

/* main entry for the exercise (keeps your original signature) */
int32_t exercise5_12(int32_t argc, char *argv[]) {
    int32_t m = M_DEFAULT, n = TAB_DEFAULT;

    if (argc < 2) {
        printf("Too less arguments\n");
        return 1;
    }

    if (strcmp(argv[1], "en") != 0 && strcmp(argv[1], "de") != 0) {
        printf("Invalid command (only en or de)\n");
        return 1;
    }

    /* parse -m and +n (order-independent). ignore other args. */
    for (int i = 2; i < argc; i++) {
        if (argv[i][0] == '-' && isdigit((unsigned char)argv[i][1]))
            m = abs(atoi(argv[i] + 1));
        else if (argv[i][0] == '+' && isdigit((unsigned char)argv[i][1]))
            n = abs(atoi(argv[i] + 1));
        else
            ; /* ignore extraneous args (like test-run flags) */
    }

    if (n <= 0)
        n = TAB_DEFAULT;

    if (strcmp(argv[1], "en") == 0)
        entab_5_12(m, n);
    else
        detab_5_12(m, n);

    return 0;
}

/* helper to calculate next tab stop after (or at) current column */
static inline int next_tabstop(int col, int m, int n) {
    if (col < m)
        return m;
    return m + (((col - m) / n) + 1) * n;
}

/* entab -> replace spaces with tabs ('#') and leftover spaces as '*' */
void entab_5_12(int32_t m, int32_t n) {
    int32_t ch;
    int32_t col = 0;

    while ((ch = getchar()) != EOF) {
        if (ch == ' ') {
            /* count consecutive spaces (we already consumed one) */
            int space_count = 1;
            int32_t c;
            while ((c = getchar()) != EOF && c == ' ')
                space_count++;
            /* c is now first non-space or EOF */

            /* consume spaces, producing '#' for each full tab-slot crossed,
               and '*' for leftover spaces that don't reach next tab stop */
            while (space_count > 0) {
                int next = next_tabstop(col, m, n);
                int need = next - col; /* spaces required to reach next stop */

                if (space_count >= need) {
                    /* we can reach the next tab stop -> emit a single '#' */
                    putchar('#');
                    col = next;
                    space_count -= need;
                } else {
                    /* not enough spaces to reach next stop -> emit '*' for each */
                    for (int i = 0; i < space_count; ++i) {
                        putchar('*');
                        col++;
                    }
                    space_count = 0;
                }
            }

            /* now process the non-space character we peeked (c) */
            if (c == EOF)
                break;

            putchar(c);
            if (c == '\n')
                col = 0;
            else
                col++;

        } else {
            putchar(ch);
            if (ch == '\n')
                col = 0;
            else
                col++;
        }
    }
}

/* detab -> replace tabs with spaces ('*') then mark stop with '#' */
void detab_5_12(int32_t m, int32_t n) {
    int32_t ch;
    int32_t col = 0;

    while ((ch = getchar()) != EOF) {
        if (ch == '\t') {
            /* print '*' until we reach next tab stop, then print '#' */
            do {
                putchar('*');
                col++;
            } while (col < m || ((col - m) % n) != 0);
            putchar('#');
        } else {
            putchar(ch);
            if (ch == '\n')
                col = 0;
            else
                col++;
        }
    }
}