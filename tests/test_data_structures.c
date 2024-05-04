#include "data_structures.h"
#include <stdio.h>

int main() {
    // Test createNode function
    Node* node = createNode(10);
    if (node != NULL && node->data == 10 && node->next == NULL) {
        printf("createNode: Passed\n");
    } else {
        printf("createNode: Failed\n");
    }

    // Add more test cases for other functions in data_structures.c

    return 0;
}

