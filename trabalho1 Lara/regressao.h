typedef struct {
    int x;
    float y;
} Ponto;

void regressao_linear(Ponto *pontos, int n);
FILE *abrir_arquivo(const char *nome_arquivo);
int contar_registros(FILE *file);
Ponto *alocar_pontos(int n);
void ler_pontos(FILE *file, Ponto *pontos, int n);
