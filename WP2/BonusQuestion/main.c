#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR 7

enum days
{
    Monday = 1,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

int main()
{

    int week;

    int today;

    scanf("%d", &week);
    if ((week < 1) || (week > 5)){
        printf("invalid week\n");
        return 0;
    }

    while (getchar() != '\n');



    scanf("%d", &today);
    if ((today < 1) || (today > 7)){
        printf("invalid day\n");
        return 0;
    }


   


    while (week < 6)
 {
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
    if (today == 7){
        today = 0;
        week++;
    }   
    today++;


     sleep(1);
    }

    return 0;
}