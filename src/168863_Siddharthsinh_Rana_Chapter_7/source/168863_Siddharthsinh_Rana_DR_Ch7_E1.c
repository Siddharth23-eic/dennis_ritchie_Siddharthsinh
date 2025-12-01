/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 16/11/2025
 * Chapter: 5
 * Exercise: 7.1
 * Description: Write a program that converts upper case to lower or lower case to upper, depending on the name it is invoked with, as found in argv[0].
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include "chapter7func.h"

#define MAXLINES 1000

char *touppercase(char *st) {
    char *temp = st;
    while (*st != '\0') {
        if (*st >= 'a' && *st <= 'z')
            *st = *st - ('a' - 'A');
        st++;
    }
    return temp;
}

char *tolowercase(char *st){
    char *temp = st;
    while(*st != '\0'){
        if(*st >= 'A' && *st <= 'Z')
            *st = *st + ('a' - 'A');
        st++;
    }
    return temp;
}

int32_t exercise7_1(int32_t argc, char *argv[]) {
    
    if(argc < 2){
        printf("Use argument: 'upper' or 'lower'\n");
        return 1;
    }
    
    char st[MAXLINES];
    int32_t chr, i = 0;

    printf("Enter a sting:\n");

    while((chr = getchar()) != EOF && chr != '\n'){
        if(i < MAXLINES - 1)
            st[i++] = (char)chr;
    }
    st[i] = '\0';

    if(strcmp(argv[1], "upper") == 0){
        printf("Upper Case: %s\n", touppercase(st));
    }
    else if(strcmp(argv[1], "lower") == 0){
        printf("Lower Case: %s\n", tolowercase(st));
    }
    else{
        printf("Invalid Argument! Use 'upper' or 'lower'.\n");
    }
    
    return 0;
}

