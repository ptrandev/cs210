#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

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
        HEAD = tmp->next; // the next node becomes the HEAD (top of stack)

        return tmp; // return the popped node (removed from top of stack)
    }

    return NULL; // stack is empty, nothing to pop
}

node* peak() {
    if(!stackEmpty()) {
        return HEAD; // node at top of stack is the HEAD
    }

    return NULL; // empty stack, no HEAD exists
}

bool clearStack() {
    struct node* tmp; // used to store node to free

    // while the stack contains nodes...
    while(!stackEmpty()) {
        tmp = pop(); // pop node and store it
        free(tmp); // free node from memory
    }
}

bool stackEmpty() {
    // no HEAD means stack is empty
    if (HEAD == NULL) {
        return true;
    }

    return false; // if HEAD exists, them the stack isn't empty
}

void printStack() {
    if (!stackEmpty()) {
        struct node* trav = HEAD; // start at HEAD node

        printf("[%f", trav->contents); // print first node value

        // traverse through stack, printing all node values
        while(trav->next) {
            trav = trav->next;
            printf(",%f", trav->contents);
        }

        printf("]\n"); // done w/ stack, print end bracket

        trav = NULL; // ground pointer, done using it
    } else {
        printf("No stack exists. \n");
    }
}