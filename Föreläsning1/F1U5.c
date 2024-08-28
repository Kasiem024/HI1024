#include <stdio.h>
#include <math.h>

int main()
{
    float dollarAmount, amountOf20, amountOf10, amountOf5, amountOf1, amountOf05, amountOf001;

    printf("Welcome, enter a US dollar amount please: \n");

    scanf("%f", &dollarAmount);

    while (dollarAmount < 0)
    {
        printf("Dollar amount can't be less than 0, please input a valid number: \n");
        scanf("%f", &dollarAmount);
    }

    amountOf20 = dollarAmount / 20;
    amountOf20 = floor(amountOf20);
    dollarAmount = dollarAmount - amountOf20 * 20;

    amountOf10 = dollarAmount / 10;
    amountOf10 = floor(amountOf10);
    dollarAmount = dollarAmount - amountOf10 * 10;

    amountOf5 = dollarAmount / 5;
    amountOf5 = floor(amountOf5);
    dollarAmount = dollarAmount - amountOf5 * 5;

    amountOf1 = dollarAmount / 1;
    amountOf1 = floor(amountOf1);
    dollarAmount = dollarAmount - amountOf1 * 1;

    amountOf05 = dollarAmount / 0.5;
    amountOf05 = floor(amountOf05);
    dollarAmount = dollarAmount - amountOf05 * 0.5;

    amountOf001 = dollarAmount;

    printf("20$ bills %g \n", amountOf20);
    printf("10$ bills %g \n", amountOf10);
    printf("5$ bills %g \n", amountOf5);
    printf("1$ bills %g \n", amountOf1);
    printf("50 cent coins %g \n", amountOf05);
    printf("1 cent coins %.2g \n", amountOf001);

    return 0;
}