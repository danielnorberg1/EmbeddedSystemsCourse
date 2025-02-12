#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHARACTERS 10



void swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}



// Main function of the program
int main(int argc, char * argv[]){

    if (argc != 2){
        printf("Must enter a argument");
        return 1;
    }

    if (strlen(argv[1]) > MAX_CHARACTERS){
        printf("The argument cannot exceed 10 charachters.");
        return 1;
    }


    



    return 0;
}