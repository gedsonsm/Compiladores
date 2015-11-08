#include "OperacoesComPilha.h"

void push(pilha *P, No* conteudo)
{
    P[tamPilha].pont = (No*) malloc(sizeof(No));
    P[tamPilha].pont = conteudo;
    tamPilha+=1;
}

No *pop(pilha *P)
{
    No* ret = (No*) malloc(sizeof(No));
    if(tamPilha > 0)
    {
        ret = P[tamPilha-1].pont;
        tamPilha-=1;
    }
    else
        ret = NULL;
    return ret;
}
No *top(pilha *P)
{
    No* ret = (No*) malloc(sizeof(No));
    if(tamPilha > 0)
    {
        ret = P[tamPilha-1].pont;
    }
    else
        ret = NULL;

    return ret;
}
void limpaPilha(pilha *P)
{
    tamPilha = 0;
}
