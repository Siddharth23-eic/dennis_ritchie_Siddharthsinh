#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdarg.h>
#include "stdinout.h"

/* minprintf: minimal printf with variable argument list, extended for 7-3 */
void minprintf(char *fmt, ...)
{
    va_list ap;        /* points to each unnamed arg in turn */
    char *p, *sval;
    int32_t ival;
    uint32_t uval;
    long lval;
    unsigned long ulval;
    double dval;
    int32_t cval;

    va_start(ap, fmt); /* make ap point to 1st unnamed arg */

    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }

        /* check for optional 'l' length modifier */
        int32_t longflag = 0;
        if (*++p == 'l') {
            longflag = 1;
            p++;
        }

        switch (*p) {
        case 'd':
        case 'i':
            if (longflag) {
                lval = va_arg(ap, long);
                printf("%ld", lval);
            } else {
                ival = va_arg(ap, int32_t);
                printf("%d", ival);
            }
            break;

        case 'u':
            if (longflag) {
                ulval = va_arg(ap, unsigned long);
                printf("%lu", ulval);
            } else {
                uval = va_arg(ap, uint32_t);
                printf("%u", uval);
            }
            break;

        case 'o':
            if (longflag) {
                ulval = va_arg(ap, unsigned long);
                printf("%lo", ulval);
            } else {
                uval = va_arg(ap, uint32_t);
                printf("%o", uval);
            }
            break;

        case 'x':
        case 'X':
            if (longflag) {
                ulval = va_arg(ap, unsigned long);
                if (*p == 'x')
                    printf("%lx", ulval);
                else
                    printf("%lX", ulval);
            } else {
                uval = va_arg(ap, uint32_t);
                if (*p == 'x')
                    printf("%x", uval);
                else
                    printf("%X", uval);
            }
            break;

        case 'f':
        case 'e':
        case 'E':
        case 'g':
        case 'G':
            dval = va_arg(ap, double);
            if (*p == 'f')
                printf("%f", dval);
            else if (*p == 'e')
                printf("%e", dval);
            else if (*p == 'E')
                printf("%E", dval);
            else if (*p == 'g')
                printf("%g", dval);
            else
                printf("%G", dval);
            break;

        case 's':
            sval = va_arg(ap, char *);
            while (*sval)
                putchar(*sval++);
            break;

        case 'c':
            cval = va_arg(ap, int32_t);
            putchar(cval);
            break;
        case 'p': {
            void *ptr = va_arg(ap, void *);
            printf("%p", ptr);
            break;
        }
        case '%':
            putchar('%');
            break;

        default:
            /* unknown specifier: print it literally */
            putchar('%');
            if (longflag)
                putchar('l');
            putchar(*p);
            break;
        }
    }

    va_end(ap); /* clean up when done */
}


/* minscanf: minimal scanf wiht variable argument */
int32_t minscanf(char *fmt, ...)
{
    va_list ap;
    char *p;
    int32_t *i32;
    uint32_t *u32;
    float *f32;
    double *d64;
    char *sval;
    char *cval;
    int matched = 0;

    va_start(ap, fmt);

    for (p = fmt; *p; p++)
    {
        if (*p != '%')
            continue;

        p++;

        /* handle length qualifiers */
        int longflag = 0;
        if (*p == 'l') {
            longflag = 1;
            p++;
        }

        switch (*p)
        {
        case 'd': /* int32_t */
            i32 = va_arg(ap, int32_t *);
            matched += scanf("%d", i32);
            break;

        case 'u': /* uint32_t */
            u32 = va_arg(ap, uint32_t *);
            matched += scanf("%u", u32);
            break;

        case 'f':
            if (longflag) {
                /* double */
                d64 = va_arg(ap, double *);
                matched += scanf("%lf", d64);
            } else {
                /* float */
                f32 = va_arg(ap, float *);
                matched += scanf("%f", f32);
            }
            break;

        case 's': /* string */
            sval = va_arg(ap, char *);
            scanf(" %[^\n]", sval);
            matched++;
            break;

        case 'c': /* character */
            cval = va_arg(ap, char *);
            scanf(" %c", cval);     /* skip whitespace */
            matched++;
            break;

        default:
            /* unsupported specifier — ignore */
            break;
        }
    }

    va_end(ap);
    return matched;
}
