/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 27/08/2025
 * Chapter: 1
 * Exercise: 1.17
 * Description: Write a program to print all input lines that are longer than 80 characters.
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "commonfunction.h"
#include "chapter1func.h"

#define MAXLINE 1000
#define MAXLINES 100 
#define THRESHOLD 8

int32_t exercise1_17(){
	printf("Exe17: Print lines longer han 8 characters\n");
    uint32_t currlen;
    char line[MAXLINE];
    char longlines[MAXLINES][MAXLINE];
    uint32_t count = 0;

    while((currlen = get_line(line, MAXLINE)) > 0){
        if(currlen > THRESHOLD && count < MAXLINES){
            copy(longlines[count], line);
            count++;
        }
    }
    printf("\nLines having more than 8 character are ->\n");
	
	for(uint32_t i = 0; i < count; i++){
		printf("%s", longlines[i]);
	}
    return 0;
}
