#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"
#include "caminho.h"

struct caminho_{
    ponto_ST *pontos;
    float distanciaCaminho;
    float distanciaPontoInicialParaPontoFinal;
};

//Funções locais que não são exportadas para main
float calcularDistanciaDeTodosPontos(ponto_ST * pontos, int quantidadeDePontos);
float calcularDistanciaPontoInicialParaPontoFinal(ponto_ST * pontos, int quantidadeDePontos);

float calcularDistanciaDeTodosPontos(ponto_ST * pontos, int quantidadeDePontos){
    float distanciaTotal = 0;
    for(int i = 0; i < quantidadeDePontos-1; i++){
        distanciaTotal += distanciaEntreDoisPontos(pontos, i, i+1);
    }
    return distanciaTotal;
}

float calcularDistanciaPontoInicialParaPontoFinal(ponto_ST * pontos, int quantidadeDePontos){
    return distanciaEntreDoisPontos(pontos, 0, quantidadeDePontos - 1);
}


//Funções exportadas
caminho_ST * criarCaminho(ponto_ST * pontos, int quantidadeDePontos){
    caminho_ST *caminho;
    caminho = (caminho_ST *) calloc(1, sizeof(caminho_ST));
    caminho->pontos = pontos;
    caminho->distanciaCaminho = calcularDistanciaDeTodosPontos(pontos, quantidadeDePontos);
    caminho->distanciaPontoInicialParaPontoFinal = calcularDistanciaPontoInicialParaPontoFinal(pontos, quantidadeDePontos);
    return caminho;
}

void mostrarCaminhoPercorrido(caminho_ST * caminho){
    printf("%.2f\n", caminho->distanciaCaminho);
}

void mostrarDistanciaEntrePontoFinalEInicial(caminho_ST * caminho){
    printf("%.2f\n", caminho->distanciaPontoInicialParaPontoFinal);
}