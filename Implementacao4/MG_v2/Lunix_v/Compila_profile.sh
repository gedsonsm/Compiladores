#!/bin/bash

gcc Codigos/CriaEntrada_KS.c -o Cria
#gcc Codigos/CriaEntrada_Turner.c -o Cria
./Cria 1000
gcc -c Codigos/main.c
gcc -c Codigos/OperacoesComGrafo.c
gcc -c Codigos/OperacoesComPilha.c
gcc -pg main main.o OperacoesComPilha.o OperacoesComGrafo.o 
wait 
time ./main
wait
gprof main gmon.out > log.txt
wait
rm main main.o OperacoesComPilha.o OperacoesComGrafo.o Cria gmon.out # string.in
