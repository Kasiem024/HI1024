#include <stdio.h>

int main()
{
    int squareSize;
    printf("How big of a rectangle do you want: ");
    scanf("%d", &squareSize);

    for (int counterLength = 0; counterLength < squareSize; counterLength++)
    {
        for (int counterWidth = 0; counterWidth < squareSize; counterWidth++)
        {
            if (counterWidth == counterLength || counterWidth + counterLength == squareSize - 1)
            {
                printf("*");
            }
            else
            {
                printf("+");
            }
        }
        printf("\n");
    }
    return 0;
}