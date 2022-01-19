#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./TADs/Util/Util.h"
#include "./TADs/Jogo/Jogo.h"
#include "./TADs/ArvoreAVL/Arvore.h"

#define PREORDEM 1
#define EMORDEM 2
#define POSORDEM 3
#define ERRO_LEITURA -300000

boolean lerLinhaCSV(FILE *arquivo, JOGO *jogo);

int main()
{
    FILE * arquivo = fopen("./CSV.csv","r+");
    fseek(arquivo,3,SEEK_SET);
    JOGO * jogo;
    ARVORE *arvore;
    arvore = alocarArvore();
    int ordemDeImpressao;
    int anoExcluido;

    while (!feof(arquivo))
    {
      jogo = alocarJogo();
      if(lerLinhaCSV(arquivo, jogo)) 
      {
        //imprimeJogo(jogo);
        inserirJogoArvoreAVL(arvore, jogo);
      }
    }
    fclose(arquivo);

    if(!scanf("%d",&ordemDeImpressao)){
      return ERRO_LEITURA;
    }    
    while(scanf("%d",&anoExcluido)){
      while(avlRemoveAno(arvore, anoExcluido)){
       continue;
      }
    }
    switch(ordemDeImpressao){
      case PREORDEM:
        imprimirArvoreInPreOrder(arvore);
        break;
      case EMORDEM:
        imprimirArvoreInOrder(arvore);
        break;
      case POSORDEM:
        imprimirArvoreInPosOrder(arvore);
        break;
      default:
        break;
    }
    
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
