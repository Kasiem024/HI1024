#include <stdio.h>
#include <string.h>
#include <math.h>

void viewMeasurements(int *pMeasurementsArray, int pAmountMeasurements);
int enterMeasurements(int *pMeasurementsArray, int pAmountMeasurements);
void computeMeasurements(int *pMeasurementsArray, int pAmountMeasurements);
int findMaxMeasurement(int *pCopyArray, int pAmountMeasurements);
int findMinMeasurement(int *pCopyArray, int pAmountMeasurements);
float findAvrMeasurement(int *pCopyArray, int pAmountMeasurements);
void findNormalizedMeasurement(int *pCopyArray, int pAmountMeasurements);

int main()
{
    char userChoice = 'e';
    int measurementsArray[10], amountMeasurements = 0;
    printf("Measurement tool 2.0\n");

    while (userChoice != 'q')
    {
        printf("VECRQ? ");
        scanf(" %c", &userChoice);

        switch (userChoice)
        {
        case 'v':
            viewMeasurements(measurementsArray, amountMeasurements);
            break;

        case 'e':
            amountMeasurements = enterMeasurements(measurementsArray, amountMeasurements);
            break;

        case 'c':
            computeMeasurements(measurementsArray, amountMeasurements);

            break;

        case 'r':
            for (int counter = 0; counter < amountMeasurements; counter++)
            {
                measurementsArray[counter] = 0;
            }
            amountMeasurements = 0;

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

void viewMeasurements(int *pMeasurementsArray, int pAmountMeasurements)
{
    if (pAmountMeasurements == 0)
    {
        printf("No measurements\n");
    }
    else
    {
        printf("[ ");
        for (int counter = 0; counter < pAmountMeasurements; counter++)
        {
            printf("%d ", pMeasurementsArray[counter]);
        }
        printf("]\n");
    }
}

int enterMeasurements(int *pMeasurementsArray, int pAmountMeasurements)
{
    int newMeasurement = 0;
    char input[10];

    while (pAmountMeasurements < 10)
    {
        printf("Enter measurement #%d (or q to quit): ", (pAmountMeasurements + 1));
        scanf("%s", &input);

        if (strcmp(input, "q") == 0)
        {
            break;
        }

        int successBool = sscanf(input, "%d", &newMeasurement);

        if (successBool)
        {
            pMeasurementsArray[pAmountMeasurements] = newMeasurement;
            pAmountMeasurements++;
        }
        else
        {
            printf("\nInvalid input. Please enter a number or 'q' to quit.\n");
        }
    }

    if (pAmountMeasurements == 10)
    {
        printf("You already have 10 measurements!\n");
    }

    return pAmountMeasurements;
}

void computeMeasurements(int *pMeasurementsArray, int pAmountMeasurements)
{
    if (pAmountMeasurements == 0)
    {
        printf("No measurements\n");
    }
    else
    {
        int copyArray[10];

        for (int counter = 0; counter < pAmountMeasurements; counter++)
        {
            copyArray[counter] = pMeasurementsArray[counter];
        }

        printf("Max mesaurement: %d\n", findMaxMeasurement(copyArray, pAmountMeasurements));
        printf("Min mesaurement: %d\n", findMinMeasurement(copyArray, pAmountMeasurements));
        printf("Avr mesaurement: %0.2f\n", findAvrMeasurement(copyArray, pAmountMeasurements));

        for (int counter = 0; counter < pAmountMeasurements; counter++)
        {
            copyArray[counter] = pMeasurementsArray[counter];
        }

        findNormalizedMeasurement(copyArray, pAmountMeasurements);
        viewMeasurements(copyArray, pAmountMeasurements);
    }
}

int findMaxMeasurement(int *pCopyArray, int pAmountMeasurements)
{
    for (int i = 0; i < pAmountMeasurements - 1; i++)
    {
        for (int counter = 0; counter < pAmountMeasurements - 1 - i; counter++)
        {
            if (pCopyArray[counter] < pCopyArray[counter + 1])
            {
                int temp = pCopyArray[counter];
                pCopyArray[counter] = pCopyArray[counter + 1];
                pCopyArray[counter + 1] = temp;
            }
        }
    }

    return pCopyArray[0];
}

int findMinMeasurement(int *pCopyArray, int pAmountMeasurements)
{
    for (int i = 0; i < pAmountMeasurements - 1; i++)
    {
        for (int counter = 0; counter < pAmountMeasurements - 1 - i; counter++)
        {
            if (pCopyArray[counter] > pCopyArray[counter + 1])
            {
                int temp = pCopyArray[counter];
                pCopyArray[counter] = pCopyArray[counter + 1];
                pCopyArray[counter + 1] = temp;
            }
        }
    }

    return pCopyArray[0];
}

float findAvrMeasurement(int *pCopyArray, int pAmountMeasurements)
{
    float avrMesaurement = 0;

    for (int counter = 0; counter < pAmountMeasurements; counter++)
    {
        avrMesaurement = avrMesaurement + pCopyArray[counter];
    }

    avrMesaurement = avrMesaurement / pAmountMeasurements;

    return avrMesaurement;
}

void findNormalizedMeasurement(int *pCopyArray, int pAmountMeasurements)
{
    int avrMesaurement = round(findAvrMeasurement(pCopyArray, pAmountMeasurements));

    for (int counter = 0; counter < pAmountMeasurements; counter++)
    {
        pCopyArray[counter] = pCopyArray[counter] - avrMesaurement;
    }
}