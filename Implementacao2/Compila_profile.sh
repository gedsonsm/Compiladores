#!/bin/bash

#gcc Codigos/CriaEntrada_KS.c -o Cria
gcc Codigos/CriaEntrada_Turner.c -o Cria
./Cria 1000
gcc -c Codigos/main.c
gcc -c Codigos/operacoesComStr.c
gcc -c Codigos/reducoes.c
gcc -pg -o main main.o operacoesComStr.o reducoes.o
wait 
time ./main
gprof main gmon.out > log.txt
wait
rm main main.o Cria operacoesComStr.o reducoes.o string.in gmon.out






























#define MAX(a,b) (a)>(b)?(a):(b)

