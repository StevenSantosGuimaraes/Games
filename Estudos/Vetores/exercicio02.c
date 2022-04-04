/*
    Escreva um algoritmo que solicite:
    1) Nome;
    2) Sexo (M/F);
    3) Idade;
    4) Três notas de um aluno.
    OBS: Ao final o algoritmo deve informar se o aluno esta aprovado ou reprovado (nota mínima: 6,0).
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM_NOME 16
#define QTD_NOTAS 3
#define NOTA_MINIMA 6.0

typedef	struct{
    char nome[TAM_NOME];
    char sexo;
    char *situacao;
    int idade;
    float nota[QTD_NOTAS];
    float total;
    float media;
} Aluno;

int main(){
    int i;
    Aluno aluno;
    system("clear");
    printf("Informe o nome do aluno: ");
    scanf(" %s", &aluno.nome);
    printf("Informe o sexo do aluno %s (M/F/O): ", aluno.nome);
    scanf(" %s", &aluno.sexo);
    printf("Informe a idade do aluno %s: ", aluno.nome);
    scanf(" %d", &aluno.idade);
    for(i = 0; i < QTD_NOTAS; i++){
        printf("Informe a %d. nota do aluno %s: ", i + 1, aluno.nome);
        scanf(" %f", &aluno.nota[i]);
        aluno.total += aluno.nota[i];
    }
    aluno.media = aluno.total / QTD_NOTAS;
    if(aluno.media >= NOTA_MINIMA){
        aluno.situacao = "APROVADO";
    }else{
        aluno.situacao = "REPROVADO";
    }
    printf("O aluno %s do sexo %c com %d anos esta %s com media %.2f pontos.", aluno.nome, aluno.sexo, aluno.idade, aluno.situacao, aluno.media);
}
