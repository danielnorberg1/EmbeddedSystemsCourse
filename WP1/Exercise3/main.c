#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100
#define MAX_NUMBER 10


int main(){
srand(time(NULL));



int randomNum = rand() % 101;
char guess;
int timesGuessed = 0;
char input[MAX_LENGTH+1];


printf("Guess a number between 0-100: \n");

fgets(&input, MAX_LENGTH, stdin);
guess = atoi(&input); 


while(timesGuessed < MAX_NUMBER){
    timesGuessed++;

    if ((guess > randomNum) && (guess < 101) && (guess > -1)) {
        printf("Your guess is to high\n");

    } else if ((guess < randomNum) && (guess < 101) && (guess > -1)){
        printf("Your guess is to low\n");

    } else {
        printf ("You have guessed %i times and your guess is correct!\n", timesGuessed);
        break;
    }

    printf("Guess a number between 0-100: \n");
    fgets(&input, MAX_LENGTH, stdin);
    guess = atoi(&input); 

}





return 0;

}
