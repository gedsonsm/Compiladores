#!/bin/bash

gcc Codigos/CriaEntrada_KS.c -o Cria
#gcc Codigos/CriaEntrada_Turner.c -o Cria
./Cria 1000
gcc -c Codigos/main.c
gcc -c Codigos/OperacoesComGrafo.c
gcc -c Codigos/OperacoesComPilha.c
gcc -o main main.o OperacoesComPilha.o OperacoesComGrafo.o 
wait
time ./main
rm main main.o OperacoesComPilha.o OperacoesComGrafo.o Cria # string.in



