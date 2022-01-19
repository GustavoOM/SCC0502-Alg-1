#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "carta.h"

struct carta_{
    char nipe[10];
    char simbolo[2];
    int valor;
};

carta_ST *criarCarta (const char *nipe, const char *simbolo, int valor){
    carta_ST *carta;

    carta = (carta_ST *) malloc(sizeof(carta_ST));

    if (carta != NULL){
        strcpy(carta->nipe, nipe);
        strcpy(carta->simbolo, simbolo);
        carta->valor = valor;
        return carta;
    }
    return NULL;
}

boolean deletarCarta(carta_ST **carta){
    if (*carta != NULL){
        (*carta)->valor = ERRO;
        free (*carta);
        *carta = NULL;
        return TRUE;
    }
    return FALSE;
}

void imprimirCarta(const carta_ST *carta){
    if (carta != NULL){
        printf("\nNipe: %s", carta->nipe);
        printf("\nSimbolo: %s", carta->simbolo);
        printf("\nValor: %d\n", carta->valor);
    }
}

int pontosDaCarta(const carta_ST *carta){
    return carta->valor;
}


int valorDoSimbolo(char *simbolo){
    if(!strcmp(simbolo,"1"))
        return 1;
    else if(!strcmp(simbolo,"2"))
        return 2;
    else if(!strcmp(simbolo,"3"))
        return 3;
    else if(!strcmp(simbolo,"4"))
        return 4;
    else if(!strcmp(simbolo,"5"))
        return 5;
    else if(!strcmp(simbolo,"6"))
        return 6;
    else if(!strcmp(simbolo,"7"))
        return 7;
    else if(!strcmp(simbolo,"8"))
        return 8;
    else if(!strcmp(simbolo,"9"))
        return 9;
    else if(!strcmp(simbolo,"10"))
        return 10;
    else if(!strcmp(simbolo,"V"))
        return 10;
    else if(!strcmp(simbolo,"D"))
        return 10;
    else if(!strcmp(simbolo,"R"))
        return 10;
    return -1;
}