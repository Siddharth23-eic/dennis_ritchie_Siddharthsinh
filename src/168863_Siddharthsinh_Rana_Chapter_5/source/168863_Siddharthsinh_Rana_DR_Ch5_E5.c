/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 29/10/2025
 * Chapter: 5
 * Exercise: 5.5
 * Description: Write versions of the library functions strncpy, strncat, and strncmp, which operate on at most first n characters of their argument strings. For example, strncpy(s,t,n) copies at most n characters of t to s. Full descriptions are in Appendix B.
 */

 #include <stdio.h>
#include <stdint.h>
#include "chapter5func.h"

/* copy at most n chars from t to s */
char *strncpy_my(char *s, char *t, size_t n) {
    char *p = s;
    while (n-- && *t)
        *s++ = *t++;
    return p;
}

/* append at most n chars of t to s */
char *strncat_my(char *s, char *t, size_t n) {
    char *p = s;
    while (*s)
        s++;
    while (n-- && *t)
        *s++ = *t++;
    *s = '\0';
    return p;
}

/* compare at most n chars of s and t */
int32_t strncmp_my(char *s, char *t, size_t n) {
    while (n-- && (*s || *t)) {
        if (*s != *t)
            return *s - *t;
        s++;
        t++;
    }
    return 0;
}

int32_t exercise5_5() {
    char str1[100], str2[100];
    size_t n;
    int32_t opt;

    printf("Choose (1=strncpy, 2=strncat, 3=strncmp): ");
    scanf("%d", &opt);
    getchar();

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    printf("Enter n: ");
    scanf("%lu", &n);

    /* remove trailing newlines */
    for (int i = 0; str1[i]; i++)
        if (str1[i] == '\n') str1[i] = '\0';
    for (int i = 0; str2[i]; i++)
        if (str2[i] == '\n') str2[i] = '\0';

    switch (opt) {
        case 1:
            strncpy_my(str1, str2, n);
            printf("After strncpy_my: %s\n", str1);
            break;
        case 2:
            strncat_my(str1, str2, n);
            printf("After strncat_my: %s\n", str1);
            break;
        case 3:
            if (strncmp_my(str1, str2, n) == 0)
                printf("Match found\n");
            else
                printf("Match not found\n");
            break;
        default:
            printf("Invalid option.\n");
            break;
    }
    return 0;
}
