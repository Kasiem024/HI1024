#include <stdio.h>

struct PlayingCard
{
    int number;
    char color;
};

struct Hand
{
    char cards[52];
    int amount;
};

int main()
{
    struct Hand myHand;
    myHand.amount = 4;
    char myHandColorsArray[4] = {'s', 'h', 'r', 'r'};
    int myHandNumbersArray[4] = {2, 12, 3, 8};

    for (int counter = 0; counter < myHand.amount; counter++)
    {
    }

    struct Hand yourHand;
    yourHand.amount = 5;
    return 0;
}