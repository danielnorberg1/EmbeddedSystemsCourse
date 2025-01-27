#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ALPHABET_LENGTH 26
#define MAX_LENGTH 100

int main(int argc, char *argv[]){

int numberCharachterShift = atoi(argv[1]);

printf("Please write your sentence: ");

char text[MAX_LENGTH];

fgets(text, MAX_LENGTH, stdin);

printf("%s \n", text);

for (int i=0; text[i]; i++){
    char charachter = text[i];
    printf("%c \n", charachter);

    if (charachter >= 'A' && charachter <= 'Z'){
        charachter = 'A' + ((charachter - 'A' + numberCharachterShift) % ALPHABET_LENGTH);

     } else if (charachter >= 'a' && charachter <= 'z'){
        charachter = 'a' + ((charachter - 'a' + numberCharachterShift) % ALPHABET_LENGTH);
    }
    text[i] = charachter;
}




return 0;


}