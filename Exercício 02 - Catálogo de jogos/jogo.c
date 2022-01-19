#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogo.h"

struct jogo_{
    char nome[50];
    char produtora[50];
    char ano[10];
};

jogo_ST * adicionarJogoNaLista(jogo_ST *jogos, int quantidadeDeJogos, char nome[], char produtora[], char ano[]){
    jogos = (jogo_ST*) realloc(jogos, quantidadeDeJogos * sizeof(jogo_ST));
    strcpy(jogos[quantidadeDeJogos-1].nome, nome);
    strcpy(jogos[quantidadeDeJogos-1].produtora, produtora);
    strcpy(jogos[quantidadeDeJogos-1].ano, ano);
    return jogos;
}

void mostrarJogos(jogo_ST *jogos, int quantidadeDeJogos){
    for (int i = 0; i < quantidadeDeJogos; i++){
        printf("JOGO %d: %s\n",i, jogos[i].nome);
        printf("%s\n", jogos[i].produtora);
        printf("%s\n", jogos[i].ano);
    }
}

void procurarPorJogos(jogo_ST *jogos, int quantidadeDeJogos, char operacao, char valor[]){
    int achou = 0;
    for(int i = 0; i < quantidadeDeJogos; i++){
        if(operacao == 'E'){
            if(!strcmp(jogos[i].produtora, valor)){
                printf("%s\n", jogos[i].nome);
                achou = 1;
            }
        }
        else if(operacao == 'A'){
            if(!strcmp(jogos[i].ano, valor)){
                printf("%s\n", jogos[i].nome);
                achou = 1;
            }
        }
    }
    if(!achou){
        printf("Nada encontrado\n");
    }

}