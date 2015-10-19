#include "OperacoesComGrafo.h"

void criaNo(char carac, No **novo)
{
    *novo = &grafo[indice];
    grafo[indice].c = carac;
    grafo[indice].dir = NULL;
    grafo[indice].esq = NULL;
    indice++;
}

No* criaGrafo(char* str, No *raiz)
{
    No *noNovo;
    No *noNovo2;
    No *aux;

    for(; str[i] != '\0'; i++)
    {
        switch(str[i])
        {
            case '(':
                i++;
                if(raiz->esq == NULL)
                    raiz = criaGrafo(str,raiz);
                else if(raiz->dir == NULL)
                {
                    criaNo('@', &noNovo);
                    raiz->dir = criaGrafo(str, noNovo);
                }
                else
                {
                    criaNo('@', &noNovo);
                    aux = raiz;
                    raiz = noNovo;
                    raiz->esq = aux;
                    criaNo('@', &noNovo);
                    raiz->dir = criaGrafo(str, noNovo);
                }
            break;

            case ')':
                return raiz;
            break;

            default:
                criaNo(str[i], &noNovo);
                if(raiz->esq == NULL)
                    raiz->esq = noNovo;

                else if(raiz->dir == NULL)
                    raiz->dir = noNovo;

                else
                {
                    criaNo('@', &noNovo2);
                    aux = raiz;
                    raiz = noNovo2;
                    raiz->esq = aux;
                    raiz->dir = noNovo;
                }
            break;
        }
    }
    return raiz;
}

int printaGrafo(No* raiz)
{
    if(raiz->esq != NULL)
        printaGrafo(raiz->esq);
    else
    {
        printf("%c", raiz->c);
        return 0;
    }
    if(raiz->dir!=NULL){
    if(raiz->dir->c == '@')
    {
        printf("(");
        printaGrafo(raiz->dir);
        printf(")");
    }
    else
        printf("%c", raiz->dir->c);
    }
    return 0;
}

