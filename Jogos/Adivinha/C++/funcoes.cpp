#include "funcoes.h"

int novo_chute(int tentativa){
    int chute;
    do{
        cout << "Tentativa " << tentativa + 1 << " - Informe seu chute: ";
        cin >> chute;
    }while(verificar_negativo(chute));
    return chute;
}

int verificar_negativo(int chute){
    int resposta;
    if(chute < 0){
        cout << "Voce informou um numero negativo, tente novamente informando um positivo!" << endl;
        resposta = 1;
    }else{
        return 0;
    }
    return resposta;
}

int verificar_chute(int chute, int nSecreto, int tentativa){
    int teste;
    if(chute == nSecreto){
        cout << "Parabens, voce acertou o numero secreto (" << nSecreto << ") em: " << tentativa + 1 << " tentativa(s)!" << endl;
        teste = 1;
    }else if(chute > nSecreto){
        cout << "Voce errou, o numero secreto e menor que: " << chute << "." << endl;
        teste = 0;
    }else if(chute < nSecreto){
        cout << "Voce errou, o numero secreto e maior que: " << chute << "." << endl;
        teste = 0;
    }
    return teste;
}
