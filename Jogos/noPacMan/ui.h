#ifndef _UI_H_
#define _UI_H_

#include "mapa.h"

#define LINHA_DESENHO 4
#define COLUNA_DESENHO 7

void imprimirMapa(MAPA* m);
void imprimeParte(char desenho[LINHA_DESENHO][COLUNA_DESENHO], int parte);

#endif
