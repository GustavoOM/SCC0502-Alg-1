#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

struct ponto_{
    float x;
    float y;
};

ponto_ST * criarPontos(int quantidadeDePontos){
    ponto_ST *pontos;
    pontos = (ponto_ST *) calloc(quantidadeDePontos, sizeof(ponto_ST));
    for(int i = 0; i < quantidadeDePontos; i++){
        scanf("%f", &pontos[i].x);
        scanf("%f", &pontos[i].y);
    }
    return pontos;
}

void mostrarPontos(ponto_ST * pontos, int quantidadeDePontosMostrados){
    for(int i = 0; i < quantidadeDePontosMostrados; i++){
        printf("%f %f\n", pontos[i].x, pontos[i].y);
    }
}

float distanciaEntreDoisPontos(ponto_ST * pontos, int indexInicial, int indexFinal){
    return sqrt(pow(pontos[indexInicial].x-pontos[indexFinal].x,2) + pow(pontos[indexInicial].y-pontos[indexFinal].y,2));
}