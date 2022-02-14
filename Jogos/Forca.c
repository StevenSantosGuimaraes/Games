#include <stdio.h>
#include <string.h>

int main(){
    char palavraSecreta[20], chutes[26];
    int acertou = 0, enforcou = 0, tentativas = 0;
    sprintf(palavraSecreta, "Morango"); // Problema -> Resolver entrada de caractere maiusculo e minusculo ao fim.
    do{
        char chute;
        for(int i = 0; i < strlen(palavraSecreta); i++){
            int achou = 0; // Verificar se a lista de letras já informadas, consta na lista de letras da palavra secreta.
            for(int j = 0; j < tentativas; j++){
                if(chutes[j] == palavraSecreta[i]){
                    achou = 1;
                    break;
                }
            }
            if(achou){
                printf("%c ", palavraSecreta[i]); // Exibir letra que consta já informada.
            }else{
                printf("_ "); // Suprimir letra ainda não encontrada.
            }
        }
        printf("\nInforme uma letra: ");
        scanf(" %c", &chute);
        chutes[tentativas] = chute; // Salvar letras já informadas.
        tentativas++; // Ponto para nível de dificuldade.
    }while(!acertou && !enforcou);
}
