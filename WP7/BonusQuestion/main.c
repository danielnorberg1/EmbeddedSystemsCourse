#include <stdio.h> // Include necessary libraries
#include <stdlib.h>

/*
This program computes the Fibonacci number using an iterative method
instead of a recursive and stores the numbers in a linked list.
First it validates that the user has årovided exactly one valid positive
integer, then it initializes the linked lsit with the first fibonacci numbers.
It then computes the finonacci numbers by summing the values of
the two most recent nodes. After creating x nodes the program prints
the value of the Fibonacci number which is stored in the last node.
Finally the program frees all the dynamically allocated memory used
in the linked list.
*/

// Defines the node for the linked list
typedef struct Node {
    int value; // integer value which holds Fibonacci number
    struct Node *next; // Pointer next to another node that is the logic to chain the lionked list
} Node;



int main(int argc, char *argv[]) {
    // Check that exactly one argument is provided
    if (argc != 2) {
        printf("invalid arguments"); // Prints
        return 0; // returns 0 to exit program
    }
    
    int n = atoi(argv[1]); // converts the argument to a string and stores it in n
    if (n <= 0) { // checks if n is less or equal to 0
        printf("0\n"); // prints 0 because we assume the fibonacci number for non-positive input deifned as 0
        return 0; // end the program
    }
    
    // This is in case of if only one number is requested
    // then output the first Fibonacci number which is 0
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    
    // Allocate and initialize the first two nodes of the Fibonacci sequence.
    // We define F(1) = 0 and F(2) = 1.
    Node *head = malloc(sizeof(Node)); // Allocates memory on the heap
    head->value = 0; // Sets the first value of the first node to 0
    head->next = NULL; // Sets the next pointer of the first node to NULL
    
    Node *second = malloc(sizeof(Node)); // Alocates memory for second node
    second->value = 1; // Sets the value of the second node to 1
    second->next = NULL; // Sets next pointer to NULL
    head->next = second; // Here we link the first node to the second node
    
    // We keep pointers to the last two nodes so that we can compute the next Fibonacci number.
    Node *prev = head;      // initially first node is F 1
    Node *curr = second;    // second node is F 2
    
    // Generate the list until we have n Fibonacci numbers.
    // Since we already have 2 numbers, we loop from 3 to n
    for (int i = 3; i <= n; i++) {
        // The next Fibonacci number is the sum of the last two numbers.
        int nextVal = prev->value + curr->value;
        
        // Create a new node to hold this value.
        Node *newNode = malloc(sizeof(Node)); // alocates memory for new node
        newNode->value = nextVal; // Sets newNode value to nextValue
        newNode->next = NULL; // Initializes the next pointer of newNode to NULL
                            //because it is the last node in the list
        
        // Append the new node to the list.
        curr->next = newNode;
        
        // Update the two pointers: shift them one position forward.
        prev = curr;
        curr = newNode; // curr is updated to newNode so it becomes the last node
                        // in the list ensuring that for the next loop iteration
                        // the two most recent fibonacci number are avaiable
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
    
    return 0; // Returns 0 if the program was a success
}