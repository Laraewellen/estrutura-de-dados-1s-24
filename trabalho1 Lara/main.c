#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "regressao.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Uso: %s arquivo.csv\n", argv[0]);
        return 1;
    }

    FILE *file = abrir_arquivo(argv[1]);
    if (file == NULL)
    {
        return 1;
    }

   
    int n = contar_registros(file);

    Ponto *pontos = alocar_pontos(n);
    if (pontos == NULL)
    {
        fclose(file);;
        return 1;
    }
    ler_pontos(file, pontos, n);


    regressao_linear(pontos, n);

    free(pontos);

    return 0;
}