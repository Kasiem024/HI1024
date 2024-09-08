#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int fillArray(int array[5])

{
    srand(time(NULL));
    for (int counter = 0; counter < 5; counter++)
    {
        array[counter] = rand() % (10 + 10 + 1) - 10;
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
    for (int counter = 0; counter < 5; counter++)
    {
        for (int counter = 0; counter < 5; counter++)
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
    int array[5] = {0, 0, 0, 0, 0};

    fillArray(array);
    printArray(array);
    sortArray(array);
    printArray(array);

    return 0;
}