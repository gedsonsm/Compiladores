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
	LiberaNo(b);   // Descomentar se quiser ativar a funcao Liberar

    //(*pLista) = l;
	return 0;
}

// struct Lista C(struct Lista *pLista, int *parou)
// {
//     struct No *p = (struct No*) malloc (sizeof (struct No));
// 	struct No *a, *b, *c, *resto;

// 	a = (struct No*) malloc (sizeof (struct No));
// 	b = (struct No*) malloc (sizeof (struct No));
// 	c = (struct No*) malloc (sizeof (struct No));
// 	resto = (struct No*) malloc (sizeof (struct No));

// 	struct Lista l;//lista aux
// 	iniciaLista(&l);

// 	p = pLista -> primeiro;// recebe o 1o no da lista(o no q ten o carac 'S')
// 	a = p -> prox; // cata o 'a'
//     if(a==NULL)
//     {
//          *parou=1;
//          return *pLista;
//     }
// 	p = p -> prox; // cata o 'b'
// 	b = p -> prox;
//     if(b==NULL)
//     {
//          *parou=1;
//          return *pLista;
//     }
// 	p = p -> prox; // cata o 'c'
// 	c = p -> prox;
//     if(c==NULL)
//     {
//          *parou=1;
//          return *pLista;
//     }
// 	p = p -> prox; // cata o 'resto'
//     resto = p -> prox;

//     l.primeiro = a   ;                     // l -> a
//     l.ultimo = a;
//     a->ante = NULL;
//     a->prox = NULL;

//     l.primeiro->prox = c;                  // l -> a -> c
//     c-> ante = l.primeiro;
//     c-> prox = NULL;
//     l.ultimo = c;

//     l.ultimo->prox = b;            // l -> a -> c -> b
//     b-> ante = l.ultimo;

//     b-> prox = resto;               //  l -> a -> c -> b -> resto
//     if(resto!=NULL)
//     {
//         resto->ante = l.ultimo;
//         l.ultimo = pLista -> ultimo;
//     }
//     else
//         l.ultimo = b;

//     free(pLista->primeiro);
//     return l;


// };

// struct Lista B(struct Lista *pLista, int *parou)
// {
//     struct No *p = (struct No*) malloc (sizeof (struct No));
// 	struct No *a, *b, *c, *resto;

// 	a = (struct No*) malloc (sizeof (struct No));
// 	b = (struct No*) malloc (sizeof (struct No));
// 	c = (struct No*) malloc (sizeof (struct No));
// 	resto = (struct No*) malloc (sizeof (struct No));

// 	struct Lista l;//lista aux
// 	iniciaLista(&l);

// 	p = pLista -> primeiro;// recebe o 1o no da lista(o no q ten o carac 'S')
// 	a = p -> prox; // cata o 'a'
//     if(a==NULL)
//     {
//          *parou=1;
//          return *pLista;
//     }
// 	p = p -> prox; // cata o 'b'
// 	b = p -> prox;
//     if(b==NULL)
//     {
//          *parou=1;
//          return *pLista;
//     }
// 	p = p -> prox; // cata o 'c'
// 	c = p -> prox;
//     if(c==NULL)
//     {
//          *parou=1;
//          return *pLista;
//     }
// 	p = p -> prox; // cata o 'resto'
//     resto = p -> prox;

//     l.primeiro = a;                 // l -> a
//     l.ultimo = a;
//     a->prox = NULL;
//     a->ante = NULL;

//     inseriNo(&l, '(');          //      -> a -> (

// 	l.ultimo -> lLista = (struct Lista*)malloc(sizeof(struct Lista));	// L -> a - > ( -> resto
// 	l.ultimo -> lLista -> primeiro = b;								 	//            |
// 	l.ultimo -> lLista -> ultimo = b;   	 						 	// 			  v
//     b->prox = c;                                                        //            b -> c
//     b->ante = NULL;
//     c->prox = NULL;
//     c->ante = b;

//     l.ultimo -> prox = resto;

//     if(resto!=NULL)
//     {
//         resto->ante = l.ultimo;
//         l.ultimo = pLista->ultimo;
//     }
//     free(pLista->primeiro);
//     return l;




// };

// struct Lista I(struct Lista *pLista, int *parou)
// {
//     struct No *Del = (struct No*) malloc (sizeof (struct No));
//     if(pLista-> primeiro -> prox!=NULL)
//     {
//         Del = pLista-> primeiro;
//         pLista-> primeiro =  pLista-> primeiro -> prox;
//         pLista-> primeiro->ante = NULL;
//         free(Del);
//     }
//     else
//         *parou=1;

//     return *pLista;
// }

// struct Lista SH(struct Lista *pLista, int *parou)
// {
//     struct No *p = (struct No*) malloc (sizeof (struct No));
// 	struct No *a, *b, *c, *d , *resto;

// 	a = (struct No*) malloc (sizeof (struct No));
// 	b = (struct No*) malloc (sizeof (struct No));
// 	c = (struct No*) malloc (sizeof (struct No));
// 	d = (struct No*) malloc (sizeof (struct No));
// 	resto = (struct No*) malloc (sizeof (struct No));

// 	struct Lista l, d2;//lista aux
// 	iniciaLista(&l);
// 	iniciaLista(&d2);

// 	p = pLista -> primeiro;// recebe o 1o no da lista(o no q ten o carac 'S')
// 	a = p -> prox; // cata o 'a'
//     if(a==NULL)
//     {
//          *parou=1;
//          return *pLista;
//     }
// 	p = p -> prox; // cata o 'b'
// 	b = p -> prox;
//     if(b==NULL)
//     {
//          *parou=1;
//          return *pLista;
//     }
// 	p = p -> prox; // cata o 'c'
// 	c = p -> prox;
//     if(c==NULL)
//     {
//          *parou=1;
//          return *pLista;
//     }
//     p = p -> prox; // cata o 'd'
// 	d = p -> prox;
//     if(d==NULL)
//     {
//          *parou=1;
//          return *pLista;
//     }

//     p = p -> prox; // cata o 'resto'
//     resto = p -> prox;

// 	d->prox = NULL;
// 	clonaNo(d, &d2);//clona o 'd'

// 	//a (bd)(cd)

// 	l.primeiro = a;                     // l -> a ->
// 	l.ultimo = a;
// 	a -> prox = NULL;
// 	a -> ante = NULL;

// 	inseriNo(&l, '(');                  //L-> a-> (

// 	l.ultimo -> lLista = (struct Lista*)malloc(sizeof(struct Lista));	// L -> a - > (      ->   (
// 	l.ultimo -> lLista -> primeiro = b;								 	//            |
// 	l.ultimo -> lLista -> ultimo = b;   	 						 	// 			  v
//     b->ante = NULL;                                                     //            b -> d
//     b->prox = d;
//     d->ante = b;
//     d->prox = NULL;
//     l.ultimo->lLista->ultimo = d;

//     inseriNo(&l, '(');

//     l.ultimo -> lLista = (struct Lista*)malloc(sizeof(struct Lista));	// L -> a - > (      ->   (
// 	l.ultimo -> lLista -> primeiro = c;								 	//            |           |
// 	l.ultimo -> lLista -> ultimo = c;   	 				            // 			  v           v
//                                                                         //            b -> d      c -> d2
//     c->ante = NULL;
//     c->prox = d2.primeiro;
//     d2.primeiro->ante = c;
//     d2.primeiro->prox = NULL;
//     l.ultimo->lLista->ultimo = d2.primeiro;

//     l.ultimo->prox =  resto;
//     if(resto!=NULL)
//     {
//         resto->ante = l.ultimo;
//         l.ultimo = pLista->ultimo;
//     }
//     free(pLista->primeiro);
//     return l;



// };

// struct Lista BH(struct Lista *pLista, int *parou)
// {
//     struct No *p = (struct No*) malloc (sizeof (struct No));
// 	struct No *a, *b, *c, *d, *resto;

// 	a = (struct No*) malloc (sizeof (struct No));
// 	b = (struct No*) malloc (sizeof (struct No));
// 	c = (struct No*) malloc (sizeof (struct No));
// 	d = (struct No*) malloc (sizeof (struct No));
// 	resto = (struct No*) malloc (sizeof (struct No));

// 	struct Lista l;//lista aux
// 	iniciaLista(&l);

// 	p = pLista -> primeiro;// recebe o 1o no da lista(o no q ten o carac 'BH')
// 	a = p -> prox; // cata o 'a'
//     if(a==NULL)
//     {
//          *parou=1;
//          return *pLista;
//     }
// 	p = p -> prox; // cata o 'b'
// 	b = p -> prox;
//     if(b==NULL)
//     {
//          *parou=1;
//          return *pLista;
//     }
// 	p = p -> prox; // cata o 'c'
// 	c = p -> prox;

//     if(c==NULL)
//     {
//          *parou=1;
//          return *pLista;
//     }
// 	p = p -> prox; // cata o 'd'
// 	d = p -> prox;
//     if(d==NULL)
//     {
//          *parou=1;
//          return *pLista;
//     }
// 	p = p -> prox; // cata o 'resto'
//     resto = p -> prox;

//     //ab(cd)
//     l.primeiro = a;                 // l -> a
//     l.ultimo = a;
//     a->prox = NULL;
//     a->ante = NULL;

//     l.primeiro->prox = b;                  // l -> a -> b
//     b-> ante = l.primeiro;
//     b-> prox = NULL;
//     l.ultimo = b;


//     inseriNo(&l, '(');          //      -> a -> b-> (

// 	l.ultimo -> lLista = (struct Lista*)malloc(sizeof(struct Lista));	// L -> a - > b -> ( -> resto
// 	l.ultimo -> lLista -> primeiro = c;								       	//            |
// 	l.ultimo -> lLista -> ultimo = c;   	 						     	// 			  v
//     c->prox = d;                                                            //            c -> d
//     c->ante = NULL;
//     d->prox = NULL;
//     d->ante = c;

//     l.ultimo -> prox = resto;

//     if(resto!=NULL)
//     {
//         resto->ante = l.ultimo;
//         l.ultimo = pLista->ultimo;
//     }
//     free(pLista->primeiro);
//     return l;
// };

// struct Lista CH(struct Lista *pLista, int *parou)
// {
//     struct No *p = (struct No*) malloc (sizeof (struct No));
// 	struct No *a, *b, *c, *d , *resto;

// 	a = (struct No*) malloc (sizeof (struct No));
// 	b = (struct No*) malloc (sizeof (struct No));
// 	c = (struct No*) malloc (sizeof (struct No));
// 	d = (struct No*) malloc (sizeof (struct No));
// 	resto = (struct No*) malloc (sizeof (struct No));

// 	struct Lista l;//lista aux
// 	iniciaLista(&l);

// 	p = pLista -> primeiro;// recebe o 1o no da lista(o no q ten o carac 'S')
// 	a = p -> prox; // cata o 'a'
//     if(a==NULL)
//     {
//          *parou=1;
//          return *pLista;
//     }
// 	p = p -> prox; // cata o 'b'
// 	b = p -> prox;
//     if(b==NULL)
//     {
//          *parou=1;
//          return *pLista;
//     }
// 	p = p -> prox; // cata o 'c'
// 	c = p -> prox;
//     if(c==NULL)
//     {
//          *parou=1;
//          return *pLista;
//     }
//     p = p -> prox; // cata o 'd'
// 	d = p -> prox;
//     if(d==NULL)
//     {
//          *parou=1;
//          return *pLista;
//     }

//     p = p -> prox; // cata o 'resto'
//     resto = p -> prox;

// 	//a(bd)c

// 	l.primeiro = a;                     // l -> a ->
// 	l.ultimo = a;
// 	a -> prox = NULL;
// 	a -> ante = NULL;

// 	inseriNo(&l, '(');                  //L-> a-> (

// 	l.ultimo -> lLista = (struct Lista*)malloc(sizeof(struct Lista));	// L -> a - > (
// 	l.ultimo -> lLista -> primeiro = b;					//            |
// 	l.ultimo -> lLista -> ultimo = b;   	 				//	      v
//     b->ante = NULL;                                                 		//	      b -> d
//     b->prox = d;
//     d->ante = b;
//     d->prox = NULL;
//     l.ultimo->lLista->ultimo = d;

//     l.ultimo->prox = c;       //   L -> a - > (		-> c
//     c-> ante = l.ultimo;	//            |
// 				//            b -> d

//     c-> prox = resto;               // L -> a - > (	-> c -> resto
// 				    //            |
// 				    //		  b -> d
//     if(resto!=NULL)
//     {
//         resto->ante = l.ultimo;
//         l.ultimo = pLista->ultimo;
//     }

//     free(pLista->primeiro);
//     return l;

// };
