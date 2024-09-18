#include <stdio.h>
#include <string.h>

void addGlossary(char sweGlossaryArray[][20], char engGlossaryArray[][20], int *amountOfGlossary);
void viewGlossary(char sweGlossaryArray[][20], char engGlossaryArray[][20], int amountOfGlossary);

void main()
{
    int userChoice = 1, amountOfGlossary = 0;
    char sweGlossaryArray[20][20] = {0}, engGlossaryArray[20][20] = {0};

    while (userChoice != 4)
    {
        printf("(1) Write Glossary (2) View Glossary (3) Delete Glossary (4) Exit: ");
        scanf("%d", &userChoice);

        switch (userChoice)
        {
        case 1:
            addGlossary(sweGlossaryArray, engGlossaryArray, &amountOfGlossary);
            break;
        case 2:
            viewGlossary(sweGlossaryArray, engGlossaryArray, amountOfGlossary);
            break;
        case 3:
            amountOfGlossary = 0;
            break;
        case 4:
            printf("Exiting\n");
            break;
        default:
            printf("Wrong input, try again\n");
            break;
        }
    }
}

void addGlossary(char sweGlossaryArray[][20], char engGlossaryArray[][20], int *amountOfGlossary)
{
    char sweWord[20], engWord[20];

    while (*amountOfGlossary < 20)
    {
        printf("\nSwedish: ");
        scanf(" %s", sweWord);

        if (strcmp(sweWord, "q") == 0)
        {
            break;
        }

        printf("\nEnglish: ");
        scanf(" %s", engWord);

        strcpy(sweGlossaryArray[*amountOfGlossary], sweWord);
        strcpy(engGlossaryArray[*amountOfGlossary], engWord);
        (*amountOfGlossary)++;
    }

    if (*amountOfGlossary == 20)
    {
        printf("You already have 20 glossary\n");
    }
}

void viewGlossary(char sweGlossaryArray[][20], char engGlossaryArray[][20], int amountOfGlossary)
{
    if (amountOfGlossary == 0)
    {
        printf("No glossaries\n");
    }
    else
    {
        for (int i = 0; i < amountOfGlossary; i++)
        {
            printf("%s - %s\n", sweGlossaryArray[i], engGlossaryArray[i]);
        }
    }
}