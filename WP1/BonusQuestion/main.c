#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BIT1 1UL //  (64 long)

int main(int argc, char *argv[]) {

    if (argc != 2){
    printf("Error: No number provided. Please provide a number as a command line argument.");
    return 0;
    }

    int i = 1;
    for (int j = 0; argv[i][j] != '\0'; j++)
    {
        if ((argv[i][j] < '0') || (argv[i][j] > '9'))
        {
            printf("Error: invalid number.\n");
            return 0;
        }
    }


unsigned long number = atol(argv[1]);

int bit_number;

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

int number_of_1s = 0;
int number_of_0s = 0;

printf("Binary: 0b");

bool found_most_significant_number = false;

 for (int i = bit_number - 1; i >= 0; i--)
    {
        // Print each bit by shifting and masking
      if (((BIT1 << i) & (number)) != 0){
        printf("1");
        number_of_1s++;
        found_most_significant_number = true;

      } else if (found_most_significant_number == true) {
        printf("0");
        number_of_0s++;
      }
    }

    

printf("\n"); // New line

printf("Number of 0s: %d\n", number_of_0s);
printf("Number of 1s: %d\n", number_of_1s);


return 0;

}