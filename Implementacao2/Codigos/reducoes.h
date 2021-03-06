#ifndef REDUCOES_H
#define REDUCOES_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "operacoesComStr.h"

//#define CONT_FLAG   //Comentar para tirar contadores das reduções

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


int OperarS(char *entrada, char *saida, int *tamEntrada);
int OperarK(char *entrada, char *saida, int *tamEntrada);
int OperarI(char **entrada, char **saida, int *tamEntrada);
int OperarC(char *entrada, char *saida, int *tamEntrada);
int OperarB(char *entrada, char *saida, int *tamEntrada);
int OperarSHifen(char *entrada, char *saida, int *tamEntrada);
int OperarBHifen(char *entrada, char *saida, int *tamEntrada);
int OperarCHifen(char *entrada, char *saida, int *tamEntrada);

#endif
