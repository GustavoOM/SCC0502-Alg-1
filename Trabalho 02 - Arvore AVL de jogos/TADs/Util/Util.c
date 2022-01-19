#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Util.h"

char *copiarString(const char *fonte) {
    char *destino = malloc(strlen (fonte) + 1);
    if (destino != NULL){
      strcpy(destino, fonte);     
      return destino;     
    }
    return NULL;
}

char* tiraVirgula(char* linha, int num)
{
    char* tok;
    for (tok = strtok(linha, ";");
         tok && *tok;
         tok = strtok(NULL, ";"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

char *readLine() {
    char *string = NULL;
    char currentInput;
    int index = 0;
    do {
        currentInput = (char)getchar();
        string = (char *) realloc(string, sizeof(char) * (index + 1));
        string[index] = currentInput;
        index++;
        if(currentInput == '\r')
        {
            currentInput = (char)getchar();
        }
    } while((currentInput != '\n') && (currentInput != EOF));
    string[index - 1] = '\0';
    return string;
}