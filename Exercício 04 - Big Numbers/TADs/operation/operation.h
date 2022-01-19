#include "../util/util.h"
#ifndef OPERATION_H
#define OPERATION_H

typedef struct operation_ operation_ST;

operation_ST * allocOperations(int quantityOfOperations);
void createOperation (operation_ST *operation, int index, char *operationTag, char *firstValue, char *secondValue);
void showOperations(operation_ST *operation, int quantityOfOperations);

#endif