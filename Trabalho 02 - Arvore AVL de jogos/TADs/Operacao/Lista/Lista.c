#include <stdlib.h>

#include "../../Util/Util.h"
#include "./Lista.h"
#include "../Operacao.h"

typedef struct nodeOperacoes_ NODEOPERACOES;
struct nodeOperacoes_{
    OPERACAO *operacao;
    NODEOPERACOES *proximo; 
};

struct listaOperacoes_{
    NODEOPERACOES * primeiro;
    NODEOPERACOES * ultimo;
    LISTA * listaDeJogos;
    int quantidadeDeOperacoes;
};

LISTAOPERACOES * alocarListaOperacoes(){
  LISTAOPERACOES * lista;
  lista = (LISTAOPERACOES *) malloc(sizeof(LISTAOPERACOES));

  if(lista == NULL){
    return NULL;
  }

  lista->primeiro = NULL;
  lista->quantidadeDeOperacoes = 0;
  return lista;
}

boolean listaVaziaOperacoes(const LISTAOPERACOES * lista){
    if(lista != NULL){
        return lista->quantidadeDeOperacoes == 0;
    }
    return ERRO_OPERACAO;
}

LISTA *getListaDeJogosDaOperacao(LISTAOPERACOES *listaOperacoes, LISTA *listaDeJogos) {
    if (listaDeJogos != NULL && !isListaVazia(listaDeJogos)) {
        return listaOperacoes->listaDeJogos;
    }
    return NULL;
}

boolean inserirListaDeJogosNaListaDeOperacoes(LISTAOPERACOES *listaOperacoes, LISTA * listaDeJogos){
    if(listaDeJogos != NULL && !isListaVazia(listaDeJogos)){
        listaOperacoes->listaDeJogos = listaDeJogos;
        return TRUE;
    }
    return FALSE;
}
boolean listaInserirFimOperacoes(LISTAOPERACOES *lista, OPERACAO *operacao)
{
    if (lista == NULL){
      return FALSE;
    }

    NODEOPERACOES *pnovo = (NODEOPERACOES *) malloc(sizeof (NODEOPERACOES));
    
    if(pnovo == NULL) {
      return FALSE;
    }
    
    pnovo->operacao = operacao;
    pnovo->proximo = NULL;
    
    if (lista->primeiro == NULL) {
        lista->primeiro = pnovo;
        
    } else {
        lista->ultimo->proximo = pnovo;
    }
    lista->ultimo = pnovo;
    lista->quantidadeDeOperacoes++;
    return TRUE;   
}

void imprimirOperacoes(LISTAOPERACOES * lista){
  NODEOPERACOES * nodeAux = lista->primeiro;
  while(nodeAux != NULL){
    imprimirOperacao(nodeAux->operacao);
    nodeAux = nodeAux->proximo;
  }
}

OPERACAO * getPrimeiraOperacao(LISTAOPERACOES * listaDeOperacoes){
  if(listaDeOperacoes == NULL){
    return NULL;
  }
  return listaDeOperacoes->primeiro->operacao;
}

void proximaOperacao(LISTAOPERACOES * listaDeOperacoes){
  if(listaDeOperacoes != NULL){
    listaDeOperacoes->primeiro = listaDeOperacoes->primeiro->proximo;
  }
}

void operacaoPegarTodosJogos(LISTAOPERACOES *listaOperacoes){
    if(listaOperacoes != NULL){
        listaImprimirJogos(listaOperacoes->listaDeJogos);
    }
}


void operacaoPegarJogoPorPosicao(LISTAOPERACOES *listaOperacoes, int index){
    if(listaOperacoes != NULL){
        listaImprimirNomePelaPosicao(listaOperacoes->listaDeJogos, index);
    }
}
void operacaoPegarJogoPorAno(LISTAOPERACOES *listaOperacoes, int ano){
    if(listaOperacoes != NULL) {
        listaImprimirNomePorAno(listaOperacoes->listaDeJogos, ano);
    }
}

void operacaoPegarJogoPorProdutora(LISTAOPERACOES *listaOperacoes, char *produtora){
    if(listaOperacoes != NULL) {
        listaImprimirNomePorProdutora(listaOperacoes->listaDeJogos, produtora);
    }
}

void operacaoMoverParaEsquerda(LISTAOPERACOES *listaOperacoes, int index, int posicoes){
    LISTA * lista = listaOperacoes->listaDeJogos;
    int tamanhoLista = listaGetTamanho(lista);
    int restoPosicao = posicoes % tamanhoLista - 1;
    int posicaoADireita = tamanhoLista - 1 - restoPosicao + index;

    posicaoADireita--;
    listaMover(lista, index, posicaoADireita);
}

void operacaoMoverParaDireita(LISTAOPERACOES *listaOperacoes, int index, int posicoes){
    LISTA * lista = listaOperacoes->listaDeJogos;;
    int tamanhoLista = listaGetTamanho(lista);

    posicoes = posicoes % tamanhoLista + index;
    listaMover(lista, index, posicoes);
}

void operacaoRemoverDuplicados(LISTAOPERACOES *listaOperacoes){
    if(listaOperacoes != NULL) {
        listaRemoverRepetidos(listaOperacoes->listaDeJogos);
    }
}