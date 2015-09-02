#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define DEBUG_FLAG

char entrada[90000000];
char saida [90000000];

int tamEntrada;
int tamResto;
int cont_K;
int cont_S;

/*void substituirY()
{
    tamResto = tamEntrada - 1;

    memcpy(resto, &entrada[1], (tamEntrada-1)*sizeof(char));
    memcpy(entrada, Y, tamY*sizeof(char));
    memcpy(&entrada[tamY], resto, tamResto*sizeof(char));

    tamEntrada = tamEntrada - 1 + tamY;
}
*/
void tirarParenteses()
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
    memmove(&entrada[0],&entrada[1],(tamEntrada-1)*sizeof(char));
    memmove(&entrada[i-1],&entrada[i],(tamEntrada - i)*sizeof(char));

    entrada[tamEntrada - 2] = '\0';
    tamEntrada -= 2;

}

void OperarS()
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
        {;
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

    memcpy(entrada,saida,(tamA+tamC+tamB+tamC+4+tamResto)*sizeof(char));

    tamEntrada = (tamA+tamC+tamB+tamC+4+tamResto);

    #ifdef DEBUG_FLAG
        cont_S++;
    #endif
}

void OperarK()
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

    memmove(&entrada[0],&entrada[1],(tamEntrada-1)*sizeof(char));
    memmove(&entrada[tamA],&entrada[tamA+tamB],tamResto*sizeof(char));

    entrada[tamA+tamResto] = '\0';
    tamEntrada = tamA + tamResto;

    #ifdef DEBUG_FLAG
        cont_K++;
    #endif
}
int main()
{
    FILE *arq = fopen("string.in", "r");
    fscanf(arq,"%s",entrada);

    tamEntrada = strlen(entrada);

    while(tamEntrada != 1)
    {
        if(entrada[0] == '(')
        {
            tirarParenteses();
        }
        /*else if(entrada[0] == 'Y')
        {
            substituirY();
        }*/
        else if(entrada[0] == 'S')
        {
            OperarS();
        }
        else if(entrada[0]== 'K')
        {
            OperarK();
        }
    }
    printf("\n%s\n",entrada);
    return 0;
}
