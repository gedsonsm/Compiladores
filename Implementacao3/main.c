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
	printf("\n");
    
    str = S(&str);
	printaLista(&str);
	printf("\n");
	
	removeParenteses(&str);
	printaLista(&str);
	printf("\n");
	
	while()
	{
		switch(str.primeiro -> c)
		{
			case '(':
				removeParenteses (&str);
			break;
			
			case 'S':
				str = S(&str);
			break;
			
			case 'K':
				str = K(&str);
			break;
		}
		int c = getchar();
		printaLista(&str);
		printf("\n");
	}

	
    return 0;
}
 // S' = W // C' = P // B' = H
