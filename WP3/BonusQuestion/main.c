#include <stdio.h> // Includes necessary libraries
#include <string.h>


int main(){

int depthOfMatrices, widthOfMatrices;

printf("Input the size: \n");

scanf("%i%i", &depthOfMatrices, &widthOfMatrices);

if ((depthOfMatrices == 1) && (widthOfMatrices == 1) ){
    printf("invalid");
    return 0;
}

int matrix1[depthOfMatrices][widthOfMatrices]; 
int matrix2[depthOfMatrices][widthOfMatrices]; 
int sumOfMatrices[depthOfMatrices][widthOfMatrices];

int i;
int j;

printf("Input elements of matrix 1: \n");
for (i = 0; i < depthOfMatrices; i++) {
    for (j = 0; j < widthOfMatrices; j++){
    if ((scanf("%i", &matrix1[i][j])) != 1){
        printf("invalid\n");
        return 0;
    }
    }
}

printf("Input elements of matrix 2: \n");

for (i = 0; i < depthOfMatrices; i++) {
    for (j = 0; j < widthOfMatrices; j++){
    if ((scanf("%i", &matrix2[i][j])) != 1){
        printf("invalid\n");
        return 0;
    }

    }
}

printf("The sum is: \n");
for (i = 0; i < depthOfMatrices; i++){
    for(j = 0; j < widthOfMatrices; j++){
    sumOfMatrices[i][j] = (matrix1[i][j] + matrix2[i][j]); 
    printf("%d ", sumOfMatrices[i][j]);
    }
    printf("\n");
}



return 0;
}