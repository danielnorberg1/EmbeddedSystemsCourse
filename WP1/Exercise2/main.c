#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100

int main(int argc, char *argv[]){



printf("Please write your sentence: ");

char text[MAX_LENGTH];

fgets(text, MAX_LENGTH, stdin);

printf("%s \n", text);




return 0;


}