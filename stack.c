#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

enum type {OPERATOR, NUMBER};

typedef struct node {
    double value;
    int type;
    struct node *next;
};

node* HEAD = NULL;

void push(node* node) {
    if (stackEmpty()) {
        HEAD = node; // for empty stack, just assign the input node as head
    }
    else {
        struct node* tmp = HEAD; // store HEAD node
        HEAD = node; // new HEAD node is input node

        node->next = tmp; // point our new HEAD node to the previous node
    }
}

node* pop() {
    if(!stackEmpty()) {
        struct node* tmp = HEAD; // store HEAD node
        tmp->next = HEAD; // the next node becomes the HEAD (top of stack)

        return tmp; // return the popped node (removed from top of stack)
    }
}

node* peak() {
    if(!stackEmpty()) {
        return HEAD;
    }
}

bool clearStack() {
    while(!stackEmpty()) {
        pop();
    }
}

bool stackEmpty() {
    // when HEAD == NULL, the stack is empty
    if (HEAD == NULL) {
        return true;
    } else {
        return false;
    }
}