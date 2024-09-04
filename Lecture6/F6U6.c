#include <stdio.h>

int main()
{
    int digitsArray[5][5], rowTotalsArray[5] = {0, 0, 0, 0, 0}, columnTotalsArray[5] = {0, 0, 0, 0, 0};

    for (int columnCounter = 0; columnCounter < 5; columnCounter++)
    {
        printf("Enter row %d: ", (columnCounter + 1));
        for (int rowCounter = 0; rowCounter < 5; rowCounter++)
        {
            scanf("%d", &digitsArray[columnCounter][rowCounter]);
        }

        // scanf("%d %d %d %d %d",
        //       &digitsArray[columnCounter][0], &digitsArray[columnCounter][1],
        //       &digitsArray[columnCounter][2], &digitsArray[columnCounter][3],
        //       &digitsArray[columnCounter][4]);
    }

    for (int columnCounter = 0; columnCounter < 5; columnCounter++)
    {
        printf("\n");
        for (int rowCounter = 0; rowCounter < 5; rowCounter++)
        {
            rowTotalsArray[columnCounter] = rowTotalsArray[columnCounter] + digitsArray[columnCounter][rowCounter];
        }
    }

    for (int columnCounter = 0; columnCounter < 5; columnCounter++)
    {
        printf("\n");
        for (int rowCounter = 0; rowCounter < 5; rowCounter++)
        {
            printf("%d", digitsArray[columnCounter][rowCounter]);
        }
    }

    printf("\n");

    for (int columnCounter = 0; columnCounter < 5; columnCounter++)
    {
        printf("%d ", rowTotalsArray[columnCounter]);
    }

    return 0;
}