#include <stdio.h> // Includes necessary librarys
#include <string.h>



// Initialize enum for the direction of the robot.
enum DIRECTION
{
    N,
    O,
    S,
    W
};

typedef struct
{
    int xpos;
    int ypos;
    enum DIRECTION dir;
} ROBOT;

void move(char * xpos)
{
}

void turn(char * xpos)
{
}

int main()
{

    ROBOT myRobot;
    char input;

    printf("Enter starting possition x, y: ");

    scanf("%i %i", &myRobot.xpos, &myRobot.ypos);
    if ((myRobot.xpos > 99 || myRobot.xpos < 0) || (myRobot.ypos > 99 || myRobot.ypos < 0))
    {
        printf("The coordinates need to be in the range 0-99\n");
        return 0;
    }

    printf("%i %i\n", myRobot.xpos, myRobot.ypos);

    printf("Please enter m for move in current direction or t for turn of direction");

    scanf("%c", &input);

    while ((strcmp(&input, "m") == 0) || (strcmp(&input, "t") == 0))
    {
        scanf("%c", &input);
        printf("Please enter m or t");
    }

    return 0;
}