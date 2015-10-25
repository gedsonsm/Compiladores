#include <stdio.h>
#include <stdlib.h>
#include "OperacoesComGrafo.h"
#include "OperacoesComPilha.h"
//#define SEM_MACRO
#define COM_MACRO


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

#define W(P, raiz)                                          \
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

#define P(P, raiz)                                          \
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

#define H(P, raiz)                                          \
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

int Fim,i;
No *OP;
No *pai_a;
No *pai_b;
No *pai_c;
No *pai_d;
No *pai_resto;

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

void W(pilha *P, No **raiz)
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

void P(pilha *P, No **raiz)
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

void H(pilha *P, No **raiz)
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

#endif // SEM_MACRO

int main()
{
    char strEntrada[200000];
    No *Raiz;
    pilha Pilha[200000];
    OP = (No*) malloc(sizeof(No));
    FILE *arq = fopen("string.in", "r");
    fscanf(arq,"%s",strEntrada);

    criaNo('@', &Raiz);
    Raiz = criaGrafo(strEntrada, Raiz);
    DecodificaOperacao(Raiz, Pilha);

    while(Fim == 0)
    {
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
    printf("\n");

    return 0;
}
// S' = W // C' = P // B' = H
