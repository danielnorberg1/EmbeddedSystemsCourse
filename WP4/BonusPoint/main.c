#include <stdio.h> // Includes necessary libraries
#include <string.h>
#include <stdlib.h>

#define MAX_CHARACTERS 10 // Defines the maxium charachter that the argument should be

// This function is a standard swapper function
void swap(char *a, char *b){ // It takes two pointer charachters
    char temp = *a; // stores the first pointer into a temp holder
    *a = *b; // points a to b
    *b = temp; // then sets b to a so that a and b has switched what they pointed to.
}

// This function creates the permutations and stores them in permutations as a copy
// It takes input that is the argument, the starting possition of the argument and end.
// It also keeps track of the count to give the permutations a adress where to be stored in permutations.
void permutate(char *input, int startingPos, int endPos, int *count, char **permutations){

    // If the starting possition == the last possition then the programs knows that there
    // is no more permutations to make, it then makes the copy of the input and places it in the permutation.
    if (startingPos == endPos){ 
        permutations[*count] = strdup(input);
        (*count)++; // The count makes itterates to make sure that we place each copy if input in the right place in the permutations
    } else {
        for (int i = startingPos; i <= endPos; i++){ // This loop will run for every i from the starting possition until the end possition.

            // Input is the adress of the first charachter of the provided argument
            // and starting possition the first time is 0 so the same as input.
            // then input + i which points to the charachter at index i and swaps these two.
            swap(input+startingPos, input+i); 
            // When they have been swapped
            permutate(input, startingPos+1, endPos, count, permutations);

            swap(input+startingPos, input+i);

        }
    }




}


// Main 
int main(int argc, char * argv[]){

    if (argc != 2){
        printf("invalid");
        return 0;
    }

    if (strlen(argv[1]) > MAX_CHARACTERS){
        printf("invalid");
        return 0;
    }

    

    int factorial = 1;
    char *input = argv[1];
    int length = strlen(input);
    int count = 0;

    // This loop calculates the factorial number of the input
    // so that we can dynamically allocate how many permutations there will be
    for (int i = 1; i <= length; i++){
        factorial *= i;;
    }



    char **permutations = (char**)malloc(factorial*sizeof(char*));


    permutate(input, 0, length-1, &count, permutations);

    printf("The permutations of the string %s: ", input);

    for (int i = 0; i <count; i++){
        printf("%s ", permutations[i]);

        free(permutations[i]);
    }

    free (permutations);

    return 0;
}




