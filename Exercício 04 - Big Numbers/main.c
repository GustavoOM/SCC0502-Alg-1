#include <stdio.h>
#include "./TADs/util/util.h"
#include "./TADs/operation/operation.h"

int main(){
    int quantityOfOperations;
    if(!scanf("%d",&quantityOfOperations)){
        return 0;
    }
    operation_ST *operations = allocOperations(quantityOfOperations);
    char operationTag[10];
    char firstValue[39];
    char secondValue[39];
    for(int i = 0; i < quantityOfOperations; i++){
        if(!scanf("%s %s %s",operationTag,firstValue,secondValue)){
            return 0;
        }
        createOperation(operations,i,operationTag,firstValue,secondValue);
    }
    showOperations(operations,quantityOfOperations);
    return 0;
}