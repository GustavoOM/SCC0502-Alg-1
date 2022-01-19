#ifndef ACCOUNT_H
#define ACCOUNT_H

typedef struct account_ ACCOUNT;

ACCOUNT *createAccount (const char *cpf, const char *name, int age, float balance);
char *getCpfFromAccount(ACCOUNT *account);
void printCpfFromAccount(ACCOUNT *account);
void printAccount(ACCOUNT *account);
void deleteAccount(ACCOUNT * account);

#endif