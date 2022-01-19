#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "account.h"
#include "../util/util.h"

struct account_{
    char cpf[15];
    char formatedCpf[15];
    char name[50];
    int age;
    float balance;
};

ACCOUNT *createAccount (const char *cpf, const char *name, int age, float balance){
    ACCOUNT *account;

    account = (ACCOUNT *) malloc(sizeof(ACCOUNT));

    if (account != NULL){
        strcpy(account->formatedCpf, cpf);
        strcpy(account->cpf, cpf);
        removeDotsAndDashesFromCpf(account->cpf);
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

void printAccount(ACCOUNT *account){
    if(account == NULL){
        printf("Pessoa nao encontrada.\n");
        return;
    }
    printf("Conta :: %s\n", account->name);
    printf("CPF :: %s\n", account->formatedCpf);
    printf("Idade :: %d\n", account->age);
    printf("Saldo atual :: R$ %.2f\n", account->balance);
}

void deleteAccount(ACCOUNT * account){
    if(account!=NULL){
        free(account->cpf);
        free(account->formatedCpf);
        free(account->name);
        account->age = 0;
        account->balance = 0;
        free(account);
        account = NULL;
    }
}