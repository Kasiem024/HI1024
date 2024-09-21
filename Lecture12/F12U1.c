#include <stdio.h>
#include <string.h>

struct BankAcc
{
    char name[40];
    int balance;
};

struct BankAcc createAccount(char name[40], int balance)
{
    struct BankAcc newUser;

    strcpy(newUser.name, name);
    newUser.balance = balance;

    return newUser;
}

void printAccount(struct BankAcc user)
{
    printf("%s %d kr\n", user.name, user.balance);
}

void transfer(struct BankAcc *account1, struct BankAcc *account2)
{
    account2->balance = account2->balance + account1->balance;
    account1->balance = 0;
}

void main()
{

    struct BankAcc account1 = createAccount("Simran Singh", 3210);
    struct BankAcc account2 = createAccount("Mark Asplund", 210);

    printAccount(account1);
    printAccount(account2);

    transfer(&account1, &account2);

    printAccount(account1);
    printAccount(account2);
}