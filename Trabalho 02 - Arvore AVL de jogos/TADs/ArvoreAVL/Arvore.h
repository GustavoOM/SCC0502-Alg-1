#ifndef ARVORE_H
#define ARVORE_H

#include "../Util/Util.h"
#include "../Jogo/Jogo.h"

#define DIREITA 0
#define ESQUERDA 1
#define IGUAL 2
#define ERRO_ARVORE_VAZIA -1000
#define max(a, b) ((a > b) ? a : b)

typedef struct arvore_st ARVORE;

ARVORE *alocarArvore();
void avl_apagar(ARVORE **arvore);
boolean  inserirJogoArvoreAVL(ARVORE *arvore, JOGO *jogo);
void imprimirArvoreInOrder(ARVORE *arvore);
void imprimirArvoreInPreOrder(ARVORE *arvore);
void imprimirArvoreInPosOrder(ARVORE *arvore);
boolean avlRemoveAno(ARVORE *arvore, int ano);

#endif