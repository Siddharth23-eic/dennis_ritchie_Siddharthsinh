/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 20/08/2025
 * Chapter: 1
 * Exercise: 1.3
 * Description: Modify the temperature conversion program to print a heading above the table.
 */

#include <stdio.h>
#include <stdint.h>
#include "chapter1func.h"

int32_t exercise1_3(){
	printf("Exe3: Printing Heading above the table of f to c\n");
    int32_t lower = 0;
    int upper = 300;
    int step = 20;
    float fahr, celsius;

    printf("%10s %10s\n", "Fahrenheit", "Celsius");

    fahr = lower;
    while(fahr <= upper){
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%10.1f %10.1f\n",fahr, celsius);
        fahr += step;
    }
    return 0;
}

