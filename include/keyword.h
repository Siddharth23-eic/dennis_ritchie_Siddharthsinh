#ifndef PARSE_H
#define PARSE_H

#define MAXWORD 1000

#include <stdint.h>

struct key {
    char *word;
    int32_t count;
};

extern struct key keytab[];
extern int32_t NKEYS;

int32_t getword(char *, int32_t);
int32_t binsearch(char *, struct key *, int32_t);

#endif
