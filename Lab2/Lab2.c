#include <stdio.h>

int viewStats();
void enterStats(int *statsArray);
int computeStats();
int resetStats();

int main()
{
    char userChoice = 'e';
    int statsArray[10];

    while (userChoice != 'q')
    {
        printf("\nVECRQ? ");
        scanf(" %c", &userChoice);

        switch (userChoice)
        {
        case 'v':
            printf(" %c ", userChoice);

            break;
        case 'e':
            enterStats(statsArray);
            break;
        case 'c':
            printf(" %c ", userChoice);

            break;
        case 'r':
            printf(" %c ", userChoice);

            break;
        case 'q':
            printf("\nExiting ", userChoice);

            break;
        default:
            printf("\nWrong input try again ");
            break;
        }
    }

    return 0;
}

void enterStats(int *statsArray)
{
    int amountOfMeasurements = 0, newMeasurement = 0;

    while (amountOfMeasurements < 10)
    {
        printf("\nEnter measurement #%d (or 'q' to quit): ", (amountOfMeasurements + 1));
        scanf("%d", &newMeasurement);
        printf("\nd= %d", newMeasurement);
        printf("\nc= %c", newMeasurement);

        char temp = newMeasurement + '0';
        printf("\nd= %d", temp);
        printf("\nc= %c", temp);

        if (temp == 'q')
        {
            printf("%d", newMeasurement);
            printf("Exiting");

            break;
        }
        else
        {
            printf("Inputting");

            statsArray[amountOfMeasurements] = newMeasurement;
            amountOfMeasurements++;
        }
    }

    for (int counter = 0; counter < amountOfMeasurements; counter++)
    {
        printf("%d ", statsArray[counter]);
    }
}
