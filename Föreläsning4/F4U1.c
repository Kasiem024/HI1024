#include <stdio.h>

int main()
{
    int dayOfTheWeek, amountOfDays;
    char weekArrayNames[7][12] = {
        "monday",
        "tuesday",
        "wednesday",
        "thursday",
        "friday",
        "saturday",
        "sunday"};

    printf("Which day of the week is it today? (1-mon, 2-tue, ..., 7-sun): ");
    scanf("%d", &dayOfTheWeek);

    printf("\nEnter amount of days: ");
    scanf("%d", &amountOfDays);

    int correctWeekDay = (dayOfTheWeek + amountOfDays) % 7;

    printf("\nIn %d days it will be %s", amountOfDays, weekArrayNames[correctWeekDay - 1]);

    return 0;
}