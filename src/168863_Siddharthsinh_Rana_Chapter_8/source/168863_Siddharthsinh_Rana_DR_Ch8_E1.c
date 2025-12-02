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

void sys_call_cat(char *file){
    char buf[BUF];
    int32_t n, fd = open(file, O_RDONLY);

    while((n = read(fd, buf, BUF)) > 0)
        write(1, buf, n);
    
    close(fd);
}

void stdio_call_cat(char *file){
    char bif[BUF];
    size_t n;
    
    FILE *fp = fopen(file, "r");
    while((n = fread(buf, 1, BUF, fp)) > 0)
        fwrite(buf, 1, n, stdout);
    
    fclose(fp);
}

int32_t exercise8_1(int32_t argc, char *argv[]){
    
    return 0;
}
