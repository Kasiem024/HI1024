#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int amountCards = 1;

    while (amountCards % 2 != 0 || amountCards < 2)
    {
        printf("\nChoose amount of cards (2-16): ");
        scanf("%d", &amountCards);
    }

    char pairsArray[amountCards];

    for (int counter = 0; counter < amountCards; counter++)
    {
        pairsArray[counter] = 0;
    }

    srand(time(NULL));
    for (int counter = 0, letterCounter = 65; counter < amountCards; counter += 2, letterCounter++)
    {
        int randomNum1 = rand() % amountCards;

        while (pairsArray[randomNum1] != 0)
        {
            randomNum1 = rand() % amountCards;
        }
        pairsArray[randomNum1] = letterCounter;

        int randomNum2 = rand() % amountCards;

        while (pairsArray[randomNum2] != 0)
        {
            randomNum2 = rand() % amountCards;
        }
        pairsArray[randomNum2] = letterCounter;
    }

    int amountTries = 0, foundPairs[amountCards], amountFoundPairs = 0;

    for (int counter = 0; counter < amountCards; counter++)
    {
        foundPairs[counter] = counter + 1;
    }

    while (amountFoundPairs != amountCards)
    {
        int playerChoice1 = 0, playerChoice2 = 0, correctInput = 0;

        while (correctInput == 0)
        {
            for (int counter = 0; counter < amountCards; counter++)
            {
                if (foundPairs[counter] != 0)
                {
                    printf("%d ", foundPairs[counter]);
                }
            }

            printf("\nWhich card do you want to turn? ");

            scanf("%d %d", &playerChoice1, &playerChoice2);
            if (playerChoice1 == playerChoice2)
            {
                printf("Wrong choice\n");
                continue;
            }
            if (foundPairs[playerChoice1 - 1] == 0 || foundPairs[playerChoice2 - 1] == 0)
            {
                printf("Wrong choice\n");
                continue;
            }

            break;
        }

        playerChoice1--, playerChoice2--;

        if (pairsArray[playerChoice1] == pairsArray[playerChoice2])
        {
            printf("You got the pair %c\n", pairsArray[playerChoice1]);
            foundPairs[playerChoice1] = 0;
            foundPairs[playerChoice2] = 0;
            amountFoundPairs += 2;
        }
        else
        {
            printf("You got %c and %c\n", pairsArray[playerChoice1], pairsArray[playerChoice2]);
        }

        amountTries++;
    }

    printf("You played for %d rounds", amountTries);

    return 0;
}