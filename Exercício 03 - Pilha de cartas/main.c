#include <stdio.h>
#include "carta.h"
#include "baralho.h"
#include "util.h"

void jogar21();

int main()
{
    jogar21();
    return 0;
}

void jogar21()
{
    baralho_ST *baralho;
    baralho = criarBaralho();
    carta_ST *carta;

    char nipe[10] = "";
    char simbolo[2] = "";
    int valor = 0;
    for(int i = 0; i < 52; i++){
        scanf("%s", nipe);
        getchar();
        scanf("%s", simbolo);
        valor = valorDoSimbolo(simbolo);
        if(valor > 0){
            carta = criarCarta(nipe,simbolo,valor);
            inserirCartas(baralho, carta);
        }
    }

    int pontos = 0;

    while (pontos < 21){
        pontos += pontosDaCarta(retirarCartaDoBaralho(baralho));
    }

    if(pontos == 21){
        printf("Ganhou ;)\n");
    }
    else{
        printf("Perdeu :(\nSoma :: %d\n", pontos);
    }
    
    apagarBaralho(&baralho);
}
