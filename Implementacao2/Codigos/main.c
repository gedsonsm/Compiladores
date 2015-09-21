#include <stdio.h>
#include <stdlib.h>
#include "operacoesComStr.h"
#include "reducoes.h"

//#define CONT_FLAG   //Comentar para tirar contadores das reduções


char strEntrada[90000000];
char strSaida[90000000];

#ifdef CONT_FLAG
	int cont_S;
	int cont_K;
	int cont_P;
	int cont_I;
	int cont_C;
	int cont_B;
	int cont_SH;
	int cont_CH;
	int cont_BH;
#endif

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
              parou = OperarI(pontE, pontS, &tamanhoEntrada);
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
    return 0;
}
 // S' = W // C' = P // B' = H