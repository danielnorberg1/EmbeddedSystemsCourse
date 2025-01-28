// (C) __Erik Gabrielsson, Daniel Norberg, Lilly Heier 292807
// Work package 1
// WP1.5 Excersise 

#include <stdio.h> //Includes necessary librarys
#include <stdlib.h>
#include <string.h>
#include <time.h>


// This function generates a set of random numbers and fills
// and uses rand() to create random numbers with the max input 
// of number of input and maxnumber restrain value between 0-19.
void create_random(int *tab, int max, int maxnumber ) {
    for (int i=0; i <max; i++){
        tab[i] = rand() % maxnumber;
    }
}



// This function takes the *tab of random numbers and creates
// a table with the frequency counts for these numbers depending on the
// maxnumber and the max
void count_frequency(int *tab, int *freq, int max, int maxnumber ){
    //This loop makes sure that there are no garbage values stored in freq[].
    for (int i= 0; i < maxnumber; i++ ){
        freq[i] = 0;
    }
    //This loop get the value of each address in the tab array and increaments the given value 
    // by 1 each itteration, and stores it in the freq array.
    for (int i = 0; i < max; i++){
        int number = tab[i];
        freq[number]++;
    }
}


// This function takes the frequency count table
// and draws a histogram of the values in that frequency table with the 
// input of the maxnumber to give the for loop the correct length.
void draw_histogram(int *freq, int maxnumber ){
// It itterates thorough every value from 0-19 and if the frequency of a value
// is > 0 it prints 1 x per frequence found.
    for (int i= 0; i < maxnumber; i++){
        if (freq[i] > 0){
            printf("%d   ", i);
            for (int j = 0; j< freq[i]; j++){
            printf("x");
            }
        printf("\n");
        }

    }
}


// ------ Main --------------------------
// The main entry point for the program
// The main program takes two arguments and checks if that there are 3 arguments total 
// included the ./main. It then converts the given arguments into integers so that
// when they are passed down into the functions they are the type that is asked for.
// Then the program creates the random table with "create_random" that gets read by "count_frequency"
// that adds the frequency of each value in the range of maxnumber. It then prints the 
// history with draw_histogram and the values are visualised with 1 x per frequency.
// At last it frees the memory allocation of frequency and table.
int main (int argc, char *argv[]){

// Checks that the input is 3 arguments including ./main
// if not it returs 1 to end the program.
if (argc != 3) {
    printf("You need to enter 2 arguments.");
    return 1;
}

int max = atoi(argv[1]); //Converts char argv[1] into integer
int maxnumber = atoi(argv[2]); // Converts char argv[2] into integer

//Initialize the time so that the random generated number is different each time.
srand(time(NULL)); 



// Defines the table array with a maximum number of values defined by
// argv[1] it is also a dynamic memory allocation so that the user have less limitation
// when creating the maxnumber of the values used.
int *table = malloc(max * sizeof(int));

// Defines frequency array with the maxium numnber value defiend by 
// argv[2] it is as above also dunamic memory allocation so that the user have less limitation
// when creating the max numbers of the program.
int *frequency = malloc(maxnumber * sizeof(int));

create_random(table, max, maxnumber); //Uses create random function
count_frequency(table, frequency, max, maxnumber); //Uses count frequency function
draw_histogram(frequency, maxnumber); // Uses draw histogram function

free(table); // Frees the memory allocation of table
free(frequency); // Frees the memory allocation of frequency


return 0; // Returns 0 if the program ran successfully

}





