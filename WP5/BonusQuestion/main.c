#include <stdio.h>  // Including necessary libraries
#include <stdlib.h>
#include <string.h>

/*
This program packs 5 arguments in a byte and prints
it as a hexadecimal form. Before packing it checks that
the arguments are valid (each argument length of 1,
only integers and max 5 of them). The users chooses the
values of the bits which the program uses bit operations to
finally pack into the last byte for faster future executions.
*/
int main(int argc, char *argv[]){

// Checks that the user has provided enough aruments
// in this case 6 including.
if (argc != 6){
    printf("invalid");
    return 0;
}

// These for loops controls that the
// length of each argument dont exceed
// 1 and it also checks that the
// input is between  0 and 9
for (int i = 1; i < 6; i++){
    if (strlen(argv[i]) > 1){ // Compares the length of argv at i to 1
        printf("invalid"); // prints
        return 0; // exits
    }
// this if statement checks that argv at i is between 0 and 9
     if (*argv[i] < '0' || *argv[i] > '9'){ // Checks that the integer value of the argument is 0-9
            printf("invalid"); // prints
            return 0; // exits
        }
    
}

// Here we converts the argument from characther to
// integer and stores it in an int
int engine_on = atoi(argv[1]);
int floor_pos = atoi(argv[2]);
int door_pos = atoi(argv[3]);
int brake1 = atoi(argv[4]);
int brake2 = atoi(argv[5]);



// Here we validate the arguments so that they
// are within the correct range.

// The bit size for engine_on should be one
// meaning either 0 or 1.
if (engine_on < 0 || engine_on > 1){ 
    printf("invalid");
    return 0;
}
// When the bit size is 3 the value can be 7
// therefore we need to check between 0 and 7.
if (floor_pos < 0 || floor_pos > 7 ){
    printf("invalid");
    return 0;
}
// Here the bit size is 2 so we need to check for 0-2
if ( door_pos < 0 || door_pos > 2 ){
    printf("invalid");
    return 0;
}
// Same as the first one either on or of (0-1)
if (brake1 < 0 || brake1 > 1){
    printf("invalid");
    return 0;
}
// same as above
if ( brake2 < 0 || brake2 > 1){
    printf("invalid");
    return 0;
}


// Each value is stores in a 8 bit usnigned char.
// meaning all bits are initially 0.
// We use the bitwise operation OR to pack the values into
// single byte. Then we uses the bitshift operators to 
// Place the values in the correct possition.
// The correct position is determined on the position
// value in the byte.
unsigned char packed_byte = 0;
// Here we shift the possition of the value of engine_on
// if engine is on (engine_on = 1) then it is compared
// to the original packed_byte 0000000'0' and then 
// placing it 7 steps left so the outcome is '1'0000000 
packed_byte |= (engine_on << 7);
// The same happends with the rest of the bit operations
// but with a difference that floor_pos = 3 bits 
// and door_pos = 2 bits. So when placing the bits
// floor_pos needs 3 less steps because of that
// and door_pos 2 less steps-
packed_byte |= (floor_pos << 4); 
packed_byte |= (door_pos << 2);
packed_byte |= (brake1 << 1);
packed_byte |= (brake2 << 0);

// This formats the packed byte and prints it.
printf("0x%02X\n", packed_byte);
return 0;




}