#ifndef REDUCOES_H
#define REDUCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operacoesComLista.h"

struct Lista S(struct Lista *pLista, int *parou);
struct Lista K(struct Lista *pLista, int *parou);
struct Lista I(struct Lista *pLista, int *parou);
struct Lista B(struct Lista *pLista, int *parou);
struct Lista C(struct Lista *pLista, int *parou);
struct Lista SH(struct Lista *pLista, int *parou);
struct Lista BH(struct Lista *pLista, int *parou);
struct Lista CH(struct Lista *pLista, int *parou);

#endif
