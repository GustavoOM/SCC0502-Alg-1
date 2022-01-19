#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Operacao.h"
#include "../Util/Util.h"
#include "./Lista/Lista.h"

struct operacao_st{
  char tag[3];
  char entrada1[50];
  char entrada2[50];
};

OPERACAO * alocarOperacao(){
  OPERACAO * operacao;
  operacao = (OPERACAO *) malloc(sizeof(OPERACAO));

  if(operacao == NULL){
    return NULL;
  }
  strcpy(operacao->tag,"");
  strcpy(operacao->entrada1,"");
  strcpy(operacao->entrada2,"");
  return operacao;
}

boolean adicionarDadosAOperacao(OPERACAO * operacao, char * tag, char * entrada1, char * entrada2){
  if(operacao != NULL){
    strcpy(operacao->tag,tag);
    strcpy(operacao->entrada1,entrada1);
    strcpy(operacao->entrada2,entrada2);
    return TRUE;
  }
  return FALSE;
}

int getCharSetNumero(OPERACAO *operacao){
  int intTag = 0;

  if(operacao != NULL)
  {
    if(strcmp(operacao->tag, "r") == 0) intTag = OPERACAO_R;
    if(strcmp(operacao->tag, "u") == 0) intTag = OPERACAO_U;
    if(strcmp(operacao->tag, "a") == 0) intTag = OPERACAO_A;
    if(strcmp(operacao->tag, "i") == 0) intTag = OPERACAO_I;
    if(strcmp(operacao->tag, "mr") == 0) intTag = OPERACAO_MR;
    if(strcmp(operacao->tag, "p") == 0) intTag = OPERACAO_P;
    if(strcmp(operacao->tag, "ml") == 0) intTag = OPERACAO_ML;
    if(strcmp(operacao->tag, "f") == 0) intTag = OPERACAO_F;
  }
  return intTag;
}

int getTag(OPERACAO *operacao){
    if(operacao != NULL){
        return getCharSetNumero(operacao);
    }
    return ERRO_OPERACAO;
}

void realizarOperacao(LISTA * listaJogos){
  OPERACAO * operacao;
  LISTAOPERACOES * listaDeOperacoes;
  listaDeOperacoes = alocarListaOperacoes();
  int tagNaoPodeSerF = F_FLAG;

  while(tagNaoPodeSerF != OPERACAO_F)
  {
    operacao = alocarOperacao();
    inputOperacao(operacao);
    listaInserirFimOperacoes(listaDeOperacoes,operacao);
    tagNaoPodeSerF = getTag(operacao);
  }
  inserirListaDeJogosNaListaDeOperacoes(listaDeOperacoes, listaJogos);

  while(getTag(getPrimeiraOperacao(listaDeOperacoes)) != OPERACAO_F){
    operacao = getPrimeiraOperacao(listaDeOperacoes);
  
    switch (getTag(operacao))
    {
      case OPERACAO_I:
          operacaoPegarTodosJogos(listaDeOperacoes);
      break;

      case OPERACAO_U:
          operacaoPegarJogoPorPosicao(listaDeOperacoes, atoi(operacao->entrada1));
      break;

      case OPERACAO_A:
          operacaoPegarJogoPorAno(listaDeOperacoes, atoi(operacao->entrada1));
      break;

      case OPERACAO_P:
          operacaoPegarJogoPorProdutora(listaDeOperacoes, operacao->entrada1);
      break;

      case OPERACAO_ML:
          operacaoMoverParaEsquerda(listaDeOperacoes,atoi(operacao->entrada1),atoi(operacao->entrada2));
      break;

      case OPERACAO_MR:
          operacaoMoverParaDireita(listaDeOperacoes,atoi(operacao->entrada1),atoi(operacao->entrada2));
      break;

      case OPERACAO_R:
          operacaoRemoverDuplicados(listaDeOperacoes);
      break;
      
    }
    proximaOperacao(listaDeOperacoes);
  }
   
}


void inputOperacao(OPERACAO *operacao) {
  char tag[3];
  char entrada1[50];
  char entrada2[50];
  int intTag;
  
  if(scanf("%s",tag) == 0) return;
  adicionarDadosAOperacao(operacao, tag, "", "");
  intTag = getCharSetNumero(operacao);

  if(intTag == OPERACAO_I || intTag == OPERACAO_F || intTag == OPERACAO_R){
    strcpy(entrada1, "");
    strcpy(entrada2, "");
  }
  else if(intTag == OPERACAO_P || intTag == OPERACAO_A || intTag == OPERACAO_U){
    if(scanf(" %[^(\r|\n)]*c", entrada1) == 0) return;
    entrada1[strcspn(entrada1, "\n")] = 0;
    entrada1[strcspn(entrada1, "\r")] = 0;
    strcpy(entrada2, "");
  }
  else{
    if(scanf("%s",entrada1) == 0) return;
    if(scanf("%s",entrada2) == 0) return;
  }
    adicionarDadosAOperacao(operacao, tag, entrada1, entrada2);
}

void imprimirOperacao(OPERACAO * operacao){
  printf("TAG: %s | ENTRADA1: %s | ENTRADA2: %s\n",operacao->tag, operacao->entrada1,operacao->entrada2);
}
