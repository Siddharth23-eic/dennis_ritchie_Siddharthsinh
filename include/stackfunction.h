#ifndef STACK_OP
#define STACK_OP

#include <stdint.h>

#define MAXOP 100
#define NUMBER '0'
#define FUNCTION 'f'
#define VARIABLE '1'

/* Stack Function */
void push(double value);
double pop(void);

/* Input function */
int32_t getch(void);
void ungetch(int32_t);
int32_t getop(char string[]);
void print_top(void);
void duplicate_top(void);
void swap_top(void);
void clear_stack(void);
void mathfunc(char string[]);
void print_stack(void);
void ungets(const char string[]);
void mod_ungetch(int32_t);
int32_t mod_getch(void);
int32_t getch_mod(void);
void ungetch_mod(int32_t);

#endif
