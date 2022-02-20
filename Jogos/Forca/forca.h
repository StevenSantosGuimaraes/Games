#ifndef FORCA_H
#define FORCA_H

#define TAMANHO_MAXIMO_PALAVRA 46 // A maior palavra da lingua portuguesa possui 46 letras (PNEUMOULTRAMICROSCOPICOSSILICOVULCANOCONIOTICO).
#define TAMANHO_MAXIMO_ALFABETO 26

void apresentacao();
void palavraAleatoria();
void inserirPalavraDicionario();
void imprimirForca();
void novaLetra();
int contarLetrasErradas();
int verificarVenceu();
bool verificarPerdeu();
int varrerPalavra(char letra);
int imprimirPalavra(char letra);

#endif