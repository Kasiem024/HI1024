#include <stdio.h>

int main()
{
    int matches = 15;

    printf("Welcome to the matches game\n");

    while (matches > 0)
    {
        for (int counter = 0; counter < matches; counter++)
        {
            printf("| ");
        }

        printf("\nHow many matches do you want to take? (1-3): ");

        int correctChoice = 0, playerMatches = 0;

        while (correctChoice == 0)
        {
            scanf("%d", &playerMatches);

            if (playerMatches <= 1 && playerMatches >= 3)
            {
                printf("\nWrong amount of matches, try again");
            }
            else
            {
                correctChoice = 1;
            }
        }

        matches = matches - playerMatches;

        if (matches == 0)
        {
            printf("\nThe player won");
        }
        else if (matches > 3)
        {
            printf("\nThe computer takes 3 matches\n");
            matches = matches - 3;
        }
        else if (matches < 3)
        {
            printf("\nThe computer takes %d matches\nThe computer won", matches);
            matches = matches - 3;
        }
    }

    return 0;
}