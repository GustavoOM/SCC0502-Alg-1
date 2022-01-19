#ifndef CATALOGO_H
#define CATALOGO_H

typedef struct catalogo_ catalogo_ST;

catalogo_ST * criarCatalogo();
void mostrarCatalogoComFiltro(catalogo_ST *catalogo);

#endif