// (C) __Erik Gabrielsson
// Work package 1
// WP1.4 Excersise
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define BIT1 0b1 // 00000001
/*
 Convert the validated decimal number into its binary representation.
 Format the output based on the required bit size.
 print the binary representation to standard output.
 -h Display a message explaning how to use the program.
 */
#define MAX_INPUT_LENGTH 21

typedef unsigned char byte;

int main(int argc, char *argv[])
{
    // Check if the user has provided the correct number of arguments in Command-line.
    // return XXX to indicate an error
    if (argc != 2)
    {
        printf("Error: argument missing.\n");
        return 1;
    }
    // Look for the help flag using string comparison.
    // If "-h" is found, a help message is displayed.
    // The 0 return indicates success.
    else if (strcmp(argv[1], "-h") == 0)
    {
        printf("This program converts a decimal 64-bit integer to binary.\n");
        return 0;
    }

    // Converts the Command line argument string into a long integer.
    char *endptr;

    unsigned long number = strtoul(argv[1], &endptr, 10);

    int bit_number = 8;

    if (number > 255) // CHange to UINT8_MAX
        bit_number = 16;
    if (number > 65535)
        bit_number = 32;
    if (number > 4294967295)
        bit_number = 64;

    for (int i = bit_number - 1; i >= 0; i--)
    {
        // Print each bit by shifting and masking
        printf("%lu", (number >> i) & BIT1);
    }
    printf("\n");

    return 0;
}