#!/bin/bash

gcc Codigos/CriaEntrada_KS.c -o Cria
#gcc Codigos/CriaEntrada_Turner.c -o Cria
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
rm main main.o operacoesComLista.o reducoes.o Cria gmon.out # string.in
