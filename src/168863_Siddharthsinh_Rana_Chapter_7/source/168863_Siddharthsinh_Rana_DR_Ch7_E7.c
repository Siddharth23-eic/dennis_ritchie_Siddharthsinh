/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 16/11/2025
 * Chapter: 5
 * Exercise: 7.7
 * Description: Modify the pattern finding program of Chapter 5 to take its input from a set of named files or, if no files are named as arguments, from the standard input. Should the file name be printed when a matching line is found?
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "chapter7func.h"

#define MAXLINE 1000

int32_t exercise7_7(int32_t argc, char *argv[]){
    if(argc < 2){
        printf("Use like this -> ./a.out file1 file2....\n");
        return -1;
    }
    char keyword[100];
    printf("Enter the keyword to search: ");
    scanf("%99s", keyword);

    int32_t found = 0;
    
    for(int32_t i = 1; i < argc; i++){
        FILE *fp = fopen(argv[i], "r");
        if(fp == NULL){
            printf("Could not open file %s\n", argv[i]);
            continue;
        }
        char line[MAXLINE];
        int32_t line_number = 0;
        while(fgets(line, MAXLINE, fp) != NULL){
            line_number++;
            /* Looking for the keyword from the file content */
            if(strstr(line, keyword) != NULL){
                printf("%s: %d: %s", argv[i], line_number, line);
                found++;
            }
        }
        fclose(fp);
    }
    if(found == 0){
        printf("No matches found for keyword '%s'\n", keyword);
        return 1;
    }
    return 0;
}