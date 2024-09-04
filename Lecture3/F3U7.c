#include <stdio.h>

int main()
{
    int number = 1, counter = 1, total = 1;

    while (number != 0)
    {
        number = 1, counter = 1, total = 1;

        printf("\nEnter a number: ");
        scanf("%d", &number);

        if (number < 0)
        {
            printf("\nThe number must be positive\nExiting");
            number = 0;
        }
        else if (number == 0)
        {
            printf("Exiting");
        }
        else
        {
            counter = number;

            while (counter != 0)
            {
                total = counter * total;
                counter--;
            }
            printf("\n!%d = %d", number, total);
        }
    }
    return 0;
}