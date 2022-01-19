#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Jogo/Jogo.h"
#include "../Util/Util.h"
#include "Arvore.h"

typedef struct node_st NODE;

struct node_st
{
    JOGO *jogo;
    NODE *direita;
    NODE *esquerda;
    int altura;
};

static void avl_apagar_aux(NODE **raiz);

static NODE *avl_inserir_no_e_rotacionar(NODE *raiz, JOGO *jogo);

static boolean desbalanceamentoIsNegativo(NODE *raiz);

static boolean desbalanceamentoIsPositivo(NODE *raiz);

static boolean jogoIsMaior(const NODE *raiz, const JOGO *jogo);

static boolean jogoIsMenor(const NODE *raiz, const JOGO *jogo);

static NODE *selecionar_e_executar_rotacao(NODE *raiz, const JOGO *jogo);

static NODE *inserir_no(NODE *raiz, JOGO *jogo);

static void imprimirNodeInOrder(NODE *raiz);

static void imprimirNodeInPreOrder(NODE *raiz);

static void imprimirNodeInPosOrder(NODE *raiz);

NODE * procuraMenor(NODE * atual);

static void trocarMaximoEsquerda(NODE * switchNode, NODE * raiz, NODE * previous);

static NODE *avlGiraArvoreAltura(NODE **raiz);

static NODE *avlRemoveAnoAux(NODE **raiz, int ano, boolean *auxiliar);

struct arvore_st{
    NODE* raiz;
    int profundidade;
    int quantidade;
};

ARVORE *alocarArvore() {
    ARVORE *arvore = (ARVORE *) malloc(sizeof(ARVORE));
    if (arvore != NULL) {
        arvore->raiz = NULL;
        arvore->profundidade = -1;
    }
    return arvore;
}

static void avl_apagar_aux(NODE **raiz) {
    if (*raiz != NULL) {
        avl_apagar_aux(&((*raiz)->esquerda));
        avl_apagar_aux(&((*raiz)->direita));
        apagaJogo(&(*raiz)->jogo);
        free(*raiz);
    }
}

void avl_apagar(ARVORE **arvore) {
    avl_apagar_aux(&(*arvore)->raiz);
    free(*arvore);
    *arvore = NULL;
}

int avlAlturaNode(NODE* raiz) {
    if (raiz == NULL) {
        return -1;
    } else {
        return raiz->altura;
    }
}

static NODE *avl_cria_no(JOGO *jogo) {
    NODE *no = (NODE *) malloc(sizeof (NODE));
    if (no != NULL) {
        no->altura = 0;
        no->direita = NULL;
        no->esquerda = NULL;
        no->jogo = jogo;
    }
    return no;
}

static NODE *rodar_direita(NODE *a) {
    NODE *b = a->esquerda;
    a->esquerda = b->direita;
    b->direita = a;

    a->altura = max(avlAlturaNode(a->esquerda),
                    avlAlturaNode(a->direita)) + 1;
    b->altura = max(avlAlturaNode(b->esquerda),
                    a->altura) + 1;
    return b;
}

static NODE *rodar_esquerda(NODE *a) {
    NODE *b = a->direita;
    a->direita = b->esquerda;
    b->esquerda = a;

    a->altura = max(avlAlturaNode(a->esquerda),
                    avlAlturaNode(a->direita)) + 1;
    b->altura = max(avlAlturaNode(b->direita),
                    a->altura) + 1;
    return b;
}

static NODE *rodar_esquerda_direita(NODE *a)   {
    a->esquerda = rodar_esquerda(a->esquerda);
    return rodar_direita(a);
}

static NODE *rodar_direita_esquerda(NODE *a)   {
    a->direita = rodar_direita(a->direita);
    return rodar_esquerda(a);
}

static NODE *avl_inserir_no_e_rotacionar(NODE *raiz, JOGO *jogo) {
    raiz = inserir_no(raiz, jogo);

    raiz->altura = max(avlAlturaNode(raiz->esquerda),
                       avlAlturaNode(raiz->direita)) + 1;

    raiz = selecionar_e_executar_rotacao(raiz, jogo);

    return raiz;
}

static NODE *inserir_no(NODE *raiz, JOGO *jogo) {
    if (raiz == NULL) {
        raiz = avl_cria_no(jogo);
    }
    else if (jogoIsMaior(raiz, jogo)) {
        raiz->direita = avl_inserir_no_e_rotacionar(raiz->direita, jogo);
    }
    else if (jogoIsMenor(raiz, jogo)) {
        raiz->esquerda = avl_inserir_no_e_rotacionar(raiz->esquerda, jogo);
    }
    return raiz;
}

static NODE *selecionar_e_executar_rotacao(NODE *raiz, const JOGO *jogo) {
    if (desbalanceamentoIsNegativo(raiz)) {
        if (jogoIsMaior(raiz->direita, jogo)) {
            raiz = rodar_esquerda(raiz);
        }
        else {
            raiz = rodar_direita_esquerda(raiz);
        }
    }

    if (desbalanceamentoIsPositivo(raiz)) {
        if (jogoIsMenor(raiz->esquerda, jogo))
            raiz = rodar_direita(raiz);
        else
            raiz = rodar_esquerda_direita(raiz);
    }
    return raiz;
}

static boolean jogoIsMenor(const NODE *raiz, const JOGO *jogoInserido) {
  if(raiz == NULL || jogoInserido == NULL){
    return ERRO_JOGO;
  }
  if(getAno(raiz->jogo) > getAno(jogoInserido)){
    return TRUE;
  }
  if(getAno(raiz->jogo) < getAno(jogoInserido)){
    return FALSE;
  }
  if(strcmp(getNome(raiz->jogo), getNome(jogoInserido)) > 0){
    return TRUE;
  }
  if(strcmp(getNome(raiz->jogo), getNome(jogoInserido)) < 0){
    return FALSE;
  }
  return ERRO_JOGO;
}

static boolean jogoIsMaior(const NODE *raiz, const JOGO *jogoInserido) {
  if(raiz == NULL || jogoInserido == NULL){
    return ERRO_JOGO;
  }
  if(getAno(raiz->jogo) < getAno(jogoInserido)){
    return TRUE;
  }
  if(getAno(raiz->jogo) > getAno(jogoInserido)){
    return FALSE;
  }
  if(strcmp(getNome(raiz->jogo), getNome(jogoInserido)) < 0){
    return TRUE;
  }
  if(strcmp(getNome(raiz->jogo), getNome(jogoInserido)) > 0){
    return FALSE;
  }
  return ERRO_JOGO;
}

static boolean desbalanceamentoIsPositivo(NODE *raiz) {
    return avlAlturaNode(raiz->esquerda)
               - avlAlturaNode(raiz->direita) == 2;
}

static boolean desbalanceamentoIsNegativo(NODE *raiz) {
    return avlAlturaNode(raiz->esquerda)
               - avlAlturaNode(raiz->direita) == -2;
}

boolean  inserirJogoArvoreAVL(ARVORE *arvore, JOGO *jogo) {
    arvore->raiz = avl_inserir_no_e_rotacionar(arvore->raiz, jogo);
    return arvore->raiz != NULL;
}

void imprimirArvoreInOrder(ARVORE *arvore){
    imprimirNodeInOrder(arvore->raiz);

}

static void imprimirNodeInOrder(NODE *raiz){
    if(raiz != NULL){
        imprimirNodeInOrder(raiz->esquerda);
        imprimirNomeJogo(raiz->jogo);
        printf("\n");
        imprimirNodeInOrder(raiz->direita);
    }
}

void imprimirArvoreInPreOrder(ARVORE *arvore){
    imprimirNodeInPreOrder(arvore->raiz);
}

static void imprimirNodeInPreOrder(NODE *raiz){
    if(raiz != NULL){
        imprimirNomeJogo(raiz->jogo);
        printf("\n");
        imprimirNodeInPreOrder(raiz->esquerda);
        imprimirNodeInPreOrder(raiz->direita);
    }
}

void imprimirArvoreInPosOrder(ARVORE *arvore){
    imprimirNodeInPosOrder(arvore->raiz);

}

static void imprimirNodeInPosOrder(NODE *raiz){
    if(raiz != NULL){
        imprimirNodeInPosOrder(raiz->esquerda);
        imprimirNodeInPosOrder(raiz->direita);
        imprimirNomeJogo(raiz->jogo);
        printf("\n");
    }
}

//Realiza o balanceamento da arvore de acordo com a altura de cada nó
static NODE *avlGiraArvoreAltura(NODE **raiz){
    if (*raiz != NULL) {
        if (avlAlturaNode((*raiz)->esquerda) - avlAlturaNode((*raiz)->direita) == -2) {
            if (avlAlturaNode((*raiz)->direita->esquerda) - avlAlturaNode((*raiz)->direita->direita) <= 0) {
                *raiz = rodar_esquerda(*raiz);
            } else {
                *raiz = rodar_direita_esquerda(*raiz);
            }
        }

        if (avlAlturaNode((*raiz)->esquerda) - avlAlturaNode((*raiz)->direita) == 2) {
            if (avlAlturaNode((*raiz)->esquerda->esquerda) - avlAlturaNode((*raiz)->esquerda->direita) >= 0) {
                *raiz = rodar_direita(*raiz);
            } else {
                *raiz = rodar_esquerda_direita(*raiz);
            }
        }
    }
    return *raiz;
}

//Recebe a raiz e procura o ano a ser removido, retorna a raiz e se a remocao
//foi realizada com sucesso
static NODE *avlRemoveAnoAux(NODE **raiz, int ano, boolean *auxiliar) {
    NODE *nodeAux;
    if ((*raiz) == NULL) {
        return NULL;
    }
    if (ano == getAno((*raiz)->jogo)) {
        if ((*raiz)->esquerda == NULL || (*raiz)->direita == NULL) {
            nodeAux = *raiz;
            if((*raiz)->esquerda == NULL){
              (*raiz) = ((*raiz)->direita);
            }
            else{
              (*raiz) = ((*raiz)->esquerda);
            }
            apagaJogo(&nodeAux->jogo);
            free(nodeAux);
            nodeAux = NULL;
        } 
        else {
            trocarMaximoEsquerda((*raiz)->esquerda, (*raiz), (*raiz));
        }
        *auxiliar = TRUE;
    }

    else if (ano < getAno((*raiz)->jogo)) {
        (*raiz)->esquerda = avlRemoveAnoAux(&(*raiz)->esquerda, ano, auxiliar);
        (*raiz)->altura = max(avlAlturaNode((*raiz)->esquerda), avlAlturaNode((*raiz)->direita)) + 1;
    }

    else if (ano > getAno((*raiz)->jogo)) {
        (*raiz)->direita = avlRemoveAnoAux(&(*raiz)->direita, ano, auxiliar);
        (*raiz)->altura = max(avlAlturaNode((*raiz)->esquerda), avlAlturaNode((*raiz)->direita)) + 1;
    }
    (*raiz) = avlGiraArvoreAltura(raiz);    
    return *raiz;
}

//Funcao principal de remocao que aparece na main
boolean avlRemoveAno(ARVORE *arvore, int ano) {
    boolean removido = FALSE;
    arvore->raiz = avlRemoveAnoAux(&arvore->raiz, ano, &removido);
    if (removido)
        return TRUE;
    return FALSE;
}

static void trocarMaximoEsquerda(NODE * switchNode, NODE * raiz, NODE * previous){
    if(switchNode->direita != NULL){
        trocarMaximoEsquerda(switchNode->direita,raiz,switchNode);
        return;
    }
    if(raiz == previous){
        previous->esquerda = switchNode->esquerda;
    }
    else{
        previous->direita = switchNode->esquerda;
    }
    raiz->jogo = switchNode->jogo;
    free(switchNode);
    switchNode = NULL;
}
