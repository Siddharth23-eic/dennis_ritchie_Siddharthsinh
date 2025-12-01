/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 16/11/2025
 * Chapter: 5
 * Exercise: 7.6
 * Description: Write a program to compare two files, printing the first line where they differ. 
 */

#include <stdio.h>
#include <stdint.h>
#include "chapter6func.h"

#define MAXLINE 1000

int32_t cmp_files(const char *file1, const char *file2){
    FILE *f1 = fopen(file1, "r");
    FILE *f2 = fopen(file2, "r");
    if (f1 == NULL || f2 == NULL) {
        printf("Error opening files.\n");
        return -1;
    }
    char str1[MAXLINE], str2[MAXLINE];
    int32_t line_number = 0;
    while(1){
        char *t1 = fgets(str1, MAXLINE,f1);
        char *t2 = fgets(str2, MAXLINE,f2);
        line_number++;

        if(t1 == NULL && t2 == NULL){
            printf("Files are identical.\n");
            break;
        }
        if(!t1 || !t2){
            printf("Files differ at line%d:\n", line_number);
            if(t1) printf("File1: %s", str1);
            else printf("File1: <End of File>\n");
            if(t2) printf("File2: %s", str2);
            else printf("File2: <End of File>\n");
            break;
        }

        if(strcmp(str1, str2) != 0){
            printf("Files differ at line %d:\n", line_number);
            printf("File1: %s", str1);
            printf("File2: %s", str2);
            break;
        }
    }
    fclose(f1);
    fclose(f2);
    return 0;
}

int32_t exercise7_6() {
    char file1[256], file2[256];
    
    printf("Enter the path of the first file: ");
    scanf("%255s", file1);
    printf("Enter the path of the second file: ");
    scanf("%255s", file2);

    cmp_files(file1, file2);
    
    return 0;
}

