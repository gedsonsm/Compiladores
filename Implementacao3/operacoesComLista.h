#ifndef OPERACOES_COM_LISTA_H
#define OPERACOES_COM_LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct No
{
	char c;
	struct  No *prox;
	struct  No *ante;
	struct Lista *lLista;
};
struct Lista
{
	struct No *primeiro;
	struct No *ultimo;
};

void iniciaLista(struct Lista *pLista);
int printaLista (struct Lista *pLista);
void inseriNo (struct Lista *pLista, char carac);
int criaLista(struct Lista *pLista, char *entrada);
//struct Lista removeParenteses (struct Lista *Pnovo,struct No *Anterior,struct No *LAnterior);
void removeParenteses(struct Lista *pLista);
int clonaNo(struct No *novo,struct Lista *clone);
void checaNulidade (struct Lista *pLista, struct No *check);
void LiberaNo (struct No *Temp);

#endif
