/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 29/10/2025
 * Chapter: 5
 * Exercise: 5.17
 * Description: Add a field-searching capability, so sorting may bee done on fields within lines, each field sorted according to an independent set of options. (The index for this book was sorted with -df for the index category and -n for the page numbers.) 
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h> 
#include "chapter5func.h"
#include "flagfunc.h"

#define MAXLINES 5000

static char *lineptr[MAXLINES];

/* Reset flags for this exercise */
static void reset_field_opts(void){
    nfields = 0;
    for(int i = 0; i < 20; i++){
        field_opts[i].field_no   = 0;
        field_opts[i].numeric    = 0;
        field_opts[i].reverse    = 0;
        field_opts[i].fold       = 0;
        field_opts[i].directory  = 0;
    }
}

static void parse_args(int argc, char *argv[]){
    FieldOpt *cur = NULL;

    for(int i = 1; i < argc; i++){
        /* -k<field>[,<flags>] */
        if(strncmp(argv[i], "-k", 2) == 0){
            char *p = argv[i] + 2;
            int field = atoi(p);

            FieldOpt opt = {0};
            opt.field_no = field;

            /* handle -k1,df style */
            while(*p && *p != ',')
                p++;
            if(*p == ',')
                p++;

            while(*p){
                switch(*p){
                    case 'n': opt.numeric   = 1; break;
                    case 'r': opt.reverse   = 1; break;
                    case 'f': opt.fold      = 1; break;
                    case 'd': opt.directory = 1; break;
                }
                p++;
            }

            field_opts[nfields] = opt;
            cur = &field_opts[nfields];
            nfields++;
            continue;
        }

        /* standalone flags apply to most recent field (-k) */
        if(cur){
            if(strcmp(argv[i], "-n") == 0)      cur->numeric   = 1;
            else if(strcmp(argv[i], "-r") == 0) cur->reverse   = 1;
            else if(strcmp(argv[i], "-f") == 0) cur->fold      = 1;
            else if(strcmp(argv[i], "-d") == 0) cur->directory = 1;
            else if(strcmp(argv[i], "-df") == 0 || strcmp(argv[i], "-fd") == 0){
                cur->directory = 1;
                cur->fold      = 1;
            }
        }
    }
}

int exercise5_17(int argc, char *argv[]){
    int n;

    reset_field_opts();
    parse_args(argc, argv);

    n = readlines_5(lineptr, MAXLINES);
    if(n <= 0){
        printf("no input to sort\n");
        return 1;
    }

    myqsort_5((void**)lineptr, 0, n-1, fieldcmp, 0);
    writelines_5(lineptr, n);

    return 0;
}
