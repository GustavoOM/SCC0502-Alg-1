#ifndef FILTRO_H
#define FILTRO_H

typedef struct filtro_ filtro_ST;

filtro_ST * adicionarFiltroNaLista(filtro_ST *filtros, int quantidadeDeFiltros, char operacao, char valor[]);
void mostrarFiltros(filtro_ST *filtros, int quantidadeDeFiltros);
char operacaoDoFiltro(filtro_ST * filtros, int index);
char * valorDoFiltro(filtro_ST * filtros, int index);

#endif