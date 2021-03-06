#include <stdio.h>
#include <stdlib.h>
#include "operacoesComStr.h"
#include "reducoes.h"


char strEntrada[90000000];
char strSaida[90000000];

int main()
{
    FILE *arq = fopen("string.in", "r");
    fscanf(arq,"%s",strEntrada);

    char *pontE = strEntrada;
    char *pontS = strSaida;
    char *aux;
    int parou;
    int tamanhoEntrada = strlen(strEntrada);

    while(tamanhoEntrada > 1)
    {
        switch(pontE[0])
        {
            case '(':
                tirarParenteses(pontE, pontS, &tamanhoEntrada);
            break;

            case 'W':
               parou = OperarSHifen(pontE, pontS, &tamanhoEntrada);
            break;

            case 'H':
               parou = OperarBHifen(pontE, pontS, &tamanhoEntrada);
            break;

            case 'P':
               parou = OperarCHifen(pontE, pontS, &tamanhoEntrada);
            break;

            case 'S':
               parou = OperarS(pontE, pontS, &tamanhoEntrada);
            break;

            case 'K':
               parou = OperarK(pontE, pontS, &tamanhoEntrada);
            break;

            case 'I':
              //parou = OperarI(&pontE, &pontS, &tamanhoEntrada);
				aux = pontS;
				pontS = pontE+1;
				pontE = aux;
				tamanhoEntrada--;  
            break;
			
            case 'C':
              parou = OperarC(pontE, pontS, &tamanhoEntrada);
            break;

            case 'B':
               parou = OperarB(pontE, pontS, &tamanhoEntrada);
            break;
        }
        if(parou == 1)//Se alguma redução retornar que não houve operandos suficientes
        {
            break;
        }
        //A saida se torna entrada
        aux = pontE;
        pontE = pontS;
        pontS = aux;
    }
	
	printf("\nResposta = %s\n",pontE);

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
