/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created date: 08/09/2025
 * Modified date:
 * Description: Header file for common functions used across all .c files.
 */

#ifndef COMMONFUNCTION_H
#define COMMONFUNCTION_H

#include <stdint.h>

/* Function Declarations */
char *reverse(char str[]);
void copy(char to[], char from[]);
int32_t get_line(char string[], uint32_t lim);

#endif // COMMONFUNCTION_H

