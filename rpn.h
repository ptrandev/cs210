#ifndef FUNCTIONS_RPN_H
#define FUNCTIONS_RPN_H

typedef struct node node;
double evaluate (char* expression, int * status); // returns result of equation
double power (double num_1, double num_2); // return result of recursive power

#endif // FUNCTIONS_RPN_H