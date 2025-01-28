#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100 // Defines the maximum number of the values in the table
#define MAXNUMBER 20 // Defines the maximum value of random numbers



// This function generates a set of random numbers
// and fills the table *tab with these numbers
void create_random(int *tab ) {
    for (int i=0; i <MAX; i++){
        tab[i] = rand() % MAXNUMBER;
    }
}



// This function takes the *tab of random numbers
// and creates a table with the frequency counts for these numbers
void count_frequency(int *tab, int *freq ){
    //This loop makes sure that there are no garbage values stored in freq[].
    for (int i= 0; i < MAXNUMBER; i++ ){
        freq[i] = 0;
    }
    //This loop get the value of each address in the tab array and increaments the given value 
    // by 1 each itteration, and stores it in the freq array.
    for (int i = 0; i < MAX; i++){
        int number = tab[i];
        freq[number]++;
    }
}


// This function takes the frequency count table
// and draws a histogram of the values in that frequency table
void draw_histogram(int *freq ){

    for (int i= 0; i < MAXNUMBER; i++){
        if (freq[i] > 0){
            printf("%d   ", i);
            for (int j = 0; j< freq[i]; j++){
            printf("x");
            }
        printf("\n");
        }

    }
}

// ------ Function definitions ----------
// ------ Main --------------------------
// The main entry point for the program
//
// If you choose to go for the optional part
// Please modify it accordingly
int main (void){
srand(time(NULL));



int table[MAX], n ;
int frequency[MAXNUMBER];

create_random(table);

 printf("Generated Random Numbers:\n");
    for (int i = 0; i < MAX; i++) {
        printf("%d ", table[i]);
        if ((i + 1) % 10 == 0) { // Print a newline every 10 numbers for readability
            printf("\n");
        }
    }
    printf("\n");

count_frequency(table, frequency);
draw_histogram(table);

printf("%d", table);

return 0;

}





