#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void simulateMove(unsigned char byte, int *bunnyPos, int *jackPos){



    // 0000000

    int mover = (byte >> 7) & 1;

    int direction = (byte >> 6) & 1;

    int multiplier = (byte >> 4) & 3;

    int steps = byte & 15;

    int moveAmount = steps * multiplier;

    if (direction == 0){
        moveAmount = -moveAmount;   
    } 

    if (mover == 1){
        *bunnyPos += moveAmount;
    } else  {*jackPos += moveAmount;
    }   



}

// This program 
int main(){

    srand(time(NULL));
    int bunnyPos = 0;
    int jackPos = 0;
    unsigned char byte;

    printf("Welcome to the game");

    for (int i=0; i < 10; i++){

        byte = rand() % 256;
        printf("Bunny draws byte");
        simulateMove(byte, &bunnyPos, &jackPos);

        byte = rand() % 256;
        printf("Jack draws byte");
        simulateMove(byte, &bunnyPos, &jackPos);

        printf("Jack's possition after round 1: %d", jackPos);
        printf("Bunnys's possition after round 1: %d", bunnyPos);


    }

    if (bunnyPos > jackPos){
        printf("Bunny won");
    } else if (jackPos > bunnyPos){
        printf("Jack won!");
    } else {
        printf("It is a tie!");
    }

   return 1;

}