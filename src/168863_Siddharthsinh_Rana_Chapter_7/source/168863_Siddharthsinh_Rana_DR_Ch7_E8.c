/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 16/11/2025
 * Chapter: 5
 * Exercise: 7.8
 * Description: Write a program to print a set of files, starting each new one on a new page, with a title and a running page count for each file.
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "chapter7func.h"

#define MAXLINE 1000
#define LINES   20

int32_t exercise7_8(int32_t argc, char *argv[]){
    if(argc < 2) {
        printf("Use it like ./a.out file1 file2 ...\n");
        return 1;
    }

    for(int32_t i = 1; i < argc; i++){
        FILE *fp = fopen(argv[i], "r");
        if(fp == NULL){
            printf("Error Opening file\n");
            continue;
        }
        char line[MAXLINE];
        int32_t line_count = 0;
        int32_t page = 1;

        /* Page header */
        printf("\n ----------- %s -- Page %d -----------\n", argv[i], page);

        while(fgets(line, MAXLINE, fp) != NULL){
            
            /* Checking all lines(Here 20) are filled in the page */
            if(line_count == LINES){
                page++;
                line_count = 0;
                printf("\n ----------- %s -- Page %d -----------\n", argv[i], page);
            }
            fputs(line, stdout);
            line_count++;
        }
        fclose(fp);
    }
    return 0;
}