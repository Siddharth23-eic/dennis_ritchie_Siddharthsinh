/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 24/09/2025
 * Chapter: 1
 * Exercise: 1.24
 * Description: Write a program to check a C program for rudimentary syntax errors like unmatched parentheses, brackets and braces. Don't forget about quotes, both single and double, escape sequences, and comments. (This program is hard if you do it in full generality.)
 */

#include <stdio.h>
#include <stdint.h>
#include "chapter1func.h"
#define FILES 1000

int32_t exercise1_24() {
    FILE *ip;
    char filename[FILES];
    int32_t character, prev = 0;
    int32_t paren = 0, bracket = 0, brace = 0;
    int32_t line = 1;
    int32_t in_single = 0, in_double = 0, in_comment = 0;

    printf("Enter a filename/filepath: ");
    scanf("%s", filename);

    ip = fopen(filename, "r");
    if (!ip) {
        printf("Cannot open file %s\n", filename);
        return 1;
    }

    while ((character = fgetc(ip)) != EOF) {
        if (character == '\n') line++;

        /* Handle comments */
        if (!in_single && !in_double) {
            if (!in_comment && prev == '/' && character == '*') {
                in_comment = 1;
            } else if (in_comment && prev == '*' && character == '/') {
                in_comment = 0;
                character = 0;
            } else if (!in_comment && prev == '/' && character == '/') {
                while ((character = fgetc(ip)) != EOF && character != '\n');
                line++;
                continue;
            }
        }

        if (in_comment) {
            prev = character;
            continue;
        }

        /* Handle quotes */
        if (character == '"' && !in_single && prev != '\\') {
            in_double = !in_double;
        } else if (character == '\'' && !in_double && prev != '\\') {
            in_single = !in_single;
        }

        if (in_single || in_double) {
            prev = character;
            continue;
        }

        /* Count brackets only if not inside quotes/comments */
        if (character == '(') paren++;
        else if (character == ')') paren--;
        else if (character == '{') brace++;
        else if (character == '}') brace--;
        else if (character == '[') bracket++;
        else if (character == ']') bracket--;

        if (paren < 0 || bracket < 0 || brace < 0) {
            printf("Unmatched closing bracket at line %d\n", line);
            fclose(ip);
            return 1;
        }

        prev = character;
    }

    fclose(ip);

    if (paren == 0 && bracket == 0 && brace == 0 && !in_single && !in_double && !in_comment)
        printf("No syntax errors found\n");
    else
        printf("Unmatched symbol detected at line %d\n", line);

    return 0;
}
