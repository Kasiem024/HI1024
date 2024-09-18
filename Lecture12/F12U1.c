#include <stdio.h>
#include <string.h>

struct bankAcc
{
    char name[40];
    int balance;
};

struct bankAcc createAccount(char name[40], int balance)
{
    struct bankAcc newUser;

    strcpy(newUser.name, name);
    newUser.balance = balance;

    return newUser;
}

void printAccount(struct bankAcc user)
{
    printf("%s %d kr\n", user.name, user.balance);
}

void transfer(struct bankAcc *account1, struct bankAcc *account2)
{
    account2.balance = account2.balance + account1.balance;
    account1.balance = 0;
}

void main()
{

    struct bankAcc account1 = createAccount("Simran Singh", 3210);
    struct bankAcc account2 = createAccount("Mark Asplund", 210);

    printAccount(account1);
    printAccount(account2);

    transfer(&account1, &account2);

    printAccount(account1);
    printAccount(account2);
}