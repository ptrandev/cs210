#include <stdio.h>

/* Snippets from Prof. Donham */
/* https://piazza.com/class/kjvlw6kzxi360o?cid=712 */

char *errorMessages[] = {
    "STATUS: SUCCESS",
    "STATUS: ERROR - Null pointer encountered",
    "STATUS: ERROR - There are too many operands",
    "STATUS: ERROR - There are too few operands",
    "STATUS: ERROR - Divide by zero",
    "STATUS: ERROR - No input given",
    "STATUS: ERROR - The input contains invalid characters"
    "STATUS: ERROR - Memory allocation failed"
};

void printStatusMessage(int status) {
    printf("%s\n", errorMessages[status]);
}