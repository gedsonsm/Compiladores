#!/bin/bash

#gcc Codigos/CriaEntrada_KS.c -o Cria
gcc Codigos/CriaEntrada_Turner.c -o Cria
./Cria 1000
gcc Codigos/main.c -O4 -o main
wait
time ./main
rm main Cria # string.in



