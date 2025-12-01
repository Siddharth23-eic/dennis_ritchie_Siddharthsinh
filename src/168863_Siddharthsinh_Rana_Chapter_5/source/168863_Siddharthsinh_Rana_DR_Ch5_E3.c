/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 29/10/2025
 * Chapter: 5
 * Exercise: 5.3
 * Description: Write a pointer version of the function strcat that we showed in Chapter 2: strcat(s,t) copies the string t to the end of s.
 */

#include <stdio.h>
#include <stdint.h>
#include "chapter5func.h"

char *strcat_ptr(char *str1, char *str2){
    char *ptr = str1;
    while(*ptr != '\0'){
        ptr++;
    }
    while(*str2 != '\0'){
        *ptr = *str2;
        ptr++;
        str2++;
    }
    *ptr = '\0';
    return str1;
}

int32_t exercise5_3(){
    char str1[100];
    char str2[50];
    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    for(int32_t i = 0; str1[i] != '\0'; i++){
        if(str1[i] == '\n'){
            str1[i] = '\0';
            break;
        }
    }
    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    for(int32_t i = 0; str2[i] != '\0'; i++){
        if(str2[i] == '\n'){
            str2[i] = '\0';
            break;
        }
    }
    printf("Concatenated string: %s\n", strcat_ptr(str1, str2));
    return 0;
}