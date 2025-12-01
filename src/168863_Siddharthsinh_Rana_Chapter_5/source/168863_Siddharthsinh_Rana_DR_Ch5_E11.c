/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 29/10/2025
 * Chapter: 5
 * Exercise: 5.11
 * Description: Modify the program entab and detab (written as exercises in Chapter 1) to accept a list of tab stops as arguments. Use the default tab settings if there are no arguments.
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "chapter5func.h"

#define TAB_DEFAULT 8

void entab_5(int32_t tabstop);
void detab_5(int32_t tabstop);

int32_t exercise5_11(int32_t argc, char *argv[]){
    int32_t tabstop = TAB_DEFAULT;

	if(argc < 2){
		printf("Too less arguments\n");
		return 1;
	}

	if(strcmp(argv[1], "en") != 0 && strcmp(argv[1], "de") != 0){
		printf("Invalid command(only en or de)\n");
		return 1;
	}

	if(argc == 2){
		printf("Run like this -> ./a.out (en/de) [number]\n");
		return 1;
	}

	if(argc >= 3){
		if(isdigit(argv[2][0]) || argv[2][0] == '+' || argv[2][0] == '-')
			tabstop = abs(atoi(argv[2]));
		else{
			printf("Run like this -> ./a.out (en/de) [number]\n");
			return 1;
		}
	}

	if(tabstop <= 0)
		tabstop = TAB_DEFAULT;
	
	if(strcmp(argv[1], "en") == 0)
		entab_5(tabstop);
	else
		detab_5(tabstop);

    return 0;
}


/* Detab -> replace tabs with spaces */
void detab_5(int32_t tabstop){
	int32_t ch, col = 0;

	while((ch = getchar()) != EOF){
		if(ch == '\t'){
			do{
				putchar(' ');
				col++;
			}while(col % tabstop != 0);
		}else{
			putchar(ch);
			if(ch == '\n')
				col = 0;
			else
				col++;
		}
	}
}

/* entab -> replace spaces with tabs */
void entab_5(int32_t tabstop){
	int32_t ch, col = 0, space = 0;

	while((ch = getchar()) != EOF){
		if(ch == ' '){
			space++;
			if(col % tabstop == tabstop - 1){
				putchar('#');
				space = 0;
			}
			col++;
		}else{
			while(space-- > 0)
				putchar(' ');
			space = 0;
			putchar(ch);
			if(ch == '\n')
				col = 0;
			else
				col++;
		}
	}
}
