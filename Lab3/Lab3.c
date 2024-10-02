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

void funcPrintPatients(AllPatients pPatientsArray);

int main()
{
    AllPatients patientsArray;
    patientsArray.amount = 0;

    // char chosenFile[40] = "patients.txt";
    char chosenFile[40];
    FILE *databaseFile = NULL;

    printf("Patient Journal System");
    printf("\nWhich file do you want to use: ");
    while (1)
    {
        scanf(" %s", &chosenFile);
        printf("\nchosenFile: %s", chosenFile);

        databaseFile = fopen(chosenFile, "r");
        printf("\ndatabaseFile: %s", databaseFile);

        if (databaseFile)
        {
            break;
        }
    }

    databaseFile = fopen(chosenFile, "r");

    char fileContent[1000][100];

    while (1)
    {
        fgets(fileContent[patientsArray.amount], 1000, databaseFile);

        patientsArray.amount++;
        if (feof(databaseFile))
        {
            break;
        }
    }
    fclose(databaseFile);

    for (int counter = 0; counter < patientsArray.amount; counter++)
    {

        char currentFullName[40];
        char currentPersonalID[20];
        char picStr[100];

        sscanf(fileContent[counter], "{%49[^}]} {%19[^}]} {%99[^}]}", currentFullName, currentPersonalID, picStr);

        strncpy(patientsArray.patient[counter].fullName, currentFullName, sizeof(patientsArray.patient[counter].fullName) - 1);
        patientsArray.patient[counter].fullName[sizeof(patientsArray.patient[counter].fullName) - 1] = '\0';

        strncpy(patientsArray.patient[counter].personalID, currentPersonalID, sizeof(patientsArray.patient[counter].personalID) - 1);
        patientsArray.patient[counter].personalID[sizeof(patientsArray.patient[counter].personalID) - 1] = '\0';

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
            patientsArray.patient[counter].picRef[counterPic] = picRef[counterPic];
        }

        patientsArray.patient[counter].picAmount = picCount;
    }

    int userChoice = 0;

    while (userChoice != 7)
    {
        printf("\nMain menu"
               "\n\t1) Register new patients"
               "\n\t2) Print all patients"
               "\n\t3) Look for patient"
               "\n\t4) Add picRef"
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
            printf("Exiting");
            break;

        default:
            break;
        }
    }

    return 0;
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