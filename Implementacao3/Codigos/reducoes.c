#include "reducoes.h"


int S(struct Lista **pLista,int *Parou)
{
	struct No *p = (struct No*) malloc (sizeof (struct No));
	struct No *a, *b, *c, *resto;

	a = (struct No*) malloc (sizeof (struct No));
	b = (struct No*) malloc (sizeof (struct No));
	c = (struct No*) malloc (sizeof (struct No));
	resto = (struct No*) malloc (sizeof (struct No));

	struct Lista c2;//lista aux
	iniciaLista(&c2);

	p = (*pLista) -> primeiro;// recebe o 1o no da lista(o no q ten o carac 'S')
	a = p -> prox; // cata o 'a'
    if(a==NULL)
    {
         *Parou=1;
         return 1;
    }
	p = p -> prox; // cata o 'b'
	b = p -> prox;
    if(b==NULL)
    {
         *Parou=1;
         return 1;
    }
	p = p -> prox; // cata o 'c'
	c = p -> prox;
    if(c==NULL)
    {
         *Parou=1;
         return 1;
    }

	p = p -> prox; // cata o 'resto'
    resto = p -> prox;

	c->prox = NULL;
	clonaNo(c, &c2);//clona o 'c'

	(*pLista)-> primeiro = a;// L -> a
	a -> ante = NULL;
	a -> prox = NULL;
	(*pLista)-> ultimo = a;

	a -> prox = c; //L-> a -> c
	c -> ante = a;
	c -> prox = NULL;
	(*pLista)-> ultimo = c;

	inseriNo((*pLista), '(');//L-> a -> c -> (

	(*pLista)-> ultimo -> lLista = (struct Lista*)malloc(sizeof(struct Lista));	// L -> a - > c -> (
	(*pLista)-> ultimo -> lLista -> primeiro = b;								 	//                 |
	(*pLista)-> ultimo -> lLista -> ultimo = b;   	 						 	// 			       v
	b -> ante = NULL;    		    					             	//				   b
	b -> prox = NULL;


	b -> prox = c2.primeiro;		   				// L -> a - > c -> (
	(*pLista)-> ultimo -> lLista -> ultimo = c2.primeiro;		//                 |
	c2.primeiro -> ante = b;                    	//				   v
	c2.primeiro -> prox = NULL;	    				//				   b -> c


    (*pLista)-> ultimo -> prox = resto;	        // L -> a - > c -> ( -> resto
    if(resto!=NULL)
    {
        resto -> ante = (*pLista)-> ultimo;
        (*pLista)-> ultimo = (*pLista) -> ultimo;
    }

    //free((*pLista)-> primeiro);

    //(*pLista) = l;
    return 0;
}

int K(struct Lista **pLista, int *parou)
{
	struct No *p = (struct No*) malloc (sizeof (struct No));
    struct No *a, *b, *c, *resto;

    a = (struct No*) malloc (sizeof (struct No));
    b = (struct No*) malloc (sizeof (struct No));
    c = (struct No*) malloc (sizeof (struct No));
    resto = (struct No*) malloc (sizeof (struct No));

    struct Lista c2;//lista aux
    iniciaLista(&c2);

    p = (*pLista) -> primeiro;// recebe o 1o no da lista(o no q ten o carac 'S')
    a = p -> prox; // cata o 'a'
    if(a==NULL)
    {
         *parou=1;
         return 1;

    }
    p = p -> prox; // cata o 'b'
    b = p -> prox;
    if(b==NULL)
    {
         *parou=1;
         return 1;
    }

	p = p -> prox; // cata o 'resto'
    resto = p -> prox;

	(*pLista)-> primeiro = a;// L -> a
	a -> ante = NULL;
	a -> prox = NULL;
	(*pLista) -> ultimo = a;

	b -> ante = NULL;
	b -> prox = NULL;

	(*pLista)-> ultimo -> prox = resto;
    if(resto!=NULL)
        resto -> ante = (*pLista) -> ultimo;



	if((*pLista) -> ultimo != b)
		(*pLista) -> ultimo = (*pLista) -> ultimo; // att o ultimo da lista principal
	else
		(*pLista) -> ultimo = a;

	*parou = 0;
	//free((*pLista)->primeiro);
	LiberaNo(&b);   // Descomentar se quiser ativar a funcao Liberar

    //(*pLista) = l;
	return 0;
}

int C(struct Lista **pLista, int *parou)
{
    struct No *p = (struct No*) malloc (sizeof (struct No));
    struct No *Dele = (struct No*) malloc (sizeof (struct No));
	struct No *a, *b, *c, *resto;

	a = (struct No*) malloc (sizeof (struct No));
	b = (struct No*) malloc (sizeof (struct No));
	c = (struct No*) malloc (sizeof (struct No));
	resto = (struct No*) malloc (sizeof (struct No));

    struct Lista c2;//lista aux
    iniciaLista(&c2);

    Dele = (*pLista) -> primeiro;
	p = (*pLista) -> primeiro;// recebe o 1o no da lista(o no q ten o carac 'S')
	a = p -> prox; // cata o 'a'
    if(a==NULL)
    {
         *parou=1;
         return 0;
    }
	p = p -> prox; // cata o 'b'
	b = p -> prox;
    if(b==NULL)
    {
         *parou=1;
         return 0;
    }
	p = p -> prox; // cata o 'c'
	c = p -> prox;
    if(c==NULL)
    {
         *parou=1;
         return 0;
    }
	p = p -> prox; // cata o 'resto'
    resto = p -> prox;


    (*pLista)->primeiro = a  ;                     // l -> a
    (*pLista)->ultimo = a;
    a->ante = NULL;
    a->prox = NULL;

    (*pLista)->primeiro->prox = c;                  // l -> a -> c
    c-> ante = (*pLista)->primeiro;
    c-> prox = NULL;
    (*pLista)->ultimo = c;

    (*pLista)->ultimo->prox = b;            // l -> a -> c -> b
    b-> ante = (*pLista)->ultimo;

    b-> prox = resto;               //  l -> a -> c -> b -> resto
    if(resto!=NULL)
    {
        resto->ante = (*pLista)->ultimo;
        (*pLista)->ultimo = (*pLista) -> ultimo;
    }
    else
        (*pLista)->ultimo = b;


    free(Dele);
    Dele = NULL;
    //liberado++;
    //free((*pLista)->primeiro);
    return 0;


};

int B(struct Lista **pLista, int *parou)
{
    struct No *p = (struct No*) malloc (sizeof (struct No));
    struct No *Dele = (struct No*) malloc (sizeof (struct No));
	struct No *a, *b, *c, *resto;

	a = (struct No*) malloc (sizeof (struct No));
	b = (struct No*) malloc (sizeof (struct No));
	c = (struct No*) malloc (sizeof (struct No));
	resto = (struct No*) malloc (sizeof (struct No));

    Dele = (*pLista) -> primeiro;
    p = (*pLista) -> primeiro;// recebe o 1o no da lista(o no q ten o carac 'S')
    a = p -> prox; // cata o 'a'

    if(a==NULL)
    {
         *parou=1;
         return 0;
    }
	p = p -> prox; // cata o 'b'
	b = p -> prox;
    if(b==NULL)
    {
         *parou=1;
         return 0;
    }
	p = p -> prox; // cata o 'c'
	c = p -> prox;
    if(c==NULL)
    {
         *parou=1;
         return 0;
    }
	p = p -> prox; // cata o 'resto'
    resto = p -> prox;

    (*pLista)->primeiro = a;                 // l -> a
    (*pLista)->ultimo = a;
    a->prox = NULL;
    a->ante = NULL;

    inseriNo((*pLista), '(');          //      -> a -> (

	(*pLista)->ultimo -> lLista = (struct Lista*)malloc(sizeof(struct Lista));	// L -> a - > ( -> resto
	(*pLista)->ultimo -> lLista -> primeiro = b;								 	//            |
	(*pLista)->ultimo -> lLista -> ultimo = b;   	 						 	// 			  v
    b->prox = c;                                                        //            b -> c
    b->ante = NULL;
    c->prox = NULL;
    c->ante = b;

    (*pLista)->ultimo -> prox = resto;

    if(resto!=NULL)
    {
        resto->ante =(*pLista)->ultimo;
        (*pLista)->ultimo = (*pLista)->ultimo;
    }
    //free((*pLista)->primeiro);

    free(Dele);
    Dele = NULL;
    //liberado++;
    return 0;




};

int I(struct Lista **pLista, int *parou)
{
    struct No *Del = (struct No*) malloc (sizeof (struct No));
    if((*pLista)-> primeiro -> prox!=NULL)
    {
        Del = (*pLista)-> primeiro;
        (*pLista)-> primeiro =  (*pLista)-> primeiro -> prox;
        (*pLista)-> primeiro->ante = NULL;
        free(Del);
        //liberado++;
    }
    else
        *parou=1;

    return 0;
}

int SH(struct Lista **pLista, int *parou)
{
    struct No *p = (struct No*) malloc (sizeof (struct No));
    struct No *Dele = (struct No*) malloc (sizeof (struct No));
	struct No *a, *b, *c, *d , *resto;

	a = (struct No*) malloc (sizeof (struct No));
	b = (struct No*) malloc (sizeof (struct No));
	c = (struct No*) malloc (sizeof (struct No));
	d = (struct No*) malloc (sizeof (struct No));
	resto = (struct No*) malloc (sizeof (struct No));

	struct Lista  d2;//lista aux
	iniciaLista(&d2);

    Dele = (*pLista) -> primeiro;
    p = (*pLista) -> primeiro;// recebe o 1o no da lista(o no q ten o carac 'S')
    a = p -> prox; // cata o 'a'
    if(a==NULL)
    {
         *parou=1;
         return 0;
    }
	p = p -> prox; // cata o 'b'
	b = p -> prox;
    if(b==NULL)
    {
         *parou=1;
         return 0;
    }
	p = p -> prox; // cata o 'c'
	c = p -> prox;
    if(c==NULL)
    {
         *parou=1;
         return 0;
    }
    p = p -> prox; // cata o 'd'
	d = p -> prox;
    if(d==NULL)
    {
         *parou=1;
         return 0;
    }

    p = p -> prox; // cata o 'resto'
    resto = p -> prox;

	d->prox = NULL;
	clonaNo(d, &d2);//clona o 'd'

	//a (bd)(cd)

	(*pLista)->primeiro = a;                     // l -> a ->
	(*pLista)->ultimo = a;
	a -> prox = NULL;
	a -> ante = NULL;

	inseriNo((*pLista), '(');                  //L-> a-> (

	(*pLista)->ultimo -> lLista = (struct Lista*)malloc(sizeof(struct Lista));	// L -> a - > (      ->   (
	(*pLista)->ultimo -> lLista -> primeiro = b;								 	//            |
	(*pLista)->ultimo -> lLista -> ultimo = b;   	 						 	// 			  v
    b->ante = NULL;                                                     //            b -> d
    b->prox = d;
    d->ante = b;
    d->prox = NULL;
    (*pLista)->ultimo->lLista->ultimo = d;

    inseriNo((*pLista), '(');

    (*pLista)->ultimo -> lLista = (struct Lista*)malloc(sizeof(struct Lista));	// L -> a - > (      ->   (
	(*pLista)->ultimo -> lLista -> primeiro = c;								 	//            |           |
	(*pLista)->ultimo -> lLista -> ultimo = c;   	 				            // 			  v           v
                                                                        //            b -> d      c -> d2
    c->ante = NULL;
    c->prox = d2.primeiro;
    d2.primeiro->ante = c;
    d2.primeiro->prox = NULL;
    (*pLista)->ultimo->lLista->ultimo = d2.primeiro;

    (*pLista)->ultimo->prox =  resto;
    if(resto!=NULL)
    {
        resto->ante = (*pLista)->ultimo;
        (*pLista)->ultimo = (*pLista)->ultimo;
    }
    //free((*pLista)->primeiro);

    free(Dele);
    Dele = NULL;
    //liberado++;
    return 0;


};

int BH(struct Lista **pLista, int *parou)
{
    struct No *p = (struct No*) malloc (sizeof (struct No));
    struct No *Dele = (struct No*) malloc (sizeof (struct No));
	struct No *a, *b, *c, *d, *resto;

	a = (struct No*) malloc (sizeof (struct No));
	b = (struct No*) malloc (sizeof (struct No));
	c = (struct No*) malloc (sizeof (struct No));
	d = (struct No*) malloc (sizeof (struct No));
	resto = (struct No*) malloc (sizeof (struct No));

    Dele = (*pLista) -> primeiro;
    p = (*pLista) -> primeiro;// recebe o 1o no da lista(o no q ten o carac 'S')
    a = p -> prox; // cata o 'a'
    if(a==NULL)
    {
         *parou=1;
         return 0;
    }
	p = p -> prox; // cata o 'b'
	b = p -> prox;
    if(b==NULL)
    {
         *parou=1;
         return 0;
    }
	p = p -> prox; // cata o 'c'
	c = p -> prox;

    if(c==NULL)
    {
         *parou=1;
         return 0;
    }
	p = p -> prox; // cata o 'd'
	d = p -> prox;
    if(d==NULL)
    {
         *parou=1;
         return 0;
    }
	p = p -> prox; // cata o 'resto'
    resto = p -> prox;

    //ab(cd)
    (*pLista)->primeiro = a;                 // l -> a
    (*pLista)->ultimo = a;
    a->prox = NULL;
    a->ante = NULL;

    (*pLista)->primeiro->prox = b;                  // l -> a -> b
    b-> ante = (*pLista)->primeiro;
    b-> prox = NULL;
    (*pLista)->ultimo = b;


    inseriNo((*pLista), '(');          //      -> a -> b-> (

	(*pLista)->ultimo -> lLista = (struct Lista*)malloc(sizeof(struct Lista));	// L -> a - > b -> ( -> resto
	(*pLista)->ultimo -> lLista -> primeiro = c;								       	//            |
	(*pLista)->ultimo -> lLista -> ultimo = c;   	 						     	// 			  v
    c->prox = d;                                                            //            c -> d
    c->ante = NULL;
    d->prox = NULL;
    d->ante = c;

    (*pLista)->ultimo -> prox = resto;

    if(resto!=NULL)
    {
        resto->ante = (*pLista)->ultimo;
        (*pLista)->ultimo = (*pLista)->ultimo;
    }
    //free((*pLista)->primeiro);


    free(Dele);
    Dele = NULL;
    //liberado++;
    return 0;
};

int CH(struct Lista **pLista, int *parou)
{
    struct No *p = (struct No*) malloc (sizeof (struct No));
    struct No *Dele = (struct No*) malloc (sizeof (struct No));
	struct No *a, *b, *c, *d , *resto;

	a = (struct No*) malloc (sizeof (struct No));
	b = (struct No*) malloc (sizeof (struct No));
	c = (struct No*) malloc (sizeof (struct No));
	d = (struct No*) malloc (sizeof (struct No));
	resto = (struct No*) malloc (sizeof (struct No));
    Dele = (*pLista) -> primeiro;
    p = (*pLista) -> primeiro;// recebe o 1o no da lista(o no q ten o carac 'S')
    a = p -> prox; // cata o 'a'

    if(a==NULL)
    {
         *parou=1;
         return 0;
    }
	p = p -> prox; // cata o 'b'
	b = p -> prox;
    if(b==NULL)
    {
         *parou=1;
         return 0;
    }
	p = p -> prox; // cata o 'c'
	c = p -> prox;
    if(c==NULL)
    {
         *parou=1;
         return 0;
    }
    p = p -> prox; // cata o 'd'
	d = p -> prox;
    if(d==NULL)
    {
         *parou=1;
         return 0;
    }

    p = p -> prox; // cata o 'resto'
    resto = p -> prox;

	//a(bd)c

	(*pLista)->primeiro = a;                     // l -> a ->
	(*pLista)->ultimo = a;
	a -> prox = NULL;
	a -> ante = NULL;

	inseriNo((*pLista), '(');                  //L-> a-> (

	(*pLista)->ultimo -> lLista = (struct Lista*)malloc(sizeof(struct Lista));	// L -> a - > (
	(*pLista)->ultimo -> lLista -> primeiro = b;					//            |
	(*pLista)->ultimo -> lLista -> ultimo = b;   	 				//	      v
    b->ante = NULL;                                                 		//	      b -> d
    b->prox = d;
    d->ante = b;
    d->prox = NULL;
    (*pLista)->ultimo->lLista->ultimo = d;

    (*pLista)->ultimo->prox = c;       //   L -> a - > (		-> c
    c-> ante = (*pLista)->ultimo;	//            |
				//            b -> d

    c-> prox = resto;               // L -> a - > (	-> c -> resto
				    //            |
				    //		  b -> d
    if(resto!=NULL)
    {
        resto->ante = (*pLista)->ultimo;
        (*pLista)->ultimo = (*pLista)->ultimo;
    }

    //free((*pLista)->primeiro);

    free(Dele);
    Dele = NULL;
    //liberado++;
    return 0;

};
