#!/bin/bash

gcc Codigos/CriaEntrada_KS.c -o Cria
#gcc Codigos/CriaEntrada_Turner.c -o Cria
./Cria 1000
gcc -c Codigos/main.c
gcc -c Codigos/operacoesComLista.c
gcc -c Codigos/reducoes.c
gcc -o main main.o operacoesComLista.o reducoes.o 
wait
time ./main
rm main main.o operacoesComLista.o reducoes.o Cria # string.in



