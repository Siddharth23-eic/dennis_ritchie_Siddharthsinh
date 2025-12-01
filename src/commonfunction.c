/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created date: 08/09/2025
 * Modified date:
 * Description: This is common function across all the .c files.
 */


#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "commonfunction.h"


char *reverse(char str[]){
    uint32_t length = strlen(str);
    for(int32_t i = 0; i < length / 2; i++){
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
    return str;
}

void copy(char to[], char from[]){
    int index = 0;
    while((to[index] = from[index]) != '\0'){
        index++;
    }
}

int32_t get_line(char string[], uint32_t lim){
    int32_t character;
    uint32_t index;

    while (index < lim - 1 && (character = getchar()) != EOF && character != '\n') {
        string[index++] = character;
    }

    if (character == '\n') {
        string[index++] = character;
    }

    string[index] = '\0';
    return index;
}
