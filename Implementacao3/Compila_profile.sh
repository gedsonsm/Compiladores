#!/bin/bash

gcc -c Codigos/CriaEntrada.c
gcc -o Cria CriaEntrada.o
./Cria 1000
gcc -c Codigos/main.c
gcc -c Codigos/operacoesComLista.c
gcc -c Codigos/reducoes.c
gcc -pg -o main main.o operacoesComLista.o reducoes.o 
wait 
time ./main
wait
gprof main gmon.out > log.txt
wait
rm main main.o operacoesComLista.o reducoes.o Cria CriaEntrada.o gmon.out # string.in
