#include "operacoesComLista.h"

void iniciaLista(struct Lista *pLista)
{
    pLista -> primeiro = NULL;
    pLista -> ultimo = NULL;
}

int printaLista (struct Lista *pLista)
{
	struct No *p;

    for (p = pLista -> primeiro; p != NULL; p = p -> prox) 
    {
        printf("%c", p -> c);
		if(p -> c == '(')
        {          
            printaLista(p -> lLista);
        }
    }
	return 0;
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

int indice;
int criaLista(struct Lista *pLista, char *entrada)
{
    for(;entrada[indice] != '\0'; indice++)
    {
        switch(entrada[indice])
        {
            case '(':
                inseriNo(pLista, '(');
                indice++;

                pLista -> ultimo -> lLista = (struct Lista*) malloc (sizeof (struct Lista));
                iniciaLista(pLista -> ultimo -> lLista);
                criaLista(pLista -> ultimo -> lLista, entrada);
            break;
        
            case ')':
                //inseriNo(pLista, ')');
                return 0;
            break;

            default:
                inseriNo(pLista, entrada[indice]);
        }
    }
    return 0;
}
