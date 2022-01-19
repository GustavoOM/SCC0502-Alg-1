#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./TADs/tree/tree.h"   
#include "./TADs/util/util.h"   

void getCpf(char * line, char * cpf);
void getName(char * line, char * name);
void getAge(char * line, char * age);
void getBalance(char * line, char * balance);
void getValue(char * line, char * value, int key);

int main(){
    TREE *binaryTree = createBinaryTree();
    ACCOUNT *account;
    int quantityOfRecords;
    if(!scanf("%d",&quantityOfRecords)){
        return 0;
    }
    readLine(); //Remove retorno da primeira linha
    char line[85] = "";
    char cpf[15] = "";
    char name[50] = "";
    char age[4] = "";
    char balance[13] = "";
    for(int i = 0; i < quantityOfRecords; i++){
        strcpy(line,readLine());
        getCpf(line,cpf);
        removeDotsAndDashesFromCpf(cpf);
        getName(line,name);
        getAge(line,age);
        getBalance(line,balance);
        account = createAccount(cpf,name,atoi(age),atof(balance));
        insertAccountInTree(binaryTree,account);
    }
    printTreeInOrder(binaryTree);
    printTreeInPreOrder(binaryTree);
    printTreeInPosOrder(binaryTree);
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