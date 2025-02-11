// (C) __Erik Gabrielsson, Daniel Norberg, Lilly Heier
// Work package 2
// WP2E3 Exercise

// Include Section
#include <stdio.h>
#include <string.h>

/*
This program presnets the user with 4 options/subroutines.
The first option is to create a new file and write a record to it.
The second is to add a new person to the file.
The third is to search for a specific person in the file.
The fourth is to print all records in the file.
And the last one simply exits the program.
 */
#include <stdlib.h>
#include <stdio.h>

// -----typedefs -------
typedef struct
{
    char firstname[20];
    char famname[20];
    char pers_number[13]; // yyyymmddnnnn
} PERSON;
// Function declaration (to be extend)
PERSON input_record(void)
{
    PERSON new_person; // Initialize a new person
    printf("Enter the first name: ");
    fgets(new_person.firstname, 20, stdin);
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
    if (new_person.firstname > 20 ){
        printf("Wrong");
    }
    printf("Enter the family name: ");
    scanf("%s", new_person.famname);                              // Read the family name
    printf("Enter the personal number in yyyymmddnnnn format: "); // Read the personal number
    scanf("%s", new_person.pers_number);
    return new_person; // Return the new person so that it can be used.
} // Reads a person’s record.

/* The function write_new_file takes a pointer to a person struct as an argument.
It then creates a new file called persondb.bin and writes the record to the binary file.
The file is then closed to prevent memory leaks and a success message is printed.
*/
void write_new_file(PERSON *inp_record)
{
    remove("persondb.bin");                   // If an old file exists, remove it before writing.
    FILE *file = fopen("persondb.bin", "wb"); // Create a pointer to a file and open it in write binary mode.
    // Check if the file exists.
    if (!file)
    {
        printf("Error: Could not open file.\n");
        return; // Return if it does not eist.
    }

    fwrite(inp_record, sizeof(PERSON), 1, file); // Write the record to the file.
    fclose(file);                                // Close the file to prevent memory leaks.
    printf("File created and record written successfully.\n");
} // Creates a file and
// writes the first record
void printfile(void)
{
    FILE *file = fopen("persondb.bin", "rb"); // Open the binary file through a pointer.
    // Check if file exist.
    if (!file)
    {
        printf("Error: Could not open file.\n");
        return; // Return if it does not eist.
    }

    // Check if file is empty
    fseek(file, 0, SEEK_END); // Pointer is set to end of file using SEEK_END
    if (ftell(file) == 0)     // If the previously set pointer already is at start of file, it is empty.
    {
        printf("The file is empty.\n");
        fclose(file); // Close the file to prevent memory leaks.
        return;
    }
    fseek(file, 0, SEEK_SET); // Reset pointer

    PERSON person;                                  // Create a person struct to store the records.
    puts("Printing all person in file");            // Print an informative message.
    while (fread(&person, sizeof(PERSON), 1, file)) // Read the records from the file through address of operator to the person struct.
    {
        printf("First Name: %s, Family Name: %s, Personal Number: %s\n",
               person.firstname, person.famname, person.pers_number);
    }
    fclose(file); // Close the file to prevent memory leaks.
} // Prints out all persons in the file

void search_by_firstname(char *name)
{
    FILE *file = fopen("persondb.bin", "rb"); // Open the binary file through a pointer.
    if (!file)
    {
        printf("Error: Could not open file.\n");
        return; // Return if it does not eist.
    }

    // Check if file is empty
    fseek(file, 0, SEEK_END); // Pointer is set to end of file using SEEK_END
    if (ftell(file) == 0)     // If the previously set pointer already is at start of file, it is empty.
    {
        printf("The file is empty.\n");
        fclose(file); // Close the file to prevent memory leaks.
        return;
    }
    fseek(file, 0, SEEK_SET); // Reset pointer

    PERSON person;                                  // Create a person struct to store the records.
    while (fread(&person, sizeof(PERSON), 1, file)) // Read the records from the file through address of operator to the person struct.
    {
        if (strcmp(person.firstname, name) == 0) // Compare the first name of the person with the name input.
        {
            printf("First Name: %s, Family Name: %s, Personal Number: %s\n",
                   person.firstname, person.famname, person.pers_number);
        }
    }
    fclose(file); // Close the file to prevent memory leaks.
} // Prints out the person if
// in list
void append_file(PERSON *inp_record)
{
    FILE *file = fopen("persondb.bin", "ab"); // Open the binary file through a pointer.
    if (!file)
    {
        printf("Error: Could not open file.\n");
        return; // Return if it does not eist.
    }

    fwrite(inp_record, sizeof(PERSON), 1, file); // Write the record to the file.
    fclose(file);                                // Close the file to prevent memory leaks.
} // appends a new person to the file

int main(void)
{
    int input;
    PERSON dummy_person = {"Jimmy", "Neutron", "199901020123"};

    do
    {
        printf("\nMenu:\n"); 
        printf("1. Create new file\n");
        printf("2. Add a new person\n");
        printf("3. Search for a person\n");
        printf("4. Print all records\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &input);

        switch (input)
        {
        case 1:
            write_new_file(&dummy_person);
            break;
        case 2:
        {
            PERSON new_person = input_record();
            append_file(&new_person);
            break;
        }
        case 3:
        {
            char search_name[20];
            printf("Enter first name to search: ");
            scanf("%19s", search_name);
            search_by_firstname(search_name);
            break;
        }
        case 4:
            printfile();
            break;
        case 5:
            printf("Exiting program.\n");
            break; // Ensure loop ends correctly when input is 5
        default:
            printf("Invalid input.\n");
        }
    } while (input != 5); // The loop continues until the user enters 5
    return 0; // Return 0 to indicate success.
}
