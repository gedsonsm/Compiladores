#include "operacoesComLista.h"

void iniciaLista(struct Lista *pLista)
{
    pLista -> primeiro = NULL;
    pLista -> ultimo = NULL;
}

void printaLista (struct Lista *pLista)
{

    struct No *p;
    for (p = pLista -> primeiro; p != NULL; p = p -> prox) 
    {
        printf("%c", p -> c);
    }
    printf("\n");

}


void inseriNo (struct Lista *pLista, char carac)
{
    struct No *novo;
    novo = (struct No*) malloc (sizeof (struct No));
    novo -> c = carac;
    
    if(pLista->primeiro == NULL)
    {
        novo -> prox = NULL;
        novo -> ante = NULL;
        pLista -> primeiro = novo;
        pLista -> ultimo = novo;
    }
    else
    {
        novo -> prox = NULL;
        novo -> ante = pLista -> ultimo;
        pLista -> ultimo -> prox = novo;
        pLista -> ultimo = novo;
    }
}

void criaLista(struct Lista *pLista, char *entrada, int indice) //incompleta
{
    for(;entrada[indice] == '\0'; indice++)
    {       
        switch(entrada[i])
        {
            case '(':
                struct No *novo = (struct No*) malloc (sizeof (struct No));
                struct Lista l;
                iniciaLista(&l);


                novo -> c = '(';
                novo -> ante = pLista -> ultimo
                novo -> prox = NULL;
                pLista -> ultimo = novo;
                
                novo -> lLista = l;
                
                indice++;
                criaLista(l, entrada, indice);
            break;

            case ')'
                
            break;

            default:
                inseriNo(pLista, entrada[indice])
        }
    }

}