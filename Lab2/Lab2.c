#include <stdio.h>

int viewStats();
int enterStats(int *statsArray, int amountOfMeasurements);
int computeStats();
int resetStats();

int main()
{
    char userChoice = 'e';
    int statsArray[10], amountOfMeasurements = 0;

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
            amountOfMeasurements = enterStats(statsArray, amountOfMeasurements);
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

int enterStats(int *statsArray, int amountOfMeasurements)
{
    char newMeasurement = 0;

    while (amountOfMeasurements < 10)
    {
        printf("\nEnter measurement #%d (or 'q' to quit): ", (amountOfMeasurements + 1));
        scanf(" %c", &newMeasurement);
        printf("\nmeasurement d= %d", newMeasurement);
        printf("\nmeasurement c= %c", newMeasurement);

        int temp = newMeasurement - '0';
        printf("\ntemp d= %d", temp);
        printf("\ntemp c= %c", temp);

        if (newMeasurement == 'q')
        {
            printf("%d", newMeasurement);
            printf("\nExiting e");

            break;
        }
        else
        {
            printf("\nInputting %d", temp);

            statsArray[amountOfMeasurements] = temp;
            amountOfMeasurements++;
        }
    }

    if (amountOfMeasurements == 10)
    {
        printf("\nYou already have 10 measurements!");
    }

    for (int counter = 0; counter < amountOfMeasurements; counter++)
    {
        printf("%d ", statsArray[counter]);
    }

    return amountOfMeasurements;
}
