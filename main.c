#include <stdio.h>
#include "list.h"
#include "node.h"

int main() {
    int list[] = {89, 39, 18, 96, 71, 25, 2, 55, 60, -8, 9, 42, 69, 96, 24};

    // PS3.1
    printf("PS3.1 Add Set of Nodes\n");

    struct node* node;

    for (int count = 0; count < sizeof(list) / sizeof(int); count++) {
        if (node = createNode(list[count])) {
            addNode(node);
        }
    }

    printList();
    printf("\n");

    // PS3.2
    printf("PS3.2 Delete the Largest Nodes\n");

    deleteLargest();

    printList();
    printf("\n");

    // PS3.3
    printf("PS3.3 Count the Nodes in the List\n");

    int length = listLength();
    printf("%d\n", length);
    printf("\n");

    // PS3.4
    printf("PS3.4 Sort the List\n");

    listSort();

    printList();

    return 0;
}