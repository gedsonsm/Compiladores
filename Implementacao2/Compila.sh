#!/bin/bash

#gcc Codigos/CriaEntrada_KS.c -o Cria
gcc Codigos/CriaEntrada_Turner.c -o Cria
./Cria 1000
gcc -c Codigos/main.c
gcc -c Codigos/operacoesComStr.c
gcc -c Codigos/reducoes.c
gcc -O4 -o main main.o operacoesComStr.o reducoes.o
wait 
time ./main
wait
rm main main.o Cria operacoesComStr.o reducoes.o string.in































#define MAX(a,b) (a)>(b)?(a):(b)

