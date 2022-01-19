#ifndef OPERACAO_H
#define OPERACAO_H

#include "../Lista/Lista.h"

#define OPERACAO_A 1
#define OPERACAO_R 2
#define OPERACAO_P 3
#define OPERACAO_U 4
#define OPERACAO_I 5
#define OPERACAO_MR 6
#define OPERACAO_ML 7
#define OPERACAO_F 8

#define F_FLAG -1
#define ERRO_OPERACAO -9000
typedef struct operacao_st OPERACAO;

OPERACAO * alocarOperacao();
boolean adicionarDadosAOperacao(OPERACAO * operacao, char * tag, char * entrada1, char * entrada2);
int getCharSetNumero(OPERACAO *operacao);
void realizarOperacao(LISTA * listaJogos);
void inputOperacao(OPERACAO *operacao);
void imprimirOperacao(OPERACAO * operacao);

#endif