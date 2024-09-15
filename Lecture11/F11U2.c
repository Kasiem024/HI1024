#include <stdio.h>

int writeGlossary(char *glossaryArray, int amountOfGlossary);
void viewGlossary(char *glossaryArray, int amountOfGlossary);

void main()
{
    int userChoice = 1, amountOfGlossary = 0;
    char glossaryArray[20];

    printf("(1) Write (2) View (3) Delete (4) Quit: ");
    while (userChoice != 4)
    {
        scanf("%d", &userChoice);

        switch (userChoice)
        {
        case 1:
            amountOfGlossary = writeGlossary(glossaryArray, amountOfGlossary);
            break;
        case 2:
            viewGlossary(glossaryArray, amountOfGlossary);

            break;
        case 3:
            break;
        case 4:
            break;

        default:
            printf("Wrong input, try again ");
            break;
        }
    }
}

int writeGlossary(char *glossaryArray, int amountOfGlossary)
{
    char *userInput[20];
    scanf(" %c", &userInput);
    glossaryArray[amountOfGlossary] = userInput;
    printf("%c ", glossaryArray[amountOfGlossary]);
    printf("%c ", userInput);
    amountOfGlossary++;
    return amountOfGlossary;
}

void viewGlossary(char *glossaryArray, int amountOfGlossary)
{
    if (amountOfGlossary == 0)
    {
        printf("The glossary is empty");
    }
    else
    {
        for (int counter = 0; counter < amountOfGlossary; counter++)
        {
            printf("%c ", glossaryArray[counter]);
        }
    }
}
