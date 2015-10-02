#include "operacoesComStr.h"


/*Retira todos os parênteses iniciais, deixando na 1ª posição do vetor sempre um operador*/
void tirarParenteses(char *entrada, char* saida, int *tamanhoEntrada)
{
    int contgeral = 1, parenteses =1, abreFecha, ini = 0, fin, i;
    while(1)
    {
        if(entrada[contgeral]=='(')
            parenteses++;
        else
        {
            fin = parenteses;
            for(i = 0; i < parenteses; i++)//Enquanto houver parênteses na 1ª posição
            {
                //Busca parênteses correspondentes
                abreFecha = 1;
                while(abreFecha != 0)
                {
                    switch(entrada[contgeral])
                    {
                        case '(':
                            abreFecha++;
                        break;

                        case ')':
                            abreFecha--;
                        break;
                    }
                    contgeral++;
                }
                memcpy(&saida[ini],&entrada[fin],(contgeral-fin-1)*sizeof(char)); //copia conteúdo dentro do parênteses p/ a saída
                ini = ini + (contgeral-fin-1);
                fin = contgeral;
            }
            memcpy(&saida[ini],&entrada[fin],(*tamanhoEntrada-fin)*sizeof(char)); //copia o 'resto' junto c/ a saída
            saida[ini+(*tamanhoEntrada-fin)] = '\0';
            break;
        }
        contgeral++;

    }
    *tamanhoEntrada = *tamanhoEntrada - 2*parenteses; //Atualiza o tamanho da nova entrada
}

/*Dependendo de quantos operandos acha o tamanho dos mesmos*/
int SeparaTermos(char *entrada, int *tamanho1, int *tamanho2, int *tamanho3, int *tamanho4, int *tamanhoResto,int *tamanhoEntrada, int loop)
{
    int abreFecha = 0;
    int i = 1;
    int parte = 1;
    int qtd_carac = 0;
    while(parte <= loop)//Para cada operando
    {
        qtd_carac = 0;
        switch(entrada[i])
        {
            case '(': //Se o operando é um conjunto de caracteres
                qtd_carac++;
                i++;
                while(abreFecha != -1)
                {
                    switch(entrada[i])
                    {
                        case '(':
                            abreFecha++;
                        break;

                        case ')':
                            abreFecha--;
                        break;
                    }
                    i++;
                    qtd_carac++;
                }
                i--;
                abreFecha = 0;
            break;

            case '\0': //Se não há operandos suficientes
                return 1;
            break;

            default: //Se o operando é apenas um caracter
                qtd_carac++;
        }

        switch(parte)
        {
            case 1: //Se for o 1º operando
                *tamanho1 = qtd_carac;
            break;

            case 2: //Se for o 2º operando
                *tamanho2 = qtd_carac;
            break;

            case 3: //Se for o 3º operando, caso haja
                *tamanho3 = qtd_carac;
            break;

            case 4: //Se for o 4º operando, caso haja
                *tamanho4 = qtd_carac;
            break;
        }
        i++;
        parte++;
    }
    *tamanhoResto = (*tamanhoEntrada-i);

    return 0;
}
