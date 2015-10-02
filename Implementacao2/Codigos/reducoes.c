#include "reducoes.h"

/*Redução S a b c => (ac)(bc)*/
int OperarS(char *entrada, char* saida, int *tamEntrada)
{
    int tamA, tamB, tamC, tamResto, foi;

    foi = SeparaTermos(entrada, &tamA, &tamB, &tamC, NULL, &tamResto, tamEntrada, 3);

    //(ac)
    saida[0] = '(';
    memcpy(&saida[1],&entrada[1],tamA*sizeof(char));
    memcpy(&saida[tamA+1],&entrada[tamA+tamB+1],tamC*sizeof(char));
    saida[tamA+tamC+1] = ')';

    //(bc)
    saida[tamA+tamC+2] = '(';
    memcpy(&saida[tamA+tamC+3],&entrada[tamA+1],(tamB+tamC)*sizeof(char));
    saida[tamA+tamC+tamB+tamC+3] = ')';

    //resto
    memcpy(&saida[tamA+tamC+tamB+tamC+4],&entrada[tamA+tamB+tamC+1],tamResto*sizeof(char));

    *tamEntrada = (tamA+tamC+tamB+tamC+4+tamResto);

    #ifdef CONT_FLAG
       cont_S++;
    #endif

    return foi;
}

/*Redução K a b => a*/
int OperarK(char *entrada, char* saida, int *tamEntrada)
{
    int tamA, tamB, tamResto;

    SeparaTermos(entrada, &tamA, &tamB, NULL, NULL, &tamResto, tamEntrada, 2);
    
    //a
    memcpy(&saida[0],&entrada[1],tamA*sizeof(char));
    //resto
    memcpy(&saida[tamA],&entrada[tamA+tamB+1],(tamResto+1)*sizeof(char));

    *tamEntrada = tamA + tamResto;

    #ifdef CONT_FLAG
        cont_K++;
    #endif

    return 0;
}

/*Redução I a => a*/
int OperarI(char *entrada, char* saida, int *tamEntrada)
{
    int tamA, tamResto;

    int abreFecha = 0;
    int i = 1;
    int parte = 1;
    int qtd_carac = 0;

    if(entrada[i] == '(')
    {
        qtd_carac++;
        i++;
        while(abreFecha != -1)
        {
            if(entrada[i] == '(')
            {
                abreFecha++;
            }
            else if(entrada[i] == ')')
            {
                abreFecha--;
            }
            i++;
            qtd_carac++;
        }
        i--;
        abreFecha = 0;
    }
    else if(entrada[i] == '\0')
    {
        return 1;
    }
    else
    {
        qtd_carac++;
    }
    if(parte == 1)
    {
        tamA = qtd_carac;
    }
    i++;
    tamResto = (*tamEntrada-i);

    memcpy(&saida[0],&entrada[1],tamA*sizeof(char));
    memcpy(&saida[tamA],&entrada[tamA+1],tamResto*sizeof(char));

    saida[tamA+tamResto] = '\0';

    *tamEntrada = tamA + tamResto;

    #ifdef CONT_FLAG
        cont_I++;
    #endif

    return 0;

}

/*Redução C f x y => f y x*/
int OperarC(char *entrada, char* saida, int *tamEntrada)
{
    int tamF, tamX, tamY, tamResto, foi;

    foi = SeparaTermos(entrada, &tamF, &tamX, &tamY, NULL, &tamResto, tamEntrada, 3);

    //f
    memcpy(&saida[0],&entrada[1],tamF*sizeof(char));

    //y
    memcpy(&saida[tamF],&entrada[tamF+tamX+1],tamY*sizeof(char));

    //x
    memcpy(&saida[tamF+tamY],&entrada[tamF+1],tamX*sizeof(char));

    //resto
    memcpy(&saida[tamF+tamY+tamX],&entrada[tamF+tamX+tamY+1],tamResto*sizeof(char));

    saida[tamF+tamY+tamX+tamResto] = '\0';

    *tamEntrada = (tamF+tamX+tamY+tamResto);

    #ifdef CONT_FLAG
       cont_C++;
    #endif

    return foi;
}

/*Redução B f g x => f (gx)*/
int OperarB(char *entrada, char* saida, int *tamEntrada)
{
    int tamF, tamG, tamX, tamResto, foi;

    foi = SeparaTermos(entrada, &tamF, &tamG, &tamX, NULL, &tamResto, tamEntrada, 3);

    //f
    memcpy(&saida[0],&entrada[1],tamF*sizeof(char));

    //(gx)
    saida[tamF] = '(';
    memcpy(&saida[tamF+1],&entrada[tamF+1],(tamG+tamX)*sizeof(char));
    saida[tamF+tamG+tamX+1] = ')';
    
    //resto
    memcpy(&saida[tamF+tamG+tamX+2],&entrada[tamF+tamG+tamX+1],tamResto*sizeof(char));

    saida[tamF+tamG+tamX+2+tamResto] = '\0';

    *tamEntrada = (tamF+tamG+tamX+2+tamResto);

    #ifdef CONT_FLAG
       cont_B++;
    #endif

    return foi;
}

/*Redução S' a b c d => a (bd)(cd)*/
int OperarSHifen(char *entrada, char* saida, int *tamEntrada)
{
    int tamA, tamB, tamC, tamD, tamResto, foi;

    foi = SeparaTermos(entrada, &tamA, &tamB, &tamC, &tamD, &tamResto, tamEntrada, 4);

    //a
    memcpy(&saida[0],&entrada[1],tamA*sizeof(char));

    //(bd)
    saida[tamA] = '(';
    memcpy(&saida[tamA+1],&entrada[tamA+1],tamB*sizeof(char));
    memcpy(&saida[tamA+1+tamB],&entrada[tamA+1+tamB+tamC],tamD*sizeof(char));
    saida[tamA+1+tamB+tamD] = ')';

    //(cd)
    saida[tamA+2+tamB+tamD] = '(';
    memcpy(&saida[tamA+3+tamB+tamD],&entrada[tamA+1+tamB],(tamC+tamD)*sizeof(char));
    saida[tamA+3+tamB+2*tamD+tamC] = ')';
    
    //resto
    memcpy(&saida[tamA+4+tamB+2*tamD+tamC],&entrada[tamA+1+tamB+tamC+tamD],tamResto*sizeof(char));

    saida[tamA+3+tamB+2*tamD+tamC+tamResto+1] = '\0';

    *tamEntrada = (tamA+tamC+tamB+2*tamD+4+tamResto);

    #ifdef CONT_FLAG
        cont_SH++;
    #endif

    return foi;
}

/*Redução B' a b c d => a b (c d)*/
int OperarBHifen(char *entrada, char* saida, int *tamEntrada)
{
    int tamA, tamB, tamC, tamD, tamResto, foi;

    foi = SeparaTermos(entrada, &tamA, &tamB, &tamC, &tamD, &tamResto, tamEntrada, 4);

    //ab
    memcpy(&saida[0],&entrada[1],(tamA+tamB)*sizeof(char));

    //(cd)
    saida[tamA+tamB] = '(';
    memcpy(&saida[tamA+1+tamB],&entrada[tamA+1+tamB],(tamC+tamD)*sizeof(char));
    saida[tamA+1+tamB+tamC+tamD] = ')';

    //resto
    memcpy(&saida[tamA+2+tamB+tamC+tamD],&entrada[tamA+1+tamB+tamC+tamD],tamResto*sizeof(char));

    saida[tamA+2+tamB+tamC+tamD+tamResto] = '\0';

    *tamEntrada = (tamA+tamC+tamB+tamD+tamResto+2);


    #ifdef CONT_FLAG
        cont_BH++;
    #endif

    return foi;
}

/*Redução C' a b c d => a (b d) c*/
int OperarCHifen(char *entrada, char* saida, int *tamEntrada)
{
    int tamA, tamB, tamC, tamD, tamResto, foi;

    foi = SeparaTermos(entrada, &tamA, &tamB, &tamC, &tamD, &tamResto, tamEntrada, 4);

    //a
    memcpy(&saida[0],&entrada[1],tamA*sizeof(char));

    //(bd)
    saida[tamA] = '(';
    memcpy(&saida[tamA+1],&entrada[tamA+1],tamB*sizeof(char));
    memcpy(&saida[tamA+1+tamB],&entrada[tamA+1+tamB+tamC],tamD*sizeof(char));
    saida[tamA+1+tamB+tamD] = ')';

    //c
    memcpy(&saida[tamA+2+tamB+tamD],&entrada[tamA+1+tamB],tamC*sizeof(char));

    //resto
    memcpy(&saida[tamA+2+tamB+tamD+tamC],&entrada[tamA+1+tamB+tamC+tamD],tamResto*sizeof(char));

    saida[tamA+2+tamB+tamC+tamD+tamResto] = '\0';

    *tamEntrada = (tamA+tamC+tamB+tamD+tamResto+2);

    #ifdef CONT_FLAG
        cont_CH++;
    #endif

    return foi;
}

