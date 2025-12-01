/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 24/09/2025
 * Chapter: 1
 * Exercise: 1.23
 * Description: Write a program to remove all comments from a C program. Don't forget to handle quoted strings and character constants properly. C comments don't nest.
 */

#include <stdio.h>
#include <stdint.h>
#include "chapter1func.h"

int32_t exercise1_23(){
	char fname[100];
	printf("Enter filename: ");
	scanf("%s", fname);
	FILE *in = fopen(fname,"r");
	FILE *op = fopen("output.c", "wb");
	
	int32_t chr1, chr2;
	while((chr1 = fgetc(in)) != EOF){
		if(chr1 == '/'){
			chr2 = fgetc(in);
			if(chr2 == '/'){
				while ((chr1 = fgetc(in)) != EOF && chr1 != '\n');
				if(chr1 == '\n') fputc('\n', op);
			}else if(chr2 == '*'){
				int32_t prev = 0;
				while((chr1 = fgetc(in)) != EOF){
					if(prev == '*' && chr1 == '/') break;
					prev = chr1;
				}
			}else {
				fputc(chr1,op);
				if(chr2 != EOF) fputc(chr2, op);
			}
		}else{
			fputc(chr1,op);
		}
	}
	
	fclose(in);
	fclose(op);

	return 0;
}
