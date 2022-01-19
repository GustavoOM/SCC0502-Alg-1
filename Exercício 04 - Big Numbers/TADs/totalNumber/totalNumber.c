#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../util/util.h"
#include "../numberPart/numberPart.h"
#include "totalNumber.h"

typedef struct partNumberNode_ partNumberNode_ST;
struct partNumberNode_{
    numberPart_ST *numberPart;
    partNumberNode_ST *nextNumberPart; 
};

struct totalNumber_{
    partNumberNode_ST * firsPart;
    partNumberNode_ST * lastPart;
    int numberOfPartsNumbers;
    char signal;
};

void addLeftZeroInPart(char * part){
    char returnString[5] = "0000";
    int partLen = strlen(part);
    if(partLen == 1){
        returnString[3] = part[0];
    }
    else if(partLen == 2){
        returnString[2] = part[0];
        returnString[3] = part[1];
    }
    else if(partLen == 3){
        returnString[1] = part[0];
        returnString[2] = part[1];
        returnString[3] = part[2];
    }
    strcpy(part, returnString);
}

char * totalNumberToString(totalNumber_ST * totalNumber){
    char *returnString;
    returnString = (char*)malloc(sizeof(char) * 4*totalNumber->numberOfPartsNumbers+1);
    partNumberNode_ST * totalNumberAux;
    for(int i = totalNumber->numberOfPartsNumbers; i > 0; i--){
        totalNumberAux = totalNumber->firsPart;
        for(int j = 1; j < i; j++){
            totalNumberAux = totalNumberAux->nextNumberPart;
        }
        strncat(returnString, getStringPart(totalNumberAux->numberPart),5);
    }
    return returnString;
}

totalNumber_ST * createTotalNumber(){
    totalNumber_ST * totalNumber;
    totalNumber = (totalNumber_ST *) malloc(sizeof(totalNumber_ST));
    if (totalNumber == NULL){
        return NULL;
    }
    totalNumber->firsPart = NULL;
    totalNumber->lastPart = NULL;
    totalNumber->numberOfPartsNumbers = 0;
    totalNumber->signal = '+';
    return totalNumber;
}

boolean totalNumberIsEmpty(const totalNumber_ST * totalNumber){
    if(totalNumber == NULL){
        return TOTAL_NUMBER_NULL_ERROR;
    }
    return totalNumber->firsPart == NULL;
}

int insertPartInTotalNumber(totalNumber_ST * totalNumber, numberPart_ST *numberPart){
    
    if(totalNumber == NULL){
        return TOTAL_NUMBER_NULL_ERROR;
    }
    
    partNumberNode_ST *newPartNumberNode = (partNumberNode_ST *) malloc(sizeof(partNumberNode_ST));
    
    if(newPartNumberNode == NULL){
        return PART_NUMBER_NODE_NULL_ERROR;
    }

    newPartNumberNode->numberPart = numberPart;
    newPartNumberNode->nextNumberPart = NULL;
    if(totalNumberIsEmpty(totalNumber)){
        totalNumber->firsPart = newPartNumberNode;
    }
    else{
        totalNumber->lastPart->nextNumberPart = newPartNumberNode;
    }
    totalNumber->lastPart = newPartNumberNode;
    totalNumber->numberOfPartsNumbers++;
    return TRUE;
}

boolean hasSignal(char * number){
    if(number[0] == '-')
        return TRUE;
    return FALSE;
}

void removeFirstChar(char * originalString, int charCount){
    char * newString;
    newString = malloc(sizeof(char)*charCount);
    for(int i = 0; i < charCount; i++){
        newString[i] = originalString[i+1];
    }
    strcpy(originalString,newString);
}

void removeLeftZeros(char * zeroValue, int charCount){
    char * unZeroValue;
    unZeroValue = malloc(sizeof(char)*charCount);
    int i = 0;
    while (i < charCount){
        if(zeroValue[i] != '0' && zeroValue[i] != '\0'){
            for(int j = i; j < charCount; j++){
                unZeroValue[j-i] = zeroValue[j];
            }    
            strcpy(zeroValue,unZeroValue);
            return;
        }
        i++;
    }
    strcpy(zeroValue,"0");
}

void printTotalNumber(totalNumber_ST * totalNumber){
    partNumberNode_ST * totalNumberAux = totalNumber->firsPart;
    while(totalNumberAux != NULL){
        printPart(totalNumberAux->numberPart);
        totalNumberAux = totalNumberAux->nextNumberPart;
    }
    printf("\n");
}

char * totalNumberOperationSum(totalNumber_ST * firstValueLL, totalNumber_ST * secondValueLL){
    if(firstValueLL == NULL || secondValueLL == NULL || firstValueLL->numberOfPartsNumbers == 0 || secondValueLL->numberOfPartsNumbers == 0){
        return "0";
    }
    totalNumber_ST * result = createTotalNumber();
    totalNumber_ST * biggestPart;
    totalNumber_ST * leastPart;
    if(firstValueLL->numberOfPartsNumbers >= secondValueLL->numberOfPartsNumbers){
        biggestPart = firstValueLL;
        leastPart = secondValueLL;
    }
    else{
        biggestPart = secondValueLL;
        leastPart = firstValueLL;
    }
    partNumberNode_ST * biggestPartAuxNode = biggestPart->firsPart;
    partNumberNode_ST * leastPartAuxNode = leastPart->firsPart;
    int sum = 0;
    int carry = 0;
    char buffer[6] = "";
    
    for(int i = 0; i < biggestPart->numberOfPartsNumbers; i++){
        if(leastPart->numberOfPartsNumbers > i){
            sum = getVeluePart(biggestPartAuxNode->numberPart) + getVeluePart(leastPartAuxNode->numberPart) + carry;
        }
        else{
            sum = getVeluePart(biggestPartAuxNode->numberPart) + carry;
        }
        itoa(sum,buffer);
        //printf("1º: %d 2º: %d SUM: %d -> %s \n",getVeluePart(biggestPartAuxNode->numberPart), getVeluePart(leastPartAuxNode->numberPart), sum, buffer);
        if(sum >= 10000){
            removeFirstChar(buffer,5);
            carry = 1;
        }
        else{
            carry = 0;
        }
        if(sum < 1000 && biggestPartAuxNode->nextNumberPart != NULL){
            addLeftZeroInPart(buffer);
        }
        insertPartInTotalNumber(result, createPart(buffer));
        biggestPartAuxNode = biggestPartAuxNode->nextNumberPart;
        if(leastPartAuxNode->nextNumberPart != NULL){
            leastPartAuxNode = leastPartAuxNode->nextNumberPart;
        }
    }
    if(carry == 1){
        insertPartInTotalNumber(result, createPart("1"));
    }

    return totalNumberToString(result);
       
}

char * totalNumberOperationIquals(totalNumber_ST * firstValueLL, totalNumber_ST * secondValueLL){
    if(firstValueLL->signal != secondValueLL->signal){
        return "False";
    }
    if(firstValueLL->numberOfPartsNumbers != secondValueLL->numberOfPartsNumbers){
        return "False";
    }
    partNumberNode_ST * firstValueLLAux = firstValueLL->firsPart;
    partNumberNode_ST * secondValueLLAux = secondValueLL->firsPart;
    while(firstValueLLAux != NULL){
        if(getVeluePart(firstValueLLAux->numberPart) != getVeluePart(secondValueLLAux->numberPart)){
            return "False";
        }
        firstValueLLAux = firstValueLLAux->nextNumberPart;
        secondValueLLAux = secondValueLLAux->nextNumberPart;
    }
    return "True";
}

char * totalNumberOperationBiggerThan(totalNumber_ST * firstValueLL, totalNumber_ST * secondValueLL){
    if(firstValueLL->signal == '-' && secondValueLL->signal == '+'){
        return "False";
    }
    else if(firstValueLL->signal == '+' && secondValueLL->signal == '-'){
        return "True";
    }
    else if(firstValueLL->signal == '-' && secondValueLL->signal == '-'){
        if(firstValueLL->numberOfPartsNumbers > secondValueLL->numberOfPartsNumbers){
            return "False";
        }
        else if(firstValueLL->numberOfPartsNumbers < secondValueLL->numberOfPartsNumbers){
            return "True";
        }
        partNumberNode_ST * firstValueLLAux;
        partNumberNode_ST * secondValueLLAux;
        for(int i = firstValueLL->numberOfPartsNumbers; i > 0; i--){
            firstValueLLAux = firstValueLL->firsPart;
            secondValueLLAux = secondValueLL->firsPart;
            for(int j = 1; j < i; j++){
                firstValueLLAux = firstValueLLAux->nextNumberPart;
                secondValueLLAux = secondValueLLAux->nextNumberPart;
            }
            if(getVeluePart(firstValueLLAux->numberPart)<getVeluePart(secondValueLLAux->numberPart)){
                return "True";
            }
            else if(getVeluePart(firstValueLLAux->numberPart)>getVeluePart(secondValueLLAux->numberPart)){
                return "False";
            }
        }
    }
    else if(firstValueLL->signal == '+' && secondValueLL->signal == '+'){
        if(firstValueLL->numberOfPartsNumbers < secondValueLL->numberOfPartsNumbers){
            return "False";
        }
        else if(firstValueLL->numberOfPartsNumbers > secondValueLL->numberOfPartsNumbers){
            return "True";
        }
        partNumberNode_ST * firstValueLLAux;
        partNumberNode_ST * secondValueLLAux;
        for(int i = firstValueLL->numberOfPartsNumbers; i > 0; i--){
            firstValueLLAux = firstValueLL->firsPart;
            secondValueLLAux = secondValueLL->firsPart;
            for(int j = 1; j < i; j++){
                firstValueLLAux = firstValueLLAux->nextNumberPart;
                secondValueLLAux = secondValueLLAux->nextNumberPart;
            }
            if(getVeluePart(firstValueLLAux->numberPart)<getVeluePart(secondValueLLAux->numberPart)){
                return "False";
            }
            else if(getVeluePart(firstValueLLAux->numberPart)>getVeluePart(secondValueLLAux->numberPart)){
                return "True";
            }
        }
    }
    return "False";
}

char * totalNumberOperationLessThan(totalNumber_ST * firstValueLL, totalNumber_ST * secondValueLL){
    if(firstValueLL->signal == '-' && secondValueLL->signal == '+'){
        return "True";
    }
    else if(firstValueLL->signal == '+' && secondValueLL->signal == '-'){
        return "False";
    }
    else if(firstValueLL->signal == '-' && secondValueLL->signal == '-'){
        if(firstValueLL->numberOfPartsNumbers > secondValueLL->numberOfPartsNumbers){
            return "True";
        }
        else if(firstValueLL->numberOfPartsNumbers < secondValueLL->numberOfPartsNumbers){
            return "False";
        }
        partNumberNode_ST * firstValueLLAux;
        partNumberNode_ST * secondValueLLAux;
        for(int i = firstValueLL->numberOfPartsNumbers; i > 0; i--){
            firstValueLLAux = firstValueLL->firsPart;
            secondValueLLAux = secondValueLL->firsPart;
            for(int j = 1; j < i; j++){
                firstValueLLAux = firstValueLLAux->nextNumberPart;
                secondValueLLAux = secondValueLLAux->nextNumberPart;
            }
            if(getVeluePart(firstValueLLAux->numberPart)<getVeluePart(secondValueLLAux->numberPart)){
                return "False";
            }
            else if(getVeluePart(firstValueLLAux->numberPart)>getVeluePart(secondValueLLAux->numberPart)){
                return "True";
            }
        }
    }
    else if(firstValueLL->signal == '+' && secondValueLL->signal == '+'){
        if(firstValueLL->numberOfPartsNumbers < secondValueLL->numberOfPartsNumbers){
            return "True";
        }
        else if(firstValueLL->numberOfPartsNumbers > secondValueLL->numberOfPartsNumbers){
            return "False";
        }
        partNumberNode_ST * firstValueLLAux;
        partNumberNode_ST * secondValueLLAux;
        for(int i = firstValueLL->numberOfPartsNumbers; i > 0; i--){
            firstValueLLAux = firstValueLL->firsPart;
            secondValueLLAux = secondValueLL->firsPart;
            for(int j = 1; j < i; j++){
                firstValueLLAux = firstValueLLAux->nextNumberPart;
                secondValueLLAux = secondValueLLAux->nextNumberPart;
            }
            if(getVeluePart(firstValueLLAux->numberPart)<getVeluePart(secondValueLLAux->numberPart)){
                return "True";
            }
            else if(getVeluePart(firstValueLLAux->numberPart)>getVeluePart(secondValueLLAux->numberPart)){
                return "False";
            }
        }
    }
    return "False";
}

char * makeOperation(char * operationTag, totalNumber_ST * firstValueLL, totalNumber_ST * secondValueLL){
    if(!strcmp(operationTag, "soma")){
        return totalNumberOperationSum(firstValueLL,secondValueLL);
    }
    else if(!strcmp(operationTag, "igual")){
        return totalNumberOperationIquals(firstValueLL,secondValueLL);
    }
    else if(!strcmp(operationTag, "maior")){
        return totalNumberOperationBiggerThan(firstValueLL,secondValueLL);
    }
    else if(!strcmp(operationTag, "menor")){
        return totalNumberOperationLessThan(firstValueLL,secondValueLL);;
    }
    else{
        return "Invalid operation";
    }
}

char * resultOperation(char *operationTag, char *firstValue, char *secondValue){
    totalNumber_ST * firstValueLL = createTotalNumber();
    totalNumber_ST * secondValueLL = createTotalNumber();
    if(hasSignal(firstValue)){
        removeFirstChar(firstValue,countChars(firstValue));
        firstValueLL->signal = '-';
    }
    if(hasSignal(secondValue)){
        removeFirstChar(secondValue,countChars(secondValue));
        secondValueLL->signal = '-';
    }
    removeLeftZeros(firstValue,countChars(firstValue));
    removeLeftZeros(secondValue,countChars(secondValue));

    int firstValueSize = countChars(firstValue);
    int secondValueSize = countChars(secondValue);

    

    int firstValueAux = firstValueSize/4 + 1;
    if(!firstValueSize%4){
        firstValueAux--;
    }
    int secondValueAux = secondValueSize/4 + 1;
    if(!secondValueSize%4){
        secondValueAux--;
    }

    char part[5];
    strcpy(part, "    ");

    while (firstValueSize > 3){
        if(firstValueSize-4 >= 0){
            for(int i = 0; i < 4; i++){
                part[i] = firstValue[firstValueSize - (4-i)];
            }
            insertPartInTotalNumber(firstValueLL,createPart(part));
        }
        firstValueSize -= 4;
    }
    if(firstValueSize == 3){
        part[0] = ' ';
        part[1] = firstValue[firstValueSize - 3];
        part[2] = firstValue[firstValueSize - 2];
        part[3] = firstValue[firstValueSize - 1];
        insertPartInTotalNumber(firstValueLL,createPart(part));
    }
    else if(firstValueSize == 2){
        part[0] = ' ';
        part[1] = ' ';
        part[2] = firstValue[firstValueSize - 2];
        part[3] = firstValue[firstValueSize - 1];
        insertPartInTotalNumber(firstValueLL,createPart(part));
    }
    else if(firstValueSize == 1){
        part[0] = ' ';
        part[1] = ' ';
        part[2] = ' ';
        part[3] = firstValue[firstValueSize - 1];
        insertPartInTotalNumber(firstValueLL,createPart(part));
    }
    
    while (secondValueSize > 3){
        if(secondValueSize-4 >= 0){
            part[0] = secondValue[secondValueSize - 4];
            part[1] = secondValue[secondValueSize - 3];
            part[2] = secondValue[secondValueSize - 2];
            part[3] = secondValue[secondValueSize - 1];
            insertPartInTotalNumber(secondValueLL,createPart(part));
        }
        secondValueSize -= 4;
    }
    if(secondValueSize == 3){
        part[0] = ' ';
        part[1] = secondValue[secondValueSize - 3];
        part[2] = secondValue[secondValueSize - 2];
        part[3] = secondValue[secondValueSize - 1];
        insertPartInTotalNumber(secondValueLL,createPart(part));
    }
    else if(secondValueSize == 2){
        part[0] = ' ';
        part[1] = ' ';
        part[2] = secondValue[secondValueSize - 2];
        part[3] = secondValue[secondValueSize - 1];
        insertPartInTotalNumber(secondValueLL,createPart(part));
    }
    else if(secondValueSize == 1){
        part[0] = ' ';
        part[1] = ' ';
        part[2] = ' ';
        part[3] = secondValue[secondValueSize - 1];
        insertPartInTotalNumber(secondValueLL,createPart(part));
    }
    
    return makeOperation(operationTag, firstValueLL, secondValueLL);
}