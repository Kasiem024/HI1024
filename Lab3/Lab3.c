#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PATIENTS 1000
#define MAX_PICS 10
#define MAX_FILE_NAME 40
#define MAX_ID_LENGTH 12
#define MAX_NAME_LENGTH 40

typedef struct
{
    char personalID[MAX_ID_LENGTH];
    char fullName[MAX_NAME_LENGTH];
    int picRef[MAX_PICS];
    int picAmount;
} Patient;

typedef struct
{
    Patient patient[MAX_PATIENTS];
    int amount;
} AllPatients;

void funcReadFile(AllPatients *pPatientsArray, char chosenFile[], FILE *pDatabaseFile);
void funcPrintData(AllPatients patientsArray);
void funcRegisterPatient(AllPatients *pPatientsArray);
void funcSaveFile(AllPatients patientsArray, char chosenFile[], FILE *pDatabaseFile);

int main()
{
    AllPatients patientsArray;
    patientsArray.amount = 0;

    char chosenFile[MAX_FILE_NAME] = "patients.txt";
    // char chosenFile[MAX_FILE_NAME];
    FILE *databaseFile = NULL;

    printf("Patient Journal System");
    printf("\nWhich file do you want to use: ");

    // while (1)
    // {
    //     scanf(" %s", &chosenFile);

    databaseFile = fopen(chosenFile, "r");

    //     if (databaseFile)
    //     {
    funcReadFile(&patientsArray, chosenFile, databaseFile);
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
            funcRegisterPatient(&patientsArray);

            break;
        case 2:
            if (patientsArray.amount == 0)
            {
                printf("Database is empty");
                break;
            }

            funcPrintData(patientsArray);

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
            funcSaveFile(patientsArray, chosenFile, databaseFile);

            break;
        default:
            break;
        }
    }

    return 0;
}

void funcReadFile(AllPatients *pPatientsArray, char chosenFile[], FILE *pDatabaseFile)
{
    pDatabaseFile = fopen(chosenFile, "r");

    char fileContent[MAX_PATIENTS][100];

    while (pPatientsArray->amount < MAX_PATIENTS)
    {
        fgets(fileContent[pPatientsArray->amount], 1000, pDatabaseFile);

        pPatientsArray->amount++;
        if (feof(pDatabaseFile))
        {
            break;
        }
    }
    fclose(pDatabaseFile);

    if (pPatientsArray->amount == MAX_PATIENTS)
    {
        printf("\nThe data for the first %d patients have been found, if there are more than %d patients their data cannot be accessed.", MAX_PATIENTS, MAX_PATIENTS);
    }

    for (int counter = 0; counter < pPatientsArray->amount; counter++)
    {
        char currentFullName[MAX_NAME_LENGTH], currentPersonalID[MAX_ID_LENGTH], picStr[100];
        Patient currentPatient = pPatientsArray->patient[counter];

        sscanf(fileContent[counter], "{%41[^}]} {%13[^}]} {%99[^}]}", currentFullName, currentPersonalID, picStr);

        strncpy(currentPatient.fullName, currentFullName, sizeof(currentPatient.fullName) - 1);
        currentPatient.fullName[sizeof(currentPatient.fullName) - 1] = '\0';

        strncpy(currentPatient.personalID, currentPersonalID, sizeof(currentPatient.personalID) - 1);
        currentPatient.personalID[sizeof(currentPatient.personalID) - 1] = '\0';

        int picRef[MAX_PICS];
        int picCount = 0;

        char *token = strtok(picStr, ",");
        while (token != NULL && picCount < MAX_PICS)
        {
            picRef[picCount] = atoi(token);
            picCount++;
            token = strtok(NULL, ",");

            if (picCount == MAX_PICS)
            {
                printf("\nThe data for the first %d pictures of %s have been found, if there are more than %d pictures they cannot be accessed.", MAX_PICS, currentFullName, MAX_PICS);
            }
        }

        for (int counterPic = 0; counterPic < picCount; counterPic++)
        {
            currentPatient.picRef[counterPic] = picRef[counterPic];
        }

        currentPatient.picAmount = picCount;

        pPatientsArray->patient[counter] = currentPatient;
    }
}

void funcRegisterPatient(AllPatients *pPatientsArray)
{
    while (1)
    {
        int continueLoop = 0;
        printf("\nEnter personal ID (or q to exit): ");
        char newID[MAX_ID_LENGTH];
        scanf(" %s", &newID);

        if (!strcmp(newID, "q"))
        {
            printf("Exiting registration");
            break;
        }

        for (int counter = 0; counter < pPatientsArray->amount; counter++)
        {
            if (!strcmp(pPatientsArray->patient[counter].personalID, newID))
            {
                printf("\nPatient already registered.");
                continueLoop = 1;
                break;
            }
        }

        if (continueLoop)
            continue;

        // Clear input buffer
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;

        printf("\nEnter full name: ");

        char newName[MAX_NAME_LENGTH];

        fgets(newName, sizeof(newName), stdin);

        newName[strcspn(newName, "\n")] = 0; // Remove newline

        int newPic = -1, newPicArray[10] = {0}, newPicCounter = 0;

        while (1)
        {
            printf("\nEnter picture references (or 0 to exit): ");

            scanf("%d", &newPic);
            if (newPic == 0)
                break;

            int continuePicLoop = 0;

            for (int counterPatient = 0; counterPatient < pPatientsArray->amount; counterPatient++)
            {
                for (int counterPics = 0; counterPics < pPatientsArray->patient[counterPatient].picAmount; counterPics++)
                {
                    if (pPatientsArray->patient[counterPatient].picRef[counterPics] == newPic)
                    {
                        printf("\nThe picture already exists.");
                        continuePicLoop = 1;
                        break;
                    }
                }
                if (continuePicLoop)
                    break;
            }
            if (continuePicLoop)
                continue;

            newPicArray[newPicCounter] = newPic;
            newPicCounter++;
        }

        strncpy(pPatientsArray->patient[pPatientsArray->amount].fullName, newName, sizeof(newName));
        strncpy(pPatientsArray->patient[pPatientsArray->amount].personalID, newID, sizeof(newID));

        pPatientsArray->amount++;

        for (int counter = 0; counter < newPicCounter; counter++)
        {
            pPatientsArray->patient[pPatientsArray->amount].picRef[counter] = newPicArray[counter];
        }
        pPatientsArray->patient[pPatientsArray->amount].picAmount = newPicCounter;
    }
}

void funcPrintData(AllPatients patientsArray)
{
    printf("\nPersonal ID \t Name \t\t Picture references\n");
    printf("\n------------------------------------------------------------------------\n");

    for (int counterPatient = 0; counterPatient < patientsArray.amount; counterPatient++)
    {
        Patient currentPatient = patientsArray.patient[counterPatient];

        printf("%s \t", currentPatient.personalID);
        printf("%s \t", currentPatient.fullName);

        printf("[");
        for (int counterPics = 0; counterPics < currentPatient.picAmount; counterPics++)
        {
            if (currentPatient.picRef[counterPics] != 0)
            {
                printf("%d", currentPatient.picRef[counterPics]);

                if ((currentPatient.picAmount - counterPics) != 1)
                {
                    printf(", ");
                }
            }
        }
        printf("]\n");
    }
}

void funcSaveFile(AllPatients patientsArray, char chosenFile[], FILE *pDatabaseFile)
{
    printf("Saving patient data in %s", chosenFile);

    pDatabaseFile = fopen(chosenFile, "w");

    for (int counterPatient = 0; counterPatient < patientsArray.amount; counterPatient++)
    {
        Patient currentPatient = patientsArray.patient[counterPatient];

        char currentFullName[MAX_NAME_LENGTH + 3] = "{";
        strcat(currentFullName, currentPatient.fullName);
        strcat(currentFullName, "} ");

        char currentPersonalID[MAX_ID_LENGTH + 3] = "{";
        strcat(currentPersonalID, currentPatient.personalID);
        strcat(currentPersonalID, "} ");

        char picStr[100] = "{";

        for (int counterPics = 0; counterPics < currentPatient.picAmount; counterPics++)
        {
            char currentPic[10];
            sprintf(currentPic, "%d", currentPatient.picRef[counterPics]); // Converts int to char
            strcat(picStr, currentPic);

            if ((currentPatient.picAmount - counterPics) != 1)
            {
                strcat(picStr, ",");
            }
        }
        strcat(picStr, "}");

        if ((patientsArray.amount - counterPatient) != 1)
        {
            fprintf(pDatabaseFile, "%s%s%s\n", currentFullName, currentPersonalID, picStr);
        }
        else
        {
            fprintf(pDatabaseFile, "%s%s%s", currentFullName, currentPersonalID, picStr);
        }
    }

    fclose(pDatabaseFile);

    printf("\nExiting");
}