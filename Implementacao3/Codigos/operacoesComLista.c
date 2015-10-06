#include "operacoesComLista.h"

int indice; 
int liberado;

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

void removeParenteses(struct Lista *pLista)
{
    struct No *aux;
    struct Lista *l;
    aux = (struct No*) malloc (sizeof (struct No));
    l = (struct Lista*) malloc (sizeof (struct Lista));

    aux = pLista -> primeiro -> prox;
    l = pLista -> primeiro -> lLista;
    
    pLista -> primeiro = l->primeiro;
    l -> ultimo -> prox = aux;  
}

void LiberaNo (struct No **Temp)
{

    struct No *Del;
    while((*Temp)!=NULL)
    {
        if((*Temp)->c == '(')
        {
            LiberaNo (&(*Temp)->lLista->primeiro);
            free((*Temp)->lLista);
            (*Temp)->lLista = NULL;
            //liberado++;
        }
        Del = (*Temp);
        (*Temp)=(*Temp)->prox;
        //printf("%c",Del->c);
        free(Del);
        Del = NULL;
        //liberado++;
    }

}

void checaNulidade (struct Lista *pLista, struct No *check)
{
    if(check==NULL)
    {
        printaLista(pLista);
        exit(1);
    }

}
