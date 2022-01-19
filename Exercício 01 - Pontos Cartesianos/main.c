#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"
#include "caminho.h"

int main(){

    //Pegar quantidade de pontos
    int quantidadeDePontos;
    scanf("%d", &quantidadeDePontos);

    //Alocar a quantidade de pontos e ler cada ponto
    ponto_ST *pontos;
    pontos = criarPontos(quantidadeDePontos);

    //Criar o objeto caminho e mostrar a propriedade distancia
    caminho_ST *caminho;
    caminho = criarCaminho(pontos, quantidadeDePontos);
    mostrarCaminhoPercorrido(caminho);

    //Encerrar Programa liberando a memória alocada
    free(pontos);
    free(caminho);
    return 0;
}