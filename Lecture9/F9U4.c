#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int scanStats();
int printStats(int amountPeople, int ageArray[]);
int getAverageAge(int amountPeople, int ageArray[]);
int getMedianAge(int amountPeople, int ageArray[]);
int getTypeValueAge(int amountPeople, int ageArray[]);

int main()
{
    int continueLoop = 1;

    while (continueLoop == 1)
    {
        int amountPeople = scanStats();

        if (amountPeople == 0)
        {
            printf("\nExiting");
            continueLoop = 0;
            break;
        }

        int ageArray[amountPeople];

        srand(time(NULL));

        for (int counter = 0; counter < amountPeople; counter++)
        {
            int randAge = rand() % (40 - 20 + 1) + 20;
            ageArray[counter] = randAge;
        }

        if (amountPeople < 31)
        {
            printStats(amountPeople, ageArray);
        }

        for (int i = 0; i < amountPeople - 1; i++)
        {
            for (int counter = 0; counter < amountPeople - 1 - i; counter++)
            {
                if (ageArray[counter + 1] < ageArray[counter])
                {
                    int temp = ageArray[counter];
                    ageArray[counter] = ageArray[counter + 1];
                    ageArray[counter + 1] = temp;
                }
            }
        }

        getAverageAge(amountPeople, ageArray);
        getMedianAge(amountPeople, ageArray);
        getTypeValueAge(amountPeople, ageArray);
    }

    return 0;
}

int scanStats()
{
    int amountPeople = 0;

    printf("\n\nHow many people do you want to do statistics on? ");
    scanf("%d", &amountPeople);

    while (0 > amountPeople || amountPeople > 1000)
    {
        printf("Wrong amount of people, try again ");
        scanf("%d", &amountPeople);
    }

    return amountPeople;
}

int printStats(int amountPeople, int ageArray[])
{
    for (int counter = 0; counter < amountPeople; counter++)
    {
        printf("%d ", ageArray[counter]);
    }

    return 0;
}

int getAverageAge(int amountPeople, int ageArray[])
{
    float averageAge = 0;

    for (int counter = 0; counter < amountPeople; counter++)
    {
        averageAge = averageAge + ageArray[counter];
    }

    averageAge = averageAge / amountPeople;

    printf("\nAverage age: %0.1f years", averageAge);

    return 0;
}

int getMedianAge(int amountPeople, int ageArray[])
{
    float medianAge = 0;

    if (amountPeople % 2 == 0)
    {
        float highMiddlePair = ageArray[amountPeople / 2];
        float lowMiddlePair = ageArray[(amountPeople / 2) - 1];
        medianAge = (highMiddlePair + lowMiddlePair) / 2;
    }
    else
    {
        medianAge = ageArray[amountPeople / 2];
    }

    printf("\nMedian age: %0.1f years", medianAge);

    return 0;
}

int getTypeValueAge(int amountPeople, int ageArray[])
{
    int ageOccurenceCounterArray[amountPeople], typeValueAgeArray[amountPeople];

    for (int counter = 0; counter < amountPeople; counter++)
    {
        ageOccurenceCounterArray[counter] = 0;
    }

    for (int counter1 = 0; counter1 < amountPeople; counter1++)
    {
        for (int counter2 = 0; counter2 < amountPeople; counter2++)
        {
            if (ageArray[counter1] == ageArray[counter2])
            {
                ageOccurenceCounterArray[counter1]++;
            }
        }
    }

    int foundTypeValue = 0, amountOfTypeValue = 0;

    for (int counter1 = amountPeople - 1; counter1 >= 0; counter1--)
    {
        for (int counter2 = amountPeople - 1; counter2 >= 0; counter2--)
        {
            if (ageOccurenceCounterArray[counter2] == counter1 && counter1 != 1 && foundTypeValue == 0)
            {
                foundTypeValue = counter1;
                typeValueAgeArray[amountOfTypeValue] = ageArray[counter2];
                amountOfTypeValue++;
            }

            if (foundTypeValue != 0 && ageOccurenceCounterArray[counter2] == foundTypeValue)
            {
                int uniqueAge = 0;

                for (int counter3 = 0; counter3 < amountOfTypeValue; counter3++)
                {
                    if (typeValueAgeArray[counter3] == ageArray[counter2])
                    {
                        uniqueAge = 1;
                    }
                }

                if (uniqueAge == 0)
                {
                    typeValueAgeArray[amountOfTypeValue] = ageArray[counter2];
                    amountOfTypeValue++;
                }
            }

            if (counter1 == 1 && foundTypeValue == 0)
            {
                typeValueAgeArray[amountOfTypeValue] = ageArray[counter2];
                amountOfTypeValue++;
            }
        }
    }

    printf("\nType value: ");

    for (int counter = 0; counter < amountOfTypeValue; counter++)
    {
        printf("%d ", typeValueAgeArray[counter]);
    }

    return 0;
}