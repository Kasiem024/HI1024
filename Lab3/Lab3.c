#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PATIENTS 1000
#define MAX_PICS 10
#define MAX_FILE_NAME 40
#define MAX_ID_LENGTH 14
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
void funcPrintData(Patient patient);
void funcPrintHeader();
void funcRegisterPatient(AllPatients *pPatientsArray);
int funcFindPatient(AllPatients patientsArray, int foundUniquePatient);
int funcSearchID(AllPatients *pPatientsArray, char searchID[]);
int funcSearchPic(AllPatients *pPatientsArray, int searchPic);
int funcAddPic(AllPatients *pPatientsArray, int *pNewPicArray, int newPicCounter, int flag);
void funcSort(AllPatients *pPatientsArray);
void funcRemovePatient(AllPatients *pPatientsArray);
void funcSaveFile(AllPatients patientsArray, char chosenFile[], FILE *pDatabaseFile);

int main()
{
    AllPatients patientsArray;
    patientsArray.amount = 0;

    char chosenFile[MAX_FILE_NAME];
    FILE *databaseFile = NULL;

    printf("Patient Journal System\nWhich file do you want to use: ");

    while (1)
    {
        scanf(" %s", &chosenFile);

        databaseFile = fopen(chosenFile, "r");

        if (databaseFile)
        {
            funcReadFile(&patientsArray, chosenFile, databaseFile);
            break;
        }
        else if (strstr(chosenFile, ".txt") == NULL)
        {
            printf("\nThe file needs to be '.txt' format\n");
            continue;
        }
        else
        {
            printf("\nFile does not exist, creating a new file called: %s", chosenFile);
            break;
        }
    }

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

        // Clear input buffer
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;

        if (userChoice != 1 && userChoice != 7 && !patientsArray.amount)
        {
            printf("\nDatabase is empty");
            continue;
        }

        switch (userChoice)
        {
        case 1:
            funcRegisterPatient(&patientsArray);
            break;

        case 2:

            funcPrintHeader();
            for (int counterPatient = 0; counterPatient < patientsArray.amount; counterPatient++)
            {
                funcPrintData(patientsArray.patient[counterPatient]);
            }

            break;
        case 3:
            funcFindPatient(patientsArray, -2);
            break;
        case 4:
            // This array does nothing
            int tempArray[10] = {0};
            funcAddPic(&patientsArray, tempArray, 0, -2);

            break;

        case 5:
            funcSort(&patientsArray);
            break;

        case 6:
            funcRemovePatient(&patientsArray);
            break;

        case 7:
            funcSaveFile(patientsArray, chosenFile, databaseFile);

            break;
        default:
            printf("\nWrong input, try again");
            break;
        }
    }
    return 0;
}

void funcReadFile(AllPatients *pPatientsArray, char chosenFile[], FILE *pDatabaseFile)
{
    pDatabaseFile = fopen(chosenFile, "r");

    char fileContent[MAX_PATIENTS][MAX_ID_LENGTH + MAX_NAME_LENGTH + MAX_PICS + 10];

    while (pPatientsArray->amount < MAX_PATIENTS)
    {
        // Each line in the file becomes its own element in the array
        fgets(fileContent[pPatientsArray->amount], sizeof(fileContent[pPatientsArray->amount]), pDatabaseFile);

        pPatientsArray->amount++;
        if (feof(pDatabaseFile)) // If end of file is reached
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
        char currentFullName[MAX_NAME_LENGTH], currentPersonalID[MAX_ID_LENGTH], picStr[MAX_PICS + 20];
        Patient currentPatient = pPatientsArray->patient[counter];

        // Tokenize fileContent elements based on '{}'
        sscanf(fileContent[counter], "{%41[^}]} {%15[^}]} {%30[^}]}", currentFullName, currentPersonalID, picStr);

        strncpy(currentPatient.fullName, currentFullName, sizeof(currentPatient.fullName) - 1);
        currentPatient.fullName[sizeof(currentPatient.fullName) - 1] = '\0';

        strncpy(currentPatient.personalID, currentPersonalID, sizeof(currentPatient.personalID) - 1);
        currentPatient.personalID[sizeof(currentPatient.personalID) - 1] = '\0';

        int picRef[MAX_PICS], picCount = 0;

        // Tokenize based on ','
        char *token = strtok(picStr, ",");
        while (token != NULL && picCount < MAX_PICS)
        {
            picRef[picCount] = atoi(token); // Convert string to int
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

    printf("\nAmount of patients: %d", pPatientsArray->amount);
}

void funcRegisterPatient(AllPatients *pPatientsArray)
{
    while (pPatientsArray->amount < MAX_PATIENTS)
    {
        printf("\nEnter personal ID (or q to exit): ");

        char newID[MAX_ID_LENGTH];
        scanf(" %s", &newID);

        if (!strcmp(newID, "q"))
        {
            printf("\nExiting registration");
            break;
        }

        int foundPatient = funcSearchID(pPatientsArray, newID);

        if (foundPatient != -1)
        {
            printf("\nPatient already registered.");
            continue;
        }

        // Clear input buffer
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;

        printf("\nEnter full name: ");

        char newName[MAX_NAME_LENGTH];
        fgets(newName, sizeof(newName), stdin);
        newName[strcspn(newName, "\n")] = 0; // Remove newline

        int newPicArray[10] = {0}, newPicCounter = 0;

        newPicCounter = funcAddPic(pPatientsArray, newPicArray, 0, -1);

        strncpy(pPatientsArray->patient[pPatientsArray->amount].fullName, newName, sizeof(newName));
        strncpy(pPatientsArray->patient[pPatientsArray->amount].personalID, newID, sizeof(newID));

        for (int counter = 0; counter < newPicCounter; counter++)
        {
            pPatientsArray->patient[pPatientsArray->amount].picRef[counter] = newPicArray[counter];
        }
        pPatientsArray->patient[pPatientsArray->amount].picAmount = newPicCounter;

        pPatientsArray->amount++;
    }
    if (pPatientsArray->amount == MAX_PATIENTS)
    {
        printf("\nMaximum number of patients in the database has ben reached.");
    }
}

void funcPrintHeader()
{
    printf("\nPersonal ID \tName\t\t\t\t\tPicture references\n");
    printf("\n------------------------------------------------------------------------\n");
}

void funcPrintData(Patient patient)
{
    // Used to reserve space for printout
    int space = MAX_NAME_LENGTH - strlen(patient.fullName);

    printf("%s\t", patient.personalID);
    printf("%s", patient.fullName);

    printf("%*s", space, "[");
    for (int counterPics = 0; counterPics < patient.picAmount; counterPics++)
    {
        if (patient.picRef[counterPics] != 0)
        {
            printf("%d", patient.picRef[counterPics]);

            if ((patient.picAmount - counterPics) != 1)
            {
                printf(", ");
            }
        }
    }
    printf("]\n");
}

int funcFindPatient(AllPatients patientsArray, int flag)
{
    int searchChoice = 0;
    while (searchChoice != 4)
    {
        printf("\nSearch by ID (1), name (2), picture reference (3), exit (4): ");

        scanf("%d", &searchChoice);

        // Clear input buffer
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;

        int foundPatient = 0, found = 1;

        switch (searchChoice)
        {
        case 1:

            char searchID[MAX_ID_LENGTH];
            printf("Enter ID: ");

            scanf(" %s", &searchID);

            foundPatient = funcSearchID(&patientsArray, searchID);

            if (foundPatient != -1)
            {
                funcPrintHeader();
                funcPrintData(patientsArray.patient[foundPatient]);
                if (flag == -1) // If this function is not called from main
                {
                    return foundPatient;
                }
            }
            else
            {
                printf("No patient with that ID in the database");
            }

            break;
        case 2:

            char searchName[MAX_NAME_LENGTH];
            printf("\nEnter search string: ");

            scanf(" %s", &searchName);

            for (int counterPatient = 0; counterPatient < patientsArray.amount; counterPatient++)
            {
                if (strstr(patientsArray.patient[counterPatient].fullName, searchName) != NULL)
                {
                    if (found == 1) // If it's the first match
                    {
                        funcPrintHeader();
                    }
                    funcPrintData(patientsArray.patient[counterPatient]);
                    foundPatient = counterPatient;
                    found++;
                }
            }

            if (found == 1)
            {
                printf("No patient with that name in the database");
            }
            else if (found > 2 && flag == -1) // If more than one patient was found and function is not called from main
            {
                printf("More than one patient with that name");
            }
            else if (found == 2 && flag == -1) // If only one patient was found and function is not called from main
            {
                return foundPatient;
            }

            break;
        case 3:
            printf("\nEnter picture reference: ");

            int searchPic = 0;
            scanf("%d", &searchPic);

            foundPatient = funcSearchPic(&patientsArray, searchPic);

            if (foundPatient != -1)
            {
                funcPrintHeader();
                funcPrintData(patientsArray.patient[foundPatient]);
                if (flag == -1)
                {
                    return foundPatient;
                }
            }
            else
            {
                printf("No picture with that reference in the database");
            }

            break;
        case 4:
            printf("\nExiting search");
            if (flag == -1)
            {
                return -3;
            }
            break;
        default:
            printf("\nWrong input, try again");

            break;
        }
    }
    return flag; // Only happens if called from main
}

int funcSearchID(AllPatients *pPatientsArray, char searchID[])
{
    for (int counter = 0; counter < pPatientsArray->amount; counter++)
    {
        if (!strcmp(pPatientsArray->patient[counter].personalID, searchID))
        {
            return counter;
        }
    }
    return -1;
}

int funcSearchPic(AllPatients *pPatientsArray, int searchPic)
{
    for (int counterPatient = 0; counterPatient < pPatientsArray->amount; counterPatient++)
    {
        for (int counterPic = 0; counterPic < pPatientsArray->patient[counterPatient].picAmount; counterPic++)
        {
            if (pPatientsArray->patient[counterPatient].picRef[counterPic] == searchPic)
            {
                return counterPatient;
            }
        }
    }
    return -1;
}

int funcAddPic(AllPatients *pPatientsArray, int *pNewPicArray, int newPicCounter, int flag)
{
    int foundUniquePatient = -1, foundPatient = -1, newPic = -1;

    if (flag == -2) // If called from main
    {
        foundUniquePatient = funcFindPatient(*pPatientsArray, -1);
        newPicCounter = pPatientsArray->patient[foundUniquePatient].picAmount;
    }

    while (newPicCounter < MAX_PICS && foundUniquePatient != -3)
    {
        printf("\nEnter picture references (or 0 to exit): ");

        scanf("%d", &newPic);
        if (newPic == 0)
            break;

        foundPatient = funcSearchPic(pPatientsArray, newPic);

        if (foundPatient != -1)
        {
            printf("\nThe picture already exists.");
            continue;
        }

        pNewPicArray[newPicCounter] = newPic;
        newPicCounter++;
    }

    if (newPicCounter == MAX_PICS)
    {
        printf("\nMaximum number of picture references for this patient has ben reached.");
    }

    if (flag == -2)
    {
        for (int counter = pPatientsArray->patient[foundUniquePatient].picAmount; counter < newPicCounter; counter++)
        {
            pPatientsArray->patient[foundUniquePatient].picRef[counter] = pNewPicArray[counter];
        }
        pPatientsArray->patient[foundUniquePatient].picAmount = newPicCounter;
    }
    else
    {
        return newPicCounter;
    }
}

void funcSort(AllPatients *pPatientsArray)
{
    printf("\nSort by ID (1), name (2): ");

    int sortChoice = 0;

    scanf("%d", &sortChoice);

    for (int counter1 = 0; counter1 < pPatientsArray->amount; counter1++)
    {
        for (int counter2 = 1; counter2 < pPatientsArray->amount - counter1; counter2++)
        {
            if (sortChoice == 1)
            {
                // Takes the first part of ID and converts it to an int
                int temp1 = atoi(strtok(pPatientsArray->patient[counter2 - 1].personalID, "-"));
                int temp2 = atoi(strtok(pPatientsArray->patient[counter2].personalID, "-"));

                if (temp1 > temp2)
                {
                    Patient temp = pPatientsArray->patient[counter2 - 1];
                    pPatientsArray->patient[counter2 - 1] = pPatientsArray->patient[counter2];
                    pPatientsArray->patient[counter2] = temp;
                }
            }
            else
            {
                if (strcmp(pPatientsArray->patient[counter2 - 1].fullName, pPatientsArray->patient[counter2].fullName) > 0)
                {
                    Patient temp = pPatientsArray->patient[counter2 - 1];
                    pPatientsArray->patient[counter2 - 1] = pPatientsArray->patient[counter2];
                    pPatientsArray->patient[counter2] = temp;
                }
            }
        }
    }
}

void funcRemovePatient(AllPatients *pPatientsArray)
{
    int foundUniquePatient = funcFindPatient(*pPatientsArray, -1);

    char userChoice = 'a';

    printf("\nDo you want to remove the patient (y/n)?");
    scanf(" %c", &userChoice);

    switch (userChoice)
    {
    case 'y':
        for (int counter = foundUniquePatient; counter < pPatientsArray->amount; counter++)
        {
            pPatientsArray->patient[counter] = pPatientsArray->patient[counter + 1];
        }
        pPatientsArray->amount--;

        printf("The patient has been removed");
        break;
    case 'n':
        break;
    default:
        printf("Wrong input, try again");
        break;
    }
}

void funcSaveFile(AllPatients patientsArray, char chosenFile[], FILE *pDatabaseFile)
{
    printf("\nSaving patient data in %s", chosenFile);

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

        char picStr[MAX_PICS + 40] = "{";

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