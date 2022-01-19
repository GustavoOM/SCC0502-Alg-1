#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Jogo.h"
#include "../Util/Util.h"

struct jogo_st{
  char nome[50];
  int ano;
  char produtora[50];
};

JOGO * alocarJogo(){
  JOGO * jogo;
  jogo = (JOGO *) malloc(sizeof(JOGO));

  if(jogo != NULL){
      strcpy(jogo->nome,"");
      jogo->ano = 0;
      strcpy(jogo->produtora,"");
      return jogo;
  }
  return NULL;
}

boolean adicionaDadosAoJogo(JOGO * jogo, char * nome, int ano, char * produtora){
  if(jogo != NULL){
    strcpy(jogo->nome,nome);
    jogo->ano = ano;
    strcpy(jogo->produtora,produtora);
    return TRUE;
  }
  return FALSE;
}

char * getNome(JOGO * jogo){
  if(jogo != NULL){
    return jogo->nome;
  }
  return NULL;
}

int getAno(JOGO * jogo){
  if(jogo != NULL){
    return jogo->ano;
  }
  return ERRO_JOGO;
}

char * getProdutora(JOGO * jogo){
  if(jogo != NULL){
    return jogo->produtora;
  }
  return NULL;
}

void imprimirNomeJogo(JOGO * jogo){
  printf("%s\n", getNome(jogo));
}

