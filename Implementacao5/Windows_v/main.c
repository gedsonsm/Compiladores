#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "OperacoesComGrafo.h"
#include "OperacoesComPilha.h"
//#define CONT_FLAG

#define SEM_MACRO
//#define COM_MACRO


#ifdef COM_MACRO

#define S(P, raiz)                                          \
({                                                          \
    pai_a = (No*) malloc(sizeof(No));                       \
    pai_b = (No*) malloc(sizeof(No));                       \
    pai_c = (No*) malloc(sizeof(No));                       \
	pai_resto = (No*) malloc(sizeof(No));                   \
                                                            \
    No *Aux1;                                               \
    No *Aux2;                                               \
    No *Aux3;                                               \
    criaNo('@', &Aux1);                                     \
    criaNo('@', &Aux2);                                     \
    criaNo('@', &Aux3);                                     \
                                                            \
    if (tamPilha > 3)                                       \
	{                                                       \
		pai_a = pop(P);                                     \
        pai_b = pop(P);                                     \
        pai_c = pop(P);                                     \
		pai_resto = pop(P);                                 \
                                                            \
		Aux2->esq = pai_a->dir;                             \
		Aux2->dir = pai_c->dir;                             \
		Aux3->esq = pai_b->dir;                             \
		Aux3->dir = pai_c->dir;                             \
		Aux1->esq = Aux2;                                   \
		Aux1->dir = Aux3;                                   \
		pai_resto->esq = Aux1;                              \
                                                            \
		DecodificaOperacao(pai_resto, P);                   \
	}                                                       \
	else if(tamPilha == 3)                                  \
    {                                                       \
        pai_a = pop(P);                                     \
        pai_b = pop(P);                                     \
        pai_c = pop(P);                                     \
                                                            \
		Aux2->esq = pai_a->dir;                             \
		Aux2->dir = pai_c->dir;                             \
		Aux3->esq = pai_b->dir;                             \
		Aux3->dir = pai_c->dir;                             \
		Aux1->esq = Aux2;                                   \
		Aux1->dir = Aux3;                                   \
		*raiz = Aux1;                                       \
                                                            \
        DecodificaOperacao(*raiz, P);                       \
    }                                                       \
    else                                                    \
    {                                                       \
        Fim = 1;                                            \
    }                                                       \
})

#define K(P, raiz)                                          \
({                                                          \
    pai_a = (No*) malloc(sizeof(No));                       \
    pai_b = (No*) malloc(sizeof(No));                       \
    pai_resto = (No*) malloc(sizeof(No));                   \
                                                            \
    if(tamPilha > 2)                                        \
    {                                                       \
        pai_a = pop(P);                                     \
        pai_b = pop(P);                                     \
        pai_resto = pop(P);                                 \
        pai_resto->esq = pai_a->dir;                        \
                                                            \
        DecodificaOperacao(pai_resto, P);                   \
    }                                                       \
    else if(tamPilha == 2)                                  \
    {                                                       \
        pai_a = pop(P);                                     \
        pai_b = pop(P);                                     \
                                                            \
        (*raiz)->dir = NULL;                                \
        (*raiz)->esq = pai_a->dir;                          \
                                                            \
        DecodificaOperacao(*raiz, P);                       \
    }                                                       \
    else                                                    \
    {                                                       \
        Fim = 1;                                            \
    }                                                       \
})

#define C(P, raiz)                                          \
({                                                          \
    pai_a = (No*) malloc(sizeof(No));                       \
    pai_b = (No*) malloc(sizeof(No));                       \
    pai_c = (No*) malloc(sizeof(No));                       \
    pai_resto = (No*) malloc (sizeof(No));                  \
                                                            \
    No *Aux1 ;                                              \
    No *Aux2 ;                                              \
    criaNo('@', &Aux1);                                     \
    criaNo('@', &Aux2);                                     \
                                                            \
    if(tamPilha > 3)                                        \
    {                                                       \
        pai_a = pop(P);                                     \
        pai_b = pop(P);                                     \
        pai_c = pop(P);                                     \
        pai_resto = pop(P);                                 \
                                                            \
        Aux2->esq = pai_a->dir;                             \
        Aux2->dir = pai_c->dir;                             \
        Aux1->dir = pai_b->dir;                             \
        Aux1->esq = Aux2;                                   \
        pai_resto->esq = Aux1;                              \
                                                            \
        DecodificaOperacao(pai_resto, P);                   \
    }                                                       \
    if(tamPilha == 3)                                       \
    {                                                       \
        pai_a = pop(P);                                     \
        pai_b = pop(P);                                     \
        pai_c = pop(P);                                     \
                                                            \
        Aux2->esq = pai_a->dir;                             \
        Aux2->dir = pai_c->dir;                             \
        Aux1->dir = pai_b->dir;                             \
        Aux1->esq = Aux2;                                   \
        *raiz = Aux1;                                       \
                                                            \
        DecodificaOperacao(*raiz, P);                       \
    }                                                       \
    else                                                    \
    {                                                       \
        Fim = 1;                                            \
    }                                                       \
})

#define B(P, raiz)                                          \
({                                                          \
    pai_a = (No*) malloc(sizeof(No));                       \
    pai_b = (No*) malloc(sizeof(No));                       \
    pai_c = (No*) malloc(sizeof(No));                       \
    pai_resto = (No*) malloc (sizeof(No));                  \
                                                            \
    No *Aux1;                                               \
    No *Aux2;                                               \
    criaNo('@', &Aux1);                                     \
    criaNo('@', &Aux2);                                     \
                                                            \
    if(tamPilha > 3)                                        \
    {                                                       \
        pai_a = pop(P);                                     \
        pai_b = pop(P);                                     \
        pai_c = pop(P);                                     \
        pai_resto = pop(P);                                 \
                                                            \
        Aux2->esq = pai_b->dir;                             \
        Aux2->dir = pai_c->dir;                             \
        Aux1->esq = pai_a->dir;                             \
        Aux1->dir = Aux2;                                   \
        pai_resto->esq = Aux1;                              \
                                                            \
        DecodificaOperacao(pai_resto, P);                   \
    }                                                       \
    else if(tamPilha == 3)                                  \
    {                                                       \
        pai_a = pop(P);                                     \
        pai_b = pop(P);                                     \
        pai_c = pop(P);                                     \
                                                            \
        Aux2->esq = pai_b->dir;                             \
        Aux2->dir = pai_c->dir;                             \
        Aux1->esq = pai_a->dir;                             \
        Aux1->dir = Aux2;                                   \
        *raiz = Aux1;                                       \
                                                            \
        DecodificaOperacao(*raiz, P);                       \
    }                                                       \
    else                                                    \
    {                                                       \
        Fim = 1;                                            \
    }                                                       \
})

#define SL(P, raiz)                                          \
({                                                          \
    pai_a = (No*) malloc(sizeof(No));                       \
    pai_b = (No*) malloc(sizeof(No));                       \
    pai_c = (No*) malloc(sizeof(No));                       \
    pai_d = (No*) malloc(sizeof(No));                       \
    pai_resto = (No*) malloc(sizeof(No));                   \
                                                            \
    No *Aux1;                                               \
    No *Aux2;                                               \
    No *Aux3;                                               \
    No *Aux4;                                               \
    criaNo('@', &Aux1);                                     \
    criaNo('@', &Aux2);                                     \
    criaNo('@', &Aux3);                                     \
    criaNo('@', &Aux4);                                     \
                                                            \
    if(tamPilha > 4)                                        \
    {                                                       \
        pai_a = pop(P);                                     \
        pai_b = pop(P);                                     \
        pai_c = pop(P);                                     \
        pai_d = pop(P);                                     \
        pai_resto = pop(P);                                 \
                                                            \
        Aux4->esq = pai_b->dir;                             \
        Aux4->dir = pai_d->dir;                             \
        Aux3->esq = pai_c->dir;                             \
        Aux3->dir = pai_d->dir;                             \
        Aux2->esq = pai_a->dir;                             \
        Aux2->dir = Aux4;                                   \
        Aux1->esq = Aux2;                                   \
        Aux1->dir = Aux3;                                   \
        pai_resto->esq = Aux1;                              \
                                                            \
        DecodificaOperacao(pai_resto, P);                   \
    }                                                       \
    else if(tamPilha == 4)                                  \
    {                                                       \
        pai_a = pop(P);                                     \
        pai_b = pop(P);                                     \
        pai_c = pop(P);                                     \
        pai_d = pop(P);                                     \
                                                            \
        Aux4->esq = pai_b->dir;                             \
        Aux4->dir = pai_d->dir;                             \
        Aux3->esq = pai_c->dir;                             \
        Aux3->dir = pai_d->dir;                             \
        Aux2->esq = pai_a->dir;                             \
        Aux2->dir = Aux4;                                   \
        Aux1->esq = Aux2;                                   \
        Aux1->dir = Aux3;                                   \
        *raiz = Aux1;                                       \
                                                            \
        DecodificaOperacao(*raiz, P);                       \
    }                                                       \
    else                                                    \
    {                                                       \
        printf("\nParametros Insuficientes (FIM)\n");       \
        Fim = 1;                                            \
    }                                                       \
})

#define CL(P, raiz)                                          \
({                                                          \
    pai_a = (No*) malloc(sizeof(No));                       \
    pai_b = (No*) malloc(sizeof(No));                       \
    pai_c = (No*) malloc(sizeof(No));                       \
    pai_d = (No*) malloc(sizeof(No));                       \
    pai_resto = (No*) malloc(sizeof(No));                   \
                                                            \
    No *Aux1;                                               \
    No *Aux2;                                               \
    No *Aux3;                                               \
    criaNo('@', &Aux1);                                     \
    criaNo('@', &Aux2);                                     \
    criaNo('@', &Aux3);                                     \
                                                            \
    if(tamPilha > 4)                                        \
    {                                                       \
        pai_a = pop(P);                                     \
        pai_b = pop(P);                                     \
        pai_c = pop(P);                                     \
        pai_d = pop(P);                                     \
        pai_resto = pop(P);                                 \
                                                            \
        Aux3->esq = pai_b->dir;                             \
        Aux3->dir = pai_d->dir;                             \
        Aux2->esq = pai_a->dir;                             \
        Aux2->dir = Aux3;                                   \
        Aux1->esq = Aux2;                                   \
        Aux1->dir = pai_c->dir;                             \
        pai_resto->esq = Aux1;                              \
                                                            \
        DecodificaOperacao(pai_resto, P);                   \
    }                                                       \
    else if(tamPilha == 4)                                  \
    {                                                       \
        pai_a = pop(P);                                     \
        pai_b = pop(P);                                     \
        pai_c = pop(P);                                     \
        pai_d = pop(P);                                     \
                                                            \
        Aux3->esq = pai_b->dir;                             \
        Aux3->dir = pai_d->dir;                             \
        Aux2->esq = pai_a->dir;                             \
        Aux2->dir = Aux3;                                   \
        Aux1->esq = Aux2;                                   \
        Aux1->dir = pai_c->dir;                             \
        *raiz = Aux1;                                       \
                                                            \
        DecodificaOperacao(*raiz, P);                       \
    }                                                       \
    else                                                    \
    {                                                       \
        Fim = 1;                                            \
    }                                                       \
})

#define BL(P, raiz)                                          \
({                                                          \
    pai_a = (No*) malloc(sizeof(No));                       \
    pai_b = (No*) malloc(sizeof(No));                       \
    pai_c = (No*) malloc(sizeof(No));                       \
    pai_d = (No*) malloc(sizeof(No));                       \
    pai_resto = (No*) malloc(sizeof(No));                   \
                                                            \
    No *Aux1 ;                                              \
    No *Aux2 ;                                              \
    No *Aux3 ;                                              \
    criaNo('@', &Aux1);                                     \
    criaNo('@', &Aux2);                                     \
    criaNo('@', &Aux3);                                     \
                                                            \
    if(tamPilha > 4)                                        \
    {                                                       \
        pai_a = pop(P);                                     \
        pai_b = pop(P);                                     \
        pai_c = pop(P);                                     \
        pai_d = pop(P);                                     \
        pai_resto = pop(P);                                 \
                                                            \
        Aux3->esq = pai_c->dir;                             \
        Aux3->dir = pai_d->dir;                             \
        Aux2->esq = pai_a->dir;                             \
        Aux2->dir = pai_b->dir;                             \
        Aux1->esq = Aux2;                                   \
        Aux1->dir = Aux3;                                   \
        pai_resto->esq = Aux1;                              \
                                                            \
        DecodificaOperacao(pai_resto, P);                   \
    }                                                       \
    else if(tamPilha == 4)                                  \
    {                                                       \
        pai_a = pop(P);                                     \
        pai_b = pop(P);                                     \
        pai_c = pop(P);                                     \
        pai_d = pop(P);                                     \
                                                            \
        Aux3->esq = pai_c->dir;                             \
        Aux3->dir = pai_d->dir;                             \
        Aux2->esq = pai_a->dir;                             \
        Aux2->dir = pai_b->dir;                             \
        Aux1->esq = Aux2;                                   \
        Aux1->dir = Aux3;                                   \
        *raiz =Aux1;                                        \
                                                            \
        DecodificaOperacao(*raiz, P);                       \
    }                                                       \
    else                                                    \
    {                                                       \
        Fim = 1;                                            \
    }                                                       \
})

#define I(P, raiz)                                          \
({                                                          \
    pai_a = (No*) malloc(sizeof(No));                       \
    pai_resto = (No*) malloc(sizeof(No));                   \
                                                            \
    if(tamPilha > 1)                                        \
    {                                                       \
        pai_a = pop(P);                                     \
        pai_resto = pop(P);                                 \
                                                            \
        pai_resto->esq = pai_a->dir;                        \
                                                            \
        DecodificaOperacao(pai_resto, P);                   \
    }                                                       \
    else if(tamPilha == 1)                                  \
    {                                                       \
        pai_a = pop(P);                                     \
                                                            \
        (*raiz)->dir = NULL;                                \
        (*raiz)->esq = pai_a->dir;                          \
                                                            \
        DecodificaOperacao(*raiz, P);                       \
    }                                                       \
    else                                                    \
    {                                                       \
        Fim=1;                                              \
    }                                                       \
})
#endif // COM_MACRO

int Fim,i, garbage;
No *OP;
No *pai_a;
No *pai_b;
No *pai_c;
No *pai_d;
No *pai_resto;

#ifdef CONT_FLAG
int cont_S;
int cont_K;
int cont_I;
int cont_C;
int cont_B;
int cont_SL;
int cont_CL;
int cont_BL;
#endif

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

void S(pilha *P, No **raiz)
{
    pai_a = (No*) malloc(sizeof(No));
    pai_b = (No*) malloc(sizeof(No));
    pai_c = (No*) malloc(sizeof(No));
    pai_resto = (No*) malloc(sizeof(No));

    No *Aux1;
    No *Aux2;
    No *Aux3;
    criaNo('@', &Aux1);
    criaNo('@', &Aux2);
    criaNo('@', &Aux3);

    if (tamPilha > 3)
    {
        pai_a = pop(P);
        pai_b = pop(P);
        pai_c = pop(P);
        pai_resto = pop(P);

        Aux2->esq = pai_a->dir;
        Aux2->dir = pai_c->dir;
        Aux3->esq = pai_b->dir;
        Aux3->dir = pai_c->dir;
        Aux1->esq = Aux2;
        Aux1->dir = Aux3;
        pai_resto->esq = Aux1;

        DecodificaOperacao(pai_resto, P);
    }
    else if(tamPilha == 3)
    {
        pai_a = pop(P);
        pai_b = pop(P);
        pai_c = pop(P);

        Aux2->esq = pai_a->dir;
        Aux2->dir = pai_c->dir;
        Aux3->esq = pai_b->dir;
        Aux3->dir = pai_c->dir;
        Aux1->esq = Aux2;
        Aux1->dir = Aux3;
        *raiz = Aux1;

        DecodificaOperacao(*raiz, P);
    }
    else
    {
        Fim = 1;
    }
}

void K(pilha *P, No **raiz)
{
    pai_a = (No*) malloc(sizeof(No));
    pai_b = (No*) malloc(sizeof(No));
    pai_resto = (No*) malloc(sizeof(No));

    if(tamPilha > 2)
    {
        pai_a = pop(P);
        pai_b = pop(P);
        pai_resto = pop(P);

        pai_resto->esq = pai_a->dir;

        DecodificaOperacao(pai_resto, P);
    }
    else if(tamPilha == 2)
    {
        pai_a = pop(P);
        pai_b = pop(P);

        (*raiz)->dir = NULL;
        (*raiz)->esq = pai_a->dir;

        DecodificaOperacao(*raiz, P);
    }
    else
    {
        Fim = 1;
    }
}

void C(pilha *P, No **raiz)
{
    pai_a = (No*) malloc(sizeof(No));
    pai_b = (No*) malloc(sizeof(No));
    pai_c = (No*) malloc(sizeof(No));
    pai_resto = (No*) malloc (sizeof(No));

    No *Aux1 ;
    No *Aux2 ;
    criaNo('@', &Aux1);
    criaNo('@', &Aux2);

    if(tamPilha > 3)
    {
        pai_a = pop(P);
        pai_b = pop(P);
        pai_c = pop(P);
        pai_resto = pop(P);

        Aux2->esq = pai_a->dir;
        Aux2->dir = pai_c->dir;
        Aux1->dir = pai_b->dir;
        Aux1->esq = Aux2;
        pai_resto->esq = Aux1;

        DecodificaOperacao(pai_resto, P);
    }
    if(tamPilha == 3)
    {
        pai_a = pop(P);
        pai_b = pop(P);
        pai_c = pop(P);

        Aux2->esq = pai_a->dir;
        Aux2->dir = pai_c->dir;
        Aux1->dir = pai_b->dir;
        Aux1->esq = Aux2;
        *raiz = Aux1;

        DecodificaOperacao(*raiz, P);
    }
    else
    {
        Fim = 1;
    }
}

void B(pilha *P, No **raiz)
{
    pai_a = (No*) malloc(sizeof(No));
    pai_b = (No*) malloc(sizeof(No));
    pai_c = (No*) malloc(sizeof(No));
    pai_resto = (No*) malloc (sizeof(No));

    No *Aux1;
    No *Aux2;
    criaNo('@', &Aux1);
    criaNo('@', &Aux2);

    if(tamPilha > 3)
    {
        pai_a = pop(P);
        pai_b = pop(P);
        pai_c = pop(P);
        pai_resto = pop(P);

        Aux2->esq = pai_b->dir;
        Aux2->dir = pai_c->dir;
        Aux1->esq = pai_a->dir;
        Aux1->dir = Aux2;
        pai_resto->esq = Aux1;

        DecodificaOperacao(pai_resto, P);
    }
    else if(tamPilha == 3)
    {
        pai_a = pop(P);
        pai_b = pop(P);
        pai_c = pop(P);

        Aux2->esq = pai_b->dir;
        Aux2->dir = pai_c->dir;
        Aux1->esq = pai_a->dir;
        Aux1->dir = Aux2;
        *raiz = Aux1;

        DecodificaOperacao(*raiz, P);
    }
    else
    {
        Fim = 1;
    }
}

void SL(pilha *P, No **raiz)
{
    pai_a = (No*) malloc(sizeof(No));
    pai_b = (No*) malloc(sizeof(No));
    pai_c = (No*) malloc(sizeof(No));
    pai_d = (No*) malloc(sizeof(No));
    pai_resto = (No*) malloc(sizeof(No));

    No *Aux1;
    No *Aux2;
    No *Aux3;
    No *Aux4;
    criaNo('@', &Aux1);
    criaNo('@', &Aux2);
    criaNo('@', &Aux3);
    criaNo('@', &Aux4);

    if(tamPilha > 4)
    {
        pai_a = pop(P);
        pai_b = pop(P);
        pai_c = pop(P);
        pai_d = pop(P);
        pai_resto = pop(P);

        Aux4->esq = pai_b->dir;
        Aux4->dir = pai_d->dir;
        Aux3->esq = pai_c->dir;
        Aux3->dir = pai_d->dir;
        Aux2->esq = pai_a->dir;
        Aux2->dir = Aux4;
        Aux1->esq = Aux2;
        Aux1->dir = Aux3;
        pai_resto->esq = Aux1;

        DecodificaOperacao(pai_resto, P);
    }
    else if(tamPilha == 4)
    {
        pai_a = pop(P);
        pai_b = pop(P);
        pai_c = pop(P);
        pai_d = pop(P);

        Aux4->esq = pai_b->dir;
        Aux4->dir = pai_d->dir;
        Aux3->esq = pai_c->dir;
        Aux3->dir = pai_d->dir;
        Aux2->esq = pai_a->dir;
        Aux2->dir = Aux4;
        Aux1->esq = Aux2;
        Aux1->dir = Aux3;
        *raiz = Aux1;

        DecodificaOperacao(*raiz, P);
    }
    else
    {
        Fim = 1;
    }
}

void CL(pilha *P, No **raiz)
{
    pai_a = (No*) malloc(sizeof(No));
    pai_b = (No*) malloc(sizeof(No));
    pai_c = (No*) malloc(sizeof(No));
    pai_d = (No*) malloc(sizeof(No));
    pai_resto = (No*) malloc(sizeof(No));

    No *Aux1;
    No *Aux2;
    No *Aux3;
    criaNo('@', &Aux1);
    criaNo('@', &Aux2);
    criaNo('@', &Aux3);

    if(tamPilha > 4)
    {
        pai_a = pop(P);
        pai_b = pop(P);
        pai_c = pop(P);
        pai_d = pop(P);
        pai_resto = pop(P);

        Aux3->esq = pai_b->dir;
        Aux3->dir = pai_d->dir;
        Aux2->esq = pai_a->dir;
        Aux2->dir = Aux3;
        Aux1->esq = Aux2;
        Aux1->dir = pai_c->dir;
        pai_resto->esq = Aux1;

        DecodificaOperacao(pai_resto, P);
    }
    else if(tamPilha == 4)
    {
        pai_a = pop(P);
        pai_b = pop(P);
        pai_c = pop(P);
        pai_d = pop(P);

        Aux3->esq = pai_b->dir;
        Aux3->dir = pai_d->dir;
        Aux2->esq = pai_a->dir;
        Aux2->dir = Aux3;
        Aux1->esq = Aux2;
        Aux1->dir = pai_c->dir;
        *raiz = Aux1;

        DecodificaOperacao(*raiz, P);
    }
    else
    {
        Fim = 1;
    }
}

void BL(pilha *P, No **raiz)
{
    pai_a = (No*) malloc(sizeof(No));
    pai_b = (No*) malloc(sizeof(No));
    pai_c = (No*) malloc(sizeof(No));
    pai_d = (No*) malloc(sizeof(No));
    pai_resto = (No*) malloc(sizeof(No));

    No *Aux1 ;
    No *Aux2 ;
    No *Aux3 ;
    criaNo('@', &Aux1);
    criaNo('@', &Aux2);
    criaNo('@', &Aux3);

    if(tamPilha > 4)
    {
        pai_a = pop(P);
        pai_b = pop(P);
        pai_c = pop(P);
        pai_d = pop(P);
        pai_resto = pop(P);

        Aux3->esq = pai_c->dir;
        Aux3->dir = pai_d->dir;
        Aux2->esq = pai_a->dir;
        Aux2->dir = pai_b->dir;
        Aux1->esq = Aux2;
        Aux1->dir = Aux3;
        pai_resto->esq = Aux1;

        DecodificaOperacao(pai_resto, P);
    }
    else if(tamPilha == 4)
    {
        pai_a = pop(P);
        pai_b = pop(P);
        pai_c = pop(P);
        pai_d = pop(P);

        Aux3->esq = pai_c->dir;
        Aux3->dir = pai_d->dir;
        Aux2->esq = pai_a->dir;
        Aux2->dir = pai_b->dir;
        Aux1->esq = Aux2;
        Aux1->dir = Aux3;
        *raiz =Aux1;

        DecodificaOperacao(*raiz, P);
    }
    else
    {
        Fim = 1;
    }
}

void I(pilha *P, No **raiz)
{
    pai_a = (No*) malloc(sizeof(No));
    pai_resto = (No*) malloc(sizeof(No));

    if(tamPilha > 1)
    {
        pai_a = pop(P);
        pai_resto = pop(P);

        pai_resto->esq = pai_a->dir;

        DecodificaOperacao(pai_resto, P);
    }
    else if(tamPilha == 1)
    {
        pai_a = pop(P);

        (*raiz)->dir = NULL;
        (*raiz)->esq = pai_a->dir;

        DecodificaOperacao(*raiz, P);
    }
    else
    {
        Fim=1;
    }
}

int OperaSinais(No *raiz)
{

    if(raiz->c=='$')
    {
        //printf("\n%d\n",raiz->esq);
        return (int)raiz->esq;
    }

    else
    {
        if(raiz->esq->esq->c=='*')
            return (OperaSinais(raiz->esq->dir) * OperaSinais(raiz->dir));
        else if(raiz->esq->esq->c=='+')
            return (OperaSinais(raiz->esq->dir) + OperaSinais(raiz->dir));
        else if(raiz->esq->esq->c=='-')
            return (OperaSinais(raiz->esq->dir) - OperaSinais(raiz->dir));
        else if(raiz->esq->esq->c=='/')  // sinal = '/'
            return (OperaSinais(raiz->esq->dir) / OperaSinais(raiz->dir));
        else
            return (int) (pow (OperaSinais(raiz->esq->dir),OperaSinais(raiz->dir)));
    }
}


void MULT(pilha *P, No **raiz)
{
    No *Aux ;
    pai_a = (No*) malloc(sizeof(No));
    pai_b = (No*) malloc(sizeof(No));
    pai_c = (No*) malloc(sizeof(No));
    pai_a = pop(P);
    pai_b = pop(P);
    pai_c = pop(P);
    if(pai_c==NULL)
    {
        criaNo('$', &Aux);
        Aux->esq = (No*)((int)OperaSinais(pai_a->dir) * (int)OperaSinais(pai_b->dir));
        *raiz = Aux;
    }
    else    // Acredito que essa condicioanl Nunca sera usada....
    {
        criaNo('$', &Aux);
        pai_c->esq = Aux;
        pai_c->esq->esq = (No*)((int)OperaSinais(pai_a->dir) * (int)OperaSinais(pai_b->dir));
        DecodificaOperacao(pai_c->esq, P);
    }
}

void ADD(pilha *P, No **raiz)
{
    No *Aux ;
    pai_a = (No*) malloc(sizeof(No));
    pai_b = (No*) malloc(sizeof(No));
    pai_c = (No*) malloc(sizeof(No));
    pai_a = pop(P);
    pai_b = pop(P);
    pai_c = pop(P);
    if(pai_c==NULL)
    {
        criaNo('$', &Aux);
        Aux->esq = (No*)((int)OperaSinais(pai_a->dir) + (int)OperaSinais(pai_b->dir));
        *raiz = Aux;
    }
    else    // Acredito que essa condicioanl Nunca sera usada....
    {
        criaNo('$', &Aux);
        pai_c->esq = Aux;
        pai_c->esq->esq = (No*)((int)OperaSinais(pai_a->dir) + (int)OperaSinais(pai_b->dir));
        DecodificaOperacao(pai_c->esq, P);
    }
}

void SUB(pilha *P, No **raiz)
{
    No *Aux ;
    pai_a = (No*) malloc(sizeof(No));
    pai_b = (No*) malloc(sizeof(No));
    pai_c = (No*) malloc(sizeof(No));
    pai_a = pop(P);
    pai_b = pop(P);
    pai_c = pop(P);
    if(pai_c==NULL)
    {
        criaNo('$', &Aux);
        Aux->esq = (No*)((int)OperaSinais(pai_a->dir) - (int)OperaSinais(pai_b->dir));
        *raiz = Aux;
    }
    else    // Acredito que essa condicioanl Nunca sera usada....
    {
        criaNo('$', &Aux);
        pai_c->esq = Aux;
        pai_c->esq->esq = (No*)((int)OperaSinais(pai_a->dir) - (int)OperaSinais(pai_b->dir));
        DecodificaOperacao(pai_c->esq, P);
    }
}

void DIV(pilha *P, No **raiz)
{
    No *Aux ;
    pai_a = (No*) malloc(sizeof(No));
    pai_b = (No*) malloc(sizeof(No));
    pai_c = (No*) malloc(sizeof(No));
    pai_a = pop(P);
    pai_b = pop(P);
    pai_c = pop(P);
    if(pai_c==NULL)
    {
        criaNo('$', &Aux);
        Aux->esq = (No*)((int)OperaSinais(pai_a->dir) / (int)OperaSinais(pai_b->dir));
        *raiz = Aux;
    }
    else    // Acredito que essa condicioanl Nunca sera usada....
    {
        criaNo('$', &Aux);
        pai_c->esq = Aux;
        pai_c->esq->esq = (No*)((int)OperaSinais(pai_a->dir) / (int)OperaSinais(pai_b->dir));
        DecodificaOperacao(pai_c->esq, P);
    }
}

void POT(pilha *P, No **raiz)
{

    No *Aux ;
    pai_a = (No*) malloc(sizeof(No));
    pai_b = (No*) malloc(sizeof(No));
    pai_c = (No*) malloc(sizeof(No));
    pai_a = pop(P);
    pai_b = pop(P);
    pai_c = pop(P);
    if(pai_c==NULL)
    {
        criaNo('$', &Aux);
        Aux->esq = (No*)((int) (pow ((int)OperaSinais(pai_a->dir),(int)OperaSinais(pai_b->dir))));
        *raiz = Aux;
    }
    else    // Acredito que essa condicioanl Nunca sera usada....
    {

        criaNo('$', &Aux);
        pai_c->esq = Aux;
        pai_c->esq->esq = (No*)((int) (pow ((int)OperaSinais(pai_a->dir),(int)OperaSinais(pai_b->dir))));
        DecodificaOperacao(pai_c->esq, P);
    }
}

void Hd(pilha *P, No **raiz);// a função Hd eh chamda na Tl e na Hd, entao precisamos de uma declaração antecipada

void Tl(pilha *P, No **raiz)
{
    No *pai_a = (No*) malloc(sizeof(No));
    No *pai_resto = (No*) malloc(sizeof(No));
    pilha Pilha[10000];
    if(tamPilha > 1)
    {
        pai_a = pop(P);
        pai_resto = pop(P);
        if(pai_a->dir->c == '@')
        {
            DecodificaOperacao(pai_a, Pilha);
            OP = pop(Pilha);
            if(OP->c == 'T')
                Tl(Pilha, &pai_a->dir);
            else if(OP->c == 'H')
                Hd(Pilha, &pai_a->dir);
            else
                printf("\n--ERRO!!--\n");
        }
        pai_resto->esq = pai_a->dir->dir;

        DecodificaOperacao(pai_resto, P);
    }
    else if(tamPilha == 1)
    {
        pai_a = pop(P);
        if(pai_a->dir->c == '@')
        {
            DecodificaOperacao(pai_a->dir, Pilha);
            OP = pop(Pilha);
            if(OP->c == 'T')
                Tl(Pilha, &pai_a->dir);
            else if(OP->c == 'H')
                Hd(Pilha, &pai_a->dir);
            else
                printf("\n--ERRO!!--\n");
        }

        (*raiz) = pai_a->dir->dir;
        DecodificaOperacao(*raiz, P);
    }
    else
    {
        Fim=1;
    }
}

void Hd(pilha *P, No **raiz)
{
    No *pai_a = (No*) malloc(sizeof(No));
    No *pai_resto = (No*) malloc(sizeof(No));
    pilha Pilha[10000];
    if(tamPilha > 1)
    {
        pai_a = pop(P);
        pai_resto = pop(P);
        if(pai_a->dir->c == '@')
        {
            DecodificaOperacao(pai_a->dir, Pilha);
            OP = pop(Pilha);
            if(OP->c == 'T')
                Tl(Pilha, &pai_a->dir);
            else if(OP->c == 'H')
                Hd(Pilha, &pai_a->dir);
            else
                printf("\n--ERRO!!--\n");
        }
        pai_resto->esq = pai_a->dir->esq;

        DecodificaOperacao(pai_resto, P);
    }
    else if(tamPilha == 1)
    {
        pai_a = pop(P);

        if(pai_a->dir->c == '@')
        {
            DecodificaOperacao(pai_a->dir, Pilha);
            OP = pop(Pilha);
            if(OP->c == 'T')
                Tl(Pilha, &pai_a->dir);
            else if(OP->c == 'H')
                Hd(Pilha, &pai_a->dir);
            else
                printf("\n--ERRO!!--\n");
        }
        (*raiz) = pai_a->dir->esq;

        DecodificaOperacao(*raiz, P);
    }
    else
    {
        Fim=1;
    }
}

#endif // SEM_MACRO

/**copia tudo o grafo para o outro heap**/
No* copia(No *Raiz)
{
    if(Raiz == NULL)
        return Raiz;
    else if(Raiz->FW == NULL) //se o no ainda está no heap antigo
    {
        indice++;
        Raiz->FW = &grafo[indice-1]; //atualiza o Forwarded
        Raiz->FW->c = Raiz->c;
        if(Raiz->c != '$')
        {
            Raiz->FW->esq = copia(Raiz->esq); //para cada filho chama-se uma copia
            Raiz->FW->dir = copia(Raiz->dir);
        }
        else
            Raiz->FW->esq = copia(Raiz->esq);
        Raiz->FW->FW = NULL;
        return Raiz->FW;
    }
    else //caso o nó ja tenha sido copiado para o novo heap
    {
        return Raiz->FW;
    }
}

void Fenichel_Yochelson(No **Raiz, pilha *p)
{
    garbage++;
    if(indice > (TAM_HEAP/2)) //do heap2 para o heap1
    {
        indice = 0;
        *Raiz = copia(*Raiz);
    }
    else ////do heap1 para o heap2
    {
        indice = TAM_HEAP/2;
        *Raiz = copia(*Raiz);
    }
    DecodificaOperacao(*Raiz, p); //preencher a pilha novamente
}

/**verifica a necessidade de GC**/
int Verifica(int qtd, pilha *p, No **Raiz)
{
    int ref = 1;
    if(indice < (TAM_HEAP/2)) //caso o grafo esteja no heap 1
    {
        if(indice + qtd >= (TAM_HEAP/2)) //se nao houver espaço pra os novos nós
        {
            limpaPilha(p);
            Fenichel_Yochelson(Raiz, p);
            ref = 0; //avisa q precisou de GC
        }
    }
    else //caso o grafo esteja do heap 2
    {
        if(indice + qtd > TAM_HEAP) //se nao houver espaço pra os novos nós
        {
            limpaPilha(p);
            Fenichel_Yochelson(Raiz, p);
            ref = 0;
        }
    }
    return ref;
}


int main()
{
    int i;
    char strEntrada[200000];
    No *Raiz;
    pilha Pilha[10000];
    OP = (No*) malloc(sizeof(No));
    FILE *arq = fopen("string.in", "r");
    fscanf(arq,"%s",strEntrada);

    criaNo('@', &Raiz);
    Raiz = criaGrafo(strEntrada, Raiz);
    DecodificaOperacao(Raiz, Pilha);

    //for(i = 0; i<1; i++)
    while(Fim == 0 && Raiz->c != ':' && Raiz->c != '$')
    {
        OP = pop(Pilha);
        switch (OP->c)
        {
        case 'S':
            if(Verifica(3,Pilha, &Raiz))
            {
                S(Pilha, &Raiz);
                #ifdef CONT_FLAG
                    cont_S++;
                #endif
            }
            break;
        case 'K':
            K(Pilha, &Raiz);
            #ifdef CONT_FLAG
                cont_K++;
            #endif
            break;
        case 'B':
            if(Verifica(3,Pilha, &Raiz))
            {
                B(Pilha, &Raiz);
                #ifdef CONT_FLAG
                    cont_B++;
                #endif
            }
            break;
        case 'b':
            if(Verifica(3,Pilha, &Raiz))
            {
                BL(Pilha, &Raiz);
                #ifdef CONT_FLAG
                    cont_BL++;
                #endif
            }
            break;
        case 'P':
            if(Verifica(3,Pilha, &Raiz))
            {
                CL(Pilha, &Raiz);
                #ifdef CONT_FLAG
                    cont_CL++;
                #endif
            }
            break;
        case 'I':
            I(Pilha, &Raiz);
            #ifdef CONT_FLAG
                cont_I++;
            #endif
            break;
        case 'W':
            if(Verifica(3,Pilha, &Raiz))
            {
                SL(Pilha, &Raiz);
                #ifdef CONT_FLAG
                    cont_SL++;
                #endif
            }
            break;
        case 'C':
            if(Verifica(3,Pilha, &Raiz))
            {
                C(Pilha, &Raiz);
                #ifdef CONT_FLAG
                    cont_C++;
                #endif
            }
            break;
        case 'H': //Hd
            Hd(Pilha, &Raiz);
            break;
        case 'T': //Tl
            Tl(Pilha, &Raiz);
            break;
        case '*':
            MULT(Pilha, &Raiz);
            break;
        case '/':
            DIV(Pilha, &Raiz);
            break;
        case '-':
            SUB(Pilha, &Raiz);
            break;
        case '+':
            ADD(Pilha, &Raiz);
            break;
        case '^':
            POT(Pilha, &Raiz);
            break;
        default:
            Fim = 1;
            break;
        }
    }
    printf("Saida: ");
    printaGrafo(Raiz);
    printf("\n");
    printf("\nChamadas ao GC:%d\n", garbage);

#ifdef CONT_FLAG
    printf("S: %d\n",cont_S);
    printf("K: %d\n",cont_K);
    printf("I: %d\n",cont_I);
    printf("C: %d\n",cont_C);
    printf("B: %d\n",cont_B);
    printf("S': %d\n",cont_SL);
    printf("C': %d\n",cont_CL);
    printf("B': %d\n",cont_BL);
#endif

    return 0;
}

// S' = W // C' = P // B' = H
