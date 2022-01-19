#ifndef MATRIZESPARSA_H
#define MATRIZESPARSA_H

typedef struct matriz_esparsa MATRIZ_ESPARSA;

MATRIZ_ESPARSA *alocarMatriz(int nr_linhas, int nr_colunas);
void deletarMatriz(MATRIZ_ESPARSA **matriz);
int setValor(MATRIZ_ESPARSA *matriz, int linha, int coluna, int valor);
int getValor(MATRIZ_ESPARSA *matriz, int linha, int coluna);

#endif //MATRIZESPARSA_H
