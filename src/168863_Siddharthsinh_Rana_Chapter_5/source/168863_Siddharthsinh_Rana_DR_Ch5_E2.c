/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 29/10/2025
 * Chapter: 5
 * Exercise: 5.2
 * Description: Write getfloat, the floating point analog of getint. What type does getfloat return as its function value?
 */

#include <stdio.h>
#include <stdint.h>
#include "stackfunction.h"
#include "chapter5func.h"

int32_t getfloat(double *pn){
    int32_t ch, sign;
    double temp = 0.0;
    double power = 1.0;
    while(isspace(ch = getch()));
    if(ch == EOF){
        return EOF;
    }
    sign = (ch == '-') ? -1 : 1;
    if(ch == '+' || ch == '-')
        ch = getch();
    for(temp = 0.0; isdigit(ch); ch = getch()){
        temp = 10.0 * temp + (ch - '0');
    }
    if(ch == '.'){
        ch = getch();
        for(power = 1.0; isdigit(ch); ch = getch()){
            temp = 10.0 * temp + (ch - '0');
            power *= 10.0;
        }
        temp /= power;
    }
    if(ch != EOF) ungetch(ch);
    *pn = sign * temp;
    return 1;
}
int32_t exercise5_2(){
    int32_t n;
    double f;
    printf("Enter floating point numbers (Ctrl+D to end):\n");
    while((n = getfloat(&f)) != EOF){
        if(n != 1){
            printf("Not a number\n");
        } else{
            printf("You entered: %f\n", f);
        }
    }
    return 0;
}
