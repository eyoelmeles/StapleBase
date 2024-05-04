#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

// Define the structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function declarations
Node* createNode(int data);
void insertAtBeginning(Node** head, int data);
void insertAtEnd(Node** head, int data);
void deleteNode(Node** head, int data);
void printList(Node* head);

#endif /* DATA_STRUCTURES_H */

