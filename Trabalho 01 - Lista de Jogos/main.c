#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./TADs/Operacao/Operacao.h"
#include "./TADs/Util/Util.h"
#include "./TADs/Jogo/Jogo.h"
#include "./TADs/Lista/Lista.h"

boolean lerLinhaCSV(FILE *arquivo, JOGO *jogo);

int main()
{
    FILE * arquivo = fopen("./CSV.csv","r+");
    JOGO * jogo;
    LISTA * lista;
    lista = alocarLista();
    if(RUNCODES){
      fseek(arquivo, 3, SEEK_SET);
    }
    while (!feof(arquivo))
    {
      jogo = alocarJogo();
      if(lerLinhaCSV(arquivo, jogo)) 
      {
        listaInserirFim(lista, jogo);
      }
    }
    fclose(arquivo);
    realizarOperacao(lista);
}



boolean lerLinhaCSV(FILE *arquivo, JOGO *jogo) {
  char linha[2024], *nome, *produtora, *ano;

  if(fgets(linha, 2024, arquivo)==NULL) return FALSE;
  if(strcmp(linha, "\n") == 0 || strcmp(linha,"\r\n") == 0) return FALSE;
  linha[strcspn(linha, "\n")] = 0;
  linha[strcspn(linha, "\r")] = 0;

  nome = copiarString(linha);
  produtora = copiarString(linha);
  ano = copiarString(linha);

  adicionaDadosAoJogo(jogo,
                      tiraVirgula(nome, COLUNA1),
                      atoi(tiraVirgula(ano, COLUNA2)),
                      tiraVirgula(produtora, COLUNA3));
  return TRUE;
}

