#!/bin/bash

#gcc -c Codigos/CriaEntrada.c
#gcc -o Cria CriaEntrada.o
#./Cria 1000
gcc -c main.c
gcc -c operacoesComLista.c
#gcc -c operacoesComStr.c
gcc -c reducoes.c
gcc -O4 -o main main.o operacoesComLista.o reducoes.o #operacoesComStr.o reducoes.o
wait 
time ./main
rm main main.o operacoesComLista.o reducoes.o #Cria CriaEntrada.o operacoesComStr.o reducoes.o string.in
