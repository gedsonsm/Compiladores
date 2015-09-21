#!/bin/bash

gcc -c Codigos/CriaEntrada.c
gcc -o Cria CriaEntrada.o
./Cria 200
gcc -c Codigos/main.c
gcc -c Codigos/operacoesComStr.c
gcc -c Codigos/reducoes.c
gcc -O4 -o main main.o operacoesComStr.o reducoes.o
wait 
time ./main
rm main main.o Cria CriaEntrada.o operacoesComStr.o reducoes.o
