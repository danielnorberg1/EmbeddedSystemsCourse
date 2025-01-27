#include <stdlib.h>
#include <stdio.h>

#define MAX_NUMBER 100


int main(){

int randomNum = (rand() % MAX_NUMBER) + 1;
char userInput;
int timesGuessed = 0;

printf("Guess a number between 0-100: \n");


while(fgets(&userInput, MAX_NUMBER, stdin)){
    timesGuessed++;

  printf("%i", timesGuessed);


}



return 0;

}