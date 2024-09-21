#include <stdio.h>
#include <string.h>

struct TempMeasurement
{
    char date[10];
    float data[10];
    int amountData;
};

struct TempMeasurement createTempMeasurement(char date[10], float data[10], int amountData);
void printTemp(struct TempMeasurement temperature);
void concatenate(struct TempMeasurement *temperature1, struct TempMeasurement *temperature2);

int main()
{
    float dataTemp1[4] = {18.7, 19.2, 18.3, 18.4};
    struct TempMeasurement temperature1 = createTempMeasurement("2021-06-27", dataTemp1, 4);

    float dataTemp2[10] = {22.1, 23.4, 22.1, 22.3, 22.3, 22.4, 22.5, 22.6, 22.7, 22.8};
    struct TempMeasurement temperature2 = createTempMeasurement("2021-06-27", dataTemp2, 10);

    printTemp(temperature1);
    // printTemp(temperature2);

    concatenate(&temperature1, &temperature2);

    printTemp(temperature1);
    // printTemp(temperature2);

    return 0;
}

void printTemp(struct TempMeasurement temperature)
{
    if (temperature.amountData > 0)
    {
        printf("\n%s", temperature.date);

        for (int counter = 0; counter < temperature.amountData; counter++)
        {
            printf(" %0.1f,", temperature.data[counter]);
        }
    }
}

struct TempMeasurement createTempMeasurement(char date[10], float data[10], int amountData)
{
    struct TempMeasurement newTemp;

    strcpy(newTemp.date, date);

    newTemp.amountData = amountData;

    for (int counter = 0; counter < amountData; counter++)
    {
        newTemp.data[counter] = data[counter];
    }

    return newTemp;
}

void concatenate(struct TempMeasurement *temperature1, struct TempMeasurement *temperature2)
{
    if (strcmp(temperature1->date, temperature2->date) == 0)
    {
        int temp1Amount = temperature1->amountData, temp2Amount = temperature2->amountData;
        int temporaryAmount = temp1Amount;

        for (int counter = 0; (counter < temp2Amount) && temporaryAmount < 10; counter++)
        {
            temporaryAmount++;
        }

        for (int counter = 0; (counter < temporaryAmount) && ((temp1Amount + counter) < 10); counter++)
        {
            temperature1->data[temp1Amount + counter] = temperature2->data[counter];
        }

        if (temporaryAmount == 10)
        {
            for (int counter1 = 0, counter2 = (temp2Amount - temp1Amount); counter1 < temp1Amount; counter1++, counter2++)
            {
                temperature2->data[counter1] = temperature2->data[counter2];
            }
            temperature2->amountData = temp1Amount;
        }
        else
        {
            temperature2->amountData = 0;
        }

        temperature1->amountData = temporaryAmount;
    }
}