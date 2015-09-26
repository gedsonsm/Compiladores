#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operacoesComLista.h"
//#include "operacoesComStr.h"
#include "reducoes.h"

//#define CONT_FLAG   //Comentar para tirar contadores das reduções


int main()
{
    char strEntrada[200000];
    FILE *arq = fopen("string.in", "r");
    fscanf(arq,"%s",strEntrada);
    struct Lista str;
    iniciaLista(&str);
    int parou;
    int tamanhoEntrada = strlen(strEntrada);
	strEntrada[tamanhoEntrada+1] = '\0'; 

	parou = criaLista(&str, strEntrada);
	printaLista(&str);

	
    return 0;
}
 // S' = W // C' = P // B' = H
