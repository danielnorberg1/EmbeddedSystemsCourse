#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5
// ##### typedefs ####
typedef struct q
{
    int number;
    struct q *next;
    struct q *prev;
} REGTYPE;

// ##### Function declarations #####
REGTYPE *random_list(void);
REGTYPE *add_first(REGTYPE *temp, int data);

// ###### Main program #######
int main(int argc, char *argv[])
{
    int nr = 0;
    REGTYPE *act_post, *head = NULL;
    srand(time(0)); // Random seed
    head = random_list();
    act_post = head;
    while (act_post != NULL)
    {
        printf("\n Post nr %d : %d", nr++, act_post->number);
        act_post = act_post->next;
    }
    int new_value = 12;
    printf("\nAdding a new first node with the value %i", new_value);
    head = add_first(head, new_value);

    printf("\nThe list after adding a new first: \n");
    act_post = head;
    nr = 0;
    while (act_post != NULL){
        printf("Post nr %d : %d\n", nr++, act_post->number);
        act_post = act_post->next;
    }


    // --- Free the allocated memory ---
    while ((act_post = head) != NULL)
    {
        head = act_post->next;
        free(act_post);
    }
    
    return 0;
}

// ==== End of main ======================================
REGTYPE* random_list(void)
{
    int nr, i = 0;
    REGTYPE *top = NULL;
    REGTYPE *old = NULL;
    REGTYPE *item;
    for (i = 0; i < MAX; i++){
    item = (REGTYPE*)malloc(sizeof(REGTYPE));
    item->number = i;
    item->next = NULL;
    item->prev = NULL;

    if (top == NULL){
        top = item;
    } else {
        old->next = item;
        item->prev = old;
    }
    old = item;

    }

    return (top);
}

//==========================================================
REGTYPE *add_first(REGTYPE *temp, int data)
{
    
REGTYPE *new_node = (REGTYPE*)malloc(sizeof(REGTYPE));
new_node->number = data;
new_node->next = temp;
new_node->prev = NULL;
if(temp != NULL){
    temp->prev = new_node;
}

return new_node;
} 