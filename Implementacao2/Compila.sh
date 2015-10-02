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




#gcc −pg c o d i g o_ f o n t e . c −o p rog rama
#. / p rog rama
#g p r o f p rog rama gmon . o u t > l o g . t x t


#d e fi n e MAX( a , b ) ( a )>(b ) ? ( a ) : ( b )

