#ifndef FORCA_H
#define FORCA_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

bool letra_existe(char letra);
bool nao_acertou();
bool nao_enforcou();
void imprimir_palavra();
void imprimir_erros();
void imprimir_encerrar();
void novo_chute();
vector<string> ler_arquivo();
void sortear_palavra();
void adicionar_palavra();
void salvar_dicionario(vector<string> nova_lista);

#endif