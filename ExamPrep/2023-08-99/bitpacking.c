#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void move(unsigned long byte, int *jackPossition, int *bunnyPossition){

    int move = (byte >> 7) & 1;
    int direction = (byte >> 6) & 1;
    int multiplier = (byte >> 4) & 3;
    int steps = byte & 15;

    int stepsMoved = steps*multiplier;
    if (direction == 0){
        stepsMoved -= stepsMoved;
    }

    
    printf("%d\n", byte);
    printf("%d\n", move);
    printf("%d\n", direction);
    printf("%d\n", multiplier);
    printf("%d\n", steps);

}

int main(){

srand(time(NULL));
int jackPossition = 0;
int bunnyPossition = 0;
unsigned long byte;

printf("Welcome to the game Bunny and Jack!\n");

for (int i = 0; i < 1; i++){
    

    // printf("Bunny moves");


   // printf("Jack moves");
    byte = rand() % 256;
    move(byte, &jackPossition, &bunnyPossition);

}



}