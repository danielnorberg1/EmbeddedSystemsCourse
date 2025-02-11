// (C) __Erik Gabrielsson, Daniel Norberg, Lilly Heier
// Work package 2
// WP2E4A Exercise

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* The program packs values in a byte, and prints it out to the console
in hexadecimal form. After printing out the program exits.
We have engine_on, gear_pos, key_pos, brake1, and brake2 as arguments.
The user prompts 5 values as arguments to fill these positions.

*/
#define ARG_AMOUNT 5 // Amount of arguments, no more or less.

int input_validator(const char *str, int min, int max)
{
    for (int i = 0; str[i] != '\0'; i++) // Loop through the string argument.
    {
        if (str[i] < '0' || str[i] > '9') // Check if the character is a digit, using ASCII values.
            return -1;                    // Return -1 if it is not a digit.
    }

    int value = atoi(str); // Convert the string to an integer.
    if (value >= min && value <= max)
    {                 // Check if the value is within accepted range of min and max.
        return value; // Return the value if yes.
    }
    else
    {
        return -1;
    } // Otherwise we return -1 to indicate an error.
}

int main(int argc, char *argv[])
{
    // Ensure the program is called with exactly 5 arguments (excluding program name)
    if (argc != 6)
    {
        printf("Error: Wrong number of arguments. Provide 5.\n");
        return 1;
    }

    // cast the arguments to integers using the atoi function.
    int engine_on = atoi(argv[1]); // MSB
    int gear_pos = atoi(argv[2]);
    int key_pos = atoi(argv[3]);
    int brake1 = atoi(argv[4]);
    int brake2 = atoi(argv[5]); // LSB

    // Validate the arguments from command line, so that they are within the correct range.
    engine_on = input_validator(argv[1], 0, 1); // Engine_on is a single bit value, so it can only be 0 or 1.
    if (engine_on == -1){   // Check if the inpiut validator has returned 
        printf("Invalid engine_on value");
        return 1;
    }
    gear_pos = input_validator(argv[2], 0, 4); // Gear_pos uses 3bits, so it can be 0-4.
    if (gear_pos == -1){
        printf("Invalid gear_pos value");
        return 1;
    }
    key_pos = input_validator(argv[3], 0, 2); // Key_pos uses 2bits, so it can be 0-2.
    if (key_pos == -1){
        printf("Invalid key_pos value");
        return 1;
    }
    brake1 = input_validator(argv[4], 0, 1); // Brake1 is a single bit value, so it can only be 0 or 1.
    if (brake1 == -1){
        printf("Invalid brake1 value");
        return 1;
    }
    brake2 =input_validator(argv[5], 0, 1); // Same as brake1.
    if (brake2 == -1){
        printf("Invalid brake2 value");
        return 1;
    }

    /*
    Each value is stores in an 8-bit unsigned char.
    Below we use the bitwise OR operator to pack said values
    into one single byte. Then we use bitshift operators to
    place the values in the correct position. The correct position depends
    on the position of the value in the byte.
    */
    unsigned char packed_byte = 0;
    packed_byte |= (engine_on << 7); // 1-bit shift for engine_on (bit 7)
    packed_byte |= (gear_pos << 4);  // 3-bit shift for gear_pos (bit 4-6)
    packed_byte |= (key_pos << 2);   // 2-bit shift for key_pos (bit 2-3)
    packed_byte |= (brake1 << 1);    // 1-bit shift for brake1 (bit 1)
    packed_byte |= (brake2 << 0);    // 1-bit shift for brake2 (bit 0)
    printf("%02X\n", packed_byte);
    return 0;
}
