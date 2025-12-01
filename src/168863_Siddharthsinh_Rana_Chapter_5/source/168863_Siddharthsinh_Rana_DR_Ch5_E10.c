/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 29/10/2025
 * Chapter: 5
 * Exercise: 5.10
 * Description: Write the program expr, which evaluates a reverse Polish expression from the command line, where each operator or operand is a separate argument. For example,
expr 2 3 4 + *
evaluates 2 * (3+4).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include "chapter5func.h"

#define MAX 100

double stack[MAX];
int32_t top = -1;

/* Pushing Operation */
void push_10(double value){
    if(top < MAX - 1)
        stack[++top] = value;
    else
        printf("Stack Overflow\n");
}

/* Popping Operation */
double pop_10(){
    if(top >= 0)
        return stack[top--];
    else{
        printf("Stack Empty\n");
        return 0.0;
    }
}

int32_t rpn_10(int32_t argc, char *argv[]) {
    double op2;

    for (int32_t i = 1; i < argc; i++) {
        char *ch = argv[i];

        if (isdigit(ch[0]) || (ch[0] == '-' && isdigit(ch[1]))) {
            push_10(atof(ch));
        } 
        else if (strlen(ch) == 1) {
            switch (ch[0]) {
                case '+':
                    if (top < 1) { printf("Insufficient operands\n"); return 1; }
                    push_10(pop_10() + pop_10());
                    break;

                case '*':
                    if (top < 1) { printf("Insufficient operands\n"); return 1; }
                    push_10(pop_10() * pop_10());
                    break;

                case '-':
                    if (top < 1) { printf("Insufficient operands\n"); return 1; }
                    op2 = pop_10();
                    push_10(pop_10() - op2);
                    break;

                case '/':
                    if (top < 1) { printf("Insufficient operands\n"); return 1; }
                    op2 = pop_10();
                    if (op2 == 0.0) { printf("Zero divisor\n"); return 1; }
                    push_10(pop_10() / op2);
                    break;

                default:
                    printf("Unknown command!\n");
                    return 1;
            }
        } 
        else {
            printf("Unknown command!\n");
            return 1;
        }
    }

    if (top == 0)
        printf("Result: %.8g\n", pop_10());
    else if (top > 0)
        printf("Operands remain\n");
    else
        printf("No result on stack\n");

    return 0;
}

int32_t exercise5_10(int32_t argc, char *argv[]) {
    if (argc < 2) {
        printf("run this code with some arguments....\n");
        return 1;
    }
    return rpn_10(argc, argv);
}
