#include "reducoes.h"


struct Lista S(struct Lista *pLista, int *parou)
{
	struct No *p = (struct No*) malloc (sizeof (struct No));
	struct No *a, *b, *c, *resto;

	a = (struct No*) malloc (sizeof (struct No));
	b = (struct No*) malloc (sizeof (struct No));
	c = (struct No*) malloc (sizeof (struct No));
	resto = (struct No*) malloc (sizeof (struct No));

	struct Lista l, c2;//lista aux
	iniciaLista(&l);
	iniciaLista(&c2); 

	p = pLista -> primeiro;// recebe o 1o no da lista(o no q tem o carac 'S')

	a = p -> prox; // cata o 'a'
	
	p = p -> prox; // cata o 'b'
	b = p -> prox;
	
	p = p -> prox; // cata o 'c'
	c = p -> prox;

	p = p -> prox; // cata o 'resto'
	if(p -> prox != NULL)
		resto = p -> prox;

	if(a == NULL || b == NULL || c == NULL)
	{
		*parou = 1;
		return *pLista;
	}

	c->prox = NULL;
	clonaNo(c, &c2);//clona o 'c'

	
	l.primeiro = a;// L -> a
	a -> ante = NULL;
	a -> prox = NULL;
	l.ultimo = a;

	a -> prox = c; //L-> a -> c
	c -> ante = a;
	c -> prox = NULL;
	l.ultimo = c;
	
	inseriNo(&l, '(');//L-> a -> c -> (

	l.ultimo -> lLista = (struct Lista*)malloc(sizeof(struct Lista));	// L -> a - > c -> (
	l.ultimo -> lLista -> primeiro = b;								 	//                 |
	l.ultimo -> lLista -> ultimo = b;   	 						 	// 			       v
	b -> ante = NULL;    		    					             	//				   b
	b -> prox = NULL;
								 								    

	b -> prox = c2.primeiro;		   				// L -> a - > c -> (
	l.ultimo -> lLista -> ultimo = c2.primeiro;		//                 |
	c2.primeiro -> ante = b;                    	//				   v
	c2.primeiro -> prox = NULL;	    				//				   b -> c


	l.ultimo -> prox = resto;	// L -> a - > c -> ( -> resto
	resto -> ante = l.ultimo;	//                 |
						    	//				    v
	 						 	//		  		    b -> c 
	
	if(pLista -> ultimo != c)
		l.ultimo = pLista -> ultimo; // att o ultimo da lista principal
	else
		l.ultimo = c;

	*parou = 0;
	return l;
}

struct Lista K(struct Lista *pLista, int *parou)
{
	struct No *p = (struct No*) malloc (sizeof (struct No));
	struct No *a, *b, *c, *resto;

	a = (struct No*) malloc (sizeof (struct No));
	b = (struct No*) malloc (sizeof (struct No));
	resto = (struct No*) malloc (sizeof (struct No));

	struct Lista l;//lista aux
	iniciaLista(&l);

	p = pLista -> primeiro;// recebe o 1o no da lista(o no q ten o carac 'K')

	a = p -> prox; // cata o 'a'
	
	p = p -> prox; // cata o 'b'
	b = p -> prox;

	if(a == NULL || b == NULL || c == NULL)
	{
		*parou = 1;
		return *pLista;
	}

	p = p -> prox; // cata o 'resto'
	if(p -> prox != NULL)
		resto = p -> prox;

	l.primeiro = a;// L -> a
	a -> ante = NULL;
	a -> prox = NULL;
	l.ultimo = a;
	

	l.ultimo -> prox = resto;	// L -> a - > c -> ( -> resto
	resto -> ante = l.ultimo;	//                 |
						    	//				    v
	 						 	//		  		    b -> c 
	
	if(pLista -> ultimo != b)
		l.ultimo = pLista -> ultimo; // att o ultimo da lista principal
	else
		l.ultimo = a;

	*parou = 0;
	return l;
}
