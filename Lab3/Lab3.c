#include <stdio.h>

typedef struct patient
{
    int personalID;
    char name[20];
    int pictures[10];
} Patient;

typedef struct allPatients
{
    Patient patient;
    int amount;
} AllPatients;

int main()
{
    printf("Patient Journal System");
    printf("\nWhich file do you want to use: ");

    char chosenFile[40] = "patients.txt";
    FILE *fptr = NULL;
    // while (1)
    // {
    //     scanf(" %s", &chosenFile);
    //     printf("\nchosenFile: %s", chosenFile);
    //     fptr = fopen(chosenFile, "r");
    //     printf("\nfptr: %s", fptr);
    //     if (fptr)
    //     {
    //         break;
    //     }
    // }

    fptr = fopen(chosenFile, "r");

    printf("%d", sizeof(fptr));

    char fileContent[4][3];

    // printf("\nsizeof: %d", sizeof(fptr));

    int amountLines = 0;
    while (1)
    {
        fgets(fileContent[amountLines], 1000, fptr);

        amountLines++;
        if (feof(fptr))
        {
            break;
        }
    }
    fclose(fptr);

    int charWordCounter = 0;
    AllPatients patientsArray[1000][1000];

    patientsArray[0]->patient.name[0] = 'a';

    for (int lineCounter = 0; lineCounter < amountLines; lineCounter++)
    {
        char word[1000];
        printf("\n%s\n", fileContent[lineCounter]);
        for (int charCounter = 0; charCounter < 1000; charCounter++)
        {
            char currentChar = fileContent[lineCounter][charCounter];
            printf("%c", currentChar);

            if (currentChar == '{')
            {
                patientsArray[0]->patient.name[charWordCounter] = currentChar;
            }
            if (currentChar == '}')
            {
                charWordCounter = 0;
            }
        }
    }

    printf("%s", patientsArray[0]->patient.name);
    printf("%s", patientsArray[1]->patient.name);
    printf("%s", patientsArray[2]->patient.name);
    printf("%s", patientsArray[3]->patient.name);

    int userChoice = 0;

    while (userChoice != 7)
    {
        printf("\nMain menu"
               "\n\t1) Register new patients"
               "\n\t2) Print all patients"
               "\n\t3) Look for patient"
               "\n\t4) Add pictures"
               "\n\t5) Sort patients"
               "\n\t6) Deregister patient"
               "\n\t7) Exit program"
               "\nEnter choice: ");

        scanf("%d", &userChoice);
        printf("\nuserChoice: %d", userChoice);
        switch (userChoice)
        {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;

        default:
            break;
        }
    }

    return 0;
}