#include <stdio.h>
#include <stdlib.h>
#include "Atv4.h"
#include <ctype.h>

int main(int argc, char *argv[])
{

    No *H = no('A', no('B', no('C', no('D', no('E', no('F', NULL))))));
    No *Hc = copiar_lista(H);
    char letra, resultado_busca;
    int posicao;

    imprimir_lista(H);
    printf("\n copia\n");
    imprimir_lista(Hc);

    // H->proximo_no->valor = 'X';
    // Hc->valor = 'U';

    printf("\n");
    imprimir_lista(H);
    printf("\n copia\n");
    imprimir_lista(Hc);

    liberar_lista(Hc);

    printf("\n qtd = %d\n", quantidade_nos(H));

    printf("\nDigite a Letra que deseja verificar?: ");
    scanf("%c", &letra);
    letra = toupper(letra);
    resultado_busca = lista_verificar_existencia(H, letra);

    if (resultado_busca)
    {
        printf("\nEncontrou");
    }
    else
    {
        printf("\nNao encontrado");
    }

    printf("\nOcorrencias: %d", lista_verificar_ocorrencias(H, letra));

    printf("\nLista inversa");
    lista_imprimir_inversa(H);
    printf("\n");

    printf("\nDigite a letra do novo no:");
    scanf(" %c", &letra);
    letra = toupper(letra);

    printf("\nDigite a posicao que deseja inserir essa letra:");
    scanf("%d", &posicao);

    No *novo_no = (No *)malloc(sizeof(No));
    novo_no->valor = letra;
    novo_no->proximo_no = NULL;

    printf("\n");
    lista_inserir_no_i(H, posicao, novo_no);
    imprimir_lista(H);

    printf("\nDigite a posicao que deseja remover da lista:");
    scanf("%d", &posicao);
    fflush(stdin);

    printf("\n");
    lista_remover_no_i(H, posicao);
    imprimir_lista(H);

    printf("\nDigite a Letra que deseja remover elementos iguais: ");
    scanf("%c", &letra);
    letra = toupper(letra);

    printf("\n");
    lista_remover_no(&H, letra);
    imprimir_lista(H);

    exit(0);
}