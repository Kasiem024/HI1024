#include <stdio.h>

int showMatches(int matches)
{

    for (int counter = 0; counter < matches; counter++)
    {
        printf("| ");
    }

    return 0;
}

int main()
{
    int matches = 15;

    printf("Welcome to the matches game\n");

    showMatches(matches);

    while (matches > 0)
    {
        printf("\nHow many matches do you want to take? (1-3): ");

        int playerMatches = 0;

        scanf("%d", &playerMatches);

        while (playerMatches < 1 || playerMatches > 3)
        {
            printf("\nWrong amount of matches, try again ");
            scanf("%d", &playerMatches);
        }

        matches = matches - playerMatches;

        showMatches(matches);

        if (matches < 1)
        {
            printf("\nThe player won");
        }
        else if (matches >= 4)
        {
            int computerMatches = matches % 4;

            if (computerMatches < 1)
            {
                computerMatches = 1;
            }

            printf("\nThe computer takes %d matches\n", computerMatches);

            matches = matches - computerMatches;

            showMatches(matches);
        }
        else
        {
            printf("\nThe computer takes %d matches\nThe computer won", matches);
            matches = matches - matches;
        }
    }

    return 0;
}