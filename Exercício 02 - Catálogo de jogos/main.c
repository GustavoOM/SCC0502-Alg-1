#include <stdlib.h>
#include "catalogo.h"
int main(){

    //Alocar e lê o catalogo com o filtro
    catalogo_ST *catalogo;
    catalogo = criarCatalogo();

    //Mostra esse catalogo
    mostrarCatalogoComFiltro(catalogo);

    //Encerrar Programa liberando a memória alocada
    free(catalogo);
    return 0;
}