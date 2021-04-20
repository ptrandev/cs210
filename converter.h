#ifndef FUNCTIONS_CONVERTER_H
#define FUNCTIONS_CONVERTER_H

typedef struct node node;
int getPrecedence(char operator);
char* convertToPostfix (char* expression, int* status);

#endif // FUNCTIONS_CONVERTER_H