#include "ponto.h"
#ifndef CAMINHO_H
#define CAMINHO_H

typedef struct caminho_ caminho_ST;

caminho_ST * criarCaminho(ponto_ST * pontos, int quantidadeDePontos);
void mostrarCaminhoPercorrido(caminho_ST * caminho);
void mostrarDistanciaEntrePontoFinalEInicial(caminho_ST * caminho);

#endif