#include <stdio.h>

int main()
{
    int digitSeenArray[10] = {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
    },
        continueLoop = 1;
    long userDigit = 1;

    while (continueLoop == 1)
    {
        printf("\n\nEnter a number: ");
        scanf("%d", &userDigit);

        if (userDigit <= 0)
        {
            continueLoop = 0;
            break;
        }

        for (int counter = 0; counter < 10; counter++)
        {
            if (userDigit != 0)
            {
                int seenDigit = userDigit % 10;
                userDigit = userDigit / 10;

                digitSeenArray[seenDigit]++;
            }
        }

        printf("Digit:      0 1 2 3 4 5 6 7 8 9\nOccurences: ");

        for (int counter = 0; counter < 10; counter++)
        {
            printf("%d ", digitSeenArray[counter]);
        }
    }
    return 0;
}