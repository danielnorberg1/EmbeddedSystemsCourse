// (C) __Erik Gabrielsson, Daniel Norberg, Lilly Heier
// Work package 2
// WP2E4B Exercise

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define ENGINE_ON_MASK (1 << 7) // Bit 7 (MSB)

int hex_validator(const char *str)
{
    int len = strlen(str);

    // Must be 1 or 2 characters (valid hex digits)
    if (len < 1 || len > 2)
    { // Check if the length is within the range of 1-2
        return 0;
    }
    for (int i = 0; i < len; i++)
    {
        char c = str[i];
        // Check if character is between is a digit or a valid letter using ASCII values.
        if (!((c >= '0' && c <= '9') ||
              (c >= 'A' && c <= 'F') ||
              (c >= 'a' && c <= 'f')))
        {
            return 0;
        }
    }
    return 1; // Return 1 if the input is a valid hex value.
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Error: Wrong number of arguments provided");
        return 1;
    }

    // Using the previously created function we validate the hex input.
    if (!hex_validator(argv[1]))
    {
        printf("Error: Invalid hexadecimal input.\n"); // Inform that it is not valid.
        return 1;
    }

    // Declare an unsigned char to store the packed byte.
    // Using strtol we convert the argument to an unsigned char.
    // This allows us to use the bitwise operators on the byte.
    unsigned char packed_byte = (unsigned char)strtol(argv[1], NULL, 16); // takes argument 1, null and a base of 16.

    // We cast the packed byte to an integer so that we can extract the values.
    // We then perform bitwise operators depending on the position of the value in the 8-bit byte.
    // engine_on is a single-bit value stored at bit 7. We extract bit 7 by left shifting 1 by 7 places.
    // We then apply the mask with packed_byte &, extracting only the bits we are interested in.
    // We then right shift the bits to the rightmost position to get the value.
    // This gives us the correct integer value.
    int engine_on = (packed_byte & (1 << 7)) >> 7; // Extract bit 7        MSB
    int gear_pos = (packed_byte & (7 << 4)) >> 4;  // Extract bits 4-6
    // Since 3 bits is needed to store 4 we need to check that it does not exeed that since 3 bits can be 7 aswell.
    if (gear_pos > 4) {
        printf("Error: gear_pos out of allowed range (0-4).\n");
        return 1; 
    }
    int key_pos = (packed_byte & (3 << 2)) >> 2;   // Extract bits 2-3
    int brake1 = (packed_byte & (1 << 1)) >> 1;    // extract bit 1
    int brake2 = (packed_byte & (1 << 0)) >> 0;    // extract bit 0        LSB

    // Print unpacked values
    printf("Name        Value\n");
    printf("-----------------\n");
    printf("engine_on   %d\n", engine_on);
    printf("gear_pos    %d\n", gear_pos);
    printf("key_pos     %d\n", key_pos);
    printf("brake1      %d\n", brake1);
    printf("brake2      %d\n", brake2);
    return 0;
}
