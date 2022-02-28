#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int tamanho_grafo, matriz[TAM][TAM];

int main(){
	int opcao;
	do{
		opcao = tela_1();
		switch(opcao){
			case 1:
				printf("Inicializando matriz...\n");
				printf("informe o tamanho do grafo: ");
				scanf(" %d", &tamanho_grafo);
				limparMatriz();
				printf("Matriz com %d vertices inicializada com sucesso!\n", tamanho_grafo);
				break;
			case 2:
				imprimirMatriz();
				break;
			case 3:	
				tela_2();
				break;
		}
	}while(opcao != 0);
	printf("Programa encerrado!\n\n");
}

int informaAdjacencia(int linha, int coluna){
	if(linha == coluna){
		printf("\nAntencao, nao e possivel informa que um laco em matrizes de adjacencias. Tente novamente!\n");
		return
	}
}

void imprimirMatriz(){
	int linha, coluna;
	printf("\n M.A. "); // matriz de adjacencia.
	for(linha = 1; linha <= tamanho_grafo; linha++){
		if(linha < 10){
			printf("|--0%d--", linha);
		}else{
			printf("|--%d--", linha);
		}
	}
	printf("|\n");
	for(linha = 1; linha <= tamanho_grafo; linha++){
		for(coluna = 1; coluna <= tamanho_grafo; coluna++){
			if(coluna == 1 && linha < 10){
				printf("  0%d--|", linha);
			}else if(coluna == 1){
				printf("  %d--|", linha);
			}
			if(linha == coluna){
				printf("  xx  |");
			}else if(matriz[linha][coluna] == 0){
				printf("      |"); // Criterio para facilitar a leitura.
			}else{
				if(matriz[linha][coluna] >= 0 && matriz[linha][coluna] <= 9){
					printf("   %d  |", matriz[linha][coluna]);
				}else if(matriz[linha][coluna] >= -9 && matriz[linha][coluna] < 0){
					printf("  %d  |", matriz[linha][coluna]);
				}else if(matriz[linha][coluna] < -9){
					printf(" %d  |", matriz[linha][coluna]);
				}else{
					printf("  %d  |", matriz[linha][coluna]);
				}
			}	
			if(coluna == tamanho_grafo){
				printf("\n");
			}
		}
	}
}

void limparMatriz(){
	int linha, coluna;
	for(linha = 0; linha <= tamanho_grafo; linha++){
		for(coluna = 1; coluna <= tamanho_grafo; coluna++){
			matriz[linha][coluna] = 0;
		}
	}
}

// -------- TELAS -------- //e

void tela_2(){
	int linha, coluna, valor, teste = 1;
	while(teste){
		printf("Informe o vertice e em seguida uma adjacencia:\n");
		scanf("%d %d", &linha, &coluna);
	}
	
	informaAdjacencia(linha, coluna);
	//matriz[linha][coluna] = valor;
}

int tela_1(){
	int resposta;
	printf("\n\n");
	printf("|==================================|\n");
	printf("|                                  |\n");
	printf("|  Informe a opcao desejada:       |\n");
	printf("|                                  |\n");
	printf("|  1) Iniciar a matriz;            |\n");
	printf("|  2) Imprimir a matriz;           |\n");
	printf("|  3) Informa vertices adjacentes; |\n");
	printf("|                                  |\n");
	printf("|  0) Encerrrar programa.          |\n");
	printf("|                                  |\n");
	printf("|==================================|\n==> ");
	scanf("%d", &resposta);
	return resposta;
}
