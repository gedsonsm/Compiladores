#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define DEBUG_FLAG

char entrada1[90000000];
char saida1[90000000];

int tamEntrada;
int tamY;
int tamResto;
int cont_S;
int cont_K;
int cont_P;
int cont_I;
int cont_C;
int cont_B;
int cont_SH;
int cont_CH;
int cont_BH;

int parou;


void tirarParenteses(char *entrada, char* saida)
{

    int contgeral = 1,parenteses =1,abreFecha,ini = 0,fin,a;
    while(1)
    {
        if(entrada[contgeral]=='(')
            parenteses++;
        else
        {
            fin = parenteses;
            for(a=0;a<parenteses;a++)
            {
                abreFecha = 1;
                while(abreFecha != 0)
                {
                    if(entrada[contgeral] == '(')
                    {
                        abreFecha++;
                    }
                    else if(entrada[contgeral] == ')')
                    {
                        abreFecha--;
                    }
                    contgeral++;
                }
                memcpy(&saida[ini],&entrada[fin],(contgeral-fin-1)*sizeof(char));
                ini = ini + (contgeral-fin-1);
                fin = contgeral;
            }
            memcpy(&saida[ini],&entrada[fin],(tamEntrada-fin)*sizeof(char));
            saida[ini+(tamEntrada-fin)] = '\0';
            break;
        }
        contgeral++;

    }
    tamEntrada = tamEntrada - 2*parenteses;
}

int OperarS(char *entrada, char* saida)
{
    int tamA, tamB, tamC;
    int abreFecha = 0;
    int i = 1;
    int parte = 1;
    int qtd_carac = 0;
    while(parte <= 3)
    {
        qtd_carac = 0;
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
            parou = 1;
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
        if(parte == 2)
        {
            tamB = qtd_carac;
        }
        else if(parte == 3)
        {
            tamC = qtd_carac;
        }
        i++;
        parte++;
    }
    tamResto = (tamEntrada-i);

    saida[0] = '(';
    memcpy(&saida[1],&entrada[1],tamA*sizeof(char));
    memcpy(&saida[tamA+1],&entrada[tamA+tamB+1],tamC*sizeof(char));
    saida[tamA+tamC+1] = ')';

    saida[tamA+tamC+2] = '(';
    memcpy(&saida[tamA+tamC+3],&entrada[tamA+1],(tamB+tamC)*sizeof(char));
    //memcpy(&saida[tamA+tamC+3],&entrada[tamA+1],(tamB)*sizeof(char));
    //memcpy(&saida[tamA+tamC+tamB+3],&entrada[tamA+tamB+1],tamC*sizeof(char));
    saida[tamA+tamC+tamB+tamC+3] = ')';

    memcpy(&saida[tamA+tamC+tamB+tamC+4],&entrada[tamA+tamB+tamC+1],tamResto*sizeof(char));

    tamEntrada = (tamA+tamC+tamB+tamC+4+tamResto);

    #ifdef DEBUG_FLAG
       cont_S++;
    #endif
    return 0;
}

int OperarK(char *entrada, char* saida)
{
    int tamA, tamB;
    int abreFecha = 0;
    int i = 1;
    int parte = 1;
    int qtd_carac = 0;
    while(parte <= 2)
    {
        qtd_carac = 0;
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
		parou = 1;
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
        if(parte == 2)
        {
            tamB = qtd_carac;
        }
        i++;
        parte++;
    }
    tamResto = (tamEntrada-i);

    memcpy(&saida[0],&entrada[1],tamA*sizeof(char));
    memcpy(&saida[tamA],&entrada[tamA+tamB+1],tamResto*sizeof(char));

    saida[tamA+tamResto] = '\0';

    tamEntrada = tamA + tamResto;

    #ifdef DEBUG_FLAG
        cont_K++;
    #endif
    return 0;
}

int OperarI(char *entrada, char* saida)
{
    int tamA;
    int abreFecha = 0;
    int i = 1;
    int parte = 1;
    int qtd_carac = 0;
//    while(parte <= 1)
//    {
//        qtd_carac = 0;
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
		parou = 1;
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
//        parte++;
//    }
    tamResto = (tamEntrada-i);

    memcpy(&saida[0],&entrada[1],tamA*sizeof(char));
    memcpy(&saida[tamA],&entrada[tamA+1],tamResto*sizeof(char));

    saida[tamA+tamResto] = '\0';

    tamEntrada = tamA + tamResto;

    #ifdef DEBUG_FLAG
        cont_I++;
    #endif
    return 0;
}

int OperarC(char *entrada, char* saida)
{
    int tamF, tamX, tamY;
    int abreFecha = 0;
    int i = 1;
    int parte = 1;
    int qtd_carac = 0;
    while(parte <= 3)
    {
        qtd_carac = 0;
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
		parou = 1;
		return 1;
	}
        else
        {
            qtd_carac++;
        }
        if(parte == 1)
        {
            tamF = qtd_carac;
        }
        if(parte == 2)
        {
            tamX = qtd_carac;
        }
        else if(parte == 3)
        {
            tamY = qtd_carac;
        }
        i++;
        parte++;
    }
    tamResto = (tamEntrada-i);

    memcpy(&saida[0],&entrada[1],tamF*sizeof(char));
    memcpy(&saida[tamF],&entrada[tamF+tamX+1],tamY*sizeof(char));
    memcpy(&saida[tamF+tamY],&entrada[tamF+1],tamX*sizeof(char));

    memcpy(&saida[tamF+tamY+tamX],&entrada[tamF+tamX+tamY+1],tamResto*sizeof(char));

    saida[tamF+tamY+tamX+tamResto] = '\0';

    tamEntrada = (tamF+tamX+tamY+tamResto);

    #ifdef DEBUG_FLAG
       cont_C++;
    #endif
    return 0;
}

int OperarB(char *entrada, char* saida)
{
    int tamF, tamG, tamX;
    int abreFecha = 0;
    int i = 1;
    int parte = 1;
    int qtd_carac = 0;
    while(parte <= 3)
    {
        qtd_carac = 0;
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
		parou = 1;
		return 1;
	}
        else
        {
            qtd_carac++;
        }
        if(parte == 1)
        {
            tamF = qtd_carac;
        }
        if(parte == 2)
        {
            tamG = qtd_carac;
        }
        else if(parte == 3)
        {
            tamX = qtd_carac;
        }
        i++;
        parte++;
    }
    tamResto = (tamEntrada-i);

    memcpy(&saida[0],&entrada[1],tamF*sizeof(char));

    saida[tamF] = '(';
    memcpy(&saida[tamF+1],&entrada[tamF+1],(tamG+tamX)*sizeof(char));
    //memcpy(&saida[tamF+1],&entrada[tamF+1],tamG*sizeof(char));
    //memcpy(&saida[tamF+tamG+1],&entrada[tamF+tamG+1],tamX*sizeof(char));
    saida[tamF+tamG+tamX+1] = ')';

    memcpy(&saida[tamF+tamG+tamX+2],&entrada[tamF+tamG+tamX+1],tamResto*sizeof(char));

    saida[tamF+tamG+tamX+2+tamResto] = '\0';

    tamEntrada = (tamF+tamG+tamX+2+tamResto);

    #ifdef DEBUG_FLAG
       cont_B++;
    #endif
    return 0;
}

int OperarSHifen(char *entrada, char* saida)
{
    int tamA, tamB, tamC, tamD;
    int abreFecha = 0;
    int i = 1;
    int parte = 1;
    int qtd_carac = 0;
    while(parte <= 4)
    {
        qtd_carac = 0;
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
            parou = 1;
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
        else if(parte == 2)
        {
            tamB = qtd_carac;
        }
        else if(parte == 3)
        {
            tamC = qtd_carac;
        }
        else if(parte == 4)
        {
            tamD = qtd_carac;
        }
        i++;
        parte++;
    }
    tamResto = (tamEntrada-i);

    memcpy(&saida[0],&entrada[1],tamA*sizeof(char));

    saida[tamA] = '(';
    memcpy(&saida[tamA+1],&entrada[tamA+1],tamB*sizeof(char));
    memcpy(&saida[tamA+1+tamB],&entrada[tamA+1+tamB+tamC],tamD*sizeof(char));
    saida[tamA+1+tamB+tamD] = ')';

    saida[tamA+2+tamB+tamD] = '(';
    memcpy(&saida[tamA+3+tamB+tamD],&entrada[tamA+1+tamB],(tamC+tamD)*sizeof(char));
    saida[tamA+3+tamB+2*tamD+tamC] = ')';

    memcpy(&saida[tamA+4+tamB+2*tamD+tamC],&entrada[tamA+1+tamB+tamC+tamD],tamResto*sizeof(char));

    saida[tamA+3+tamB+2*tamD+tamC+tamResto+1] = '\0';

    tamEntrada = (tamA+tamC+tamB+2*tamD+4+tamResto);

    #ifdef DEBUG_FLAG
        cont_SH++;
    #endif
    return 0;
}

int OperarBHifen(char *entrada, char* saida)
{
    int tamA, tamB, tamC, tamD;
    int abreFecha = 0;
    int i = 1;
    int parte = 1;
    int qtd_carac = 0;
    while(parte <= 4)
    {
        qtd_carac = 0;
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
		parou = 1;
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
        else if(parte == 2)
        {
            tamB = qtd_carac;
        }
        else if(parte == 3)
        {
            tamC = qtd_carac;
        }
        else if(parte == 4)
        {
            tamD = qtd_carac;
        }
        i++;
        parte++;
    }
    tamResto = (tamEntrada-i);

    memcpy(&saida[0],&entrada[1],(tamA+tamB)*sizeof(char));

    saida[tamA+tamB] = '(';
    memcpy(&saida[tamA+1+tamB],&entrada[tamA+1+tamB],(tamC+tamD)*sizeof(char));
    saida[tamA+1+tamB+tamC+tamD] = ')';

    memcpy(&saida[tamA+2+tamB+tamC+tamD],&entrada[tamA+1+tamB+tamC+tamD],tamResto*sizeof(char));

    saida[tamA+2+tamB+tamC+tamD+tamResto] = '\0';

    tamEntrada = (tamA+tamC+tamB+tamD+tamResto+2);


    #ifdef DEBUG_FLAG
        cont_BH++;
    #endif
    return 0;
}

int OperarCHifen(char *entrada, char* saida)
{
    int tamA, tamB, tamC, tamD;
    int abreFecha = 0;
    int i = 1;
    int parte = 1;
    int qtd_carac = 0;
    while(parte <= 4)
    {
        qtd_carac = 0;
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
		parou = 1;
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
        else if(parte == 2)
        {
            tamB = qtd_carac;
        }
        else if(parte == 3)
        {
            tamC = qtd_carac;
        }
        else if(parte == 4)
        {
            tamD = qtd_carac;
        }
        i++;
        parte++;
    }
    tamResto = (tamEntrada-i);

    memcpy(&saida[0],&entrada[1],tamA*sizeof(char));

    saida[tamA] = '(';
    memcpy(&saida[tamA+1],&entrada[tamA+1],tamB*sizeof(char));
    memcpy(&saida[tamA+1+tamB],&entrada[tamA+1+tamB+tamC],tamD*sizeof(char));
    saida[tamA+1+tamB+tamD] = ')';

    memcpy(&saida[tamA+2+tamB+tamD],&entrada[tamA+1+tamB],tamC*sizeof(char));

    memcpy(&saida[tamA+2+tamB+tamD+tamC],&entrada[tamA+1+tamB+tamC+tamD],tamResto*sizeof(char));

    saida[tamA+2+tamB+tamC+tamD+tamResto] = '\0';

    tamEntrada = (tamA+tamC+tamB+tamD+tamResto+2);

    #ifdef DEBUG_FLAG
        cont_CH++;
    #endif
    return 0;
}

int main()
{
    FILE *arq = fopen("string.in", "r");
    fscanf(arq,"%s",entrada1);

    char *pontE = entrada1;
    char *pontS = saida1;
    char *aux;
    tamEntrada = strlen(entrada1);

    while(1)
    {
        switch(pontE[0])
        {
            case '(':
                tirarParenteses(pontE, pontS);
            break;

            case 'W':
                OperarSHifen(pontE, pontS);
            break;

            case 'H':
                OperarBHifen(pontE, pontS);
            break;

            case 'P':
                OperarCHifen(pontE, pontS);
            break;

            case 'S':
                OperarS(pontE, pontS);
            break;

            case 'K':
                OperarK(pontE, pontS);
            break;

            case 'I':
                OperarI(pontE, pontS);
            break;

            case 'C':
                OperarC(pontE, pontS);
            break;

            case 'B':
                OperarB(pontE, pontS);
            break;
        }
        if(parou == 1)
        {
            break;
        }
        aux = pontE;
        pontE = pontS;
        pontS = aux;
    }
    printf("\nResposta = %s\n",pontE);
    return 0;
}
 // S' = W // C' = P // B' = H
