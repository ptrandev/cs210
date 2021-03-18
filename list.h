#include <stdbool.h>

#ifndef FUNCTIONS_LIST_H
#define FUNCTIONS_LIST_H

typedef struct node node;

bool addNode(node* node); // add note to list
node* findNode(int value); // find node in list
bool deleteNode(node* node); // delete node in list
void printList(void); // print values in list
int findLargest(void); // find largest value in list
void deleteLargest(void); // deletes largest nodes in list
int listLength(void); // return length of list
void swap(node* prev, node* trav, node* next); // swaps position of 2 nodes
void listSort(void); // sort list using bubble sort

#endif // FUNCTIONS_LIST_H