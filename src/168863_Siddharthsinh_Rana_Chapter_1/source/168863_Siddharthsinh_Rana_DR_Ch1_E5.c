/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 20/08/2025
 * Chapter: 1
 * Exercise: 1.5
 * Description: Modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0.
 */

#include <stdio.h>
#include <stdint.h>
#include "chapter1func.h"

int32_t exercise1_5(){

	printf("Exe5: Fahrenheit to Celsius in reverse order\n");
    int lower = 0;
    int upper = 300;
    int step = 20;
    float fahr, celsius;

    printf("%10s %10s\n", "Fahrenheit", "Celsius");

    fahr = upper;
    while(fahr >= lower){
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%10.1f %10.1f\n",fahr, celsius);
        fahr -= step;
    }
    return 0;
}
