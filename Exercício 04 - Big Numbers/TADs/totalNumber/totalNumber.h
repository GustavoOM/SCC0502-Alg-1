#include "../util/util.h"
#ifndef TOTALNUMBER_H
#define TOTALNUMBER_H

typedef struct totalNumber_ totalNumber_ST;

totalNumber_ST * createTotalNumber();
boolean totalNumberIsEmpty(const totalNumber_ST * totalNumber);
char * resultOperation(char *operationTag, char *firstValue, char *secondValue);
#endif