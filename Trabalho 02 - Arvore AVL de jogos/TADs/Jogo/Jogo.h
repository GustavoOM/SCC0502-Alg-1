#ifndef JOGO_H
#define JOGO_H

#define ERRO_JOGO -55000

#include "../Util/Util.h"

typedef struct jogo_st JOGO;
JOGO * alocarJogo();
boolean adicionaDadosAoJogo(JOGO * jogo, char * nome, int ano, char * produtora);
const char * getNome(const JOGO * jogo);
int getAno(const JOGO * jogo);
const char * getProdutora(const JOGO * jogo);
void imprimirJogo(JOGO * jogo);
void imprimirNomeJogo(JOGO * jogo);
void imprimeJogo(JOGO * jogo);
boolean apagaJogo(JOGO **jogo);

#endif