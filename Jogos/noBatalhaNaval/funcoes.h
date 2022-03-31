#ifndef FUNCOES_H
#define FUNCOES_H

#include "principal.h"

#define TAMANHO_CAMPO 10

void limpar_tela();
void jogar();
void iniciar_campo(char campo[TAMANHO_CAMPO][TAMANHO_CAMPO], char mascara[TAMANHO_CAMPO][TAMANHO_CAMPO]);
void imprimir_matriz(char matriz[TAMANHO_CAMPO][TAMANHO_CAMPO]);
void posicionar_barcos(char matriz[TAMANHO_CAMPO][TAMANHO_CAMPO]);
void verificar_disparo(char matriz[TAMANHO_CAMPO][TAMANHO_CAMPO], int linha_chute, int coluna_chute, int *pontos);

#endif
