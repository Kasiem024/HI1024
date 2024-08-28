#include <stdio.h>

int main()
{

    int date, month, year;

    printf("Enter a date (mm/dd/yyy): ");

    scanf("%d/%d/%d", &month, &date, &year);

    printf("You entered the date: %d%02d%02d", year, month, date);

    return 0;
}