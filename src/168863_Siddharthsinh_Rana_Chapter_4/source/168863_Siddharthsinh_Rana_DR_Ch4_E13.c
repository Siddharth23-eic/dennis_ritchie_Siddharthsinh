/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 18/09/2025
 * Chapter: 4
 * Exercise: 4.13
 * Description: Write a recursive version of the function reverse(s), which reverses the string s in place.
 */

#include <stdio.h>
#include <stdint.h>
#include "stackfunction.h"
#include "chapter4func.h"
#include <string.h>

#define MAXLINE 100

int32_t mget_line(char s[], int32_t lim)
{
    int32_t i, c;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i++] = '\n';
    s[i] = '\0';
    return i;
}

void reverser(char s[], int32_t i, int32_t len)
{
    int32_t c, j;
    j = len - (i + 1);
    if (i < j)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        reverser(s, ++i, len);
    }
}

int32_t exercise4_13() {
	char str[MAXLINE];
	printf("Enter a string: ");
	mget_line(str, MAXLINE);
	reverser(str, 0, strlen(str));
	printf("\nReversed string: ");
	printf("%s", str);
    return 0;
}                                                                                       

