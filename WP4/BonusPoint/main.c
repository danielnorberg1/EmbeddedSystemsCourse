#include <stdio.h> // Includes necessary libraries
#include <string.h>
#include <stdlib.h>

#define MAX_CHARACTERS 10 // Defines the maxium charachter that the argument should be

/*
* This program takes the input of a argument when starting the system and checks
* that it is less than 10. It then takes the argument and uses the function
* permutate() to make all permutations of the given argument. By using
* a recursive functionality along with the swap function
* it also stores all the permutations in a array and at last prints all the
* permutations.
*/

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
            // When they have been swapped we make a recursive call
            // to start generating the permutations of the substring that
            // starts just after the currect fixed position.
            // so for every call the charachter at starting pos will be fixed
            // and the rest will be swapped.
            permutate(input, startingPos+1, endPos, count, permutations);
            // This line undoes the previous swap to help backtrack.
            // This essentially restores the orgiginal order of the string
            // for the next iteration of the loop allowing every charachter to be
            // tried in the starting possition.
            swap(input+startingPos, input+i);

        }
    }
}


int main(int argc, char * argv[]){

    // Checks that there are two arguments and prints invalid if there isnt.
    if (argc != 2){
        printf("invalid");
        return 0;
    }
    // Checks that the argument that is not the system is <= 10 and prints 
    // invlaid if it is bigger.
    if (strlen(argv[1]) > MAX_CHARACTERS){
        printf("invalid");
        return 0;
    }

    int factorial = 1; // Initialize the factorial integer
    char *input = argv[1]; // initialize input that points to the first argument
    int length = strlen(input); // takes the length of input att stores it in length
    int count = 0; // Initialize count.

    // This loop calculates the factorial number of the input
    // so that we can dynamically allocate how many permutations there will be
    for (int i = 1; i <= length; i++){
        factorial *= i;;
    }


    // Initialize the permutations array to store all the permutation from
    // the permute function
    char **permutations = (char**)malloc(factorial*sizeof(char*));


    // Inserts the arguyment along with the other necessary values
    // to start the permutate function.
    permutate(input, 0, length-1, &count, permutations);

    // Prints the original input
    printf("The permutations of the string %s: ", input);

    // Takes each permutations in the permutations array and prints them.
    for (int i = 0; i <count; i++){
        printf("%s ", permutations[i]);
        // Since we are already looping each i in the permutation
        // We free it at the same time
        free(permutations[i]); 
        
    }

    // Frees the last adress that hold the array
    free (permutations);

    return 0; // Returns 0 if the program ran successfully
}