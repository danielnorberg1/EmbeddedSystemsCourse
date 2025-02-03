#include <stdbool.h> // Includes necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// This defines the bit that is then used to compare the number and determine
// if a 0 or 1 should be printed. (It is 64 long)
#define BIT1 1UL 

// This program first checks that there are two arguments and that there
// only are decimals and no charachters.
// It then assignes the the bit size depending on how big the decimal number is.
// It compares the chosen bit size lets say 8 (00000001) and prints a 0 or 1 depending
// if the bit also has a 0 or 1 at the same place.
// The program also counts how many 0 and 1 being printed.
// The final pourpuse is to have a print outcome of Number (entered), Binary version of it and then
// the number of 0's and 1's.
int main(int argc, char *argv[]) {


   
    if (argc != 2){  //  Checks that there is 1 argument other that the program name.
    printf("Error: No number provided. Please provide a number as a command line argument."); // Prints error message if not.
    return 0; // Returns o and exits if the program does not have the argument
    }

    int i = 1; // Initialize i.
    // This for loop goes thourgh every charachter (j) in argument i.
    // Since there is only 1 expected argument we set i at one therefore checking i.
    for (int j = 0; argv[i][j] != '\0'; j++)
    {
        if ((argv[i][j] < '0') || (argv[i][j] > '9')) // Checks if argument is between the wanted 0-9.
        {
            printf("Error: invalid number.\n"); // Error statements if it is not.
            return 0; // Returns if not and exits.
        }
    }


unsigned long number = atol(argv[1]); // Converts the argument that is charachter into long.

int bit_number; // Initialize bit_number

// If statements to check the size of the decimal
// depending on the size of the decimals it sets the corresponding bit_number.
if (number <= UINT8_MAX){
    bit_number = 8;
} else if (number <= UINT16_MAX){
    bit_number = 16;
} else if (number <= UINT32_MAX){
    bit_number = 32;
} else {
    bit_number = 64;
}

printf("Number: %ld\n", number); // Prints decimal number

// Initializes variables that hold the number of 1's and 0's
int number_of_1s = 0;
int number_of_0s = 0;

printf("Binary: 0b"); // Prints the 0b so that the binary string gets formated correctly

// Initialize bool to false so that when the most significant number is 
// found we can set it to true.
bool found_most_significant_number = false; 

// This for loop compares the bit size that is defined
// with the decimal number and if both numbers are equal (&)
// it then prints that number.
// It also counts the number of 1's and 0's.
 for (int i = bit_number - 1; i >= 0; i--) // Itterates thourgh the size of the bit_number backwards.
    {
        // Print each bit by shifting and masking
      if (((BIT1 << i) & (number)) != 0){ // If the shifted bit and the number has 1 it gets printed.
        printf("1"); // Prints the 1's
        number_of_1s++; // Increments number of 1's
        found_most_significant_number = true; // Sets true so that the 0's can start being printed

      } else if (found_most_significant_number == true) { // If the most significant number is found it prints 0's to prevent all 0's being printed.
        printf("0"); // Prints the 0's
        number_of_0s++; // Increments number of 0's
      }
    }

    

printf("\n"); // New line

printf("Number of 0s: %d\n", number_of_0s); // Prints the number of 0's
printf("Number of 1s: %d\n", number_of_1s); // Prints the number of 1's


return 0; // Returns 0  as success message and exist

}