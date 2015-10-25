#include <stdio.h>
#include <stdlib.h>
#include "OperacoesComGrafo.h"
#include "OperacoesComPilha.h"
#define SEM_MACRO
//#define COM_MACRO

int Fim,i;
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

#ifdef COM_MACRO

#define S(P,raiz)({                                                         \
{                                                                           \
    pai_a = (No*) malloc(sizeof(No));                                       \
    pai_b = (No*) malloc(sizeof(No));                                       \
    pai_c = (No*) malloc(sizeof(No));                                       \
                                                                            \
    No *novo1 = (No*) malloc(sizeof(No));                                   \
                                                                            \
    if(tamPilha > 2)                                                        \
    {                                                                       \
        pai_a = pop(P);                                                     \
        pai_b = pop(P);                                                     \
        pai_c = pop(P);                                                     \
                                                                            \
        pai_b->esq = (pai_a->dir);                                          \
        novo1 = pai_b->dir;                                                 \
        pai_b->dir = pai_c->dir;                                            \
        pai_c->dir = pai_a;                                                 \
        pai_c->dir->dir = pai_b->dir;                                       \
        pai_c->dir->esq = novo1 ;                                           \
                                                                            \
        DecodificaOperacao(pai_c, P);                                       \
    }                                                                       \
    else                                                                    \
    {                                                                       \
        printf("\nParametros Insuficientes (FIM)\n");                       \
        Fim = 1;                                                            \
    }                                                                       \
}                                                                           \
})


#define K(P,raiz)({                                                        \
{                                                                           \
    pai_a = (No*) malloc(sizeof(No));                                       \
    pai_b = (No*) malloc(sizeof(No));                                       \
    resto = (No*) malloc(sizeof(No));                                       \
    No *novo1 = (No*) malloc(sizeof(No));                                   \
                                                                            \
    if(tamPilha > 2)                                                        \
    {                                                                       \
        pai_a = pop(P);                                                     \
        pai_b = pop(P);                                                     \
        resto = pop(P);                                                     \
                                                                            \
        pai_a->esq = NULL;                                                  \
        resto->esq = pai_a->dir;                                            \
        novo1 = pai_b;                                                      \
        novo1->esq->dir = NULL;                                             \
        novo1->dir = NULL;                                                  \
        novo1->esq = NULL;                                                  \
        DecodificaOperacao(resto, P);                                       \
    }                                                                       \
    else if(tamPilha == 2)                                                  \
    {                                                                       \
        pai_a = pop(P);                                                     \
        pai_b = pop(P);                                                     \
                                                                            \
        novo1 = pai_b->esq;                                                 \
        pai_b->dir = NULL;                                                  \
        pai_b->esq = NULL;                                                  \
                                                                            \
        if(pai_a->dir->c == '@')                                            \
        {                                                                   \
            pai_b = pai_a->dir;                                             \
        }                                                                   \
        else                                                                \
        {                                                                   \
            pai_b->esq = pai_a->dir;                                        \
        }                                                                   \
        DecodificaOperacao(pai_b, P);                                       \
        novo1->dir = NULL;                                                  \
        novo1->esq = NULL;                                                  \
    }                                                                       \
    else                                                                    \
    {                                                                       \
        printf("\nParametros Insuficientes (FIM)\n");                       \
        Fim = 1;                                                            \
    }                                                                       \
}                                                                           \
})                                                                          \



#define C(P,raiz)({                                                        \
{                                                                           \
    pai_a = (No*) malloc(sizeof(No));                                       \
    pai_b = (No*) malloc(sizeof(No));                                       \
    pai_c = (No*) malloc(sizeof(No));                                       \
    if(tamPilha > 2)                                                        \
    {                                                                       \
        pai_a = pop(P);                                                     \
        pai_b = pop(P);                                                     \
        pai_c = pop(P);                                                     \
        pai_a->esq = pai_c->dir;                                            \
        pai_c->dir = pai_b->dir;                                            \
        pai_b->dir = pai_a->esq;                                            \
        pai_b->esq = pai_a->dir;                                            \
        pai_a->esq = NULL;                                                  \
        pai_a->dir = NULL;                                                  \
        DecodificaOperacao(pai_c, P);                                       \
    }                                                                       \
    else                                                                    \
    {                                                                       \
        printf("\nParametros Insuficientes (FIM)\n");                       \
        Fim = 1;                                                            \
    }                                                                       \
}                                                                           \
})

#define B(P,raiz)({                                                        \
{                                                                           \
    pai_a = (No*) malloc(sizeof(No));                                       \
    pai_b = (No*) malloc(sizeof(No));                                       \
    pai_c = (No*) malloc(sizeof(No));                                       \
    No *Aux = (No*) malloc (sizeof(No));                                    \
    if(tamPilha > 2)                                                        \
    {                                                                       \
        pai_a = pop(P);                                                     \
        pai_b = pop(P);                                                     \
        pai_c = pop(P);                                                     \
        pai_c->esq = pai_a->dir;                                            \
        Aux = pai_c->dir;                                                   \
        pai_c->dir = pai_a;                                                 \
        pai_c->dir->dir = Aux;                                              \
        pai_c->dir->esq = pai_b->dir;                                       \
        pai_b->dir = NULL;                                                  \
        pai_b->esq = NULL;                                                  \
        DecodificaOperacao(pai_c, P);                                       \
    }                                                                       \
    else                                                                    \
    {                                                                       \
        printf("\nParametros Insuficientes (FIM)\n");                       \
        Fim = 1;                                                            \
    }                                                                       \
}                                                                           \
})


#define W(P,raiz)({                                                        \
{                                                                           \
    pai_a = (No*) malloc(sizeof(No));                                       \
    pai_b = (No*) malloc(sizeof(No));                                       \
    pai_c = (No*) malloc(sizeof(No));                                       \
    pai_d = (No*) malloc(sizeof(No));                                       \
                                                                            \
    if(tamPilha > 3)                                                        \
    {                                                                       \
        pai_a = pop(P);                                                     \
        pai_b = pop(P);                                                     \
        pai_c = pop(P);                                                     \
        pai_d = pop(P);                                                     \
        pai_d->esq = pai_a;                                                 \
        pai_d->esq->esq = pai_d->esq->dir;                                  \
        pai_d->esq->dir = pai_b;                                            \
        pai_d->esq->dir->esq = pai_d->esq->dir->dir;                        \
        pai_d->esq->dir->dir = pai_d->dir;                                  \
        pai_d->dir = pai_c;                                                 \
        pai_d->dir->esq = pai_d->dir->dir;                                  \
        pai_d->dir->dir = pai_d->esq->dir->dir;                             \
        DecodificaOperacao(pai_d, P);                                       \
    }                                                                       \
    else                                                                    \
    {                                                                       \
        printf("\nParametros Insuficientes (FIM)\n");                       \
        Fim = 1;                                                            \
    }                                                                       \
}                                                                           \
})


#define P(P,raiz)({                                                        \
{                                                                           \
    pai_a = (No*) malloc(sizeof(No));                                       \
    pai_b = (No*) malloc(sizeof(No));                                       \
    pai_c = (No*) malloc(sizeof(No));                                       \
    pai_d = (No*) malloc(sizeof(No));                                       \
    No *Aux = (No*) malloc (sizeof(No));                                    \
    if(tamPilha > 3)                                                        \
    {                                                                       \
        pai_a = pop(P);                                                     \
        pai_b = pop(P);                                                     \
        pai_c = pop(P);                                                     \
        pai_d = pop(P);                                                     \
        Aux = pai_d->dir;                                                   \
        pai_d->dir = pai_c->dir;                                            \
        pai_d->esq = pai_a;                                                 \
        pai_d->esq->esq = pai_d->esq->dir;                                  \
        pai_d->esq->dir = pai_b;                                            \
        pai_d->esq->dir->esq = pai_d->esq->dir->dir;                        \
        pai_d->esq->dir->dir = Aux;                                         \
        pai_c->dir = NULL;                                                  \
        pai_c->esq = NULL;                                                  \
        DecodificaOperacao(pai_d, P);                                       \
    }                                                                       \
    else                                                                    \
    {                                                                       \
        printf("\nParametros Insuficientes (FIM)\n");                       \
        Fim = 1;                                                            \
    }                                                                       \
}                                                                           \
})

#define H(P,raiz)({                                                        \
{                                                                           \
    pai_a = (No*) malloc(sizeof(No));                                       \
    pai_b = (No*) malloc(sizeof(No));                                       \
    pai_c = (No*) malloc(sizeof(No));                                       \
    pai_d = (No*) malloc(sizeof(No));                                       \
    No *Aux = (No*) malloc (sizeof(No));                                    \
    if(tamPilha > 3)                                                        \
    {                                                                       \
        pai_a = pop(P);                                                     \
        pai_b = pop(P);                                                     \
        pai_c = pop(P);                                                     \
        pai_d = pop(P);                                                     \
        pai_d->esq = pai_b;                                                 \
        pai_d->esq->esq = pai_a->dir;                                       \
        Aux = pai_d->dir;                                                   \
        pai_d->dir = pai_c;                                                 \
        pai_d->dir->esq = pai_d->dir->dir;                                  \
        pai_d->dir->dir = Aux;                                              \
        pai_a->esq = NULL;                                                  \
        pai_a->dir = NULL;                                                  \
        DecodificaOperacao(pai_d, P);                                       \
    }                                                                       \
    else                                                                    \
    {                                                                       \
        printf("\nParametros Insuficientes (FIM)\n");                       \
        Fim = 1;                                                            \
    }                                                                       \
}                                                                           \
})

#define I(P,raiz)({                                                        \
{                                                                           \
    pai_a = (No*) malloc(sizeof(No));                                       \
    pai_b = (No*) malloc(sizeof(No));                                       \
    if(tamPilha > 1)                                                        \
    {                                                                       \
        pai_a = pop(P);                                                     \
        pai_b = pop(P);                                                     \
        pai_b->esq = pai_a->dir;                                            \
        pai_a->esq = NULL;                                                  \
        pai_a->dir = NULL;                                                  \
        DecodificaOperacao(pai_b, P);                                       \
    }                                                                       \
    else if(tamPilha == 1)                                                  \
    {                                                                       \
        pai_a = pop(P);                                                     \
        pai_a->esq = pai_a->dir;                                            \
        pai_a->dir = NULL;                                                  \
        DecodificaOperacao(pai_a, P);                                       \
    }                                                                       \
    else                                                                    \
    {                                                                       \
        printf("\nParametros Insuficientes (FIM)\n");                       \
        Fim=1;                                                              \
    }                                                                       \
}                                                                           \
})
#endif // COM_MACRO



#ifdef SEM_MACRO

void S(pilha *P, No **raiz)
{
    pai_a = (No*) malloc(sizeof(No));
    pai_b = (No*) malloc(sizeof(No));
    pai_c = (No*) malloc(sizeof(No));

    No *novo1 = (No*) malloc(sizeof(No));

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

void C(pilha *P, No **raiz)
{
    pai_a = (No*) malloc(sizeof(No));
    pai_b = (No*) malloc(sizeof(No));
    pai_c = (No*) malloc(sizeof(No));

    if(tamPilha > 2)
    {
        pai_a = pop(P);
        pai_b = pop(P);
        pai_c = pop(P);

        pai_a->esq = pai_c->dir;
        pai_c->dir = pai_b->dir;
        pai_b->dir = pai_a->esq;
        pai_b->esq = pai_a->dir;
        pai_a->esq = NULL;
        pai_a->dir = NULL;

        DecodificaOperacao(pai_c, P);
    }
    else
    {
        printf("\nParametros Insuficientes (FIM)\n");
        Fim = 1;
    }
}

void B(pilha *P, No **raiz)
{
    pai_a = (No*) malloc(sizeof(No));
    pai_b = (No*) malloc(sizeof(No));
    pai_c = (No*) malloc(sizeof(No));
    No *Aux = (No*) malloc (sizeof(No));

    if(tamPilha > 2)
    {
        pai_a = pop(P);
        pai_b = pop(P);
        pai_c = pop(P);


        pai_c->esq = pai_a->dir;
        Aux = pai_c->dir;
        pai_c->dir = pai_a;
        pai_c->dir->dir = Aux;
        pai_c->dir->esq = pai_b->dir;
        pai_b->dir = NULL;
        pai_b->esq = NULL;

        DecodificaOperacao(pai_c, P);
    }
    else
    {
        printf("\nParametros Insuficientes (FIM)\n");
        Fim = 1;
    }
}

void W(pilha *P, No **raiz)
{
    pai_a = (No*) malloc(sizeof(No));
    pai_b = (No*) malloc(sizeof(No));
    pai_c = (No*) malloc(sizeof(No));
    pai_d = (No*) malloc(sizeof(No));

    if(tamPilha > 3)
    {
        pai_a = pop(P);
        pai_b = pop(P);
        pai_c = pop(P);
        pai_d = pop(P);


        pai_d->esq = pai_a;
        pai_d->esq->esq = pai_d->esq->dir;
        pai_d->esq->dir = pai_b;
        pai_d->esq->dir->esq = pai_d->esq->dir->dir;
        pai_d->esq->dir->dir = pai_d->dir;
        pai_d->dir = pai_c;
        pai_d->dir->esq = pai_d->dir->dir;
        pai_d->dir->dir = pai_d->esq->dir->dir;

        DecodificaOperacao(pai_d, P);
    }
    else
    {
        printf("\nParametros Insuficientes (FIM)\n");
        Fim = 1;
    }
}

void P(pilha *P, No **raiz)
{
    pai_a = (No*) malloc(sizeof(No));
    pai_b = (No*) malloc(sizeof(No));
    pai_c = (No*) malloc(sizeof(No));
    pai_d = (No*) malloc(sizeof(No));
    No *Aux = (No*) malloc (sizeof(No));

    if(tamPilha > 3)
    {
        pai_a = pop(P);
        pai_b = pop(P);
        pai_c = pop(P);
        pai_d = pop(P);



        Aux = pai_d->dir;
        pai_d->dir = pai_c->dir;
        pai_d->esq = pai_a;
        pai_d->esq->esq = pai_d->esq->dir;
        pai_d->esq->dir = pai_b;
        pai_d->esq->dir->esq = pai_d->esq->dir->dir;
        pai_d->esq->dir->dir = Aux;
        pai_c->dir = NULL;
        pai_c->esq = NULL;

        DecodificaOperacao(pai_d, P);
    }
    else
    {
        printf("\nParametros Insuficientes (FIM)\n");
        Fim = 1;
    }
}

void H(pilha *P, No **raiz)
{
    pai_a = (No*) malloc(sizeof(No));
    pai_b = (No*) malloc(sizeof(No));
    pai_c = (No*) malloc(sizeof(No));
    pai_d = (No*) malloc(sizeof(No));
    No *Aux = (No*) malloc (sizeof(No));

    if(tamPilha > 3)
    {
        pai_a = pop(P);
        pai_b = pop(P);
        pai_c = pop(P);
        pai_d = pop(P);


        pai_d->esq = pai_b;
        pai_d->esq->esq = pai_a->dir;
        Aux = pai_d->dir;
        pai_d->dir = pai_c;
        pai_d->dir->esq = pai_d->dir->dir;
        pai_d->dir->dir = Aux;
        pai_a->esq = NULL;
        pai_a->dir = NULL;

        DecodificaOperacao(pai_d, P);
    }
    else
    {
        printf("\nParametros Insuficientes (FIM)\n");
        Fim = 1;
    }
}

void I(pilha *P, No **raiz)
{
    pai_a = (No*) malloc(sizeof(No));
    pai_b = (No*) malloc(sizeof(No));

    if(tamPilha > 1)
    {
        pai_a = pop(P);
        pai_b = pop(P);

        pai_b->esq = pai_a->dir;
        pai_a->esq = NULL;
        pai_a->dir = NULL;

        DecodificaOperacao(pai_b, P);
    }
    else if(tamPilha == 1)
    {
        pai_a = pop(P);
        pai_a->esq = pai_a->dir;
        pai_a->dir = NULL;
        DecodificaOperacao(pai_a, P);
    }
    else
    {
        printf("\nParametros Insuficientes (FIM)\n");
        Fim=1;
    }
}

#endif // SEM_MACRO

int main()
{
    char strEntrada[200000];
    No *Raiz;
    int profundidade = 0;
    pilha Pilha[200000];
    OP = (No*) malloc(sizeof(No));
    FILE *arq = fopen("string.in", "r");
    fscanf(arq,"%s",strEntrada);
    criaNo('@', &Raiz);
    Raiz = criaGrafo(strEntrada, Raiz);
    DecodificaOperacao(Raiz, Pilha);
    int a=0;
    while(Fim == 0)
    {
        a++;
        OP = pop(Pilha);
        switch (OP->c)
        {
        case 'S':
            S(Pilha, &Raiz);
            break;
        case 'K':
            K(Pilha, &Raiz);
            break;
        case 'B':
            B(Pilha, &Raiz);
            break;
        case 'H':
            H(Pilha, &Raiz);
            break;
        case 'P':
            P(Pilha, &Raiz);
            break;
        case 'I':
            I(Pilha, &Raiz);
            break;
        case 'W':
            W(Pilha, &Raiz);
            break;
        case 'C':
            C(Pilha, &Raiz);
            break;
        }


    }

    printf("Saida: ");
    printaGrafo(Raiz);
    printf("\nIteracoes: %d",a);

    return 0;
}
// S' = W // C' = P // B' = H
