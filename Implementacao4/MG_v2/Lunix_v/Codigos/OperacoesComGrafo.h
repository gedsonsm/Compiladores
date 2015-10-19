#ifndef OPERACOESCOMGRAFO_H_INCLUDED
#define OPERACOESCOMGRAFO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
typedef struct No
{
    char c;
    char mem;
    struct No *esq;
    struct No *dir;
}No;

int i, indice;
No grafo[70000000];
No *Busca[20000000];
No *Aux;

void criaNo(char carac, No **novo);
No* criaGrafo(char* str, No *raiz);
int printaGrafo(No* raiz);

#endif // OPERACOESCOMGRAFO_H_INCLUDED
