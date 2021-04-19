#include <stdio.h>
#include <stdlib.h>
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

node* createNode (double value, int type) {
    node *newNode = NULL; // ground the pointer

    newNode = (struct node*) malloc(sizeof(node)); // allocate memory to node

    // return error if malloc returns null
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    newNode->value = value; // assign value to node
    newNode->type = type; // assign type to node
    newNode->next = NULL; // new nodes do not point to the next node

    return newNode; // return the created node
}
