/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 29/10/2025
 * Chapter: 5
 * Exercise: 5.13
 * Description: Write the program tail, which prints the last n lines of its input. By default, n is set to 10, let us say, but it can be changed by an optional argument so that
tail -n
prints the last n lines. The program should behave rationally no matter how unreasonable the input or the value of n. Write the program so it makes the best use of available storage; lines should be stored as in the sorting program of Section 5.6, not in a two-dimensional array of fixed size.
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "chapter5func.h"
#include "commonfunction.h"
#define MAXLINES 5000
#define MAXLEN   1000
#define ALLOCSIZE 100000     

static char allocbuf[ALLOCSIZE]; 
static char *allocp = allocbuf;   

/* allocate n characters from allocbuf */
static char *alloc_tail(int n) {
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else {
        return NULL;
    }
}

/* read lines for tail */
static int readlines_tail(char *lineptr[], int maxlines) {
    int len, nlines = 0;
    char *p, line[MAXLEN];

    while ((len = get_line(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc_tail(len)) == NULL)
            return -1;

        line[len - 1] = '\0'; 
        strcpy(p, line);
        lineptr[nlines++] = p;
    }
    return nlines;
}

/* print last n lines of input */
void print_last_n_lines(int32_t n) {
    char *lineptr[MAXLINES];
    int nlines = readlines_tail(lineptr, MAXLINES);

    if (nlines < 0) {
        fprintf(stderr, "error: input too big to store\n");
        return;
    }

    if (n <= 0)
        n = 10;
    if (n > nlines)
        n = nlines;

    printf("\nLast %d lines of input:\n", n);
    for (int i = nlines - n; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}


int32_t exercise5_13(int32_t argc, char *argv[]){
    int32_t n = 10; 
    if(argc == 2){
        n = atoi(argv[1]);
    }
    print_last_n_lines(n);
    return 0;
}
