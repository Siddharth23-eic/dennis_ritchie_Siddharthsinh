/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 02/09/2025
 * Chapter: 3
 * Exercise: 3.2
 * Description: Write a function escape(s,t) that converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a function for the other direction as well, converting escape sequences into the real characters.
 */

#include <stdio.h>
#include <stdint.h>
#include "chapter3func.h"

char *escape(char from[], char to[]){
	uint32_t i = 0, j = 0; 
	int32_t character;
	while(from[i] != '\0'){
		character = from[i];

		/* Making switch case to print visible escape character */

		switch(character){
			case '\n': 
				to[j++] = '\\';
				to[j++] = 'n';
				break;
            case '\t':
            	to[j++] = '\\';
            	to[j++] = 't';
				break;

			case '\b':
            	to[j++] = '\\';
            	to[j++] = 'b';
				break;

			case '\\':
            	to[j++] = '\\';
            	to[j++] = '\\';
				break;

			case '\"':
            	to[j++] = '\\';
            	to[j++] = '\"';
				break;
			case '\?':
				to[i++] = '\\';
				to[i++] = '?';
			default:
				to[j++] = character;
				break;
		}
		i++;
	}
	to[j] = '\0';
	return to;
}

int32_t exercise3_2(){
	int32_t character;
	char from[1000], to[1000];
	int16_t itr = 0;
	
	while ((character = getchar()) != '\n' && character != EOF);
	printf("Enter a from string & ctrl+D for EOF: \n");
	while((character = getchar()) != EOF && itr < 999){
		from[itr++] = (char)character;
	}
	from[itr] = '\0';
	printf("String with escape character printed: %s", escape(from,to));
	return 0;
}
