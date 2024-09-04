#include <stdio.h>

int main()
{
    int rowTotalsArray[5] = {0, 0, 0, 0, 0}, columnTotalsArray[5] = {0, 0, 0, 0, 0};

    for (int columnCounter = 0; columnCounter < 5; columnCounter++)
    {
        printf("Enter row %d: ", (columnCounter + 1));
        for (int rowCounter = 0; rowCounter < 5; rowCounter++)
        {
            int inputDigit = 0;
            scanf("%d", &inputDigit);

            rowTotalsArray[columnCounter] = rowTotalsArray[columnCounter] + inputDigit;
            columnTotalsArray[rowCounter] = columnTotalsArray[rowCounter] + inputDigit;
        }
    }

    printf("\nRow totals: ");

    for (int columnCounter = 0; columnCounter < 5; columnCounter++)
    {
        printf("%d ", rowTotalsArray[columnCounter]);
    }

    printf("\nColumn totals: ");

    for (int columnCounter = 0; columnCounter < 5; columnCounter++)
    {
        printf("%d ", columnTotalsArray[columnCounter]);
    }

    return 0;
}