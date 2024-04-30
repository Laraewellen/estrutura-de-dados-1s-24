#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "regressao.h"


FILE *abrir_arquivo(const char *nome_arquivo) {
    FILE *file = fopen(nome_arquivo, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    }
    return file;
}


int contar_registros(FILE *file) {
    int n = 0;
    char linha[100];
    while (fgets(linha, sizeof(linha), file) != NULL) {
        n++;
    }
    rewind(file);
    return n;
}


Ponto *alocar_pontos(int n) {
    Ponto *pontos = malloc(n * sizeof(Ponto));
    if (pontos == NULL) {
        printf("Erro de alocacao de memoria.\n");
    }
    return pontos;
}


void ler_pontos(FILE *file, Ponto *pontos, int n) {
    char linha[100];
    int i = 0;
    while (fgets(linha, sizeof(linha), file) != NULL) {
        sscanf(linha, "%d,%f", &pontos[i].x, &pontos[i].y);
        i++;
    }
}


void regressao_linear(Ponto *pontos, int n) {
    int i;
    float soma_x = 0, soma_y = 0, soma_xy = 0, soma_x2 = 0;

    for (i = 0; i < n; i++) {
        soma_x += pontos[i].x;
        soma_y += pontos[i].y;
        soma_xy += pontos[i].x * pontos[i].y;
        soma_x2 += pontos[i].x * pontos[i].x;
    }

    float media_x = soma_x / n;
    float media_y = soma_y / n;

    float inclinacao = (soma_xy - n * media_x * media_y) / (soma_x2 - n * media_x * media_x);
    float intercepcao = media_y - inclinacao * media_x;
    intercepcao = ceil(intercepcao);
    printf("Equacao da regressao linear: y = %.1fx + %.f\n", inclinacao, intercepcao);
}
