#!/bin/bash

gcc Codigos/CriaEntrada_KS.c -o Cria
#gcc Codigos/CriaEntrada_Turner.c -o Cria
./Cria 132
gcc -c Codigos/main.c
gcc -c Codigos/operacoesComStr.c
gcc -c Codigos/reducoes.c
gcc -O4 -o main main.o operacoesComStr.o reducoes.o
wait 
time ./main
rm main main.o Cria operacoesComStr.o reducoes.o
