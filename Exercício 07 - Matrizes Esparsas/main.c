#include <stdio.h>
#include <stdlib.h>
#include "MatrizEsparsa.h"

//Boolean returns
#define TRUE 1
#define FALSE 0

typedef int boolean;

boolean calcularDistancia(MATRIZ_ESPARSA * matrizEsparsa, int estacao1, int estacao2);

int main(){
    int quantidadeDeEstacoes;
    int quantidadeDeCaminhos;
    if(!scanf("%d %d",&quantidadeDeEstacoes,&quantidadeDeCaminhos)){
        return 0;
    }
    if(quantidadeDeEstacoes == 0 || quantidadeDeCaminhos == 0){
        printf("Não existe caminho.\n");
        return 0;
    }
    MATRIZ_ESPARSA * matrizEsparsa = alocarMatriz(quantidadeDeEstacoes,quantidadeDeEstacoes);
    int estacao1;
    int estacao2;
    int distancia;
    boolean existeCaminho = FALSE;
    for(int i = 0; i < quantidadeDeCaminhos; i++){
        if(!scanf("%d %d %d",&estacao1,&estacao2,&distancia)){
            return 0;
        }
        setValor(matrizEsparsa,estacao1,estacao2,distancia);
    }
    if(!scanf("%d %d",&estacao1,&estacao2)){
        return 0;
    }
    existeCaminho = calcularDistancia(matrizEsparsa,estacao1,estacao2);
    if(existeCaminho){
        printf("Existe caminho.\n");
    }
    else{
        printf("Não existe caminho.\n");
    }
    deletarMatriz(&matrizEsparsa);
}

boolean calcularDistancia(MATRIZ_ESPARSA * matrizEsparsa, int estacao1, int estacao2){
    boolean existeCaminho = FALSE;
    if(estacao1==estacao2)
        existeCaminho = TRUE;
    if(getValor(matrizEsparsa,estacao1,estacao2))
        existeCaminho = TRUE;
    if(getValor(matrizEsparsa,estacao2,estacao1))
        existeCaminho = TRUE;
    return existeCaminho;
}