#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operacoesComLista.h"
//#include "operacoesComStr.h"
//#include "reducoes.h"

//#define CONT_FLAG   //Comentar para tirar contadores das reduções


int main()
{
	char strEntrada[200000];
    FILE *arq = fopen("string.in", "r");
    fscanf(arq,"%s",strEntrada);


    int parou;
    int tamanhoEntrada = strlen(strEntrada);

    struct Lista str;
    iniciaLista(&str);
	int i;
	for(i = 0; strEntrada[i] != '\0'; i++)
    	inseriNo(&str, strEntrada[i]);
    printaLista(&str);
    
    
    return 0;
}
 // S' = W // C' = P // B' = H