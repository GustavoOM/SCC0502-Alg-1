#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include "../Jogo/Jogo.h"
#include "../Util/Util.h"

typedef struct node_st NODE;

struct node_st{
    JOGO *jogo;
    NODE *proximo;
    NODE *anterior; 
};

struct lista_st{
    NODE * primeiro;
    NODE * ultimo;
    int quantidadeDeJogos;
};


void verSeNodeEstaNaExtremidade(LISTA *lista, const NODE *nodeAux);
static void listaCopiarJogo(NODE *copiaNode, JOGO *jogoCopiado);

LISTA * alocarLista(){
  LISTA * lista;
  lista = (LISTA *) malloc(sizeof(LISTA));

  if(lista == NULL){
    return NULL;
  }
  lista->primeiro = NULL;
  lista->ultimo = NULL;
  lista->quantidadeDeJogos = 0;
  return lista;
}

boolean isListaVazia(const LISTA * lista){
    if(lista != NULL){
        if(lista->primeiro == NULL){
            return TRUE;
        }
    }
    return FALSE;
}

boolean listaInserirFim(LISTA *lista, JOGO *jogo)
{
    if (lista == NULL){
      return FALSE;
    }
    
    NODE *pnovo = (NODE *) malloc(sizeof (NODE));
    if(pnovo == NULL) {
      return FALSE;
    }
    pnovo->jogo = jogo;
    if (lista->primeiro == NULL) {
        lista->primeiro = pnovo;
        pnovo->anterior = pnovo;
        pnovo->proximo = pnovo;
    } else {
        lista->ultimo->proximo = pnovo;
        pnovo->anterior = lista->ultimo;
    }
    
    lista->ultimo = pnovo;
    pnovo->proximo = lista->primeiro;
    lista->primeiro->anterior = pnovo;
    lista->quantidadeDeJogos++;
    return TRUE;   
}

void listaImprimirJogos(LISTA * lista){
  NODE * nodeAux = lista->primeiro;
  for(int i = 0; i < lista->quantidadeDeJogos; i++){
    imprimirNomeJogo(nodeAux->jogo);
    nodeAux = nodeAux->proximo;
  }
}

NODE * buscarIndexNode(LISTA * lista, int index){
  NODE * nodeAux = lista->primeiro;
  for(int i = 0; i < index; i++){
    nodeAux = nodeAux->proximo;
  }
  return nodeAux;
}

boolean removerNode(LISTA * lista, int index){
  if(lista == NULL || isListaVazia(lista)){
    return FALSE;
  }
  
  NODE * nodeAux = buscarIndexNode(lista, index);
  if(nodeAux == NULL){
    return FALSE;
  }
  
  verSeNodeEstaNaExtremidade(lista, nodeAux);
  nodeAux->anterior->proximo = nodeAux->proximo;
  nodeAux->proximo->anterior = nodeAux->anterior;
  nodeAux->anterior = NULL;
  nodeAux->proximo = NULL;
  nodeAux->jogo = NULL;
  lista->quantidadeDeJogos--;
  free(nodeAux);
  return TRUE;
}

void verSeNodeEstaNaExtremidade(LISTA *lista, const NODE *nodeAux) {
    if(lista->primeiro == nodeAux){
      lista->primeiro = lista->primeiro->proximo;
    }
    if(lista->ultimo == nodeAux){
      lista->ultimo = lista->ultimo->anterior;
    }
}

//FUNÇÃO r
void listaRemoverRepetidos(LISTA * lista){
  if(lista->primeiro == NULL || lista->primeiro->proximo == NULL){
    return;
  }
  int tamanhoLista = lista->quantidadeDeJogos;
  int * posicoes = calloc(tamanhoLista, sizeof(int));
  
  for(int referencia = 0; referencia < tamanhoLista - 1; referencia++){
    if(posicoes[referencia] == NAO_SELECIONADO_FLAG){
      posicoes[referencia] = JOGO_REFERENCIA_FLAG;
      for(int proximo = referencia + 1; proximo < tamanhoLista; proximo++){
        JOGO * jogoReferencia = buscarIndexNode(lista, referencia)->jogo;
        JOGO * jogoBuscado = buscarIndexNode(lista, proximo)->jogo;
        
        if(isJogoIgual(jogoReferencia, jogoBuscado)){
          posicoes[proximo] = IS_REPETIDO_FLAG;
        }
      }
    }
  }
  
  for(int i = 0; i < tamanhoLista; i++){
    if(posicoes[i] == IS_REPETIDO_FLAG){
      removerNode(lista,i);
      tamanhoLista--;
      i--;
      for(int j = i; j < tamanhoLista; j++){
        posicoes[j] = posicoes[j+1];
      } 
    }
  }

}

boolean isJogoIgual(JOGO *jogoReferencia, JOGO *proximoJogo){
  if(strcmp(getNome(jogoReferencia), getNome(proximoJogo)) == 0){
      if(strcmp(getProdutora(jogoReferencia), getProdutora(proximoJogo)) == 0){
          if(getAno(jogoReferencia) == getAno(proximoJogo)){
            return TRUE;
          }
      }
  }
  return FALSE;
}

//FUNÇÃO p
void listaImprimirNomePorProdutora(LISTA * lista, char *produtora){
  NODE * nodeAux = lista->primeiro;
  for(int i = 0; i < lista->quantidadeDeJogos; i++){
    if(strcmp(getProdutora(nodeAux->jogo), produtora)==0){
      imprimirNomeJogo(nodeAux->jogo);
    }
    nodeAux = nodeAux->proximo;
  }
}

//FUNÇÃO a
void listaImprimirNomePorAno(LISTA *lista, int ano){
  NODE * nodeAux = lista->primeiro;
  for(int i = 0; i < lista->quantidadeDeJogos; i++){
    if(getAno(nodeAux->jogo) == ano){
      imprimirNomeJogo(nodeAux->jogo);
    }
    nodeAux = nodeAux->proximo;
  }
}

//FUNÇÃO i
void listaImprimirTodosOsNomes(LISTA * lista){
  NODE * nodeAux = lista->primeiro;
  for(int i = 0; i < lista->quantidadeDeJogos; i++){
    imprimirNomeJogo(nodeAux->jogo);
    nodeAux = nodeAux->proximo;
  }
}

//FUNÇÃO u
void listaImprimirNomePelaPosicao(LISTA * lista, int index){
  NODE * nodeAux = lista->primeiro;
  for(int i = 0; i < index; i++){
    nodeAux = nodeAux->proximo;
  }
  imprimirNomeJogo(nodeAux->jogo);
}

void listaMover(LISTA* lista, int index, int posicao){
    NODE *copiaNode =  (NODE *) malloc(sizeof (NODE));
    JOGO *paraMover = buscarIndexNode(lista, index)->jogo;
    NODE*nodeInicial = lista->ultimo->proximo;

    listaCopiarJogo(copiaNode, paraMover);
    removerNode(lista, index);

    do{
        nodeInicial = nodeInicial->proximo;
        posicao--;
    } while(posicao > 1);

    copiaNode->anterior = nodeInicial;
    copiaNode->proximo = nodeInicial->proximo;
    nodeInicial->proximo->anterior = copiaNode;
    nodeInicial->proximo = copiaNode;

    if(nodeInicial == lista->ultimo) lista->ultimo =lista->ultimo->proximo;
    lista->quantidadeDeJogos++;
}

void listaCopiarJogo(NODE *copiaNode, JOGO *jogoCopiado) {
    JOGO * jogoCopia = alocarJogo();
    if(jogoCopiado != NULL) {
        adicionaDadosAoJogo(jogoCopia, getNome(jogoCopiado), getAno(jogoCopiado), getProdutora(jogoCopiado));
        copiaNode->jogo = jogoCopia;
    }
}

int listaGetTamanho(LISTA *lista){
    if(lista != NULL){
        return lista->quantidadeDeJogos;
    }
    return ERRO_LISTA;
}