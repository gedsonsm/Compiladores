#!/bin/bash

#gcc Codigos/CriaEntrada_KS.c -o Cria
gcc Codigos/CriaEntrada_Turner.c -o Cria
./Cria 1000
gcc -O4 -c Codigos/main.c
gcc -O4 -c Codigos/OperacoesComGrafo.c
gcc -O4 -c Codigos/OperacoesComPilha.c
gcc -O4 -o main main.o OperacoesComPilha.o OperacoesComGrafo.o 
wait
time ./main
rm main main.o OperacoesComPilha.o OperacoesComGrafo.o Cria # string.in



