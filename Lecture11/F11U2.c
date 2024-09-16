#include <stdio.h>
#include <string.h>

void addGlossary(char sweGlossaryArray[][20], char engGlossaryArray[][20], int *amountOfGlossary);
void viewGlossary(char sweGlossaryArray[][20], char engGlossaryArray[][20], int amountOfGlossary);
void deleteGlossary(char sweGlossaryArray[][20], char engGlossaryArray[][20], int *amountOfGlossary);

int main()
{
    int userChoice = 1, amountOfGlossary = 0;
    char sweGlossaryArray[20][20] = {0}, engGlossaryArray[20][20] = {0};

    while (userChoice != 4)
    {
        printf("(1) Skriva in (2) Skriva ut (3) Radera (4) Avsluta: ");
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
            deleteGlossary(sweGlossaryArray, engGlossaryArray, &amountOfGlossary);
            break;
        case 4:
            printf("Avslutar\n");
            break;
        default:
            printf("Felaktig inmatning, försök igen\n");
            break;
        }
    }

    return 0;
}

void addGlossary(char sweGlossaryArray[][20], char engGlossaryArray[][20], int *amountOfGlossary)
{
    char sweWord[20], engWord[20];

    while (*amountOfGlossary < 20)
    {
        printf("\nSvenska: ");
        scanf(" %s", sweWord);

        if (strcmp(sweWord, "q") == 0)
        {
            break;
        }

        printf("\nEngelska: ");
        scanf(" %s", engWord);

        strcpy(sweGlossaryArray[*amountOfGlossary], sweWord);
        strcpy(engGlossaryArray[*amountOfGlossary], engWord);
        (*amountOfGlossary)++;
    }

    if (*amountOfGlossary == 20)
    {
        printf("Du har redan 20 glosor\n");
    }
}

void viewGlossary(char sweGlossaryArray[][20], char engGlossaryArray[][20], int amountOfGlossary)
{
    if (amountOfGlossary == 0)
    {
        printf("Gloslistan är tom\n");
    }
    else
    {
        for (int i = 0; i < amountOfGlossary; i++)
        {
            printf("%s - %s\n", sweGlossaryArray[i], engGlossaryArray[i]);
        }
    }
}

void deleteGlossary(char sweGlossaryArray[][20], char engGlossaryArray[][20], int *amountOfGlossary)
{
    printf("Raderar alla glosor\n");
    *amountOfGlossary = 0;
}