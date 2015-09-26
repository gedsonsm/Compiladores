#include "reducoes.h"
#include "operacoesComLista.h"

int S(struct Lista *pLista)
{
	struct No *p = pLista -> primeiro;// recebe o 1o no da lista(o no q ten o carac 'S')
	struct No *a, *b, *c, *resto, *c2;
	
	struct Lista l;//lista aux
	iniciaLista(&l); 

	a = p -> prox; // cata o 'a'
	
	p = p -> prox; // cata o 'b'
	b = p -> prox;
	
	p = p -> prox; // cata o 'c'
	c = p -> prox;

	p = p -> prox; // cata o 'resto'
	resto = p -> prox;

	c2 = clone(c);//clona o 'c' falta implementar
	
	l.primeiro = a;// L -> a
	a -> ante = NULL;

	a -> prox = c; //L-> a -> c
	c -> ante = a;
	l.ultimo = c;
	
	inseriNo(l, '(');//L-> a -> c -> (
	
	l.ultimo -> lLista -> primeiro = b;// L -> a - > c -> (
	b -> ante = NULL;      			   //                 |
									   //				  v
									   //				  b

	b -> prox = c2;					   // L -> a - > c -> (
	c2 -> ante = b;					   //                 |
	l.ultimo -> lLista -> ultimo = c2; //				  v
									   //				  b -> c

	l.ultimo -> prox = resto;// L -> a - > c -> ( -> resto
	resto -> ante = l.ultimo;//                 |
	resto -: prox = NULL;    //				    v
							 //		  		    b -> c 

	l.ultimo = resto; // att o ultimo da lista principal

	pLista = &l; // att a lista 

	return 0;
}


