#include "operacoesComLista.h"

int indice; 

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
             printf(")");
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

int clonaNo(struct No *novo,struct Lista *clone)
{

    for(;novo  != NULL; novo = novo->prox)
    {
        switch(novo -> c)
        {
            case '(':

                inseriNo(clone, '(');
                indice++;
                clone -> ultimo -> lLista = (struct Lista*) malloc (sizeof (struct Lista));
                iniciaLista(clone -> ultimo -> lLista);
                clonaNo(novo->lLista->primeiro,clone -> ultimo -> lLista);
            break;
            case ')':
                return 0;
            break;

            default:
                inseriNo(clone, novo -> c);
        }
    }
    return 0;
}

struct Lista removeParenteses (struct Lista *Pnovo,struct No *Anterior,struct No *LAnterior)
{
    struct No *novo = Pnovo->primeiro;
    if(novo -> c == '(')
    {
        if(novo->prox==NULL)
            *Pnovo = removeParenteses (novo->lLista,Anterior,Pnovo->ultimo);
        else
            *Pnovo = removeParenteses (novo->lLista,novo->prox,Pnovo->ultimo);
<<<<<<< HEAD
            free(novo);
=======
        free(&novo);
>>>>>>> origin/master
    }
    Pnovo-> ultimo -> prox = Anterior;
    if(Anterior!=NULL)
        Anterior->ante = Pnovo-> ultimo;
    Pnovo-> ultimo = LAnterior;
    return *Pnovo;
}
