#include <unistd.h> // Includes necessary libraries
#include <stdio.h>
#include <stdlib.h>


// Creates the enum list of weekdays 
enum days
{
    Monday = 1, // Setting monday at 1 so the user types 1 instead of default 0
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

// This program takes input of day and week from the user and
// check the inputs value and matches it to corresponding week/day.
// It then gets printed each second while its being incremented.
int main()
{

    int week; // Initialize week integer

    int today; // Initialize today integer

 
    scanf("%d", &week);   // Takes input from the user and stores it in week
    if ((week < 1) || (week > 5)){ // Checks if the input is between 1 and 5
        printf("invalid week\n"); // Prints error message if it is not
        return 0; // Returns 0 and stops the program if its invalid.
    }

    while (getchar() != '\n'); // Clear the buffer from \n



    scanf("%d", &today); // Takes the input from the user and stores it in today
    if ((today < 1) || (today > 7)){ // Checks if the input is between 1 and 7
        printf("invalid day\n"); // Prints error message if its not
        return 0; // Returns 0 and stops the program if its invalid
    }


   

// This while loops runs until week 5 and includes the switch case
// for the enum list. 
// At the bottom it increments week and day each iteration and has a 1 second delay.
    while (week < 6)
 {
    // This switch statements takes the value of today and matches it with
    // the correspondin enum (monday through sunday)
    // depending on the day it prints the day along with the week.
        switch (today)
        {
        case Monday:
            printf("Week %d, Monday\n", week);
            break;
        case Tuesday:
            printf("Week %d, Tuesday\n", week);
            break;
        case Wednesday:
            printf("Week %d, Wednesday\n", week);
            break;
        case Thursday:
            printf("Week %d, Thursday\n", week);
            break;
        case Friday:
            printf("Week %d, Friday\n", week);
            break;
        case Saturday:
            printf("Week %d, Saturday\n", week);
            break;
        case Sunday:
            printf("Week %d, Sunday\n", week);
            break;

        default:
            return 0;
        }

    // When today becomes 7 (sunday) it will be resetted to monday.
    // Here we also increment week so that the week increments when a week has gone.
    if (today == 7){
        today = 0; // Set it at 0 (not 1 (monday)) since it gets incremented below to 1.
        week++;
    }   
    today++; // Increments the day after each itteration.


     sleep(1); // This function add the one second delay so that the while loop updates once a second
    }

    return 0; // Returs 0 meaning the program was a success and exits.
}