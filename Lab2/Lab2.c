#include <stdio.h>
#include <string.h>
#include <math.h>

void viewMeasurements(int *measurementsArray, int amountOfMeasurements);
int enterMeasurements(int *measurementsArray, int amountOfMeasurements);
void computeMeasurements(int *measurementsArray, int amountOfMeasurements);
int findMaxMeasurement(int *copyArray, int amountOfMeasurements);
int findMinMeasurement(int *copyArray, int amountOfMeasurements);
float findAvrMeasurement(int *copyArray, int amountOfMeasurements);
void findNormalizedMeasurement(int *copyArray, int amountOfMeasurements);

int main()
{
    char userChoice = 'e';
    int measurementsArray[10], amountOfMeasurements = 0;
    printf("Measurement tool 2.0\n");

    while (userChoice != 'q')
    {
        printf("VECRQ? ");
        scanf(" %c", &userChoice);

        switch (userChoice)
        {
        case 'v':
            viewMeasurements(measurementsArray, amountOfMeasurements);
            break;

        case 'e':
            amountOfMeasurements = enterMeasurements(measurementsArray, amountOfMeasurements);
            break;

        case 'c':
            computeMeasurements(measurementsArray, amountOfMeasurements);

            break;

        case 'r':
            for (int counter = 0; counter < amountOfMeasurements; counter++)
            {
                measurementsArray[counter] = 0;
            }
            amountOfMeasurements = 0;

            break;

        case 'q':
            printf("Exit Measurement tool", userChoice);
            break;

        default:
            printf("Wrong input try again");
            break;
        }
    }

    return 0;
}

void viewMeasurements(int *measurementsArray, int amountOfMeasurements)
{
    if (amountOfMeasurements == 0)
    {
        printf("No measurements\n");
    }
    else
    {
        printf("[ ");
        for (int counter = 0; counter < amountOfMeasurements; counter++)
        {
            printf("%d ", measurementsArray[counter]);
        }
        printf("]\n");
    }
}

int enterMeasurements(int *measurementsArray, int amountOfMeasurements)
{
    int newMeasurement = 0;
    char input[10];

    while (amountOfMeasurements < 10)
    {
        printf("Enter measurement #%d (or q to quit): ", (amountOfMeasurements + 1));
        scanf("%s", &input);

        if (strcmp(input, "q") == 0)
        {
            break;
        }

        int successBool = sscanf(input, "%d", &newMeasurement);

        if (successBool)
        {
            measurementsArray[amountOfMeasurements] = newMeasurement;
            amountOfMeasurements++;
        }
        else
        {
            printf("\nInvalid input. Please enter a number or 'q' to quit.");
        }
    }

    if (amountOfMeasurements == 10)
    {
        printf("\nYou already have 10 measurements!");
    }

    return amountOfMeasurements;
}

void computeMeasurements(int *measurementsArray, int amountOfMeasurements)
{
    if (amountOfMeasurements == 0)
    {
        printf("No measurements\n");
    }
    else
    {
        int copyArray[10];

        for (int counter = 0; counter < amountOfMeasurements; counter++)
        {
            copyArray[counter] = measurementsArray[counter];
        }

        printf("Max mesaurement: %d\n", findMaxMeasurement(copyArray, amountOfMeasurements));
        printf("Min mesaurement: %d\n", findMinMeasurement(copyArray, amountOfMeasurements));
        printf("Avr mesaurement: %0.2f\n", findAvrMeasurement(copyArray, amountOfMeasurements));

        for (int counter = 0; counter < amountOfMeasurements; counter++)
        {
            copyArray[counter] = measurementsArray[counter];
        }

        findNormalizedMeasurement(copyArray, amountOfMeasurements);
        viewMeasurements(copyArray, amountOfMeasurements);
    }
}

int findMaxMeasurement(int *copyArray, int amountOfMeasurements)
{
    for (int i = 0; i < amountOfMeasurements - 1; i++)
    {
        for (int counter = 0; counter < amountOfMeasurements - 1; counter++)
        {
            if (copyArray[counter] < copyArray[counter + 1])
            {
                int temp = copyArray[counter];
                copyArray[counter] = copyArray[counter + 1];
                copyArray[counter + 1] = temp;
            }
        }
    }

    return copyArray[0];
}

int findMinMeasurement(int *copyArray, int amountOfMeasurements)
{
    for (int i = 0; i < amountOfMeasurements - 1; i++)
    {
        for (int counter = 0; counter < amountOfMeasurements - 1; counter++)
        {
            if (copyArray[counter] > copyArray[counter + 1])
            {
                int temp = copyArray[counter];
                copyArray[counter] = copyArray[counter + 1];
                copyArray[counter + 1] = temp;
            }
        }
    }

    return copyArray[0];
}

float findAvrMeasurement(int *copyArray, int amountOfMeasurements)
{
    float avrMesaurement = 0;

    for (int counter = 0; counter < amountOfMeasurements; counter++)
    {
        avrMesaurement = avrMesaurement + copyArray[counter];
    }

    avrMesaurement = avrMesaurement / amountOfMeasurements;

    return avrMesaurement;
}

void findNormalizedMeasurement(int *copyArray, int amountOfMeasurements)
{
    int avrMesaurement = round(findAvrMeasurement(copyArray, amountOfMeasurements));

    for (int counter = 0; counter < amountOfMeasurements; counter++)
    {
        copyArray[counter] = copyArray[counter] - avrMesaurement;
    }
}