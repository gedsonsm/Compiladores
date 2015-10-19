#include <stdio.h>
#include <stdlib.h>
#include "OperacoesComGrafo.h"
#include "OperacoesComPilha.h"
#define SEM_MACRO

int Fim;
No *OP;
No *pai_a;
No *pai_b;
No *pai_c;
No *pai_d;
No *resto;


void DecodificaOperacao(No *Raiz, pilha *p)
{
    No *Aux1;
    Aux1 = Raiz;
    push(p ,Aux1);
    while(Aux1->esq!=NULL)
    {
        Aux1 = Aux1->esq;
        push(p ,Aux1);
    }
}
#ifdef SEM_MACRO
//Operacoes Sem Macro

void S(pilha *P, No **raiz)
{
    pai_a = (No*) malloc(sizeof(No));
    pai_b = (No*) malloc(sizeof(No));
    pai_c = (No*) malloc(sizeof(No));
    resto = (No*) malloc(sizeof(No));

    No *novo1 = (No*) malloc(sizeof(No));
    No *novo2 = (No*) malloc(sizeof(No));
    No *novo3 = (No*) malloc(sizeof(No));

    if(tamPilha > 2)
    {
        pai_a = pop(P);
        pai_b = pop(P);
        pai_c = pop(P);

        pai_b->esq = (pai_a->dir);
        novo1 = pai_b->dir;
        pai_b->dir = pai_c->dir;
        pai_c->dir = pai_a;
        pai_c->dir->dir = pai_b->dir;
        pai_c->dir->esq = novo1 ;
        //pai_c->esq = NULL ;
        DecodificaOperacao(pai_c, P);
    }
    else
    {
        printf("\nParametros Insuficientes (FIM)\n");
        Fim = 1;
    }
}

void K(pilha *P, No **raiz)
{
    pai_a = (No*) malloc(sizeof(No));
    pai_b = (No*) malloc(sizeof(No));
    resto = (No*) malloc(sizeof(No));
    No *novo1 = (No*) malloc(sizeof(No));

    if(tamPilha > 2)
    {
        pai_a = pop(P);
        pai_b = pop(P);
        resto = pop(P);

        pai_a->esq = NULL;
        resto->esq = pai_a->dir;
        novo1 = pai_b;
        novo1->esq->dir = NULL;
        novo1->dir = NULL;
        novo1->esq = NULL;
        DecodificaOperacao(resto, P);
    }
    else if(tamPilha == 2)
    {
        pai_a = pop(P);
        pai_b = pop(P);

        novo1 = pai_b->esq;
        pai_b->dir = NULL;
        pai_b->esq = NULL;

        if(pai_a->dir->c == '@')
        {
            pai_b = pai_a->dir;
        }
        else
        {
            pai_b->esq = pai_a->dir;
        }
        DecodificaOperacao(pai_b, P);
        novo1->dir = NULL;
        novo1->esq = NULL;
    }
    else
    {
        printf("\nParametros Insuficientes (FIM)\n");
        Fim = 1;
    }
}
#endif
int main()
{
    char strEntrada[200000];
    No *Raiz;
    int profundidade = 0;
    pilha P[200000];

    OP = (No*) malloc(sizeof(No));

    FILE *arq = fopen("string.in", "r");
    fscanf(arq,"%s",strEntrada);

    criaNo('@', &Raiz);
    Raiz = criaGrafo(strEntrada, Raiz);
    //printaGrafo(Raiz);
    printf("\n");

    DecodificaOperacao(Raiz, P);
    do
    {
        OP = pop(P);
        switch (OP->c)
        {
        case 'S':
            S(P, &Raiz);
            break;
        case 'K':
            K(P, &Raiz);
            break;
        case 'B':
            //B(profundidade);
            break;
        case 'H':
            //H(profundidade);
            break;
        case 'P':
            //P(profundidade);
            break;
        case 'I':
            //I(profundidade);
            break;
        case 'W':
            //W(profundidade);
            break;
        case 'C':
            //C(P);
            break;
        }
    }
    while(Fim == 0);
    printf("\n");
    printaGrafo(Raiz);
    printf("\n");

    return 0;
}
