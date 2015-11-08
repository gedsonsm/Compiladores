#ifndef OPERACOESCOMGRAFO_H_INCLUDED
#define OPERACOESCOMGRAFO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#define TAM_HEAP 153002
typedef struct No
{
    char c;
    char mem;
    struct No *esq;
    struct No *dir;
    struct No *FW;
}No;

int i, indice;
No grafo[TAM_HEAP];
No *Aux;

void criaNo(char carac, No **novo);
No* criaGrafo(char* str, No *raiz);
int printaGrafo(No* raiz);

#endif // OPERACOESCOMGRAFO_H_INCLUDED
