#!/bin/bash

gcc -c Codigos/CriaEntrada.c
gcc -o Cria CriaEntrada.o
./Cria 1000
gcc -c Codigos/main.c
gcc -c Codigos/operacoesComStr.c
gcc -c Codigos/reducoes.c
gcc -o main main.o operacoesComStr.o reducoes.o
rm main.o Cria CriaEntrada.o operacoesComStr.o reducoes.o
