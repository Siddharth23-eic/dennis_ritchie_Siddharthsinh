/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 29/10/2025
 * Chapter: 5
 * Exercise: 5.7
 * Description: Rewrite readlines to store lines in an array supplied by main, rather than calling alloc to maintain storage. How much faster is the program?
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "chapter5func.h"
#include "commonfunction.h"

#define MAXLINES 5000 /* max lines to be stored */
#define MAXLEN 1000 /* max length of any input line */
#define MAXSTORE (MAXLEN * MAXLEN) /* size of available storage */

/* Pointers to text lines */
char *lineptr[MAXLINES];
char buf[MAXSTORE]; /* buffer to hold all lines */

int32_t readlines(char *lineptr[], int32_t nlines, char *store, int32_t maxstore);
void writelines(char *lineptr[], int32_t nlines);
void qsort(char *lineptr[], int32_t left, int32_t right);

int32_t exercise5_7() {
    int32_t nlines;

    if ((nlines = readlines(lineptr, MAXLINES, buf, MAXSTORE)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

/* readlines: read input lines into an array */
int32_t readlines(char *lineptr[], int32_t maxlines, char *store, int32_t maxstore){
    int32_t len, nlines = 0;
    char line[MAXLEN];
    char *p = store, *end = store + maxstore;

    while ((len = get_line(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || p + len > end)
            return -1;
        if (line[len - 1] == '\n')  
            line[len - 1] = '\0';
        strcpy(p, line);             
		lineptr[nlines++] = p;       
        p += strlen(p) + 1;          
    }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines){
	for(int32_t i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}


void swap(char *v[], int32_t i, int32_t j);

/* qsort: sort array in increasing order */
void qsort(char *v[], int32_t left, int32_t right){
	int32_t i, last;
	if(left >= right) return; /* do nothing if array has fewer than 2 elements */
	
	swap(v, left, (left + right)/2);
	last = left;

	for(i = left + 1; i <= right; i++)
		if(strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);

	swap(v, left, last);

	qsort(v, left, last -1);
	qsort(v, last + 1, right);
}

/* swap: interchnage strings at position i and j */
void swap(char *v[], int32_t i, int32_t j){
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
