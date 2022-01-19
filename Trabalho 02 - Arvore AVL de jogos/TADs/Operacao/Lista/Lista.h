#ifndef LISTAOPERACOES_H
#define LISTAOPERACOES_H

#include "../Operacao.h"
#include "../../Lista/Lista.h"

typedef struct listaOperacoes_ LISTAOPERACOES;
LISTAOPERACOES * alocarListaOperacoes();
boolean listaInserirFimOperacoes(LISTAOPERACOES *lista, OPERACAO *operacao);
void imprimirOperacoes(LISTAOPERACOES * lista);
OPERACAO * getPrimeiraOperacao(LISTAOPERACOES * listaDeOperacoes);
void proximaOperacao(LISTAOPERACOES * listaDeOperacoes);
boolean inserirListaDeJogosNaListaDeOperacoes(LISTAOPERACOES *listaOperacoes, LISTA * listaDeJogos);
void operacaoPegarTodosJogos(LISTAOPERACOES *listaOperacoes);
void operacaoPegarJogoPorPosicao(LISTAOPERACOES *listaOperacoes, int index);
void operacaoPegarJogoPorAno(LISTAOPERACOES *listaOperacoes, int ano);
void operacaoPegarJogoPorProdutora(LISTAOPERACOES *listaOperacoes, char *produtora);
void operacaoMoverParaEsquerda(LISTAOPERACOES *listaOperacoes, int index, int posicoes);
void operacaoMoverParaDireita(LISTAOPERACOES *listaOperacoes, int index, int posicoes);
void operacaoRemoverDuplicados(LISTAOPERACOES *listaOperacoes);
void operacaoRemoverRepetidos(LISTA * lista);

#endif