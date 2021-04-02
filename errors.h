/* Snippets from Prof. Donham */
/* https://piazza.com/class/kjvlw6kzxi360o?cid=712 */

#ifndef FUNCTIONS_ERRORS_H
#define FUNCTIONS_ERRORS_H

#define SUCCESS 0
#define NULLPTR 1
#define TOOMANY 2
#define TOOFEW 3
#define BYZERO 4
#define NOINPUT 5
#define INVALIDINPUT 6

void printStatusMessage(int status);

#endif // FUNCTIONS_ERRORS_H