/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 02/12/2025
 * Chapter: 8
 * Exercise: 8.1
 * Description: Rewrite the program cat from Chapter 7 using read, write, open, and close instead of their standard library equivalents. Perform experiments to determine the relative speeds of the two versions. 
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

#define BUF 4000

/* Systemcall version of cat */
void sys_call_cat(char *file){
    char buf[BUF];
    int32_t n, file_descriptor;

    if(file == NULL){
        file_descriptor = 0;
    }
    else{
        file_descriptor = open(file, O_RDONLY);
        if(file_descriptor < 0){
            printf("\nsys: Cannot open file %s\n", file);
            return;
        }
    }

    while((n = read(file_descriptor, buf, BUF)) > 0)
        write(1, buf, n);
    
    close(file_descriptor);
}

/* stdio version of cat */
void stdio_cat(char *file){
    char buf[BUF];
    size_t n;
    FILE *file_pointer;

    if(file == NULL){
        file_pointer = stdin;
    }else{
        file_pointer = fopen(file, "r");
        if(file_pointer == NULL){
            printf("\nStdio: cannot open file %s\n", file);
            return;
        }
    }
    while((n = fread(buf, 1, BUF, file_pointer)) > 0)
        fwrite(buf, 1, n, stdout);
    
    if(file != NULL)
        fclose(file_pointer);
}

int32_t exercise8_1(int32_t argc, char *argv[]){
    clock_t start, end;
    if(argc == 1){
        sys_call_cat(NULL);
        stdio_cat(NULL);
    }
    start = clock();
    for(int32_t i = 1; i < argc; i++)
        sys_call_cat(argv[i]);
    end = clock();
    printf("syscall cat time %f seconds\n", (double)(end - start)/CLOCKS_PER_SEC);

    start = clock();    
    for(int32_t i = 1; i < argc; i++)
            stdio_cat(argv[i]);
    end = clock();
    printf("Stdio cat time: %f seconds", (double)(end - start)/CLOCKS_PER_SEC);

    return 0;
}
