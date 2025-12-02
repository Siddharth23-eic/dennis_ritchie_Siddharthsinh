/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 16/11/2025
 * Chapter: 5
 * Exercise: 7.2
 * Description: Write a program that will print arbitrary input in a sensible way. As a minimum, it should print non-graphic characters in octal or hexadecimal according to local custom, and break long text lines. 
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include "chapter7func.h"

#define MAXCOL 30 /* maximum column width */
#define BUFSIZE 100000

static void printable(int32_t c, int32_t *col){
    char buf[16];
    int32_t width;
    /* Special handling for newline */
    if(c == '\n'){
        snprintf(buf, sizeof(buf), "0xa");
        width = (int32_t)strlen(buf);
        
        if(*col + width > MAXCOL){
            printf("\n");
            *col = 0;
        }
        fputs(buf, stdout);
        putchar('\n');
        *col = 0;
        return;
    }

    if(isprint((unsigned char)c)){
        /* Printable character */
        if(*col + 1 > MAXCOL){
            putchar('\n');
            *col = 0;
        }
        putchar(c);
        (*col)++;
    }else{
        /* Non-printable character */
        snprintf(buf, sizeof(buf), "0x%02x", (unsigned char)c);
        width = (int32_t)strlen(buf);
        
        if(*col + width > MAXCOL){
            putchar('\n');
            *col = 0;
        }
        fputs(buf, stdout);
        *col += width;
    }
}
int32_t exercise7_2() {
    int32_t c;
    int32_t col = 0;
    static int32_t buffer[BUFSIZE];
    int32_t size = 0;

    while((c = getchar()) != EOF){
        if(size < BUFSIZE)
            buffer[size++] = c;
        else
            break;
    }

    for(int32_t i = 0; i < size; i++){
        printable(buffer[i], &col);
    }

    if(col > 0)
        putchar('\n');

    return 0;
}