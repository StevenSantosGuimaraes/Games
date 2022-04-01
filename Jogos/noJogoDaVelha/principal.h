#include <iostream>
#include <string>

#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#define TAM_MATRIZ 3

#include "telas.h"
#include "funcoes.h"

using namespace std;

void iniciar_jogo(char matriz[TAM_MATRIZ][TAM_MATRIZ]);
void imprimir_matriz(char matriz[TAM_MATRIZ][TAM_MATRIZ]);
bool marcar_jogada(int linha, int coluna, int rodada, char matriz[TAM_MATRIZ][TAM_MATRIZ]);
bool verificar_vencedor(char matriz[TAM_MATRIZ][TAM_MATRIZ]);
void jogar();

#endif
