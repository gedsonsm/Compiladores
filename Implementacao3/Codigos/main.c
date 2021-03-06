#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operacoesComLista.h"
//#include "operacoesComStr.h"
#include "reducoes.h"


int main()
{
    char strEntrada[200000];
    FILE *arq = fopen("string.in", "r");
    fscanf(arq,"%s",strEntrada);
    struct Lista *str = (struct Lista*) malloc (sizeof (struct Lista));
    iniciaLista(str);
    int parou;
    int tamanhoEntrada = strlen(strEntrada);
	strEntrada[tamanhoEntrada+1] = '\0';

	parou = criaLista(str, strEntrada);

	do
	{
		switch(str -> primeiro -> c)
		{
			case '(':
				removeParenteses (str);
			break;

			case 'S':
				S(&str, &parou);
			break;

			case 'K':
				K(&str, &parou);
			break;

			case 'I':
				I(&str, &parou);
			break;

			case 'B':
				B(&str, &parou);
			break;

			case 'C':
				C(&str, &parou);
			break;

			case 'W':
				SH(&str, &parou);
			break;

			case 'H':
				BH(&str, &parou);
			break;

			case 'P':
				CH(&str, &parou);
			break;
		}
	}
	while(parou==0);
	printaLista(str);
	printf("\n");
	//printf("No total houveram %d Nos Liberados",liberado);

	#ifdef CONT_FLAG	   	
		printf("S: %d\n",cont_S);
		printf("K: %d\n",cont_K);
		printf("I: %d\n",cont_I);
		printf("C: %d\n",cont_C);
		printf("B: %d\n",cont_B);
		printf("S': %d\n",cont_SH);
		printf("C': %d\n",cont_CH);
		printf("B': %d\n",cont_BH);
	#endif

    return 0;
}
 // S' = W // C' = P // B' = H
