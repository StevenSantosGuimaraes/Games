/*
    Escreva um algoritmo que solicite ao usuário o tamanho de uma amostra, e apresente:
    1) Listar os elementos pares;
    2) Listar os elementos impares;
    3) Informa o maior valor da amostra;
    4) Informa o menor valor da amostra;
    5) Média aritmética da amostra.
    OBS: Utilizar um vetores para armazenar os elementos pares e impares.
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 100

void imprimir_vetor(int *vetor, int tamanho){
    int i;
    printf("{");
    for(i = 0; i < tamanho; i++){
        printf("%d", vetor[i]);
        if(i + 1 < tamanho){
            printf(", ");
        }else{
            printf("}");
        }
    }
}

int main(){
    int tamanho, i, menor_valor, maior_valor;
    int valor, vetor_impares[TAM], vetor_pares[TAM], quantidade_impares, quantidade_pares;
    float total;
    printf("Informe o tamanho da amostra: ");
    scanf("%d", &tamanho);
    for(i = 0; i < tamanho; i++){
        printf("Informe o %d. elemento: ", i + 1);
        scanf(" %d", &valor);
        if(i == 0){
            menor_valor = valor;
            maior_valor = valor;
        }else if(valor > maior_valor){
            maior_valor = valor;
        }else if(valor < menor_valor){
            menor_valor = valor;
        }
        if(valor % 2 == 0){
            vetor_pares[quantidade_pares] = valor;
            quantidade_pares++;
        }else if(valor % 2 != 0){
            vetor_impares[quantidade_impares] = valor;
            quantidade_impares++;
        }
        total += valor;
    }
    printf("\nLista de elementos pares: ");
    imprimir_vetor(vetor_pares, quantidade_pares);
    printf(";\nLista de elementos impares: ");
    imprimir_vetor(vetor_impares, quantidade_impares);
    printf(";\nMaior valor da amostra: %d;", maior_valor);
    printf("\nMenor valor da amostra: %d;", menor_valor);
    printf("\nMedia dos valores da amostra: %.2f.", total / tamanho);
}
