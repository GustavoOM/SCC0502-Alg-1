#include "util.h"
#ifndef CARTA_H
#define CARTA_H

typedef struct carta_ carta_ST;

carta_ST *criarCarta (const char *nipe, const char *simbolo, int valor);
boolean deletarCarta(carta_ST **carta);
void imprimirCarta(const carta_ST *carta);
int pontosDaCarta(const carta_ST *carta);

#endif