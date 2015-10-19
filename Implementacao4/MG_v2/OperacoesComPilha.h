#ifndef OPERACOESCOMPILHA_H_INCLUDED
#define OPERACOESCOMPILHA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "OperacoesComGrafo.h"

typedef struct Pilha
{
    No* pont;
}pilha;

int tamPilha;

void inicia(pilha *P);
void push(pilha *P, No* contetudo);
No *pop(pilha *P);
No *top(pilha *P);


#endif // OPERACOESCOMPILHA_H_INCLUDED
