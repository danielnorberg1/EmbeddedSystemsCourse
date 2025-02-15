// (C) __Erik Gabrielsson, Daniel Norberg, Lilly Heier
// Work package 2
// WP2E2 Exercise

// Include Section
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define Section
#define MAX_NODES 5
#define MAX_VALUE 100

/*
Modify a doubly linked list. Each node is connected to the next one
using a pointer. The max amount of nodes is 5.
*/

// For myself - delete
/*
Each node has a number field which is assigned a random number between 0 and 100
Points to the next node 'next' links to the next element in the list.
Points to the previous node 'prev' links to the previous element in the list.
REGTYPE *random_list(void) returns a pointer to the first node (head) of the linked list
*/

// Helper function that generates a random integer between 0 and 100.
// It calls on the rand() function from the stdlib.h library.
// Using the modulo operator to get a number between 0 and 100.
int rand_int(void)
{
    return rand() % (MAX_VALUE + 1);
}

// We define a struct called q, that is a doubly linked list.
typedef struct q
{
    int number;
    struct q *next; // Pointer to the next node
    struct q *prev; // Pointer to the previous node
} REGTYPE;

void print_linkedlist(REGTYPE *head)
{
    int nr = 0;
    REGTYPE *act_post = head;

    // While loop that iterates until the current node is NULL.
    while (act_post != NULL)
    {
        printf("\n Post nr %d : %d", nr++, act_post->number);
        act_post = act_post->next;
    }
    printf("\n");
}
// function declaration for random_list()
REGTYPE *random_list(void);
// function declaration for add_first(), it takes a pointer to a node and an integer as arguments.
REGTYPE *add_first(REGTYPE *temp, int data);
// Declare function that prints the linked list.
void print_linkedlist(REGTYPE *head);

// ###### Main program #######
int main(void)
{

    // Declare a variable to count nr of nodes.
    REGTYPE *act_post, *head = NULL; // Declare pointers to current and head node.
    srand(time(0));                  // Seed the random number generator so we get different numbers each time.

    // Since random_list() returns a pointer to the head of the linked list.
    // We assign the return value to the head pointer.
    head = random_list();

    printf("Original List:\n"); // Print the original list.
    print_linkedlist(head);

    int new_data = rand_int(); // Generate a new random number and store it in integer new_data.

    // Call the add_first() function to add a new node at the start of the list.
    // The function takes the head pointer and the new_data as arguments.
    head = add_first(head, new_data);

    printf("\nUpdated List After Adding %d:\n", new_data);
    print_linkedlist(head);

    // Free memory for each node in the linked list.
    while ((act_post = head) != NULL) // While the current node is not null.
    {
        head = act_post->next; // Move the head to the next node.
        free(act_post);        // Free the memory of the current node.
    }

    return 0;
}

// ==== End of main ======================================
REGTYPE *random_list(void)
{
    // Declare pointers to the head, current and previous node.
    // They are all initialized to NULL.
    REGTYPE *item, *top = NULL, *old = NULL;

    // Loop that iterates through the max amount of nodes.
    // MAX_NODES is 5 for this program.
    for (int i = 0; i < MAX_NODES; i++)
    {
        item = (REGTYPE *)malloc(sizeof(REGTYPE)); // Dynamically allocate memory for the current node.

        // If current is NULL, an error message is printed and we return to the head.
        if (!item)
        {
            printf("Memory allocation failed.\n");
            return item;
        }

        item->number = i; // Assign a random number to number of current node.
        item->next = NULL;         // Assign the next pointer to NULL
        item->prev = NULL;     // Assign the prev pointer to NULL

        // If top is not NULL
        if (top == NULL)
        {
            top = item; // Set top to equal item
        }
        else
        {
            old->next = item; // If top is !NULL there is another item which old next is pointed too
            item->prev = old; // Item prev then points to the old
        }

        old = item; // Set old to point to item after the iteration
    }

    return top; // Return the head of the linked list
}

//==========================================================
REGTYPE *add_first(REGTYPE *temp, int data)
{
    REGTYPE *node = malloc(sizeof(REGTYPE)); // Dynamically allocates memory on the heap.

    // Error handling if the memory allocation fails.
    if (!node)
    { // If node is null
        printf("Memory alloc failed.\n");
        return temp; // Return the original list if it fails
    }

    node->number = data; // set the number to the data input
    node->prev = NULL;   // Assign the previous pointer to NULL
    node->next = temp;   // Assign the next pointer to the head

    // If the head is not NULL
    // Assign the previous pointer of the head to the new node
    if (temp)
        temp->prev = node;

    return node; // New node is now the head
}
