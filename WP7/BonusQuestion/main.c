#include <stdio.h> // Include necessary libraries
#include <stdlib.h>

// Defines the node for the linked list
typedef struct Node {
    int value;
    struct Node *next;
} Node;

int main(int argc, char *argv[]) {
    // Check that exactly one argument is provided
    if (argc != 2) {
        printf("invalid arguments");
        return 0;
    }
    
    int n = atoi(argv[1]);
    if (n <= 0) {
        printf("0\n");
        return 0;
    }
    
    // This is in case of if only one number is requested
    // then output the first Fibonacci number which is 0
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    
    // Allocate and initialize the first two nodes of the Fibonacci sequence.
    // We define F(1) = 0 and F(2) = 1.
    Node *head = malloc(sizeof(Node));
    head->value = 0;
    head->next = NULL;
    
    Node *second = malloc(sizeof(Node));
    second->value = 1;
    second->next = NULL;
    head->next = second;
    
    // We keep pointers to the last two nodes so that we can compute the next Fibonacci number.
    Node *prev = head;      // initially first node is F 1
    Node *curr = second;    // second node is F 2
    
    // Generate the list until we have n Fibonacci numbers.
    // Since we already have 2 numbers, we loop from 3 to n
    for (int i = 3; i <= n; i++) {
        // The next Fibonacci number is the sum of the last two numbers.
        int nextVal = prev->value + curr->value;
        
        // Create a new node to hold this value.
        Node *newNode = malloc(sizeof(Node));
        newNode->value = nextVal;
        newNode->next = NULL;
        
        // Append the new node to the list.
        curr->next = newNode;
        
        // Update the two pointers: shift them one position forward.
        prev = curr;
        curr = newNode;
    }
    
    // Print the value of the last node 
    printf("%d\n", curr->value);
    
    // Free the allocated memory.
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    
    return 0;
}