#include <stdio.h>
#include <string.h>

#define MAX_SENTENCES 5
#define MAX_CHARACTHERS 31

void clearstdin(void)
{
    char lastChar;
    while ((lastChar = getchar()) != '\n' && lastChar != EOF);
}

int main()
{
    char sentences[MAX_SENTENCES][MAX_CHARACTHERS];
    int i = 0;
    int j = 0;

    for (i = 0; i < MAX_SENTENCES; i++)
    {

        fgets(sentences[i], MAX_CHARACTHERS, stdin);

        char *end = strchr(sentences[i], '\n');
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