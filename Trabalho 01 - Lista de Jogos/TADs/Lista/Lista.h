#ifndef LISTA_H
#define LISTA_H

#include "../Util/Util.h"
#include "../Jogo/Jogo.h"
#include "../Lista/Lista.h"

#define IS_REPETIDO_FLAG -1

#define ERRO_LISTA -33000
#define JOGO_REFERENCIA_FLAG 1
#define NAO_SELECIONADO_FLAG 0
typedef struct lista_st LISTA;
LISTA * alocarLista();
boolean isListaVazia(const LISTA * lista);
boolean listaInserirFim(LISTA *lista, JOGO *jogo); 
void listaRemoverRepetidos(LISTA * lista);
void listaImprimirJogos(LISTA * lista);
void listaImprimirNomePelaPosicao(LISTA * lista, int index);
void listaImprimirTodosOsNomes(LISTA * lista);
void listaImprimirNomePorAno(LISTA *lista, int ano);
void listaImprimirNomePorProdutora(LISTA * lista, char *produtora);
boolean isJogoIgual(JOGO *jogoReferencia, JOGO *proximoJogo);
int listaGetTamanho(LISTA *lista);
void listaMover(LISTA* lista, int index, int posicao);


#endif