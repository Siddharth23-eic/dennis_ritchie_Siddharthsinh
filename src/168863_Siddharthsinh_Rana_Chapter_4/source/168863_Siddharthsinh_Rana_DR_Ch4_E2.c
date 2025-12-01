/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 09/09/2025
 * Chapter: 4
 * Exercise: 4.2
 * Description: Extend atof to handle scientific notation of the form 123.45e-6 where a floating-point number may be followed by e or E and an optionally signe exponent.
 */

#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include "chapter4func.h"

double atof(char string[]){
	double value, power;
	int32_t i;

	/* Skip spaces */
	for(i = 0; isspace((unsigned char)string[i]); i++);

	int32_t sign = (string[i] == '-') ? -1 : 1;
	if(string[i] == '+' || string[i] == '-')
		i++;
	
	for(value = 0.0; isdigit((unsigned char)string[i]); i++)
		value = 10.0 * value +(string[i] - '0');
	
	if(string[i] == '.')
		i++;
	
	for(power = 1.0; isdigit((unsigned char)string[i]); i++){
		value = 10.0 * value + (string[i] - '0');
		power = power * 10.0;
	}
	value = sign * value / power;

	int32_t e_sign, e_value;

	if(string[i] == 'e' || string[i] == 'E'){
		i++;
		e_sign = (string[i] == '-') ? -1 : 1;
		
		if(string[i] == '+' || string[i] == '-')
			i++;

		for(e_value = 0; isdigit((unsigned char)string[i]); i++)
			e_value = 10 * e_value + (string[i] - '0');

		/*Apply exponent*/
		double factor = 1.0;
		while(e_value-- > 0)
			factor *= 10.0;

		if(e_sign == -1)
			value /= factor;
		else
			value *= factor;
	}
	return value;
}

int32_t exercise4_2(){
	char string[1000];
	int32_t character;
	uint32_t i = 0;

	while((character = getchar()) != '\n' && character != EOF);
	while((character = getchar()) != '\n'){
		string[i] = character;
		i++;
	}
	string[i] = '\0';

	printf("%f\n", atof(string));
	return 0;
}
