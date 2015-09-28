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
	//printaLista(&str);
	//printf("\n");
 		
	do
	{
		//int c = getchar();
		switch(str.primeiro -> c)
		{
			case '(':
				removeParenteses (&str);
			break;
			
			case 'S':
				str = S(&str, &parou);
			break;
			
			case 'K':
				str = K(&str, &parou);
			break;

			case 'I':
				str = I(&str, &parou);
			break;

			case 'B':
				str = B(&str, &parou);
			break;

			case 'C':
				str = C(&str, &parou);
			break;

			case 'W':
				str = SH(&str, &parou);
			break;

			case 'H':
				str = BH(&str, &parou);
			break;

			case 'P':
				str = CH(&str, &parou);
			break;
		}
	}
	while(parou == 0);
	printaLista(&str);
	printf("\n");
    return 0;
}
 // S' = W // C' = P // B' = H
