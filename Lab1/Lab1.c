#include <stdio.h>

int main()
{
    printf("Lunar decent challenge"
           "\nYou will pilot a lunar decent the last 250m."
           "\nEach turn represent 1-second decent time."
           "\nSet the throttle for each turn (0-100)"
           "\nTime       Height       Velocity     Throttle?\n");

    float height = 250, velocity = -25, throttle = 0, time = 0;

    while (height > 0)
    {
        printf("%g          %0.1f          %0.1f          ", time, height, velocity);
        scanf("%f", &throttle);

        while (throttle < 0 || throttle > 100)
        {
            printf("Wrong amount of throttle, try again ");
            scanf("%f", &throttle);
        }

        height = height + velocity + (0.1 * throttle - 1.5) / 2;
        velocity = velocity + (0.1 * throttle - 1.5);
        time++;
    }

    if (velocity >= -2)
    {
        printf("\nSUCESS! Landed succesfully at %0.1f m/s", velocity);
    }
    else
    {
        printf("\nFAILED! Crash landed at %0.1f m/s", velocity);
    }

    return 0;
}