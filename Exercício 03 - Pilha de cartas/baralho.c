#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "carta.h"
#include "baralho.h"

typedef struct node_ node_ST;

struct node_{
    carta_ST *cartas;
    node_ST *anterior;  
};

struct baralho_{
    node_ST * topo;
    int quantidadeDeCartas;;
};

baralho_ST * criarBaralho(){
    baralho_ST *baralho = (baralho_ST *) malloc(sizeof(baralho_ST));
    if (baralho != NULL){
        baralho->topo = NULL;
        baralho->quantidadeDeCartas = 0;
    }
    return baralho;
}

boolean baralhoEstaVazio(const baralho_ST *baralho){
    return baralho->quantidadeDeCartas == 0;
}

//boolean baralhoEstaCheio(const baralho_ST *baralho){
//    return FALSE;
//}

int tamanhoBaralho(const baralho_ST *baralho){
    return baralho->quantidadeDeCartas;
}

boolean inserirCartas(baralho_ST * baralho, carta_ST *carta){
    if(baralho != NULL){
        node_ST *novoNode = (node_ST *) malloc(sizeof(node_ST));
        if(novoNode != NULL){
            novoNode->cartas = carta;
            novoNode->anterior = baralho->topo;
            baralho->topo = novoNode;
            baralho->quantidadeDeCartas++;
            return TRUE;
        }
    }
    return FALSE;
}

carta_ST * topoDoBaralho(const baralho_ST *baralho){
    if((baralho != NULL) && (!baralhoEstaVazio(baralho))){
        return baralho->topo->cartas;
    }
    return NULL;
}

carta_ST * retirarCartaDoBaralho(baralho_ST *baralho){
    if((baralho != NULL) && (!baralhoEstaVazio(baralho))){
        node_ST *desempilhado = baralho->topo;
        carta_ST *carta = baralho->topo->cartas;
        baralho->topo = baralho->topo->anterior;
        desempilhado->anterior = NULL;
        free(desempilhado);
        baralho->quantidadeDeCartas--;
        return carta;
    }
    return NULL;
}

static void removerTopoBaralho(baralho_ST *const *baralho){
    node_ST *nodeTemporario;
    nodeTemporario = (*baralho)->topo;
    (*baralho)->topo = (*baralho)->topo->anterior;
    deletarCarta(&nodeTemporario->cartas);
    nodeTemporario->anterior = NULL;
    free(nodeTemporario);
    nodeTemporario = NULL;
}

static void apagarTodasCartas(baralho_ST *const *baralho){
    while((*baralho)->topo != NULL){
        removerTopoBaralho(baralho);
    }
}

boolean apagarBaralho(baralho_ST ** baralho){
    if((*baralho != NULL) && (!baralhoEstaVazio(*baralho))){
        apagarTodasCartas(baralho);
        free(*baralho);
        *baralho = NULL;
        return TRUE;
    }
    return FALSE;
}