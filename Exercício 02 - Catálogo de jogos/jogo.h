#ifndef JOGO_H
#define JOGO_H

typedef struct jogo_ jogo_ST;

jogo_ST * adicionarJogoNaLista(jogo_ST *jogos, int quantidadeDeJogos, char nome[], char produtora[], char ano[]);
void mostrarJogos(jogo_ST *jogos, int quantidadeDeJogos);
void procurarPorJogos(jogo_ST *jogos, int quantidadeDeJogos, char operacao, char valor[]);

#endif