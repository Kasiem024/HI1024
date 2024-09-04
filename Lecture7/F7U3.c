#include <stdio.h>

int fillArray(int array[5])
{
    for (int counter = 0; counter < 5; counter++)
    {
    }
    printf("\n");

    return 0;
}

int printArray(int array[5])
{
    for (int counter = 0; counter < 5; counter++)
    {
        printf("%d ", array[counter]);
    }
    printf("\n");

    return 0;
}

int sortArray(int array[5])
{
    return 0;
}

int main()
{
    int array[5] = {0, 0, 0, 0, 0};

    fillArray(array);
    printArray(array);
    sortArray(array);
    printArray(array);

    return 0;
}