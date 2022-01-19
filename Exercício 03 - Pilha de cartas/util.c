#include <stdio.h>
#include "util.h"

void converterInteiro(boolean valor){
    if(valor == TRUE)
        printf("TRUE\n");
    else if(valor == FALSE)
        printf("FALSE\n");
    else
        printf("ERRO\n");
}
