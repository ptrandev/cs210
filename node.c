#include <stdio.h>
#include "node.h"

typedef struct node {
    int value;
    struct node *next;
};

node* createNode (int value) {
    node *newNode = NULL; // ground the pointer

    newNode = (struct node*) malloc(sizeof(node)); // allocate memory to node
    
    newNode->value = value; // assign value to node
    newNode->next = NULL; // new nodes do not point to the next node

    return newNode; // return the created node
}