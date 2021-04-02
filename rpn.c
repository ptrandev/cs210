#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rpn.h"
#include "node.h"
#include "stack.h"

enum type {OPERATOR, NUMBER};

typedef struct node {
    double value;
    int type;
    struct node *next;
} node;

double evaluate (char* expression, int * status) {
    char delimiter[] = " ";
    char *token;
    int value;
    enum type charType;
    struct node* node;
    double result;

    struct node* num_1;
    struct node* num_2;

    struct node* final_node;

    token = strtok(expression, delimiter);

    while(token != NULL) {
        if(!strcmp(token, "+") || !strcmp(token, "-") || !strcmp(token, "/") ||
           !strcmp(token, "*") || !strcmp(token, "^")) {
            if (!stackEmpty()) {
                num_1 = pop();
                num_2 = pop();

                // somehow incorrect formatting
                if (num_2 == NULL) {
                    *status = -1;
                    clearStack();
                    return 0.0;
                }

                switch(*token) {
                    case '+':
                        result = num_2->value + num_1->value;
                        break;
                    case '-':
                        result = num_2->value - num_1->value;
                        break;
                    case '/':
                        // divide by zero
                        if (num_2 == 0) {
                            *status = -2;
                            return 0.0;
                        }

                        result = num_2->value / num_1->value;
                        break;
                    case '*':
                        result = num_2->value * num_1->value;
                        break;
                    case '^':
                        result = power(num_2->value, num_1->value);
                        break;
                }
            } else {
                // no values to perform operations on
                *status = -1;
                return 0.0;
            }

            node = createNode(result, NUMBER);
            push(node);

            free(num_1);
            free(num_2);

        } else {
            charType = NUMBER;
            value = atol(token);

            node = createNode(value, charType);
            push(node);
        }

        token = strtok(NULL, delimiter);
    }

    final_node = pop();

    // no values in stack, improper formatting (empty input)
    if (final_node == NULL) {
        *status = -1;
        return 0.0;
    }

    // values left in stack, improper formatting
    if(!stackEmpty()) {
        *status = -1;
        clearStack();
        return 0.0;
    }

    result = final_node->value;

    free(final_node);

    *status = 0;
    return result;
}

double power (double num_1, double num_2) {
    if (num_2 == 1) {
        return num_1;
    }

    return num_1 * power(num_1, num_2 - 1);
}