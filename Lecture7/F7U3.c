#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int fillArray(int array[], int arraySize)
{
    array[arraySize];

    srand(time(NULL));

    for (int counter = 0; counter < arraySize; counter++)
    {
        array[counter] = rand() % (10 + 10 + 1) - 10;
    }

    printf("\n");

    return 0;
}

int printArray(int array[], int arraySize)
{
    array[arraySize];

    for (int counter = 0; counter < arraySize; counter++)
    {
        printf("%d ", array[counter]);
    }
    printf("\n");

    return 0;
}

int sortArray(int array[], int arraySize)
{
    array[arraySize];

    for (int i = 0; i < arraySize - 1; i++)
    {
        for (int counter = 0; counter < arraySize - 1 - i; counter++)
        {
            if (array[counter] > array[counter + 1])
            {
                int temp = array[counter + 1];
                array[counter + 1] = array[counter];
                array[counter] = temp;
            }
        }
    }

    return 0;
}

int main()
{
    int arraySize = 5;
    int array[5];

    fillArray(array, arraySize);
    printArray(array, arraySize);
    sortArray(array, arraySize);
    printArray(array, arraySize);

    return 0;
}