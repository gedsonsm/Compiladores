#ifndef REDUCOES_H
#define REDUCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operacoesComLista.h"

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

int S(struct Lista **pLista, int *parou);
int K(struct Lista **pLista, int *parou);
int I(struct Lista **pLista, int *parou);
int B(struct Lista **pLista, int *parou);
int C(struct Lista **pLista, int *parou);
int SH(struct Lista **pLista, int *parou);
int BH(struct Lista **pLista, int *parou);
int CH(struct Lista **pLista, int *parou);

#endif
