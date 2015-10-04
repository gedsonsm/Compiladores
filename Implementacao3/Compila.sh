#!/bin/bash

gcc -c Codigos/CriaEntrada.c
gcc -o Cria CriaEntrada.o
./Cria 1000
gcc -c Codigos/main.c
gcc -c Codigos/operacoesComLista.c
gcc -c Codigos/reducoes.c
gcc -o main main.o operacoesComLista.o reducoes.o 
wait 
time ./main
rm main main.o operacoesComLista.o reducoes.o Cria CriaEntrada.o # string.in



