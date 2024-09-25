#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct card
{
    int number;
    char color;
};
typedef struct card Card;

struct hand
{
    Card cards[52];
    int amount;
};
typedef struct hand Hand;

void printHand(Hand currentHand);
void swap(Hand *firstHand, Hand *secondHand);

int main()
{
    Hand myHand = {{{2, 's'},
                    {12, 'h'},
                    {3, 'r'},
                    {8, 'r'}},
                   4};

    Hand yourHand = {{{3, 'k'},
                      {4, 'k'},
                      {5, 'k'},
                      {6, 'k'},
                      {7, 'k'}},
                     5};

    printHand(myHand);
    printHand(yourHand);

    swap(&myHand, &yourHand);

    printHand(myHand);
    printHand(yourHand);

    return 0;
}

void printHand(Hand currentHand)
{
    for (int counter = 0; counter < currentHand.amount; counter++)
    {
        printf("%c %d, ", currentHand.cards[counter].color, currentHand.cards[counter].number);
    }
    printf("\n");
}

void swap(Hand *firstHand, Hand *secondHand)
{
    srand(time(NULL));

    int randomNum = rand() % firstHand->amount;

    secondHand->cards[secondHand->amount].color = firstHand->cards[randomNum].color;
    secondHand->cards[secondHand->amount].number = firstHand->cards[randomNum].number;

    secondHand->amount++;

    for (int counter = 0; counter < firstHand->amount; counter++)
    {
        int foundCard = 0;
        if (firstHand->cards[counter].color == firstHand->cards[randomNum].color && firstHand->cards[counter].number == firstHand->cards[randomNum].number)
        {
            foundCard = 1;
        }
        if (foundCard == 1)
        {
            firstHand->cards[counter].color = firstHand->cards[counter + 1].color;
            firstHand->cards[counter].number = firstHand->cards[counter + 1].number;
        }
    }

    firstHand->amount--;
}