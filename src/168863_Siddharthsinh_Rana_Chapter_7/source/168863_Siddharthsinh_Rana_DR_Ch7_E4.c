/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 16/11/2025
 * Chapter: 5
 * Exercise: 7.4
 * Description: Write a private version of scanf analogous to minprintf from previous section.
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "chapter7func.h"
#include "keyword.h"

int32_t exercise7_4() {
    int32_t inum;
    uint32_t uinum;
    float fnum;
    double dnum;
    char str[100];
    char ch;

    printf("Enter an integer: ");
    minscanf("%d", &inum);

    printf("Enter an unsigned integer: ");
    minscanf("%u", &uinum);
    
    printf("Enter a float: ");
    minscanf("%f", &fnum);
    
    printf("Enter a double: ");
    minscanf("%lf", &dnum);
    
    printf("Enter a string: ");
    minscanf("%s", str);
    
    printf("Enter a character: ");
    minscanf(" %c", &ch);

    printf("You entered:\n");
    minprintf("inum: %d\n", inum);
    minprintf("uinum: %u\n", uinum);
    minprintf("fnum: %f\n", fnum);
    minprintf("dnum: %lf\n", dnum);
    minprintf("str: %s\n", str);
    minprintf("ch: %c\n", ch);
    minprintf("octal of inum: %o\n", inum);
    minprintf("hexadecimal of inum: %x\n", inum);
    minprintf("Pointer to inum: %p\n", (void*)&inum);
    
    return 0;
}

