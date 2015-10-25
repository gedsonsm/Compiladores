#include <stdio.h>
#include <stdlib.h>
//#define SEM_MACRO
#define COM_MACRO

/** Macros **/
#define criaNo(carac, novo)({                                           \
{                                                                       \
    novo = &grafo[indice];                                              \
    grafo[indice].c = carac;                                            \
    grafo[indice].dir = NULL;                                           \
    grafo[indice].esq = NULL;                                           \
    indice++;                                                           \
}                                                                       \
})

#ifdef COM_MACRO

#define S(profundidade,Raiz)({                                          \
{                                                                       \
    No *Aux1 ;                                                          \
    No *Aux2 ;                                                          \
    No *Aux3 ;                                                          \
    criaNo('@', Aux1);                                                  \
    criaNo('@', Aux2);                                                  \
    criaNo('@', Aux3);                                                  \
    if(profundidade>3)                                                  \
    {                                                                   \
        Aux2->esq = Busca[profundidade-1]->dir;                         \
        Aux2->dir = Busca[profundidade-3]->dir;                         \
        Aux3->esq = Busca[profundidade-2]->dir;                         \
        Aux3->dir = Busca[profundidade-3]->dir;                         \
        Aux1->esq = Aux2;                                               \
        Aux1->dir = Aux3;                                               \
        Busca[profundidade-4]->esq = Aux1;                              \
    }                                                                   \
    else if(profundidade==3)                                            \
    {                                                                   \
        Aux2->esq = Busca[profundidade-1]->dir;                         \
        Aux2->dir = Busca[profundidade-3]->dir;                         \
        Aux3->esq = Busca[profundidade-2]->dir;                         \
        Aux3->dir = Busca[profundidade-3]->dir;                         \
        Aux1->esq = Aux2;                                               \
        Aux1->dir = Aux3;                                               \
        *Raiz = Aux1;                                                   \
    }                                                                   \
    else                                                                \
    {                                                                   \
        Fim=1;                                                          \
    }                                                                   \
}                                                                       \
})


#define K(profundidade,Raiz)({                                          \
{                                                                       \
    if(profundidade>2)                                                  \
    {                                                                   \
        Busca[profundidade-3]->esq = Busca[profundidade-1]->dir;        \
    }                                                                   \
    else if(profundidade==2)                                            \
    {                                                                   \
        (*Raiz)->dir = NULL;                                            \
        (*Raiz)->esq = Busca[profundidade-1]->dir;                      \
    }                                                                   \
    else                                                                \
    {                                                                   \
        Fim=1;                                                          \
    }                                                                   \
}                                                                       \
})                                                                      \

#define B(profundidade,Raiz)({                                          \
{                                                                       \
    No *Aux1 ;                                                          \
    No *Aux2 ;                                                          \
    criaNo('@', Aux1);                                                  \
    criaNo('@', Aux2);                                                  \
    if(profundidade>3)                                                  \
    {                                                                   \
        Aux2->esq = Busca[profundidade-2]->dir;                         \
        Aux2->dir = Busca[profundidade-3]->dir;                         \
        Aux1->esq = Busca[profundidade-1]->dir;                         \
        Aux1->dir = Aux2;                                               \
        Busca[profundidade-4]->esq = Aux1;                              \
    }                                                                   \
    else if(profundidade==3)                                            \
    {                                                                   \
        Aux2->esq = Busca[profundidade-2]->dir;                         \
        Aux2->dir = Busca[profundidade-3]->dir;                         \
        Aux1->esq = Busca[profundidade-1]->dir;                         \
        Aux1->dir = Aux2;                                               \
        *Raiz = Aux1;                                                   \
    }                                                                   \
    else                                                                \
    {                                                                   \
        Fim=1;                                                          \
    }                                                                   \
}                                                                       \
})

#define C(profundidade,Raiz)({                                          \
{                                                                       \
    No *Aux1 ;                                                          \
    No *Aux2 ;                                                          \
    criaNo('@', Aux1);                                                  \
    criaNo('@', Aux2);                                                  \
    if(profundidade>3)                                                  \
    {                                                                   \
        Aux2->esq = Busca[profundidade-1]->dir;                         \
        Aux2->dir = Busca[profundidade-3]->dir;                         \
        Aux1->dir = Busca[profundidade-2]->dir;                         \
        Aux1->esq = Aux2;                                               \
        Busca[profundidade-4]->esq = Aux1;                              \
    }                                                                   \
    else if(profundidade==3)                                            \
    {                                                                   \
        Aux2->esq = Busca[profundidade-1]->dir;                         \
        Aux2->dir = Busca[profundidade-3]->dir;                         \
        Aux1->dir = Busca[profundidade-2]->dir;                         \
        Aux1->esq = Aux2;                                               \
        *Raiz = Aux1;                                                   \
    }                                                                   \
    else                                                                \
    {                                                                   \
        Fim=1;                                                          \
    }                                                                   \
}                                                                       \
})

#define W(profundidade,Raiz)({                                          \
{                                                                       \
    No *Aux1 ;                                                          \
    No *Aux2 ;                                                          \
    No *Aux3 ;                                                          \
    No *Aux4 ;                                                          \
    criaNo('@', Aux1);                                                  \
    criaNo('@', Aux2);                                                  \
    criaNo('@', Aux3);                                                  \
    criaNo('@', Aux4);                                                  \
    if(profundidade>4)                                                  \
    {                                                                   \
        Aux4->esq = Busca[profundidade-2]->dir;                         \
        Aux4->dir = Busca[profundidade-4]->dir;                         \
        Aux3->esq = Busca[profundidade-3]->dir;                         \
        Aux3->dir = Busca[profundidade-4]->dir;                         \
        Aux2->esq = Busca[profundidade-1]->dir;                         \
        Aux2->dir = Aux4;                                               \
        Aux1->esq = Aux2;                                               \
        Aux1->dir = Aux3;                                               \
        Busca[profundidade-5]->esq = Aux1;                              \
    }                                                                   \
    else if(profundidade==4)                                            \
    {                                                                   \
        Aux4->esq = Busca[profundidade-2]->dir;                         \
        Aux4->dir = Busca[profundidade-4]->dir;                         \
        Aux3->esq = Busca[profundidade-3]->dir;                         \
        Aux3->dir = Busca[profundidade-4]->dir;                         \
        Aux2->esq = Busca[profundidade-1]->dir;                         \
        Aux2->dir = Aux4;                                               \
        Aux1->esq = Aux2;                                               \
        Aux1->dir = Aux3;                                               \
        *Raiz = Aux1;                                                   \
    }                                                                   \
    else                                                                \
    {                                                                   \
        Fim=1;                                                          \
    }                                                                   \
}                                                                       \
})

#define H(profundidade,Raiz)({                                          \
{                                                                       \
    No *Aux1 ;                                                          \
    No *Aux2 ;                                                          \
    No *Aux3 ;                                                          \
    criaNo('@', Aux1);                                                  \
    criaNo('@', Aux2);                                                  \
    criaNo('@', Aux3);                                                  \
    if(profundidade>4)                                                  \
    {                                                                   \
        Aux3->esq = Busca[profundidade-3]->dir;                         \
        Aux3->dir = Busca[profundidade-4]->dir;                         \
        Aux2->esq = Busca[profundidade-1]->dir;                         \
        Aux2->dir = Busca[profundidade-2]->dir;                         \
        Aux1->esq = Aux2;                                               \
        Aux1->dir = Aux3;                                               \
        Busca[profundidade-5]->esq = Aux1;                              \
    }                                                                   \
    else if(profundidade==4)                                            \
    {                                                                   \
        Aux3->esq = Busca[profundidade-3]->dir;                         \
        Aux3->dir = Busca[profundidade-4]->dir;                         \
        Aux2->esq = Busca[profundidade-1]->dir;                         \
        Aux2->dir = Busca[profundidade-2]->dir;                         \
        Aux1->esq = Aux2;                                               \
        Aux1->dir = Aux3;                                               \
        *Raiz = Aux1;                                                   \
    }                                                                   \
    else                                                                \
    {                                                                   \
        Fim=1;                                                          \
    }                                                                   \
}                                                                       \
})

#define P(profundidade,Raiz)({                                          \
{                                                                       \
    No *Aux1 ;                                                          \
    No *Aux2 ;                                                          \
    No *Aux3 ;                                                          \
    criaNo('@', Aux1);                                                  \
    criaNo('@', Aux2);                                                  \
    criaNo('@', Aux3);                                                  \
    if(profundidade>4)                                                  \
    {                                                                   \
        Aux3->esq = Busca[profundidade-2]->dir;                         \
        Aux3->dir = Busca[profundidade-4]->dir;                         \
        Aux2->esq = Busca[profundidade-1]->dir;                         \
        Aux2->dir = Aux3;                                               \
        Aux1->esq = Aux2;                                               \
        Aux1->dir = Busca[profundidade-3]->dir;                         \
        Busca[profundidade-5]->esq = Aux1;                              \
    }                                                                   \
    else if(profundidade==4)                                            \
    {                                                                   \
        Aux3->esq = Busca[profundidade-2]->dir;                         \
        Aux3->dir = Busca[profundidade-4]->dir;                         \
        Aux2->esq = Busca[profundidade-1]->dir;                         \
        Aux2->dir = Aux3;                                               \
        Aux1->esq = Aux2;                                               \
        Aux1->dir = Busca[profundidade-3]->dir;                         \
        *Raiz = Aux1;                                                   \
    }                                                                   \
    else                                                                \
    {                                                                   \
        Fim=1;                                                          \
    }                                                                   \
}                                                                       \
})

#define I(profundidade,Raiz)({                                          \
{                                                                       \
    if(profundidade>1)                                                  \
    {                                                                   \
        Busca[profundidade-2]->esq = Busca[profundidade-1]->dir;        \
    }                                                                   \
    else if(profundidade==1)                                            \
    {                                                                   \
        (*Raiz)->esq = (*Raiz)->dir;                                    \
        (*Raiz)->dir = NULL;                                            \
    }                                                                   \
    else                                                                \
    {                                                                   \
        Fim=1;                                                          \
    }                                                                   \
}                                                                       \
})
#endif // COM_MACRO


typedef struct No
{
    char c;
    char mem;
    struct No *esq;
    struct No *dir;
} No;

int indice, i,Fim;

No grafo[70000000];
No *Busca[20000000];
No *Aux;

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
                criaNo('@', noNovo);
                raiz->dir = criaGrafo(str, noNovo);
            }
            else
            {
                criaNo('@', noNovo);
                aux = raiz;
                raiz = noNovo;
                raiz->esq = aux;
                criaNo('@', noNovo);
                raiz->dir = criaGrafo(str, noNovo);
            }
            break;

        case ')':
            return raiz;
            break;

        default:
            criaNo(str[i], noNovo);
            if(raiz->esq == NULL)
                raiz->esq = noNovo;

            else if(raiz->dir == NULL)
                raiz->dir = noNovo;

            else
            {
                criaNo('@', noNovo2);
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
    if(raiz->dir!=NULL)
    {
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

void DecodificaOperacao(No *Raiz, int *profundidade)
{
    *profundidade = 0;
    No *Aux1;
    Aux1 = Raiz;

    while(Aux1->esq!=NULL)
    {
        Busca[*profundidade] = Aux1;
        Aux1 = Aux1->esq;
        *profundidade = *profundidade +1;
    }
    Busca[*profundidade] = Aux1;
}

#ifdef SEM_MACRO

void S (int profundidade,No **Raiz)
{
    No *Aux1 ;
    No *Aux2 ;
    No *Aux3 ;
    criaNo('@', Aux1);
    criaNo('@', Aux2);
    criaNo('@', Aux3);
    if(profundidade>3)
    {
        Aux2->esq = Busca[profundidade-1]->dir;
        Aux2->dir = Busca[profundidade-3]->dir;
        Aux3->esq = Busca[profundidade-2]->dir;
        Aux3->dir = Busca[profundidade-3]->dir;
        Aux1->esq = Aux2;
        Aux1->dir = Aux3;
        Busca[profundidade-4]->esq = Aux1;
    }
    else if(profundidade==3)
    {
        Aux2->esq = Busca[profundidade-1]->dir;
        Aux2->dir = Busca[profundidade-3]->dir;
        Aux3->esq = Busca[profundidade-2]->dir;
        Aux3->dir = Busca[profundidade-3]->dir;
        Aux1->esq = Aux2;
        Aux1->dir = Aux3;
        *Raiz = Aux1;
    }
    else
    {
        Fim=1;
    }
}

void K (int profundidade,No **Raiz)
{

    if(profundidade>2)
    {
        Busca[profundidade-3]->esq = Busca[profundidade-1]->dir;
    }
    else if(profundidade==2)
    {
        (*Raiz)->dir = NULL;
        (*Raiz)->esq = Busca[profundidade-1]->dir;
    }
    else
    {
        Fim=1;
    }

}

void B (int profundidade,No **Raiz)
{
    No *Aux1 ;
    No *Aux2 ;
    criaNo('@', Aux1);
    criaNo('@', Aux2);
    if(profundidade>3)
    {
        Aux2->esq = Busca[profundidade-2]->dir;
        Aux2->dir = Busca[profundidade-3]->dir;
        Aux1->esq = Busca[profundidade-1]->dir;
        Aux1->dir = Aux2;
        Busca[profundidade-4]->esq = Aux1;
    }
    else if(profundidade==3)
    {
        Aux2->esq = Busca[profundidade-2]->dir;
        Aux2->dir = Busca[profundidade-3]->dir;
        Aux1->esq = Busca[profundidade-1]->dir;
        Aux1->dir = Aux2;
        *Raiz = Aux1;
    }
    else
    {
        Fim=1;
    }
}

void C (int profundidade,No **Raiz)
{
    No *Aux1 ;
    No *Aux2 ;
    criaNo('@', Aux1);
    criaNo('@', Aux2);
    if(profundidade>3)
    {
        Aux2->esq = Busca[profundidade-1]->dir;
        Aux2->dir = Busca[profundidade-3]->dir;
        Aux1->dir = Busca[profundidade-2]->dir;
        Aux1->esq = Aux2;
        Busca[profundidade-4]->esq = Aux1;
    }
    else if(profundidade==3)
    {
        Aux2->esq = Busca[profundidade-1]->dir;
        Aux2->dir = Busca[profundidade-3]->dir;
        Aux1->dir = Busca[profundidade-2]->dir;
        Aux1->esq = Aux2;
        *Raiz = Aux1;
    }
    else
    {
        Fim=1;
    }
}

void W (int profundidade,No **Raiz)
{
    No *Aux1 ;
    No *Aux2 ;
    No *Aux3 ;
    No *Aux4 ;
    criaNo('@', Aux1);
    criaNo('@', Aux2);
    criaNo('@', Aux3);
    criaNo('@', Aux4);
    if(profundidade>4)
    {
        Aux4->esq = Busca[profundidade-2]->dir;
        Aux4->dir = Busca[profundidade-4]->dir;
        Aux3->esq = Busca[profundidade-3]->dir;
        Aux3->dir = Busca[profundidade-4]->dir;
        Aux2->esq = Busca[profundidade-1]->dir;
        Aux2->dir = Aux4;
        Aux1->esq = Aux2;
        Aux1->dir = Aux3;
        Busca[profundidade-5]->esq = Aux1;
    }
    else if(profundidade==4)
    {
        Aux4->esq = Busca[profundidade-2]->dir;
        Aux4->dir = Busca[profundidade-4]->dir;
        Aux3->esq = Busca[profundidade-3]->dir;
        Aux3->dir = Busca[profundidade-4]->dir;
        Aux2->esq = Busca[profundidade-1]->dir;
        Aux2->dir = Aux4;
        Aux1->esq = Aux2;
        Aux1->dir = Aux3;
        *Raiz = Aux1;
    }
    else
    {
        Fim=1;
    }
}

void H (int profundidade,No **Raiz)
{
    No *Aux1 ;
    No *Aux2 ;
    No *Aux3 ;
    criaNo('@', Aux1);
    criaNo('@', Aux2);
    criaNo('@', Aux3);
    if(profundidade>4)
    {
        Aux3->esq = Busca[profundidade-3]->dir;
        Aux3->dir = Busca[profundidade-4]->dir;
        Aux2->esq = Busca[profundidade-1]->dir;
        Aux2->dir = Busca[profundidade-2]->dir;
        Aux1->esq = Aux2;
        Aux1->dir = Aux3;
        Busca[profundidade-5]->esq = Aux1;
    }
    else if(profundidade==4)
    {
        Aux3->esq = Busca[profundidade-3]->dir;
        Aux3->dir = Busca[profundidade-4]->dir;
        Aux2->esq = Busca[profundidade-1]->dir;
        Aux2->dir = Busca[profundidade-2]->dir;
        Aux1->esq = Aux2;
        Aux1->dir = Aux3;
        *Raiz = Aux1;
    }
    else
    {
        Fim=1;
    }
}

void P (int profundidade,No **Raiz)
{
    No *Aux1 ;
    No *Aux2 ;
    No *Aux3 ;
    criaNo('@', Aux1);
    criaNo('@', Aux2);
    criaNo('@', Aux3);
    if(profundidade>4)
    {
        Aux3->esq = Busca[profundidade-2]->dir;
        Aux3->dir = Busca[profundidade-4]->dir;
        Aux2->esq = Busca[profundidade-1]->dir;
        Aux2->dir = Aux3;
        Aux1->esq = Aux2;
        Aux1->dir = Busca[profundidade-3]->dir;
        Busca[profundidade-5]->esq = Aux1;
    }
    else if(profundidade==4)
    {
        Aux3->esq = Busca[profundidade-2]->dir;
        Aux3->dir = Busca[profundidade-4]->dir;
        Aux2->esq = Busca[profundidade-1]->dir;
        Aux2->dir = Aux3;
        Aux1->esq = Aux2;
        Aux1->dir = Busca[profundidade-3]->dir;
        *Raiz = Aux1;
    }
    else
    {
        printf("Numero De Parametros Insuficientes\n");
        Fim=1;
    }
}

void I (int profundidade,No **Raiz)
{
    if(profundidade>1)
    {
        Busca[profundidade-2]->esq = Busca[profundidade-1]->dir;
    }
    else if(profundidade==1)
    {
        (*Raiz)->esq = (*Raiz)->dir;
        (*Raiz)->dir = NULL;
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
    int profundidade = 0;
    FILE *arq = fopen("string.in", "r");
    fscanf(arq,"%s",strEntrada);
    criaNo('@', Raiz);
    Raiz = criaGrafo(strEntrada, Raiz);

    while(1)
    {
        DecodificaOperacao(Raiz, &profundidade);
        switch (Busca[profundidade-1]->esq->c)
        {
        case 'S':
            S(profundidade,&Raiz);
        break;
        case 'K':
            K(profundidade,&Raiz);
        break;
        case 'B':
            B(profundidade,&Raiz);
        break;
        case 'H':
            H(profundidade,&Raiz);
        break;
        case 'P':
            P(profundidade,&Raiz);
        break;
        case 'I':
            I(profundidade,&Raiz);
        break;
        case 'W':
            W(profundidade,&Raiz);
        break;
        case 'C':
            C(profundidade,&Raiz);
        break;
        }
        if(Fim)
            break;
    }
    printf("Saida: ");
    printaGrafo(Raiz);
    printf("\n");
    return 0;
}
// S' = W // C' = P // B' = H
