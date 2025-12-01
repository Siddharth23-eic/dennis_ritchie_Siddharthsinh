/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 20/08/2025
 * Chapter: 1
 * Exercise: 1.4
 * Description: Write a program to print the corresponding Celsius to Fahrenheit table.
 */

#include <stdio.h>
#include <stdint.h>
#include "chapter1func.h"

int32_t exercise1_4(){

	printf("Exe4: Celsius to Fahrenheit \n");
    int lower = 0;
    int upper = 300;
    int step = 20;
    float fahr, celsius;

    printf("%10s %10s\n", "Celsius", "Fahrenheit");

    celsius = lower;
    while(celsius <= upper){
        fahr = (9.0 / 5.0) * celsius + 32.0;
        printf("%10.1f %10.1f\n",celsius, fahr);
        celsius += step;
    }
    return 0;
}
