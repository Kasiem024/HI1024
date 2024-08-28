#include <stdio.h>

int main()
{

    int numbers[4] = {0, 0, 0, 0};

    printf("Enter 4 integers :");
    scanf("%d,%d,%d,%d", &numbers[0], &numbers[1], &numbers[2], &numbers[3]);

    int largest = numbers[0], smallest = numbers[0], counter = 0;

    for (int counter = 0; counter < 4; counter++)
    {
        if (largest < numbers[counter])
        {
            largest = numbers[counter];
        }
        if (smallest > numbers[counter])
        {
            smallest = numbers[counter];
        }
    }

    printf("\nLargest: %d\nSmallest: %d", largest, smallest);
    return 0;
}