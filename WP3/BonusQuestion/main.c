#include <stdio.h> // Includes necessary libraries
#include <string.h>
#include <stdlib.h>

// This program will use pointers to initialize three matrices
// Two of which will hold user input and one that will hold the sum of these
// First the user chooses the size of the matrices, then enter the input for matrix1 
// and then matrix2. After this the program will then print out 
int main(){

int depthOfMatrices, widthOfMatrices; // Initialize variables to store the matrix

printf("Input the size: \n"); // Pomts the user to input the size

// Takes user inout and stores in the initialized variables
scanf("%i%i", &depthOfMatrices, &widthOfMatrices);

// If the input for the width and depth of the matrix is 1 and 1
// The system will stop and output invalid.
if ((depthOfMatrices == 1) && (widthOfMatrices == 1) ){
    printf("invalid");
    return 0;
}


// Here we initialize the matrices that is allocated using the heap.
// The usage of pointers to pointers ensures us that matrix1 for example
// points to the integer that will point to the integer that hold a the value.
// So that it becomes two dimentional. Then the porgram will print out
// The value that each matrix hold at every possition and lastly free the
// allocated memory in the end.
// The program also checks that there cannot be a matrix the size of 1x1, that the
// input of the matrixes always equals the number of the size and that there
// are only integers in the matrix.
int **matrix1 = (int **)malloc(depthOfMatrices * sizeof(int *));
int **matrix2 = (int **)malloc(depthOfMatrices * sizeof(int *));
// This is used to store the sum of the matrices
int **sumOfMatrices = (int **)malloc(depthOfMatrices * sizeof(int *));
// Goes through the size of matrix1 and allocates memory for each itteration.
for (int i = 0; i < depthOfMatrices; i++){ 
    matrix1[i] = (int *)malloc(widthOfMatrices * sizeof(int));
    matrix2[i] = (int *)malloc(widthOfMatrices * sizeof(int));
    // This allocates memory for the sumurized matrix
    sumOfMatrices[i] = (int *)malloc(widthOfMatrices * sizeof(int)); 
}

int i; // Loop variables
int j;


printf("Input elements of matrix 1: \n"); // Prints message
// The outer loop iterates over every allocated memory i (depth)
for (i = 0; i < depthOfMatrices; i++) {
    //The inner loop itterates over every allocated memory j (width)
    for (j = 0; j < widthOfMatrices; j++){
        // At every possition in the array, it scans
        // and validates that it read 1 integer.
        // If it is one integer it returns 1 and puts the input at the given position
        // if it is != 1 e.g, user input is non-numeric like abc the program exits and 
        // prints invalid.
    if ((scanf("%i", &matrix1[i][j])) != 1){ 
        printf("invalid\n");
        return 0;
    }
    }
}
// from line 60 to 70 it does the same as the loop above but for matrix2
// instead of matrix1
printf("Input elements of matrix 2: \n");

for (i = 0; i < depthOfMatrices; i++) {
    for (j = 0; j < widthOfMatrices; j++){
    if ((scanf("%i", &matrix2[i][j])) != 1){
        printf("invalid\n");
        return 0;
    }

    }
}


printf("The sum is: \n"); // Prints message
// These loops summarizes the prevoius matrices by
// casting the value at every given position i, j
// to then print the sum.
for (i = 0; i < depthOfMatrices; i++){
    for(j = 0; j < widthOfMatrices; j++){
    sumOfMatrices[i][j] = (matrix1[i][j] + matrix2[i][j]); 
    printf("%d ", sumOfMatrices[i][j]);
    }
    printf("\n"); // This print ensures new line after a "width" has been printet ensuring the right esthethics.
}

// Here we free the memory at each row in the matrices
// This is necessary since memory is allocated in a x*x manner.
// So we itterate over every matrix preventing memory leeks.
for (i = 0; i < depthOfMatrices; i++) {
    free(matrix1[i]);
    free(matrix2[i]);
    free(sumOfMatrices[i]);
}

// This free the pointer array itself
free(matrix1);
free(matrix2);
free(sumOfMatrices);




return 0; // Exits
}