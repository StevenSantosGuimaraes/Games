#include "./forca.h"

string palavra_secreta = "MELANCIA";

map<char, bool> chutou;
vector<char> chutes_errados;

int main(){
    system("clear");
    ler_arquivo();
    sortear_palavra();
    do{
        imprimir_palavra();
        imprimir_erros();
        novo_chute();
    }while(nao_acertou() && nao_enforcou());
    imprimir_encerrar();
}

bool letra_existe(char chute){
    for(char letra : palavra_secreta){
        if(chute == letra){
            return true;
        }
    }
    return false;
}

bool nao_acertou(){
    for(char letra : palavra_secreta){
        if(!chutou[letra]){
            return true;
        }
    }
    return false;
}

bool nao_enforcou(){
    return chutes_errados.size() < 5;
}

void imprimir_palavra(){
    cout << "\nPalavra Secreta: ";
    for(char letra : palavra_secreta){
        if(chutou[letra]){
            cout << letra << " ";
        }else{
            cout << "_ ";
        }
    }
}

void imprimir_erros(){
    cout << endl << "Chutes Errados: ";
    for(char letra : chutes_errados){
        cout << letra << ", ";
    }
}

void imprimir_encerrar(){
    cout << endl << "Fim de jogo!" << endl;
    if(nao_acertou()){
        cout << "Nao fique triste, tente novamente!" << endl;
    }else{
        char opcao;
        cout << "Parabens, voce acertou a palavra secreta!" << endl;
        cout << "A palavra secreta era: " << palavra_secreta << endl;
        cout << "Deseja adicionar uma nova palavra ao dicionario? (S/N): ";
        cin >> opcao;
        if(opcao == 's' || opcao == 'S'){
            adicionar_palavra();
        }
    }
}

void novo_chute(){
    char chute;
    cout << endl << "Chute --> ";
    cin >> chute;
    chutou[chute] = true;
    if(letra_existe(chute)){
        system("clear");
        cout << "A letra: " << chute << " ESTAVA na palavra secreta.";
    }else{
        system("clear");
        cout << "A letra: " << chute << " NAO estava na palavra secreta.";
        chutes_errados.push_back(chute);
    }
}

vector<string> ler_arquivo(){
    int quantidade_palavras, i;
    ifstream arquivo;
    vector<string> palabras_arquivo;
    arquivo.open("./dicionario.txt");
    if(arquivo.is_open()){
        arquivo >> quantidade_palavras;
        for(i = 0; i < quantidade_palavras; i++){
            string palavra_lida;
            arquivo >> palavra_lida;
            palabras_arquivo.push_back(palavra_lida);
        }
        arquivo.close();
        return palabras_arquivo;
    }else{
        cout << "Nao foi possivel acessar o dicionario com palavras secretas. Verifique se o arquivo '.txt' foi excluido, renomeado ou realocado." << endl;
        exit(0);
    }
}

void sortear_palavra(){
    vector<string> palavras = ler_arquivo();
    srand(time(NULL));
    int indice_sorteado = rand() % palavras.size();
    palavra_secreta = palavras[indice_sorteado];
}

void adicionar_palavra(){
    string nova_palavra;
    cout << "Informe a nova palavra com LETRAS MAIUSCULAS: ";
    cin >> nova_palavra;
    vector<string> lista_palavras = ler_arquivo();
    lista_palavras.push_back(nova_palavra);
    salvar_dicionario(lista_palavras);
    cout << "Nova palavra: " << nova_palavra << " foi adicionar com sucesso." << endl;
}

void salvar_dicionario(vector<string> nova_lista){
    ofstream arquivo;
    arquivo.open("./dicionario.txt");
    if(arquivo.is_open()){
        arquivo << nova_lista.size() << endl;
        for(string palavra : nova_lista){
            arquivo << palavra << endl;
        }
        arquivo.close();
    }else{
        cout << "Arquivo contendo as palavras em '.txt' nao foi encontrado. Verifique o ocorrido. (Nome do arquivo necessario: 'dicionario.txt').";
        exit(0);
    }
}
