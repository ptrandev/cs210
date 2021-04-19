#include <stdbool.h>

#ifndef FUNCTIONS_STACK_H
#define FUNCTIONS_STACK_H

typedef struct node node;

void push(node* node); // push a node onto the stack
node* pop(); // pop the top of the stack
node* peek(); // return a reference to the node on the top of the stack

bool clearStack(); // resets the stack to empty
bool stackEmpty(); // returns state of the stack
void printStack(); // prints the nodes in the stack

int nodeType(node* node); // return type of node

#endif // FUNCTIONS_STACK_H