#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "account.h"

struct account_{
    char cpf[15];
    char name[50];
    int age;
    float balance;
};

ACCOUNT *createAccount (const char *cpf, const char *name, int age, float balance){
    ACCOUNT *account;

    account = (ACCOUNT *) malloc(sizeof(ACCOUNT));

    if (account != NULL){
        strcpy(account->cpf, cpf);
        strcpy(account->name, name);
        account->age = age;
        account->balance = balance;
        return account;
    }
    return NULL;
}

char *getCpfFromAccount(ACCOUNT *account){
    return account->cpf;
}

void printCpfFromAccount(ACCOUNT *account){
    int j = 0;
    for(int i = 0; i < 15; i++){
        if(account->cpf[i]=='0'){
            j++;
        }
        else{
            break;
        }
    }
    char cpfAux[15] = "";
    for(int i = 0; account->cpf[i+j] != '\0';i++){
        cpfAux[i] = account->cpf[i+j];
    }
    printf("%s",cpfAux);
}