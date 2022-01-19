#ifndef JOGO_H
#define JOGO_H

#define ERRO_JOGO -55000

#include "../Util/Util.h"

typedef struct jogo_st JOGO;
JOGO * alocarJogo();
boolean adicionaDadosAoJogo(JOGO * jogo, char * nome, int ano, char * produtora);
char * getNome(JOGO * jogo);
int getAno(JOGO * jogo);
char * getProdutora(JOGO * jogo);
void imprimirJogo(JOGO * jogo);
void imprimirNomeJogo(JOGO * jogo);

#endif