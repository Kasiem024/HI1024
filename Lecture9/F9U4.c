#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int continueLoop = 1;

    while (continueLoop == 1)
    {

        float averageAge = 0, medianAge = 0, typeValueAge = 0;
        int amountPeople = 0;

        printf("\nHow many people do you want to do statistics on? ");
        scanf("%d", &amountPeople);

        while (0 > amountPeople || amountPeople > 100)
        {
            printf("Wrong amount of people, try again ");
            scanf("%d", &amountPeople);
        }

        int ageArray[amountPeople], uniqueAgeArray[40] = {0};

        srand(time(NULL));

        for (int counter = 0; counter < amountPeople; counter++)
        {
            int randAge = rand() % (40 - 20 + 1) + 20;
            ageArray[counter] = randAge;
        }

        if (amountPeople < 31)
        {
            for (int counter = 0; counter < amountPeople; counter++)
            {
                printf("%d ", ageArray[counter]);
            }
        }

        for (int counter0 = 0; counter0 < amountPeople - 1; counter0++)
        {
            for (int counter1 = 0; counter1 < amountPeople - 1; counter1++)
            {
                if (ageArray[counter1 + 1] < ageArray[counter1])
                {
                    int temp = ageArray[counter1];
                    ageArray[counter1] = ageArray[counter1 + 1];
                    ageArray[counter1 + 1] = temp;
                }
            }
        }

        printf("\n");

        for (int counter = 0; counter < amountPeople; counter++)
        {
            printf("%d ", ageArray[counter]);
        }

        for (int counter = 0; counter < amountPeople; counter++)
        {
            averageAge = averageAge + ageArray[counter];
        }

        averageAge = averageAge / amountPeople;

        printf("\nAverage age: %0.1f years", averageAge);

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

        printf("\nMedian age: %0.1f years\n", medianAge);

        for (int counter0 = 0; counter0 < amountPeople - 1; counter0++)
        {
            if (ageArray[counter0] == ageArray[counter0 + 1])
            {
                uniqueAgeArray[ageArray[counter0]]++;
            }
        }

        for (int counter = 0; counter < 41; counter++)
        {
            printf("%d ", uniqueAgeArray[counter]);
        }
    }

    return 0;
}