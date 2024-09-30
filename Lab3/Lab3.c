#include <stdio.h>

struct patient
{
    int personalID;
    char name[20];
    int pictures[10];
};
typedef struct patient Patient;

main()
{

    int userChoice = 0;

    while (userChoice != 7)
    {
        printf("Main menu\n");
        printf("\t1) Register new patients\n");
        printf("\t2) Print all patients\n");
        printf("\t3) Look for patient\n");
        printf("\t4) Add pictures\n");
        printf("\t5) Sort patients\n");
        printf("\t6) Deregister patient\n");
        printf("\t7) Exit program\n");
        printf("Enter choice: ");

        scanf("%d", &userChoice);

        switch (userChoice)
        {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;

        default:
            break;
        }
    }

    return 0;
}