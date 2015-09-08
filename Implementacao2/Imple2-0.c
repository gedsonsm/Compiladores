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

/*void substituirY()
{
	tamResto = tamEntrada - 1;

	memcpy(resto, &entrada[1], (tamEntrada-1)*sizeof(char));


	memcpy(entrada, Y, tamY*sizeof(char));

	memcpy(&entrada[tamY], resto, tamResto*sizeof(char));

	tamEntrada = tamEntrada - 1 + tamY;
}
*/
void tirarParenteses(char *entrada, char* saida)
{
    int abreFecha = 0;
    int i = 1;
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
    }
    i--;

    memcpy(saida,&entrada[1],(i-1)*sizeof(char));
    memcpy(&saida[i-1],&entrada[i+1],(tamEntrada - i)*sizeof(char));

    tamEntrada-=2;
	//#ifdef DEBUG_FLAG
	//	cont_P++;
	//#endif
}

void OperarS(char *entrada, char* saida)
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
    memcpy(&saida[tamA+tamC+3],&entrada[tamA+1],tamB*sizeof(char));
    memcpy(&saida[tamA+tamC+tamB+3],&entrada[tamA+tamB+1],tamC*sizeof(char));
    saida[tamA+tamC+tamB+tamC+3] = ')';

    memcpy(&saida[tamA+tamC+tamB+tamC+4],&entrada[tamA+tamB+tamC+1],tamResto*sizeof(char));

    tamEntrada = (tamA+tamC+tamB+tamC+4+tamResto);
	
    //#ifdef DEBUG_FLAG
    //   cont_S++;
    //#endif
}

void OperarK(char *entrada, char* saida)
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

    //#ifdef DEBUG_FLAG
    //    cont_K++;
    //#endif
}

void OperarI(char *entrada, char* saida)
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

    //#ifdef DEBUG_FLAG
    //    cont_I++;
    //#endif
}

int main()
{
    FILE *arq = fopen("string.in", "r");
    fscanf(arq,"%s",entrada1);
    //printf("\n%s\n",entrada1);

    char *pontE = entrada1;
    char *pontS = saida1;
    char *aux;
    tamEntrada = strlen(entrada1);

    while(tamEntrada != 1)
    {
        if(pontE[0] == '(')
        {
            tirarParenteses(pontE, pontS);
        }
        /*else if(entrada[0] == 'Y')
        {
            substituirY();
        }*/
        else if(pontE[0] == 'S')
        {
            OperarS(pontE, pontS);
        }
        else if(pontE[0]== 'K')
        {
            OperarK(pontE, pontS);
        }
	else if(pontE[0] == 'I')
	{
	    OperarI(pontE, pontS);
	}

        aux = pontE;
        pontE = pontS;
        pontS = aux;
    }
    //printf("\n%s\n",pontE);
    //printf("\n%d\n",cont_S);
    //printf("\n%d\n",cont_K);
    //printf("\n%d\n",cont_P);
    return 0;
}
