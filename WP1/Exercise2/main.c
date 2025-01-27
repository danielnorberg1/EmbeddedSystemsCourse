#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ALPHABET_LENGTH 26
#define MAX_LENGTH 100


int main(int argc, char *argv[]){

int numberCharachterShift = atoi(argv[1]);
char text[MAX_LENGTH];

printf("Please write your sentence: \n");

while (fgets(text, MAX_LENGTH, stdin)) {

printf("Please write your sentence: \n");

for (int i=0; text[i]; i++){
    char charachter = text[i];

    if (charachter >= 'A' && charachter <= 'Z'){
        charachter = 'A' + ((charachter - 'A' + numberCharachterShift) % ALPHABET_LENGTH);

     } else if (charachter >= 'a' && charachter <= 'z'){
        charachter = 'a' + ((charachter - 'a' + numberCharachterShift) % ALPHABET_LENGTH);
    }
    text[i] = charachter;
}


printf("%s \n", text);

}

return 0;


}