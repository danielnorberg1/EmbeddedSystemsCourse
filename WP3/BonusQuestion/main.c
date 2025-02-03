#include <stdio.h> // Includes necessary libraries

void clearBuffer(){
    char lastChar;
    while((lastChar = getChar()) != ("\n"));
}

int main(){

printf("Input the size: \n");

int sizeOfMatrices = scanf("%i", sizeOfMatrices);
clearBuffer();

int matrix1[sizeOfMatrices][sizeOfMatrices]; 
int matrix2[sizeOfMatrices][sizeOfMatrices]; 
int sumOfMatrices[sizeOfMatrices][sizeOfMatrices];

int i;
int j;

printf("Input elements of matrix 1: \n");
for (i = 0; i < sizeOfMatrices; i++) {
    for (j = 0; j < sizeOfMatrices; j++){
    scanf("%i", matrix1[i][j]);
    clearBuffer();
    }
}


printf("Input elements of matrix 2: \n");
for (i = 0; i < sizeOfMatrices; i++) {
    for (j = 0; j < sizeOfMatrices; j++){
    scanf("%i", matrix2[i][j]);
    clearBuffer();
    }
}





return 0;
}