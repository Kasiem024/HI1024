#include <stdio.h>

int main()
{

    int int1, int2, int3, int4, largest, smallest;

    printf("Enter 4 integers :");
    scanf("%d %d %d %d", &int1, &int2, &int3, &int4);

    int numbers[4] = {int1, int2, int3, int4};

    printf("%d", numbers);

    printf("Largest: %d\nSmallest: %d", largest, smallest);

    return 0;
}