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
        HEAD = tmp->next; // the next node becomes the HEAD (top of stack)

        return tmp; // return the popped node (removed from top of stack)
    }

    return NULL;
}

node* peak() {
    if(!stackEmpty()) {
        return HEAD;
    }
}

bool clearStack() {
    struct node* tmp = HEAD;
    while(!stackEmpty()) {
        tmp = pop();
        free(tmp);
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

void printStack() {
    if (HEAD) {
        struct node* trav = HEAD; // start at HEAD node

        printf("[%f", trav->value); // print first node value

        // traverse through stack, printing all node values
        while(trav->next) {
            trav = trav->next;
            printf(",%f", trav->value);
        }

        printf("]\n"); // done w/ stack, print end bracket

        trav = NULL; // ground pointer, done using it
    } else {
        printf("No stack exists. \n");
    }
}