#include <stdio.h>
#include <stdlib.h>
#include "Atv4.h"
#include <ctype.h>

No *no(char valor, No *proximo_no)
{
    No *no = malloc(sizeof(No));
    no->valor = valor;
    no->proximo_no = proximo_no;
    return no;
}

void inserir_no(No *H, No *no)
{
    if (H != NULL)
    {
        if (H->proximo_no == NULL)
        {
            H->proximo_no = no;
        }
        else
        {
            inserir_no(H->proximo_no, no);
        }
    }
}

void imprimir_lista(No *H)
{
    if (H != NULL)
    {
        printf("%c ", H->valor);
        imprimir_lista(H->proximo_no);
    }
}

int quantidade_nos(No *H)
{
    if (H != NULL)
    {
        return 1 + quantidade_nos(H->proximo_no);
    }
    return 0;
}

int lista_verificar_existencia(No *L, char valor_busca)
{
    No *aux = L;
    while (aux != NULL)
    {
        if (aux->valor == valor_busca)
        {
            return 1;
        }
        aux = aux->proximo_no;
    }
    return 0;
}
int lista_verificar_ocorrencias(No *L, char valor_busca)
{
    No *aux = L;
    int contador = 0;
    while (aux != NULL)
    {
        if (aux->valor == valor_busca)
        {
            contador++;
        }
        aux = aux->proximo_no;
    }
    return contador;
}

No *copiar_lista(No *H)
{
    if (H != NULL)
    {
        return no(H->valor, copiar_lista(H->proximo_no));
    }
    return NULL;
}

void liberar_lista(No *H)
{
    if (H != NULL)
    {
        liberar_lista(H->proximo_no);
        free(H);
    }
}
void lista_imprimir_inversa(No *L)
{
    if (L != NULL)
    {
        lista_imprimir_inversa(L->proximo_no);
        printf("%c ", L->valor);
    }
}
void lista_inserir_no_i(No *L, int i, No *novo_no)
{
    if (L == NULL || i == 0)
    {
        novo_no->proximo_no = L;
        L = novo_no;
    }
    else
    {
        No *aux = L;
        for (int j = 0; j < i - 1 && aux->proximo_no != NULL; j++)
        {
            aux = aux->proximo_no;
        }
        novo_no->proximo_no = aux->proximo_no;
        aux->proximo_no = novo_no;
    }
}
void lista_remover_no_i(No *L, int i)
{
    if (L == NULL)
    {
        printf("Lista vazia. Nada a ser removido.\n");
        return;
    }

    if (i == 0)
    {
        No *temp = L;
        L = L->proximo_no;
        free(temp);
        return;
    }

    No *anterior = L;
    No *atual = L->proximo_no;
    for (int j = 1; atual != NULL && j < i; j++)
    {
        anterior = atual;
        atual = atual->proximo_no;
    }

    if (atual == NULL)
    {
        printf("Posição não encontrada na lista.\n");
        return;
    }

    anterior->proximo_no = atual->proximo_no;
    free(atual);
}

void lista_remover_no(No **L, char valor_busca)
{
    No *atual = *L;
    No *anterior = NULL;

    while (atual != NULL)
    {
        if (atual->valor == valor_busca)
        {
            if (anterior == NULL)
            {
                *L = atual->proximo_no;
            }
            else
            {
                anterior->proximo_no = atual->proximo_no;
            }
            No *temp = atual;
            atual = atual->proximo_no;
            free(temp);
        }
        else
        {
            anterior = atual;
            atual = atual->proximo_no;
        }
    }
}