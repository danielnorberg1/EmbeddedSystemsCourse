#include <stdio.h> // Includes necessary libraries
#include <string.h>


int main(){

int depthOfMatrices, widthOfMatrices;

printf("Input the size: \n");

scanf("%i%i", &depthOfMatrices, &widthOfMatrices);





int matrix1[depthOfMatrices][widthOfMatrices]; 
int matrix2[depthOfMatrices][widthOfMatrices]; 
int sumOfMatrices[depthOfMatrices][widthOfMatrices];

int i;
int j;

printf("Input elements of matrix 1: \n");
for (i = 0; i < depthOfMatrices; i++) {
    for (j = 0; j < widthOfMatrices; j++){
    scanf("%i", &matrix1[i][j]);
    }
}


printf("Input elements of matrix 2: \n");
for (i = 0; i < depthOfMatrices; i++) {
    for (j = 0; j < widthOfMatrices; j++){
    scanf("%i", &matrix2[i][j]);
    
    }
}

printf("The sum is: \n");
for (i = 0; i < depthOfMatrices; i++){
    for(j = 0; j < widthOfMatrices; j++){
    sumOfMatrices[i][j] = (matrix1[i][j] + matrix2[i][j]); 
    printf("%d\n", sumOfMatrices[i][j]);
    }

}



return 0;
}