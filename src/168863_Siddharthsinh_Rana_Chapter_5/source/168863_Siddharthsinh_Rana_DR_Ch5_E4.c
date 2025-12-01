/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 29/10/2025
 * Chapter: 5
 * Exercise: 5.4
 * Description: Write a function strend(s,t) that returns 1 if the string t occurs at the end of the string s, and zero otherwise.
 */

#include <stdio.h>
#include <stdint.h>
#include "chapter5func.h"

int32_t strend(char *s, char *t){
    char *temp1 = s;
    char *temp2 = t;

    while(*s != '\0'){
        s++;
    }
    while(*t != '\0'){
        t++;
    }
    s--;
    t--;

    while(t > temp2){
        if(*s != *t){
            return 0;
        }
        s--;
        t--;
    }
    return 1;
}

int32_t exercise5_4(){
    char str1[100], str2[100];
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);

    for (int i = 0; str1[i] != '\0'; i++)
        if (str1[i] == '\n') str1[i] = '\0';
    for (int i = 0; str2[i] != '\0'; i++)
        if (str2[i] == '\n') str2[i] = '\0';


    if(strend(str1, str2) == 1){
        printf("%s occured at the end of %s.\n", str2, str1);
    } else {
        printf("%s not occured at the end of %s.\n", str2, str1);
    }   
    return 0;
}
