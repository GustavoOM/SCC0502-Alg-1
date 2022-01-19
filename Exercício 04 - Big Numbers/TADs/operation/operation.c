#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "operation.h"
#include "../util/util.h"
#include "../totalNumber/totalNumber.h"

struct operation_{
    char operationTag[10];
    char firstValue[DIGITS];
    char secondValue[DIGITS];
    char result[DIGITS+1];
    int firstValueQuantity;
    int secondValueQuantity;
};

operation_ST * allocOperations(int quantityOfOperations){
    operation_ST * operations = (operation_ST *) malloc(quantityOfOperations*sizeof(operation_ST));
    return operations;
}

void createOperation(operation_ST *operation, int index, char *operationTag, char *firstValue, char *secondValue){
    strcpy(operation[index].operationTag, operationTag);
    strcpy(operation[index].firstValue, firstValue);
    strcpy(operation[index].secondValue, secondValue);
    strcpy(operation[index].result, resultOperation(operationTag, firstValue, secondValue));
    
}

void showOperations(operation_ST *operation, int quantityOfOperations){
    for(int i = 0; i < quantityOfOperations; i++){
        printf("Resultado :: %s\n",operation[i].result);
    }
}