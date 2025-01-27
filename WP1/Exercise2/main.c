#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ALPHABET_LENGTH 26
#define MAX_LENGTH 100


int main(int argc, char *argv[]){

//Assigns the second argument to numberCharachterShift 
// atoi converts it from characther to integer.
int numberCharachterShift = atoi(argv[1]);

char text[MAX_LENGTH];

printf("Please write your sentence: \n");

//Retrives argument from user with a maximum of MAX_LENGTH
// Performs algorithm until EOF is reached.
while (fgets(text, MAX_LENGTH, stdin)) {

printf("Please write your sentence: \n");

for (int i=0; text[i]; i++){

    char charachter = text[i]; // Assign text charachter at given [i] possition to charachter.
// Checks if charachter is Upper case
    if (charachter >= 'A' && charachter <= 'Z'){ 
// The charachter is shifted by the places in alphabet using the modolo operator and the given value.
        charachter = 'A' + ((charachter - 'A' + numberCharachterShift) % ALPHABET_LENGTH);

// Does the same as lines 29 to 31 but for lower case
     } else if (charachter >= 'a' && charachter <= 'z'){ 
        charachter = 'a' + ((charachter - 'a' + numberCharachterShift) % ALPHABET_LENGTH);
    }
    text[i] = charachter; // The text at [i] is assigned as charachter at [i].
}


printf("%s \n", text); // prints the text with encryption

}

return 0; // Returns 0 if program exits correctly

}