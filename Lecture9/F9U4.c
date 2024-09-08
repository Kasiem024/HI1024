#include <stdio.h>

int main()
{
    int amountPeople;
    printf("How many people do you want to do statistics on? ");
    scanf("%d", &amountPeople);

    while (0 > amountPeople || amountPeople > 100)
    {
        printf("Wrong amount of people, try again ");
        scanf("%d", &amountPeople);
    }

    int ageArray[amountPeople];

    for (int counter = 0; counter < amountPeople; counter++)
    {
        int randAge = rand() % (1000 - 1 + 1) + 1;
        ageArray[counter] = randAge;
    }

    return 0;
}