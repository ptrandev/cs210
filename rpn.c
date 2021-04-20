#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rpn.h"
#include "node.h"
#include "stack.h"
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

double evaluate (char* expression, int* status) {
    char delimiter[] = " "; // what each of our terms are separated by
    char *token; // used to walk through the expression

    double result; // stores result of operations on num_1 and num_2

    // used to store numbers we will perform operations on
    struct node* num_1;
    struct node* num_2;

    struct node* node; // stores node that will be pushed to stack
    struct node* final_node; // stores last node in stack (final answer)

    token = strtok(expression, delimiter); // prime the token

    // while there are still terms in the token...
    while(token != NULL) {
        // if the token is an operator...
        if(isOperator(token)) {
            // handle case where stack contains nodes (the normal case)
            if (!stackEmpty()) {
                // pop two numbers from the stack
                num_1 = pop();
                num_2 = pop();

                // ERROR: too few operands, since second number doesn't exist
                if (num_2 == NULL) {
                    // set status code and print status message
                    *status = 3;
                    printStatusMessage(*status);

                    clearStack(); // clear all nodes from the stack for the next evaluation

                    return 0.0;
                }
                // return result of operation according to the operator
                switch(*token) {
                    case '+':
                        result = num_2->contents.value + num_1->contents.value;
                        break;
                    case '-':
                        result = num_2->contents.value - num_1->contents.value;
                        break;
                    case '/':
                        // ERROR: divide by zero, since the divisor is 0
                        if (num_1->contents.value == 0.0) {
                            // set status code and print status message
                            *status = 4;
                            printStatusMessage(*status);

                            clearStack(); // clear all nodes from the stack for the next evaluation

                            return 0.0;
                        }

                        result = num_2->contents.value / num_1->contents.value;
                        break;
                    case '*':
                        result = num_2->contents.value * num_1->contents.value;
                        break;
                    case '^':
                        result = power(num_2->contents.value, num_1->contents.value);
                        break;
                }
            } 
            // ERROR: there are no numbers to operate on (too few operands)
            else {
                // set status code and print status message
                *status = 3;
                printStatusMessage(*status);

                clearStack(); // clear all nodes from the stack for the next evaluation

                return 0.0;
            }

            // create node containing result of calculation and push to stack
            node = createNode(result, NUMBER);
            push(node);

            // free nodes we performmed operations on, we're done using them
            free(num_1);
            free(num_2);

        }
        // if the token is a number ...
        else if (isNumber(token)) {
            // create node containing the number and push to stack
            node = createNode(atol(token), NUMBER);
            push(node);
        }
        // ERROR: the input is invalid
        else {
            // set status code and print status message
            *status = 6;
            printStatusMessage(*status);

            clearStack(); // clear all nodes from the stack for the next evaluation

            return 0.0;
        }

        token = strtok(NULL, delimiter); // move onto next term in expression
    }

    final_node = pop(); // pop the final answer from the stack

    // ERROR: no input given, since there is nothing in the stack
    if (final_node == NULL) {
        // set status code and print status message
        *status = 5;
        printStatusMessage(*status);

        clearStack(); // clear all nodes from the stack for the next evaluation

        return 0.0;
    }

    // ERROR: too many operands, since there are still nodes on the stack
    if(!stackEmpty()) {
        // set status code and print status message
        *status = 2;
        printStatusMessage(*status);

        clearStack(); // clear all nodes from the stack for the next evaluation

        return 0.0;
    }

    result = final_node->contents.value; // store the value of the final answer

    free(final_node); // free the node, we're doing using it

    // set status code and print status message
    *status = 0;
    printStatusMessage(*status);

    return result; // return the final answer
}

// recursive power function
double power (double num_1, double num_2) {
    // base case
    if (num_2 == 1) {
        return num_1;
    }

    // recursive case
    return num_1 * power(num_1, num_2 - 1);
}

bool isOperator(char *token) {
    // if the token matches an operator char, return true
    if (!strcmp(token, "+") || !strcmp(token, "-") || !strcmp(token, "/") ||
    !strcmp(token, "*") || !strcmp(token, "^")) {
        return true;
    }

    return false; // else, it is not an operator
}

bool isNumber(char *token) {
    char * end;

    strtod(token, &end); // check to see if token is a number

    return token != end; // if end changes, then it is not a number
}