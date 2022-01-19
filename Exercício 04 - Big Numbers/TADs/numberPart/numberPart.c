#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "numberPart.h"

struct numberPart_{
    char numberValue[5];
};

numberPart_ST *createPart (char *value){
    numberPart_ST *numberPart;

    numberPart = (numberPart_ST *) malloc(sizeof(numberPart_ST));

    if (numberPart == NULL){
        return NULL;
    }

    strcpy(numberPart->numberValue, value);
    return numberPart;
}

// boolean deletarCarta(carta_ST **carta){
//     if (*carta != NULL){
//         (*carta)->valor = ERRO;
//         free (*carta);
//         *carta = NULL;
//         return TRUE;
//     }
//     return FALSE;
// }

void printPart(const numberPart_ST *numberPart){
    if (numberPart != NULL){
        printf("%s ", numberPart->numberValue);
    }
}

int getVeluePart(const numberPart_ST *numberPart){
    return atoi(numberPart->numberValue);
}

char * getStringPart(numberPart_ST *numberPart){
    return numberPart->numberValue;
}


