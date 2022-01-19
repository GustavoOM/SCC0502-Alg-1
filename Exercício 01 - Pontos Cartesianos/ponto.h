#include <math.h>
#ifndef PONTO_H
#define PONTO_H

typedef struct ponto_ ponto_ST;

ponto_ST * criarPontos(int quantidadeDePontos);
void mostrarPontos(ponto_ST * pontos, int quantidadeDePontosMostrados);
float distanciaEntreDoisPontos(ponto_ST * pontos, int indexIncial, int indexFinal);

#endif