#include <stdio.h>
#include <stdlib.h>
#define SEM_MACRO
//#define COM_MACRO

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

#define S(profundidade)({                                                          \
    {                                                                   \
        if(profundidade > 2)                                            \
        {                                                               \
        Busca[profundidade-2]->esq = (Busca[profundidade-1]->dir);      \
        Aux = Busca[profundidade-2]->dir;                               \
        Busca[profundidade-2]->dir = Busca[profundidade-3]->dir;        \
        Busca[profundidade-3]->dir = Busca[profundidade-1];             \
        Busca[profundidade-3]->dir->dir = Busca[profundidade-2]->dir;   \
        Busca[profundidade-3]->dir->esq = Aux ;                         \
    }                                                                   \
}                                                                       \
})

#define K(profundidade)({                                                          \
{                                                                       \
    if(profundidade > 2)                                                \
    {                                                                   \
        Busca[profundidade-1]->esq = NULL;                              \
        Busca[profundidade-3]->esq = Busca[profundidade-1]->dir;        \
        Aux = Busca[profundidade-2];                                    \
        Aux->esq->dir = NULL;                                           \
        Aux->dir = NULL;                                                \
        Aux->esq = NULL;                                                \
    }                                                                   \
    else if(profundidade == 2)                                          \
    {                                                                   \
        Aux = Busca[profundidade-2]->esq;                               \
        Busca[profundidade-2]->dir = NULL;                              \
        Busca[profundidade-2]->esq = NULL;                              \
        if(Busca[profundidade-1]->dir->c == '@')                        \
        {                                                               \
            Busca[profundidade-2] = Busca[profundidade-1]->dir;         \
        }                                                               \
        else                                                            \
        {                                                               \
            Busca[profundidade-2]->esq = Busca[profundidade-1]->dir;    \
        }                                                               \
        Aux->dir = NULL;                                                \
        Aux->esq = NULL;                                                \
    }                                                                   \
    else                                                                \
    {                                                                   \
        printf("\nParametros Insuficientes (FIM)\n");                   \
        Fim=1;                                                          \
    }                                                                   \
}                                                                       \
})

#define B(profundidade)({                                               \
{                                                                       \
    if(profundidade>2)                                                  \
    {                                                                   \
        No *Aux = (No*) malloc (sizeof(No));                            \
        Busca[profundidade-3]->esq = Busca[profundidade-1]->dir;        \
        Aux = Busca[profundidade-3]->dir;                               \
        Busca[profundidade-3]->dir = Busca[profundidade-1];             \
        Busca[profundidade-3]->dir->dir = Aux;                          \
        Busca[profundidade-3]->dir->esq = Busca[profundidade-2]->dir;   \
        Busca[profundidade-2]->dir = NULL;                              \
        Busca[profundidade-2]->esq = NULL;                              \
    }                                                                   \
    else                                                                \
    {                                                                   \
        printf("\nParametros Insuficientes (FIM)\n");                   \
        Fim=1;                                                          \
    }                                                                   \
}                                                                       \
})

#define H(profundidade)({                                                    \
{                                                                            \
    if(profundidade>3)                                                       \
    {                                                                        \
        No *Aux = (No*) malloc (sizeof(No));                                 \
        Busca[profundidade-4]->esq = Busca[profundidade-2];                  \
        Busca[profundidade-4]->esq->esq = Busca[profundidade-1]->dir;        \
        Aux = Busca[profundidade-4]->dir;                                    \
        Busca[profundidade-4]->dir = Busca[profundidade-3];                  \
        Busca[profundidade-4]->dir->esq = Busca[profundidade-4]->dir->dir;   \
        Busca[profundidade-4]->dir->dir = Aux;                               \
        Busca[profundidade-1]->esq = NULL;                                   \
        Busca[profundidade-1]->dir = NULL;                                   \
    }                                                                        \
    else                                                                     \
    {                                                                        \
        printf("\nParametros Insuficientes (FIM)\n");                        \
        Fim=1;                                                               \
    }                                                                        \
}                                                                            \
})

#define P(profundidade)({                                                                    \
{                                                                                            \
    if(profundidade>3)                                                                       \
    {                                                                                        \
        No *Aux = (No*) malloc (sizeof(No));                                                 \
        Aux = Busca[profundidade-4]->dir;                                                    \
        Busca[profundidade-4]->dir = Busca[profundidade-3]->dir;                             \
        Busca[profundidade-4]->esq = Busca[profundidade-1];                                  \
        Busca[profundidade-4]->esq->esq = Busca[profundidade-4]->esq->dir;                   \
        Busca[profundidade-4]->esq->dir = Busca[profundidade-2];                             \
        Busca[profundidade-4]->esq->dir->esq = Busca[profundidade-4]->esq->dir->dir;         \
        Busca[profundidade-4]->esq->dir->dir = Aux;                                          \
        Busca[profundidade-3]->dir = NULL;                                                   \
        Busca[profundidade-3]->esq = NULL;                                                   \
    }                                                                                        \
    else                                                                                     \
    {                                                                                        \
        printf("\nParametros Insuficientes (FIM)\n");                                        \
        Fim=1;                                                                               \
    }                                                                                        \
}                                                                                            \
})

#define I(profundidade)({                                                                    \
{                                                                                            \
    if(profundidade > 1)                                                                     \
    {                                                                                        \
       Busca[profundidade-2]->esq = Busca[profundidade-1]->dir;                              \
       Busca[profundidade-1]->esq = NULL;                                                    \
       Busca[profundidade-1]->dir = NULL;                                                    \
    }                                                                                        \
    else if(profundidade == 1)                                                               \
    {                                                                                        \
        Busca[profundidade-1]->esq = Busca[profundidade-1]->dir;                             \
        Busca[profundidade-1]->dir = NULL;                                                   \
    }                                                                                        \
 	else                                                                                     \
    {                                                                                        \
        printf("\nParametros Insuficientes (FIM)\n");                                        \
        Fim=1;                                                                               \
    }                                                                                        \
}                                                                                            \
})

#define W(profundidade)({                                                                               \
{                                                                                            \
    if(profundidade>3)                                                                       \
    {                                                                                        \
        Busca[profundidade-4]->esq = Busca[profundidade-1];                                  \
        Busca[profundidade-4]->esq->esq = Busca[profundidade-4]->esq->dir;                   \
        Busca[profundidade-4]->esq->dir = Busca[profundidade-2];                             \
        Busca[profundidade-4]->esq->dir->esq = Busca[profundidade-4]->esq->dir->dir;         \
        Busca[profundidade-4]->esq->dir->dir = Busca[profundidade-4]->dir;                   \
        Busca[profundidade-4]->dir = Busca[profundidade-3];                                  \
        Busca[profundidade-4]->dir->esq = Busca[profundidade-4]->dir->dir;                   \
        Busca[profundidade-4]->dir->dir = Busca[profundidade-4]->esq->dir->dir;              \
    }                                                                                        \
    else                                                                                     \
    {                                                                                        \
        printf("\nParametros Insuficientes (FIM)\n");                                        \
        Fim=1;                                                                               \
    }                                                                                        \
                                                                                             \
}                                                                                            \
})

#define C(profundidade)({                                                                    \
{                                                                                            \
    if(profundidade>2)                                                                       \
    {                                                                                        \
        Busca[profundidade-1]->esq = Busca[profundidade-3]->dir;                             \
        Busca[profundidade-3]->dir = Busca[profundidade-2]->dir;                             \
        Busca[profundidade-2]->dir = Busca[profundidade-1]->esq;                             \
        Busca[profundidade-2]->esq = Busca[profundidade-1]->dir;                             \
        Busca[profundidade-1]->esq = NULL;                                                   \
        Busca[profundidade-1]->dir = NULL;                                                   \
    }                                                                                        \
    else                                                                                     \
    {                                                                                        \
        printf("\nParametros Insuficientes (FIM)\n");                                        \
        Fim=1;                                                                               \
    }                                                                                        \
}                                                                                            \
})
#endif // /** Fim das Macros **/




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
        *profundidade+=1;
    }
    Busca[*profundidade] = Aux1;
}



#ifdef SEM_MACRO //Operacoes Sem Macro

void H (int profundidade)
{
    //printf("Para um Valor de Profundidade %d\n",profundidade);
    if(profundidade>3)
    {
        No *Aux = (No*) malloc (sizeof(No));
        Busca[profundidade-4]->esq = Busca[profundidade-2];
        Busca[profundidade-4]->esq->esq = Busca[profundidade-1]->dir;
        Aux = Busca[profundidade-4]->dir;
        Busca[profundidade-4]->dir = Busca[profundidade-3];
        Busca[profundidade-4]->dir->esq = Busca[profundidade-4]->dir->dir;
        Busca[profundidade-4]->dir->dir = Aux;
        Busca[profundidade-1]->esq = NULL;
        Busca[profundidade-1]->dir = NULL;

    }
    else
    {
        printf("\nParametros Insuficientes (FIM)\n");
        Fim=1;
    }
}

void B (int profundidade)
{
    //printf("Para um Valor de Profundidade %d\n",profundidade);
    if(profundidade>2)
    {
        No *Aux = (No*) malloc (sizeof(No));
        Busca[profundidade-3]->esq = Busca[profundidade-1]->dir;
        Aux = Busca[profundidade-3]->dir;
        Busca[profundidade-3]->dir = Busca[profundidade-1];
        Busca[profundidade-3]->dir->dir = Aux;
        Busca[profundidade-3]->dir->esq = Busca[profundidade-2]->dir;
        Busca[profundidade-2]->dir = NULL;
        Busca[profundidade-2]->esq = NULL;
    }
    else
    {
        printf("\nParametros Insuficientes (FIM)\n");
        Fim=1;
    }
}

void S (int profundidade)
{
    //printf("Para um Valor de Profundidade %d\n",profundidade);
    if(profundidade>2)                                                    //Essa variavel guarda o tamanho do meu grafo, calculada na funcao DecodificaOperacao
    {
        No *Aux = (No*) malloc (sizeof(No));                              // Variavel auxiliar para salva um ramo que sera perdido
        Busca[profundidade-2]->esq = (Busca[profundidade-1]->dir);        //O meu Vetor Busca, guarda o caminho mais a esquerda do meu grafo. Minha ultima posicao do vetor eh meu operador, minha posicao -1 eh o ultimo arroba, minha posicao -2 eh meu penultimo arroba. Vou mandar uma print para tu ver isso melhor
        Aux = Busca[profundidade-2]->dir;                                 // O resto, eh so eu apontando ponteiros, na figura da pra entender
        Busca[profundidade-2]->dir = Busca[profundidade-3]->dir;
        Busca[profundidade-3]->dir = Busca[profundidade-1];
        Busca[profundidade-3]->dir->dir = Busca[profundidade-2]->dir;
        Busca[profundidade-3]->dir->esq = Aux ;
        //Busca[profundidade-3]->esq = NULL ;
    }
    else
    {
        printf("\nParametros Insuficientes (FIM)\n");
        Fim=1;
    }
}

void K (int profundidade)
{
    if(profundidade > 2)
    {
        Busca[profundidade-1]->esq = NULL;
        Busca[profundidade-3]->esq = Busca[profundidade-1]->dir;
        Aux = Busca[profundidade-2];
        Aux->esq->dir = NULL;
        Aux->dir = NULL;
        Aux->esq = NULL;
    }
    else if(profundidade == 2)
    {
        Aux = Busca[profundidade-2]->esq;
        Busca[profundidade-2]->dir = NULL;
        Busca[profundidade-2]->esq = NULL;

        if(Busca[profundidade-1]->dir->c == '@')
        {
            Busca[profundidade-2] = Busca[profundidade-1]->dir;
        }
        else
        {
            Busca[profundidade-2]->esq = Busca[profundidade-1]->dir;
        }
        Aux->dir = NULL;
        Aux->esq = NULL;
    }
    else
    {
        printf("\nParametros Insuficientes (FIM)\n");
        Fim=1;
    }
}

void P (int profundidade)
{
    //printf("Para um Valor de Profundidade %d\n",profundidade);
    if(profundidade>3)
    {

        No *Aux = (No*) malloc (sizeof(No));
        Aux = Busca[profundidade-4]->dir;
        Busca[profundidade-4]->dir = Busca[profundidade-3]->dir;
        Busca[profundidade-4]->esq = Busca[profundidade-1];
        Busca[profundidade-4]->esq->esq = Busca[profundidade-4]->esq->dir;
        Busca[profundidade-4]->esq->dir = Busca[profundidade-2];
        Busca[profundidade-4]->esq->dir->esq = Busca[profundidade-4]->esq->dir->dir;
        Busca[profundidade-4]->esq->dir->dir = Aux;
        Busca[profundidade-3]->dir = NULL;
        Busca[profundidade-3]->esq = NULL;
    }
    else
    {
        printf("\nParametros Insuficientes (FIM)\n");
        Fim=1;
    }
}

void I(int profundidade)
{
    if(profundidade > 1)
    {
        Busca[profundidade-2]->esq = Busca[profundidade-1]->dir;
        Busca[profundidade-1]->esq = NULL;
        Busca[profundidade-1]->dir = NULL;
    }
    else if(profundidade == 1)
    {
        Busca[profundidade-1]->esq = Busca[profundidade-1]->dir;
        Busca[profundidade-1]->dir = NULL;
    }
    else
    {
        printf("\nParametros Insuficientes (FIM)\n");
        Fim=1;
    }
}

void W (int profundidade)
{
    //printf("Para um Valor de Profundidade %d\n",profundidade);
    if(profundidade>3)
    {
        Busca[profundidade-4]->esq = Busca[profundidade-1];
        Busca[profundidade-4]->esq->esq = Busca[profundidade-4]->esq->dir;
        Busca[profundidade-4]->esq->dir = Busca[profundidade-2];
        Busca[profundidade-4]->esq->dir->esq = Busca[profundidade-4]->esq->dir->dir;
        Busca[profundidade-4]->esq->dir->dir = Busca[profundidade-4]->dir;
        Busca[profundidade-4]->dir = Busca[profundidade-3];
        Busca[profundidade-4]->dir->esq = Busca[profundidade-4]->dir->dir;
        Busca[profundidade-4]->dir->dir = Busca[profundidade-4]->esq->dir->dir;
    }
    else
    {
        printf("\nParametros Insuficientes (FIM)\n");
        Fim=1;
    }
}

void C (int profundidade)
{
    //printf("Para um Valor de Profundidade %d\n",profundidade);
    if(profundidade>2)
    {
        Busca[profundidade-1]->esq = Busca[profundidade-3]->dir;
        Busca[profundidade-3]->dir = Busca[profundidade-2]->dir;
        Busca[profundidade-2]->dir = Busca[profundidade-1]->esq;
        Busca[profundidade-2]->esq = Busca[profundidade-1]->dir;
        Busca[profundidade-1]->esq = NULL;
        Busca[profundidade-1]->dir = NULL;
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
    FILE *arq = fopen("string.in", "r");
    fscanf(arq,"%s",strEntrada);
    criaNo('@', Raiz);
    Raiz = criaGrafo(strEntrada, Raiz);
    //printaGrafo(Raiz);
    //printf("\n");
    int a=0;
    do
    {
        a++;
        DecodificaOperacao(Raiz, &profundidade);
        switch (Busca[profundidade-1]->esq->c)
        {
        case 'S':
            S(profundidade);
        break;
        case 'K':
            K(profundidade);
        break;
        case 'B':
            B(profundidade);
        break;
        case 'H':
            H(profundidade);
        break;
        case 'P':
            P(profundidade);
        break;
        case 'I':
            I(profundidade);
        break;
        case 'W':
            W(profundidade);
        break;
        case 'C':
            C(profundidade);
        break;
        }
    }
    while(!Fim);
    printf("Saida: ");
    printaGrafo(Raiz);
    printf("\nIteracoes: %d",a);

    return 0;
}
// S' = W // C' = P // B' = H
