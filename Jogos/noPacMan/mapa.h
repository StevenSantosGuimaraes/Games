struct mapa{
    int linhas, colunas;
    char** matriz;
};

struct posicao{
    int x, y;
};

typedef struct mapa MAPA;
typedef struct posicao POSICAO;

void alocarMapa(MAPA* m);
void carregarMapa(MAPA* m);
void liberarMapa(MAPA* m);
void imprimirMapa(MAPA* m);
void encontrarPersonagem(MAPA* m, POSICAO* p, char c);
