#include "commonfunction.h"
#include "flagfunc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int32_t numeric_flag   = 0;
int32_t reverse_flag   = 0;
int32_t fold_flag      = 0;
int32_t directory_flag = 0;

FieldOpt field_opts[20];
int nfields = 0;

/* readlines: read input into lineptr[] */
int32_t readlines_5(char *lineptr[], int32_t maxlines){
    int32_t len, nlines = 0;
    char line[1000];

    while((len = get_line(line, sizeof(line))) > 0){
        if(line[len - 1] == '\n')
            line[len - 1] = '\0';

        char *p = malloc(len);
        if(!p)
            return -1;

        strcpy(p, line);
        lineptr[nlines++] = p;

        if(nlines >= maxlines)
            return -1;
    }
    return nlines;
}

/* writelines: print lines */
void writelines_5(char *lineptr[], int32_t nlines){
    while(nlines-- > 0)
        printf("%s\n", *lineptr++);
}

/* swap: swap two pointers */
void swap_5(void *v[], int32_t i, int32_t j){
    void *temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* numcmp : numeric comparison of strings */
int32_t numcmp_5(char *s1, char *s2){
    double v1 = atof(s1);
    double v2 = atof(s2);
    if(v1 < v2) return -1;
    if(v1 > v2) return 1;
    return 0;
}

/* myqsort_5: quicksort with reversing */
void myqsort_5(void *v[], int32_t left, int32_t right,
               int32_t (*comp)(void *, void *), int32_t reverse){

    int32_t i, last;
    if(left >= right)
        return;

    swap_5(v, left, (left + right)/2);
    last = left;

    for(i = left + 1; i <= right; i++){
        int cmp = (*comp)(v[i], v[left]);

        if((!reverse && cmp < 0) ||
           ( reverse && cmp > 0))
            swap_5(v, ++last, i);      /* FIXED */
    }

    swap_5(v, left, last);             /* FIXED */

    myqsort_5(v, left,     last - 1, comp, reverse);
    myqsort_5(v, last + 1, right,    comp, reverse);
}

/* case-insensitive version of strcmp() */
int32_t foldcmp_5(char *str1, char *str2){
    while(*str1 != '\0' && *str2 != '\0'){
        char chr1 = tolower((unsigned char)*str1);
        char chr2 = tolower((unsigned char)*str2);

        if(chr1 != chr2)
            return chr1 - chr2;

        str1++;
        str2++;
    }
    if(*str1 == '\0' && *str2 == '\0')
        return 0;
    else if(*str1 == '\0')
        return -1;
    else
        return 1;
}

int32_t dircmp_5(char *s1, char *s2, int32_t fold){
    char c1, c2;

    while (*s1 != '\0' && *s2 != '\0') {

        while (!isalnum((unsigned char)*s1) &&
               !isspace((unsigned char)*s1) &&
               *s1 != '\0')
            s1++;

        while (!isalnum((unsigned char)*s2) &&
               !isspace((unsigned char)*s2) &&
               *s2 != '\0')
            s2++;

        c1 = *s1;
        c2 = *s2;

        if (fold) {
            c1 = tolower((unsigned char)c1);
            c2 = tolower((unsigned char)c2);
        }

        if (c1 != c2)
            return c1 - c2;

        if (*s1 == '\0' || *s2 == '\0')
            break;

        s1++;
        s2++;
    }

    if(*s1 == '\0' && *s2 == '\0')
        return 0;
    else if(*s1 == '\0')
        return -1;
    else
        return 1;
}

/* extract nth field */
char *extract_field(const char *line, int n){
    static char buf[256];
    int count = 1;

    while(*line && isspace((unsigned char)*line))
        line++;

    const char *start = line;

    while(*line){
        if(isspace((unsigned char)*line)){
            if(count == n){
                int len = (int)(line - start);
                if(len > 255) len = 255;
                strncpy(buf, start, len);
                buf[len] = '\0';
                return buf;
            }
            while(*line && isspace((unsigned char)*line))
                line++;
            start = line;
            count++;
        }
        line++;
    }

    if(count == n){
        strncpy(buf, start, 255);
        buf[255] = '\0';
        return buf;
    }

    return "";
}

/* compare two fields */
int cmp_field(const char *f1, const char *f2, FieldOpt *opt){
    int r;

    if(opt->directory)
        r = dircmp_5((char*)f1, (char*)f2, opt->fold);
    else if(opt->numeric)
        r = numcmp_5((char*)f1, (char*)f2);
    else if(opt->fold)
        r = foldcmp_5((char*)f1, (char*)f2);
    else
        r = strcmp(f1, f2);

    if(opt->reverse)
        r = -r;

    return r;
}

/* master comparator: field-by-field */
int fieldcmp(void *a, void *b){
    char *s1 = *(char **)a;
    char *s2 = *(char **)b;

    for(int i = 0; i < nfields; i++){
        FieldOpt *opt = &field_opts[i];

        char *f1 = extract_field(s1, opt->field_no);
        char *f2 = extract_field(s2, opt->field_no);

        int r = cmp_field(f1, f2, opt);
        if(r != 0)
            return r;
    }

    return strcmp(s1, s2);
}
