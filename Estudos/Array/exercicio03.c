/*
    Ajuste o algoritmo do exercicio anterior, solicitando ao usuário:
    1) Quantos alunos há na aluno.
    2) Quantas serão as notas dos alunos.
    3) Qual o valor da média aritmética para aprovação.
    OBS: Ao final o programa deve apresentar relatório com os nomes dos alunos aprovados com sua respectiva média, média de idade dos alunos reprovados e quantos aprovados são do sexo masculino e quantos são do sexo feminino (em percentual).
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM_NOME 16
#define NOTA_CORTE 6.0

typedef struct{
    float *nota;
} Notas;

typedef struct{
    char nome[TAM_NOME];
    char sexo;
    int idade;
    Notas *notaPtr;
} Aluno;

// malloc
// calloc
// realloc
// free
// sizeof

int main(){

    int quantidade_notas, quantidade_alunos, a, n;
    Aluno *aluno;

    system("clear");

    printf("Informe a quantidade de alunos: ");
    scanf(" %d", &quantidade_alunos);
    printf("Informe a quantidade de notas: ");
    scanf(" %d", &quantidade_notas);
    
    aluno = malloc(quantidade_alunos * sizeof(Aluno));
    aluno->notaPtr = malloc(quantidade_notas * sizeof(Notas));

    // Ler
    for(a = 0; a < quantidade_alunos; a++){
        printf("\nInforme o nome do %d. aluno: ", a + 1);
        scanf(" %s", &aluno[a].nome);
        printf("Informe o sexo (M/F) do aluno %s: ", aluno[a].nome);
        scanf(" %c", &aluno[a].sexo);
        printf("Informe a idade de %s: ", aluno[a].nome);
        scanf(" %d", &aluno[a].idade);
        for(n = 0; n < quantidade_notas; n++){
            printf("Informe a %d. nota de %s: ", n + 1, aluno[a].nome);
            scanf(" %f", &aluno[a].notaPtr->nota[n]);
        }
    }

    // Imprimir
    for(a = 0; a < quantidade_alunos; a++){
        printf("\nAluno -> %d", a);
        printf("Nome: %s", a, aluno[a].nome);
        printf("Sexo: %c", a, aluno[a].sexo);
        printf("Idade: %d", a, aluno[a].idade);
        for(n = 0; n < quantidade_notas; n++){
            printf("\n%d. nota: %.2f", n + 1, aluno->notaPtr->nota[n]);
        }
        printf("\n");
    }

    // Liberar
    free(aluno);
}

// Informacoes do terminal:
/*
Informe a quantidade de alunos: 2
Informe a quantidade de notas: 3

Informe o nome do 1. aluno: steven
Informe o sexo (M/F) do aluno steven: m
Informe a idade de steven: 28
Informe a 1. nota de steven: 6.25
Informe a 2. nota de steven: 7.25
Informe a 3. nota de steven: 8.25

Informe o nome do 2. aluno: clara
Informe o sexo (M/F) do aluno clara: f
Informe a idade de clara: 26
Informe a 1. nota de clara: Segmentation fault
*/
