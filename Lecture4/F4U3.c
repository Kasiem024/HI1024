#include <stdio.h>

int main()
{
    int a = 100, b = 1;

    while (a > b)
    {
        printf("\na=%d, b=%d", a, b);

        if ((a / b) > 20)
        {
            a = a / 2;
        }
        else
        {
            while (b < (a / 2))
            {
                b++;
                printf("\nb=%d", b);
            }
            b++;
        }
    }

    printf("\na=%d, b=%d", a, b);

    return 0;
}