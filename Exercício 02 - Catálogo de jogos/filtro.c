#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filtro.h"

struct filtro_{
    char operacao;
    char valor[50];
};

filtro_ST * adicionarFiltroNaLista(filtro_ST *filtros, int quantidadeDeFiltros, char operacao, char valor[]){
    filtros = (filtro_ST*) realloc(filtros, quantidadeDeFiltros * sizeof(filtro_ST));
    filtros[quantidadeDeFiltros-1].operacao = operacao;
    strcpy(filtros[quantidadeDeFiltros-1].valor, valor);
    return filtros;
}

void mostrarFiltros(filtro_ST *filtros, int quantidadeDeFiltros){
    for(int i = 0; i < quantidadeDeFiltros; i++){
        printf("Busca por: %c // E = Empresa Produtora // A = Ano\n", filtros[i].operacao);
        printf("Valor: %s\n", filtros[i].valor);
    }
}

char operacaoDoFiltro(filtro_ST * filtros, int index){
    return filtros[index].operacao;
}

char * valorDoFiltro(filtro_ST * filtros, int index){
    return filtros[index].valor;
}