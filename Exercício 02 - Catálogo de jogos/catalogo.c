#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogo.h"
#include "filtro.h"
#include "catalogo.h"

struct catalogo_{
    jogo_ST * jogos;
    int quantidadeDeJogos;
    filtro_ST * filtros;
    int quantidadeDeFiltros;
};

//Funções exportadas
catalogo_ST * criarCatalogo(){
    catalogo_ST *catalogo;
    catalogo = (catalogo_ST *) calloc(1, sizeof(catalogo_ST));
    catalogo->quantidadeDeJogos = 0;
    catalogo->quantidadeDeFiltros = 0;
    char recebeuF[50];

    char nome[50];
    char produtora[50];
    char ano[10];

    char operacao;
    char valor[50];

    strcpy(recebeuF,"");
    while (strcmp("F", recebeuF)){
        scanf(" %[^(\r|\n)]*c", recebeuF);
        getchar();
        if(strcmp("F", recebeuF)){
            catalogo->quantidadeDeJogos++;
            strcpy(nome, recebeuF);
            scanf(" %[^(\r|\n)]*c", produtora);
            getchar();
            scanf(" %[^(\r|\n)]*c", ano);
            getchar();
            catalogo->jogos = adicionarJogoNaLista(catalogo->jogos, catalogo->quantidadeDeJogos, nome, produtora, ano);
        }
    }

    strcpy(recebeuF,"");
    while (strcmp("F", recebeuF)){
        scanf(" %[^(\r|\n)]*c", recebeuF);
        getchar();
        if(strcmp("F", recebeuF)){
            operacao = recebeuF[0];
            if(operacao == 'A' || operacao == 'E'){
                catalogo->quantidadeDeFiltros++;
                scanf(" %[^(\r|\n)]*c", valor);
                getchar();
                catalogo->filtros = adicionarFiltroNaLista(catalogo->filtros,catalogo->quantidadeDeFiltros, operacao, valor);
            }
            
        }
    }
    return catalogo;
}

void mostrarCatalogoComFiltro(catalogo_ST *catalogo){
    for(int i = 0; i < catalogo->quantidadeDeFiltros; i++){
        procurarPorJogos(catalogo->jogos, catalogo->quantidadeDeJogos, operacaoDoFiltro(catalogo->filtros, i), valorDoFiltro(catalogo->filtros, i));
    }
}