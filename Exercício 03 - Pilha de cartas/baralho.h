#include "util.h"
#ifndef BARALHO_H
#define BARALHO_H


typedef struct baralho_ baralho_ST;

baralho_ST * criarBaralho();
boolean baralhoEstaVazio(const baralho_ST *baralho);
//boolean baralhoEstaCheio(const baralho_ST *baralho);
int tamanhoBaralho(const baralho_ST *baralho);
boolean inserirCartas(baralho_ST * baralho, carta_ST *carta);
carta_ST * topoDoBaralho(const baralho_ST *baralho);
carta_ST * retirarCartaDoBaralho(baralho_ST *baralho);
boolean apagarBaralho(baralho_ST ** baralho);
int valorDoSimbolo(char *simbolo);

#endif