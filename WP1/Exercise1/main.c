#include <stdio.h> // Include necessary libraries
#include <string.h>

#define MAX_SENTENCES 5 // Sets number 5 as the number of maximum of sentences
#define MAX_CHARACTHERS 31 // Sets 31 as the maximum number of charachters

// Function to clear the buffer
void clearstdin(void)
{
    char lastChar; // Initialize lastChar to hold the charachter that comes from getChar()
    while ((lastChar = getchar()) != '\n' && lastChar != EOF); // Gets the characchters from the input buffer until it reaches \n and the lastChar is not end of file.
}



int main()
{
    char sentences[MAX_SENTENCES][MAX_CHARACTHERS]; // Initialize the multi array
    // Initialize loop variables
    int i = 0;
    int j = 0;

    // The loop iterates though every position in sentences an uses fgets
    // and saves it to the position i.
    for (i = 0; i < MAX_SENTENCES; i++)
    {

        fgets(sentences[i], MAX_CHARACTHERS, stdin); // gets user input and stores it in sentences array at position i.

        char *end = strchr(sentences[i], '\n'); // strchr() searches for the first time \n is found in sentences[i] and uses *end as the pointer to it.
        if (end)
        {
            *end = '\0';
        }
        else
        {
            clearstdin();
        }

    
    }

    for (j = 1; j < 5; j++)
    {
        for (i = 0; i < 4; i++)
        {
            if ((strcmp((sentences[i]), sentences[j]) == 0) && (i  != j))

            {
                printf("Duplicate found.");
            }
        }
    }

    int userNumber;

    while (scanf("%d", &userNumber) == 1 && userNumber >= 1 && userNumber <= 5)
    {
        printf(" Please enter a number between 1 - 5: \n");
        printf("%s\n", sentences[userNumber - 1]);

    }

    return 0;
}