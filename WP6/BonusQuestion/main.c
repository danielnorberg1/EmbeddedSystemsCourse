#include <stdio.h> // Includes necessary librarys
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256 // Max size of the string
#define MAX_STRINGS 5 // Maximum of strings 

/*
This program takes 5 strings at a maximum length of 256 from the console and stores them
in an array.
It looks for which is the smallest string an then removes it
It then prints the old array and the new array without the shortest string in it.
*/


// This function takes 3 elements, an two dimentional array, the size of the array
// and a new two dimensional array with the newsize.
// It then finds the shortest string by iterating through the array
// and comparing the strings. And finally returns the newArray
char **removeShortestString(char **array, int size, int *newSize) {
    int minIndex = 0; // Initialize minIndex to the same as minLength
    int minLength = strlen(array[0]); // set minLength to the length of the string at array[0]
    
    // Finds the index of the shortest string.
    for (int i = 1; i < size; i++) {
        int len = strlen(array[i]); // Set len to equal i so that every possition is compared
        if (len < minLength) { // if len is less than minLength we set minLength to len to keep track of the smallest string
            minLength = len;
            minIndex = i; // Here we set minIndex to i so that we keep track of where minLength index is
        }
    }

 // Print the removed string.
printf("\nShortest string removed: %s\n\n", array[minIndex]);
    
// Allocate new array with one less element.
char **newArray = malloc((size - 1) * sizeof(char *));


int j = 0; // Initilize loop iterator
// This loop takes all the strings of the old array and put
// them in the new array with the exception of the shortest string.
    for (int i = 0; i < size; i++) {
        if (i == minIndex) { // If i == minIndex it skips adding it to the array.
            continue; // (Uses continue to skip)
        }
        newArray[j++] = array[i]; // Increments after the assignment to ensure that the next string is placed in the next avaible possition.
    }
    
    *newSize = size - 1; // Sets the newSize so that we can use it it main
    return newArray; // Returns the new array

}

// The main takes 5 strings from the console and puts them into an dynamic array.
// Then prints the old and new array.
int main(void){
    // Creates the twodimensional array with max 5 strings which will eventually point to a
    // Dynamically allocated string
    char *array[MAX_STRINGS]; 
    char buffer[MAX_LEN]; // Create a temporary buffer when reading each string to limit string len to 256
    
    // Read 5 strings from the console.
    for (int i = 0; i < MAX_STRINGS; i++) {
        printf("Enter string %d: ", i + 1); // Ask for the string and what number
        if (fgets(buffer, MAX_LEN, stdin) != NULL) { // Reads a line into the buffer.
            // Remove newline character if present.
            buffer[strcspn(buffer, "\n")] = '\0';
        }else {
            buffer[0] = '\0'; // If EOF or no input this ensures that the buffer is set to an empty string
        }
            // Allocate memory for the string and copy it.
            array[i] = malloc((strlen(buffer) + 1) * sizeof(char));
            strcpy(array[i], buffer);
        }
    

      // Display all elements of the original array.
      printf("\nOriginal array:\n"); // Prints meesage
      for (int i = 0; i < MAX_STRINGS; i++) { // Iterates trough all 5 possible strings
          printf("%s\n", array[i]); // Prints at each stabe
      }
      
      // Remove the shortest string using the removeShortestString function.
      int newSize;
      char **newArray = removeShortestString(array, MAX_STRINGS, &newSize);
      
      // Print the new array after removal.
      printf("Array after removal:\n");
      for (int i = 0; i < newSize; i++) { // Uses newSize so that we dont print empty string if we dont need to.
          printf("%s\n", newArray[i]);
      }
      
      // Free all allocated memory.
      for (int i = 0; i < MAX_STRINGS; i++) {
          free(array[i]);
      }
      free(newArray); // Frees the newArray


}