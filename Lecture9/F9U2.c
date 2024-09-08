#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int shuffleArray(int integerArray[], int maxInteger);

int main()
{
    int maxInteger = 0;
    printf("What is the highest integer you want to include? (1-1000): ");
    scanf("%d", &maxInteger);

    while (maxInteger < 1 || 1000 < maxInteger)
    {
        printf("\nYou must choose an integer between 1 and 1000!\n"
               "What is the highest integer you want to include? (1-1000): ");
        scanf("%d", &maxInteger);
    }

    int integerArray[maxInteger];

    for (int counter = 1; counter <= maxInteger; counter++)
    {
        integerArray[counter - 1] = counter;
    }

    srand(time(NULL));

    shuffleArray(integerArray, maxInteger);

    for (int counter = 0; counter < maxInteger; counter++)
    {
        printf("%d ", integerArray[counter]);
    }

    return 0;
}

int shuffleArray(int integerArray[], int maxInteger)
{
    for (int counter = 0; counter < maxInteger; counter++)
    {
        int randInteger = rand() % (maxInteger - 1 + 1);

        if (integerArray[randInteger] != integerArray[counter])
        {
            int tempInteger = integerArray[randInteger];
            integerArray[randInteger] = integerArray[counter];
            integerArray[counter] = tempInteger;
        }
    }

    return 0;
}