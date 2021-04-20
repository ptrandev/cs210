#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "converter.h"
#include "rpn.h"
#include "stack.h"
#include "node.h"
#include "errors.h"

enum type {OPERATOR, NUMBER};

typedef struct node {
    union {
        double value;
        char operator;
    } contents;
    int type;
    int precedence;
    struct node *next;
} node;

char* convertToPostfix (char* expression, int* status) {
    clearStack(); // remove all residual nodes left from prior conversions

    char delimiter[] = " "; // what each of our terms are separated by
    char *token; // used to walk through the expression

    token = strtok(expression, delimiter); // prime the token

    struct node* node; // stores node that will be pused to stack

    char* output = (char*)calloc(sizeof(expression)/sizeof(char),sizeof(char)); // allocate memory to char array
    int count = 0; // keeps track of location in char array

    // keep track of parentheses, odd # means mismatched pairs
    int numParentheses = 0;

    // while there are still terms in the token...
    while(token != NULL) {
        // if the token is an operator...
        if (isNumber(token)) {
            strcat(output, token); // appened number to output string
            count += strlen(token); // increment counter by # of digits

            output[count++] = ' ';
        }
        // if the token is '(', push it to the stack and increment '(' counter
        else if (*token == '(') {
            node = createNode(*token, OPERATOR);

            // handle case where memory allocation fails
            if (node == NULL) {
                *status = 7;
                printStatusMessage(*status);

                return NULL;
            }

            push(node);
            numParentheses++;
        }
        // if the token is ')'...
        else if (*token == ')') {
            // while the stack isn't empty and the top operator isn't a '('
            while(!stackEmpty() && peek()->contents.operator != '(') {
                // pop and append the top operator to the output string
                output[count++] = pop()->contents.operator;
                output[count++] = ' ';
            }

            free(pop()); // discard the ')'
            numParentheses++; // increment ')' counter

        // if token is another operator ...
        } else if (getPrecedence(*token) != -1) {
            // when stack isn't empty and current token has lower/equal
            // precedence to top of stack: pop contents, append to output string
            while(!stackEmpty() && getPrecedence(*token) <= peek()->precedence) {
                output[count++] = pop()->contents.operator;
                output[count++] = ' ';
            }

            node = createNode(*token, OPERATOR);

            // handle case where memory allocation fails
            if (node == NULL) {
                *status = 7;
                printStatusMessage(*status);

                return NULL;
            }

            push(node); // otherwise, push token to stack
        }
        // handles case where input is invalid
        else {
            // set status code, print status message
            *status = 6;
            printStatusMessage(*status);

            return NULL;
        }

        token = strtok(NULL, delimiter); // move onto next term in expression
    }

    // mismatched parentheses, expression is invalid
    if (numParentheses % 2 == 1) {
        // set status code, print status message
        *status = 6;
        printStatusMessage(*status);

        return NULL;
    }

    // pop remaining operators and append to output string
    while(!stackEmpty()) {
        // if '(' or non-operator is present, then expression is invalid
        if (peek()->contents.operator == '(') {
            // set status code, print status message
            *status = 6;
            printStatusMessage(*status);

            return NULL;
        }

        output[count++] = pop()->contents.operator;
        output[count++] = ' ';
    }

    // set status code, print status message
    *status = 0;
    printStatusMessage(*status);

    return output; // return postfix result
}

int getPrecedence(char operator) {
    // return precedence ranking number based upon the operator
    if (operator == '(' || operator == ')') {
        return 1;
    } else if (operator == '+' || operator == '-') {
        return 2;
    } else if (operator == '*' || operator == '/') {
        return 3;
    } else if (operator == '^') {
        return 4;
    } else {
        return -1; // error case
    }
}