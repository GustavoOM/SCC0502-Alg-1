#include "../util/util.h"
#ifndef NUMBERPART_H
#define NUMBERPART_H

typedef struct numberPart_ numberPart_ST;

numberPart_ST *createPart (char *value);
int getVeluePart(const numberPart_ST *numberPart);
void printPart(const numberPart_ST *numberPart);
char * getStringPart(numberPart_ST *numberPart);

#endif