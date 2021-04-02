#include <stdio.h>
#include <stdlib.h>
#include "node.h"

enum type {OPERATOR, NUMBER};

typedef struct node {
    double value;
    int type;
    struct node *next;
} node;

node* createNode (int value, int type) {
    node *newNode = NULL; // ground the pointer

    newNode = (struct node*) malloc(sizeof(node)); // allocate memory to node

    newNode->value = value; // assign value to node
    newNode->type = type; // assign type to node
    newNode->next = NULL; // new nodes do not point to the next node

    return newNode; // return the created node
}
