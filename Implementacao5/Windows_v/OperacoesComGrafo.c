#include "OperacoesComGrafo.h"

void criaNo(char carac, No **novo)
{
    *novo = &grafo[indice];
    grafo[indice].c = carac;
    grafo[indice].dir = NULL;
    grafo[indice].esq = NULL;
    indice++;
}

int ConvertePraInteiro (char* str)
{
    char Numero[20];
    int b=1;
    while(str[i+b]!='$')
    {

        Numero[b-1] = str[i+b];
        b++;
    }
    Numero[b-1] = '\0';
    i = i + b;
    return atoi(Numero);
}


No* CriaLista(char* str)   // Funca que cria lista no formato [] Raiz precisa vim como NULL
{
    No *Aux;
    No *Aux1;
    i++;                    //Meu vetor esta na posicao '[', quero comecar a pegara a a partir dele (primeiro elemento da lista)
    if(str[i-1]!=']')       //No caso dessa lista, todo elemento é uma sublista [SAS,SSS] = SAS é uma lista no grafo, nao uma lista [], uma lista @
    {
        criaNo('@', &Aux);  // Crio esse arroba pq a funcao criagrafo recebe algo para trabalhar, ou seja, ela precisa de algo para comecar
        Aux = criaGrafo(str, Aux);  // Uso a funcao criagrafo para criar a sublista (elementos)
        if(Aux->dir==NULL)          // Aqui eu checo se é o caso do elemento ter apenas um caracter = [A.B,D]. pq nesse caso, o arroba vai ter apenas um ponteiro a esquerda, o direito sera NULL
        {
            Aux->c = ':';           // Esse arroba sera meu Cons(:)
            Aux->dir = CriaLista(str);  // Continuo com os proximos elementos chamando a recursao
            return Aux;
        }
        else                        //Nesse caso, meu elemento tem mais de 1 caracter, logo, o arroba ja esta com o ponteiro esquerdo e o direito preenchidos.
        {
            criaNo(':', &Aux1);         //Crio uma nova celula cons
            Aux1->esq = Aux;            // Faco a esquerda apontar para a sublista ja criada
            Aux1->dir = CriaLista(str); // Chamo a recursao para a direita
            return Aux1;
        }
    }
    else                                // Fim da lista ']'
    {
        criaNo(']', &Aux);              // lista vazia "[]"
        return Aux;                     //retorno
    }

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

        case ')':                   // Final de lista (), retorno raiz
            return raiz;
            break;
        case ',':                   // Final de elemento pertecente a uma lista [], retorno raiz
            return raiz;
            break;
        case ']':                   // Final de lista [], retorno raiz
            return raiz;
            break;

        case '[':                               //Criar Lista tipo []
            if(raiz->esq == NULL)               // A unica diferenca pra o codigo antigo do default, é que agora eu nao pego uma estrutura com o caracter lido, mas, sim, a funcao CriaLista
                raiz->esq = CriaLista(str);
            else if(raiz->dir == NULL)
                raiz->dir = CriaLista(str);
            else
            {
                criaNo('@', &noNovo2);
                aux = raiz;
                raiz = noNovo2;
                raiz->esq = aux;
                raiz->dir = CriaLista(str); //CriaLista, Funcao que devolve uma lista tipo []
            }
            i--;                            //Minha funcao criaLista, incrementa o i logo no inicio. Por isso tenho que decrementalo aqui pra na volta essa funcao continuar do lugar certo
            break;
        case '$':
            criaNo('$', &noNovo);                           //Significa que é uma celula de um INT
            noNovo->esq = (No*) ConvertePraInteiro (str);   // O ponteiro desse No, é o proprio NUM (escolhi o esquerdo pq quis)
            if(raiz->esq == NULL)                           // O resto é auto explicativo, mas, um Num é uma celula comum so que o Char é $ e os ponteiros nao apontam pra outras celulas, 1 deles é o proprio num e o outro ta NULL
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


int printaGrafoLista(No* raiz)              //Printa Lista tipo [], recebe uma celula com Cons (:)
{
    if(raiz->dir!=NULL)                     // Se a direita é diferente de NULL, ou seja, se existe mais coisa nessa lista [], nem que seja o proprio "[]"(lista vazia)
            printaGrafo(raiz->esq);         //Imprimo meu primeiro elemento
    if(raiz->dir->c != ']')                 //Se cheguei ao fim da lista []. Esse ']' significa "[]"
    {
        printf(",");                        //Printo uma virgula para o proximo elemento
        printaGrafoLista(raiz->dir);
    }
    return 0;
}


int printaGrafo(No* raiz)
{
    if(raiz!=NULL)
    {
        if(raiz->c==':')                    // Caso uma sublista () possua apenas uma lista [] como conteudo (caso especial, nao deem muita atencao)
        {
            printf("[");
            printaGrafoLista(raiz);
            printf("]");
            return 0;
        }

    }
    if(raiz->esq != NULL&&raiz->c!='$')
        printaGrafo(raiz->esq);
    else
    {
        if(raiz->c=='$')                        // Se for $, entao precisamos imprimir o NUM (ponteiro a esquerda)
            printf("%d", (int)raiz->esq);
        else
        {
            printf("%c", raiz->c);
        }

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
        else if(raiz->dir->c == ':')
        {
            printf("[");
            printaGrafoLista(raiz->dir);                //Caso seja tipo []
            printf("]");
        }
        else
        {
            if(raiz->dir->c=='$')
                printf("%d ", (int)raiz->dir->esq);
            else
                printf("%c", raiz->dir->c);
        }
    }
    return 0;
}

