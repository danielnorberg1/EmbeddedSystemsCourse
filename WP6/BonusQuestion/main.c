#include <stdio.h> // Includes necessary librarys
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256 // Max size of the string
#define MAX_STRINGS 5 // Maximum of strings 


char **removeShortestString(char **arr, int size, int *newSize) {
    int minIndex = 0;
    int minLength = strlen(arr[0]);
    
    // Find the index of the shortest string.
    for (int i = 1; i < size; i++) {
        int len = strlen(arr[i]);
        if (len < minLength) {
            minLength = len;
            minIndex = i;
        }
    }

 // Print the removed string.
printf("\nRemoved string: %s\n\n", arr[minIndex]);
    
// Allocate new array with one less element.
char **newArr = malloc((size - 1) * sizeof(char *));


int j = 0;
    for (int i = 0; i < size; i++) {
        if (i == minIndex) {
            continue;
        }
        newArr[j++] = arr[i];
    }
    
    *newSize = size - 1;
    return newArr;

}


int main(void){







}