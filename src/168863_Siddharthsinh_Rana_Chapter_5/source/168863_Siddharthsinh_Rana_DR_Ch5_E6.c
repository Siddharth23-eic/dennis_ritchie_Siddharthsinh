/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 29/10/2025
 * Chapter: 5
 * Exercise: 5.6
 * Description: Rewrite appropriate programs from earlier chapters and exercises with pointers instead of array indexing. Good possibilities include getline (Chapters 1 and 4), atoi, itoa, and their variants (Chapters 2, 3, and 4), reverse (Chapter 3), and strindex and getop (Chapter 4).
 */

#include <stdio.h>
#include <stdint.h>
#include "chapter5func.h"

/* getline: read a line into s, return length */
int32_t getline_ptr(char *str, int32_t lim){
    char *tem = str;
    int32_t ch;
    while(--lim > 0 && (ch = getchar()) != EOF && ch != '\n')
        *str++ = ch;
    if(ch == '\n'){
        *str++ = ch;
    }
    *str = '\0';
    return str - tem;
}

/* atoi_ptr: convert string to integer */
int32_t atoi_ptr(char *str){
    int32_t n = 0;
    int32_t sign = 1;

    /* Skip whitespace */
    while(*str == ' ' || *str == '\t')
        str++;

    /* Handle optional sign */
    if(*str == '-'){
        sign = -1;
        str++;
    } else if(*str == '+'){
        str++;
    }

    /* Convert digits to integer */
    while(*str >= '0' && *str <= '9'){
        n = n * 10 + (*str - '0');
        str++;
    }

    return sign * n;
}

/* itoa_ptr: convert integer to string */
void itoa_ptr(int32_t n, char *str){
    char *tem = str;
    int32_t sign;
    if((sign = n) < 0)
        n = -n;
    do {
        *str++ = n % 10 + '0';
    } while((n /= 10) > 0);
    if(sign < 0)
        *str++ = '-';
    *str = '\0';
    // Reverse the string
    char *start = tem;
    char *end = str - 1;
    char temp;
    while(start < end){
        temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}

/* reverse_ptr: reverse a string in place */
void reverse_ptr(char *str){
    char *start = str;
    char *end = str;
    char temp;
    while(*end != '\0')
        end++;
    end--;
    while(start < end){
        temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}  

/* strindex */
int32_t strindex_ptr(char *s, char *t){
    char *s_start = s;
    char *t_start = t;
    for(; *s != '\0'; s++){
        char *s_temp = s;
        t_start = t;
        while(*t_start != '\0' && *s_temp == *t_start){
            s_temp++;
            t_start++;
        }
        if(t_start != t && *t_start == '\0')
            return s - s_start;
    }
    return -1;
}

/* getop to get next operator or numeric operand */
int32_t getop_ptr(char *s){
    while((*s = getchar()) == ' ' || *s == '\t')
        ;
    *(s + 1) = '\0';
    if(!isdigit(*s) && *s != '.')
        return *s; // not a number
    if(isdigit(*s)){
        while(isdigit(*(++s) = getchar()))
            ;
    }
    if(*s == '.'){
        while(isdigit(*(++s) = getchar()))
            ;
    }
    *s = '\0';
    return '0'; // signal that a number was found
}   

/* exercise5_6: Main function for exercise 5.6 */
int32_t exercise5_6(){
    char line[100], strn[20];
    printf("Enter a line: ");
    getline_ptr(line, 100);
    printf("Line: %s\n", line);

    printf("Enter a number string to convert: ");
    getline_ptr(strn, 20);
    int32_t num = atoi_ptr(strn);
    printf("Converted string to %d\n", num);

    char str[20];
    itoa_ptr(num, str);
    printf("Converted back to %s\n", str);

    reverse_ptr(line);
    printf("Reversed: %s\n", line);

    char substr[20];
    printf("Enter a substring to search: ");
    getline_ptr(substr, 20);
    int32_t index = strindex_ptr(line, substr);
    printf("Starting index of %s: %d\n", substr, index);

    char token[100];
    printf("Enter a token: ");
    int32_t type = getop_ptr(token);
    if(type == '0'){
        printf("Number: %s\n", token);
    } else {
        printf("Operator: %c\n", type);
    }

    return 0;
}
