#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct node {
    int value;
    struct node *next;
} node;

node* HEAD = NULL;

bool addNode(node* node) {
    // if no head exists, make the argument mode the head node
    // else, traverse to end of list and add node
    if (!HEAD) {
        HEAD = node;
    } else {
        struct node* trav = HEAD; // start at head node

        // while a next node exists, keep traversing
        while (trav->next) {
            trav = trav->next;
        }

        trav->next = node; // add node to end of list

        trav = NULL; // ground pointer, done using it
    }

    return true;
}

node* findNode(int value) {
    // handle case in which list is empty
    if (!HEAD) {
        return NULL;
    }

    struct node* trav = HEAD; // start at head node

    // while we are still on a node, keep traversing
    while (trav) {
        // return node when match found
        if (trav->value == value) {
            return trav;
        }

        trav = trav->next; // else, move onto next node
    }

    trav = NULL; // ground pointer, done using it

    return NULL; // searching yields no results
}

bool deleteNode(node* node) {
    // empty list, return false
    if (!HEAD) {
        return false;
    }

    // start searching at HEAD node
    struct node* trav = HEAD;
    struct node* prev = HEAD;

    // if match found in HEAD...
    if (trav == node) {
        HEAD = trav->next; // skip over matching node

        free(trav); // free memory allocated to matching node
        trav = NULL; // ground pointer

        return true;
    }

    // crawl rest of list to find node
    while(trav) {
        prev = trav; // keep track of previous node
        trav = trav->next; // move onto next node

        // if match found in list...
        if (trav == node) {
            prev->next = trav->next; // skip over the matching node

            free(trav); // free memory allocated to matching node
            trav = NULL; // ground pointer

            return true;
        }
    }

    // ground pointers, done using them
    trav = NULL;
    prev = NULL;

    return false; // no node found
}

void printList() {
    // if no list exists, do nothing
    if (!HEAD) {
        return;
    }

    struct node* trav = HEAD; // start at HEAD

    printf("[%d", trav->value); // print first node value

    // traverse through list, printing all node values
    while(trav->next) {
        trav = trav->next;
        printf(",%d", trav->value);
    }

    printf("]\n"); // done w/ list, print end bracket

    trav = NULL; // ground pointer, done using it
}

int findLargest(void) {
    // only run if a list exists
    if (HEAD) {
        struct node* trav = HEAD; // start at HEAD
        int largest = HEAD->value; // assume first number is largest

        trav = trav->next; // move onto the next node for comparison

        // while we are still on a node...
        while (trav) {
            // if current node is larger, assign largest to current node value
            if (trav->value > largest) {
                largest = trav->value;
            }

            trav = trav->next; // move onto next node
        }

        trav = NULL; // ground pointer, done using it

        return largest; // return our result, value of largest node
    }
}

void deleteLargest(void) {
    // no list exists, nothing to do
    if (!HEAD) {
        return;
    }

    int largest = findLargest(); // obtain largest value
    struct node* current = findNode(largest); // find node w/ largest value

    // while there exists a node w/ the largest value...
    while (current) {
        deleteNode(current); // delete the node w/ largest value
        current = findNode(largest); // find another node w/ largest value
    }

    current = NULL; // ground pointer, done using it
}

int listLength(void) {
    int counter = 0; // keep track of # of nodes, start @ 0 (no list exists)

    // if a list exists..
    if (HEAD) {
        struct node* trav = HEAD; // start at HEAD

        counter++; // increment counter by 1, since a head node exists
        
        // while a next node exists...
        while(trav->next) {
            trav = trav->next; // move onto next node
            counter++; // increment counter by 1
        }

        trav = NULL; // ground pointer, done using it
    }

    return counter; // return our result, the # of nodes
}

void swap(node* prev, node* trav, node* next) {
    // handle case in which current node is HEAD node
    // else, node that comes after prev is the node after current
    if (prev == NULL) {
        HEAD = trav->next;
    } else {
        prev->next = trav->next;
    }

    // swap position of the nodes
    trav->next = next->next;
    next->next = trav;
}

void listSort(void) {
    // if no linked list exists, nothing to do
    if (!HEAD) {
        return;
    }

    // initialize pointers used to traverse list
    node* prev = NULL;
    node* trav = NULL;
    node* next = NULL;

    bool changed = false; // tells us if a change to the list has occured
    bool sorting = true; // tells us if sorting is done

    // continue sorting from the beginning of the list
    while (sorting) {
        changed = false; // no nodes have changed this itteration

        // start traversing at beginning of list
        prev = NULL;
        trav = HEAD;

        // traverse through list while a next node exists
        while (trav->next) {
            next = trav->next; // keep track of the next node

            // if the next node is smaller than the current node...
            if (next->value < trav->value) {
                swap(prev, trav, next); // swaps position of trav and next
                changed = true; // a change has been made to the list
            }

            // move onto the next node to perform comparsion
            prev = trav;
            trav = next;

            next = NULL; // ground pointer, we're done using it
        }

        // if a node hasn't been changed after going through entire list ...
        if (!changed) {
            sorting = false; // we are no longer sorting
        }
    }

    // ground pointers, we're done using them
    prev = NULL;
    trav = NULL;
}