// Gerador para K e S
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numY = 200;
    printf("Numero de repeticoes de Y: ");
    scanf("%d", &numY);
    int i=0;
    char valordeY[1000] = "S'(C'BI(SII))I(B(C'BI(SII))I)";

    FILE *entradagerada;
    entradagerada = fopen ("string.in", "w");

    for(i = 0 ; i < numY-2 ; i++)
    {
        fputs(valordeY,entradagerada);
        fputs("((",entradagerada);
    }
        fputs(valordeY,entradagerada);
        fputs("((",entradagerada);
        fputs(valordeY,entradagerada); 
        fputs("(KK))K)",entradagerada);

    for(i = 0 ; i < numY-2 ; i++)
    {
        fputs(")K)",entradagerada);

    }

    return 0;
}
