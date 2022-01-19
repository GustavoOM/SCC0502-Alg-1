#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "util.h"

char *readLine() {
    char *string = NULL;
    char currentInput;
    int index = 0;
    do {
        currentInput = (char)getchar();
        string = (char *) realloc(string, sizeof(char) * (index + 1));
        string[index] = currentInput;
        index++;
        if(currentInput == '\r')
        {
            currentInput = (char)getchar();
        }
    } while((currentInput != '\n') && (currentInput != EOF));
    string[index - 1] = '\0';
    return string;
}

int cpfComparator(char *cpf1, char *cpf2){
    for(int i = 0; i < 15; i++){
        if((cpf1[i]-'0') > (cpf2[i]-'0')){
            return GREATER;
        }else if((cpf1[i]-'0') < (cpf2[i]-'0')){
            return LESSER;
        }
    }
    return EQUAL;
}

void removeDotsAndDashesFromCpf(char *cpf){
    char aux[15] = "";
    int i = 0;
    int j = 0;
    while (cpf[i] != '\0'){
        if(cpf[i] != '.' && cpf[i] != '-'){
            aux[j] = cpf[i];
            j++;
        }
        i++;
    }
    strcpy(cpf,aux);
}