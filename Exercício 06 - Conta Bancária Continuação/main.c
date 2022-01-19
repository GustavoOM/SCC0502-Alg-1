#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./TADs/tree/tree.h"   
#include "./TADs/util/util.h"   

#define lineLen 85
#define cpfLen 15
#define nameLen 50
#define ageLen 4
#define balanceLen 13

void getCpf(char * line, char * cpf);
void getName(char * line, char * name);
void getAge(char * line, char * age);
void getBalance(char * line, char * balance);
void getValue(char * line, char * value, int key);
void cleanInfo(char * line, char * cpf, char * name, char * age, char * balance);

int main(){
    TREE *binaryTree = createBinaryTree();
    ACCOUNT *account;
    int quantityOfRecords;
    if(!scanf("%d",&quantityOfRecords)){
        return 0;
    }
    readLine(); //Remove retorno da primeira linha
    char line[lineLen] = "";
    char cpf[cpfLen] = "";
    char name[nameLen] = "";
    char age[ageLen] = "";
    char balance[balanceLen] = "";
    for(int i = 0; i < quantityOfRecords; i++){
        cleanInfo(line,cpf,name,age,balance);
        strcpy(line,readLine());
        getCpf(line,cpf);
        getName(line,name);
        getAge(line,age);
        getBalance(line,balance);
        account = createAccount(cpf,name,atoi(age),atof(balance));
        insertAccountInTree(binaryTree,account);
    }
    char operation;
    if(!scanf("%c",&operation)){
        return 0;
    }
    readLine();
    cleanInfo(line,cpf,name,age,balance);

    switch (operation){
    case 'I':
        strcpy(line,readLine());
        getCpf(line,cpf);
        getName(line,name);
        getAge(line,age);
        getBalance(line,balance);
        account = createAccount(cpf,name,atoi(age),atof(balance));
        insertAccountInTree(binaryTree,account);
        printTreeInPreOrder(binaryTree);
        break;
    case 'B':
        strcpy(line,readLine());
        getCpf(line,cpf);
        account = findAccount(binaryTree,cpf);
        printAccount(account);
        printf("\n");
        break;
    case 'R':
        strcpy(line,readLine());
        getCpf(line,cpf);
        account = findAccount(binaryTree,cpf);
        printAccount(account);
        removeAccount(binaryTree, cpf);
        printTreeInPreOrder(binaryTree);
        break;
    default:
        break;
    }
    free(binaryTree);
    return 0;
}

void getCpf(char * line, char * cpf){

    getValue(line,cpf,0);
}

void getName(char * line, char * name){
    getValue(line,name,1);
}

void getAge(char * line, char * age){
    getValue(line,age,2);
}

void getBalance(char * line, char * balance){
    getValue(line,balance,3);
}

void getValue(char * line, char * value, int key){
    int i = 0;
    for(int jump = 0; jump < key; jump++){
        while (line[i] != '\0' && line[i] != ';'){
            i++;
        }
        i++;
    }
    int j = 0;
    while (line[i] != '\0' && line[i] != ';'){
        value[j] = line[i];
        i++;
        j++;
    }
}

void cleanInfo(char * line, char * cpf, char * name, char * age, char * balance){
    for(int i = 0; i < lineLen; i++){
        line[i] = '\0';
    }
    for(int i = 0; i < cpfLen; i++){
        cpf[i] = '\0';
    }
    for(int i = 0; i < nameLen; i++){
        name[i] = '\0';
    }
    for(int i = 0; i < ageLen; i++){
        age[i] = '\0';
    }
    for(int i = 0; i < balanceLen; i++){
        balance[i] = '\0';
    }
}