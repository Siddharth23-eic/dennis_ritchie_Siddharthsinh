/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 16/11/2025
 * Chapter: 5
 * Exercise: 7.5
 * Description: Rewrite the postfix calculator of Chapter 4 to use scanf and/or sscanf to do the input and number conversion. 
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "chapter7func.h"

#define MAXOP 100
#define MAXVAL 100

static int32_t sp = 0;
static double val[MAXVAL];

static void push(double f){
    if(sp < MAXVAL){
        val[sp++] = f;
    } else {
        printf("Error: Stack full");
    }
}

static double pop(){
    if(sp > 0){
        return val[--sp];
    } else{
        printf("Error: Stack empty");
        return 0.0;
    }
}
int32_t exercise7_5(){
    char token[MAXOP];
    double op2;

    printf("ENter a postfic expression(ctrl+d to end): \n");

    while(scanf("%99s", token) != EOF){
        double num;

        if(sscanf(token, "%lf", &num) == 1){
            push(num);
        }
        else if(strlen(token) == 1){
            switch(token[0]){
                case '+':
                    push(pop() + pop());
                    break;

                case '*':
                    push(pop() * pop());
                    break;

                case '-':
                    op2 = pop();
                    push(pop() - op2);
                    break;

                case '/':
                    op2 = pop();
                    if(op2 != 0.0){
                        push(pop() / op2);
                    } else {
                        printf("Error: Division by zero\n");
                    }
                    break;
                
                default:
                    printf("Error: Unknown command %s\n", token);
                    break;
            }
        }
        else {
            printf("Error: Unknown command %s\n", token);
        }
    }

    if(sp > 0){
    printf("Result: %.8g\n", pop());
    }
    
    return 0;
}
