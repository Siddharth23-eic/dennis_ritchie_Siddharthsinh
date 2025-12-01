/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 16/11/2025
 * Chapter: 5
 * Exercise: 6.1
 * Description: Our version of getword does not properly handle underscores, string constants, comments, or preprocessor control lines. Write a better version. 
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "chapter6func.h"
#include "stackfunction.h"
#include "keyword.h"

#define MAXWORD 1000

int32_t exercise6_1(void) {
    char word[MAXWORD];
    int32_t n;

    while(getword(word, MAXWORD) != EOF){
        if(isalpha(word[0]) || word[0] == '_'){
            if((n = binsearch(word, keytab, NKEYS)) >= 0){
                keytab[n].count++;
            }
        }
    }
    
    printf("\nKeywords counts:\n");
    for(n = 0; n < NKEYS; n++){
        if(keytab[n].count > 0){
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
        }
    }
    return 0;
}

