#ifndef FLAGFUNC_H
#define FLAGFUNC_H

#include <stdint.h>
#define MAXLINES 5000
/* global flags from your original implementation */
extern int32_t numeric_flag;
extern int32_t reverse_flag;
extern int32_t fold_flag;
extern int32_t directory_flag;

/* field sorting options */
typedef struct {
    int field_no;
    int numeric;
    int reverse;
    int fold;
    int directory;
} FieldOpt;

/* field config array and count */
extern FieldOpt field_opts[20];
extern int nfields;

/* existing functions in your file */
int32_t readlines_5(char *lineptr[], int32_t maxlines);
void writelines_5(char *lineptr[], int32_t nlines);
void swap_5(void *v[], int32_t i, int32_t j);
int32_t numcmp_5(char *s1, char *s2);
int32_t foldcmp_5(char *str1, char *str2);
int32_t dircmp_5(char *s1, char *s2, int32_t fold);
void myqsort_5(void *v[], int32_t left, int32_t right,
               int32_t (*comp)(void *, void *), int32_t reverse);

/* new functions added for Exercise 5-17 */
char *extract_field(const char *line, int n);
int cmp_field(const char *f1, const char *f2, FieldOpt *opt);
int fieldcmp(void *a, void *b);

#endif
