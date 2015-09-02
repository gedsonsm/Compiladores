#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char entrada[90000000];
char saida [90000000];
char Y [100];
char resto[90000000];

int tamEntrada;
int tamY;
int tamResto;

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
    int tamSaida = tamEntrada - 2;
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
	memcpy(entrada, saida, tamSaida+1);

	tamEntrada = tamSaida;
}

void OperarS()
{
    char a[600000];
    char b[600000];
    char c[600000];
    int tamA, tamB, tamC;
    int abreFecha = 0;
	int i = 1;
	int j = 0;
	int k = 0;
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
            j = i;
        }
        if(parte == 2)
        {
            tamB = qtd_carac;
            k = i;
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
}

void OperarK()
{
    char a[600000];
    char b[600000];
    int tamA, tamB;
    int abreFecha = 0;
	int i = 1;
	int j = 0;
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
            j = i;
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

    memcpy(entrada,saida,(tamA+tamResto)*sizeof(char));

    entrada[tamA+tamResto] = '\0';
    tamEntrada = tamA + tamResto;
}
int main()
{
    FILE *arq = fopen("string.in", "r");
    fscanf(arq,"%s",entrada);
    //printf("\n%s\n",entrada);

    tamEntrada = strlen(entrada);
    tamY = strlen(Y);

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
