#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct patient
{
    char personalID[11];
    char fullName[40];
    int picRef[10];
    int picAmount;
} Patient;

typedef struct allPatients
{
    Patient patient[1000];
    int amount;
} AllPatients;

void funcCreateArray(AllPatients *pPatientsArray, char *pChosenFile, FILE *pDatabaseFile);
void funcPrintPatients(AllPatients pPatientsArray);
void funcSaveFile(AllPatients *pPatientsArray, char *pChosenFile, FILE *pDatabaseFile);

int main()
{
    AllPatients patientsArray;
    patientsArray.amount = 0;

    char chosenFile[40] = "patients.txt";
    // char chosenFile[40];
    FILE *databaseFile = NULL;

    printf("Patient Journal System");
    printf("\nWhich file do you want to use: ");

    // while (1)
    // {
    //     scanf(" %s", &chosenFile);

    databaseFile = fopen(chosenFile, "r");

    //     if (databaseFile)
    //     {
    funcCreateArray(&patientsArray, chosenFile, databaseFile);
    //         break;
    //     }
    //     else if (strstr(chosenFile, ".txt") == NULL)
    //     {
    //         printf("The file needs to be '.txt' format\n");
    //         continue;
    //     }
    //     else
    //     {
    //         printf("File does not exist, creating a new file called: %s", chosenFile);
    //         break;
    //     }
    // }

    int userChoice = 0;

    while (userChoice != 7)
    {
        printf("\nMain menu"
               "\n\t1) Register new patients"
               "\n\t2) Print all patients"
               "\n\t3) Look for patient"
               "\n\t4) Add picture references"
               "\n\t5) Sort patients"
               "\n\t6) Deregister patient"
               "\n\t7) Exit program"
               "\nEnter choice: ");

        scanf("%d", &userChoice);

        switch (userChoice)
        {
        case 1:

            break;
        case 2:
            if (patientsArray.amount == 0)
            {
                printf("Database is empty");
                break;
            }

            funcPrintPatients(patientsArray);

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
            funcSaveFile(&patientsArray, chosenFile, databaseFile);

            break;
        default:
            break;
        }
    }

    return 0;
}

void funcCreateArray(AllPatients *pPatientsArray, char *pChosenFile, FILE *pDatabaseFile)
{
    pDatabaseFile = fopen(pChosenFile, "r");

    char fileContent[1000][100];

    while (pPatientsArray->amount < 1000)
    {
        fgets(fileContent[pPatientsArray->amount], 1000, pDatabaseFile);

        pPatientsArray->amount++;
        if (feof(pDatabaseFile))
        {
            break;
        }
    }
    fclose(pDatabaseFile);

    if (pPatientsArray->amount == 1000)
    {
        printf("The data for the first 1000 patients have been found, if there are more than 1000 patients their data cannot be accessed");
    }

    for (int counter = 0; counter < pPatientsArray->amount; counter++)
    {
        char currentFullName[40];
        char currentPersonalID[20];
        char picStr[100];

        sscanf(fileContent[counter], "{%49[^}]} {%19[^}]} {%99[^}]}", currentFullName, currentPersonalID, picStr);

        strncpy(pPatientsArray->patient[counter].fullName, currentFullName, sizeof(pPatientsArray->patient[counter].fullName) - 1);
        pPatientsArray->patient[counter].fullName[sizeof(pPatientsArray->patient[counter].fullName) - 1] = '\0';

        strncpy(pPatientsArray->patient[counter].personalID, currentPersonalID, sizeof(pPatientsArray->patient[counter].personalID) - 1);
        pPatientsArray->patient[counter].personalID[sizeof(pPatientsArray->patient[counter].personalID) - 1] = '\0';

        int picRef[10];
        int picCount = 0;

        char *token = strtok(picStr, ",");
        while (token != NULL)
        {
            picRef[picCount] = atoi(token);
            picCount++;
            token = strtok(NULL, ",");
        }

        for (int counterPic = 0; counterPic < picCount; counterPic++)
        {
            pPatientsArray->patient[counter].picRef[counterPic] = picRef[counterPic];
        }

        pPatientsArray->patient[counter].picAmount = picCount;
    }
}

void funcPrintPatients(AllPatients pPatientsArray)
{
    printf("\nPersonal ID \t Name \t\t Picture references\n");
    printf("\n------------------------------------------------------------------------\n");

    for (int counterPatient = 0; counterPatient < pPatientsArray.amount; counterPatient++)
    {
        printf("%s \t", pPatientsArray.patient[counterPatient].personalID);
        printf("%s \t", pPatientsArray.patient[counterPatient].fullName);

        printf("[");
        for (int counterPics = 0; counterPics < pPatientsArray.patient[counterPatient].picAmount; counterPics++)
        {
            if (pPatientsArray.patient[counterPatient].picRef[counterPics] != 0)
            {
                printf("%d", pPatientsArray.patient[counterPatient].picRef[counterPics]);

                if ((pPatientsArray.patient[counterPatient].picAmount - counterPics) != 1)
                {
                    printf(", ");
                }
            }
        }
        printf("]\n");
    }
}

void funcSaveFile(AllPatients *pPatientsArray, char *pChosenFile, FILE *pDatabaseFile)
{
    printf("Saving patient data in %s", pChosenFile);

    char newFile[1000];

    for (int counterPatient = 0; counterPatient < pPatientsArray->amount; counterPatient++)
    {
        char currentString[100];

        char currentFullName[40] = "{";

        strcat(currentFullName, pPatientsArray->patient[counterPatient].fullName);
        strcat(currentFullName, "} ");

        char currentPersonalID[40] = "{";

        strcat(currentPersonalID, pPatientsArray->patient[counterPatient].personalID);
        strcat(currentPersonalID, "} ");

        char picStr[100];

        for (int counterPics = 0; counterPics < pPatientsArray->patient[counterPatient].picAmount; counterPics++)
        {
            if (pPatientsArray->patient[counterPatient].picRef[counterPics] != 0)
            {
                char tempString[10];
                itoa(pPatientsArray->patient[counterPatient].picRef[counterPics], tempString, 10);
                strcat(picStr, tempString);
            }
        }

        strcat(currentString, currentFullName);
        strcat(currentString, currentPersonalID);
        // strcat(currentString, picStr + '\n');

        printf("\ncurrentString: %s\n", currentString);

        strcat(newFile, currentString);
    }

    // pDatabaseFile = fopen(pChosenFile, "w");
    // fprintf(pDatabaseFile, newFile);
    // printf("%s", newFile);

    printf("Exiting");
}