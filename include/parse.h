#ifndef PARSE_H
#define PARSE_H

#include <stdint.h>

#define MAXTOKEN 100

/* Token types */
enum {
    NAME = 256,
    PARENS,
    BRACKETS,
    TYPE,
    QUALIFIER
};

extern int32_t tokentype;
extern char token[MAXTOKEN];
extern char name[MAXTOKEN];
extern char datatype[MAXTOKEN];
extern char out[1000];
extern int32_t errflag;

int32_t gettoken(void);
void dcl(void);
void dirdcl(void);
void undcl(void);

/* helper */
void parse_datatype(void);

#endif
