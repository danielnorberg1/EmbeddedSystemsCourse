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

void move(ROBOT *robot)
{
    switch (robot->dir)
    {
    case N:
        if (robot->ypos < 99)
        {
            robot->ypos++;
        }
        break;
    case O:
        if (robot->xpos < 99)
        {
            robot->xpos++;
        }
        break;
    case S:
        if (robot->ypos > 0)
        {
            robot->ypos--;
        }
        break;
    case W:
        if (robot->xpos > 0)
        {
            robot->xpos--;
        }
        break;
    }
}

void turn(ROBOT *robot)
{
    robot->dir = (robot->dir + 1) % 4;
}

int main()
{
    ROBOT myRobot;
    char command[64];

    while (1)
    {
        printf("Enter starting possition x and y or -1 to exit: \n");
        while (scanf("%i %i", &myRobot.xpos, &myRobot.ypos) != 2){
            printf("Invalid input. Please enter two integers: \n");

            while (getchar() != '\n'){
                ;
            }
        }
        if ((myRobot.ypos == -1) || (myRobot.xpos == -1) )
            {
                printf("You have exited the program\n");
                return 0;
            }

        while ((myRobot.xpos > 99 || myRobot.xpos < 0) || (myRobot.ypos > 99 || myRobot.ypos < 0) ) 
        {   printf("The coordinates need to be in the range 0-99\n");
            printf("Enter starting possition x and y or -1 to exit: \n");

            while (scanf("%i %i", &myRobot.xpos, &myRobot.ypos) != 2){
                printf("Invalid input. Please enter two integers: \n");
    
                while (getchar() != '\n'){
                    ;
                }
            }

    
            if ((myRobot.ypos == -1) || (myRobot.xpos == -1))
            {
                printf("You have exited the program\n");
                return 0;
            }

            
            scanf("%i %i", &myRobot.xpos, &myRobot.ypos);
        }
    

        // Sets thbe robot direction to North
        myRobot.dir = N;

        // Prints the possition of x and y
        printf("%i %i\n", myRobot.xpos, myRobot.ypos);

      
       
            printf("Please enter the command line, m's for move, and t's for turn and -1 for exit:\n");
            scanf("%s", command);


            if (strcmp(command, "-1") == 0){
                printf("You exited the program\n");
                return 0;
            }

        int valid = 0;

        while (!valid){
            for (int i = 0; command[i] != '\0'; i++){
                if (command[i] != 'm' && command[i] != 't'){
                    valid = 0;
                    printf("Please only enter m's or t's\n");
                    scanf("%s", command);
                }
                valid = 1;
            }

        }

        for(int i = 0; command[i] != '\0'; i++){
            switch (command[i])
            {
            case 'm':
                move(&myRobot);
                break;
            case 't':
                turn(&myRobot);
                break;
            }
        }
        printf("Robots possition is: x = %d y = %d - Direction: ", myRobot.xpos, myRobot.ypos);
        switch (myRobot.dir){
            case N:
                printf("North\n");
                break;
            case O:
                printf("East\n");
                break;
            case S:
                printf("South\n");
                break;
            case W:
                printf("West\n");
                break;

        }
    }

    return 0;
}