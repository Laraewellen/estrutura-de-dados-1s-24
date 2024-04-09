#include <stdio.h> 
#include <stdlib.h>
#include "bubble_sort.h"

int main(int argc, char* argv[]){
    
    FILE *fp = fopen(argv[1], "r"); //ponteiro para arqv

    if(fp == NULL){
        printf("Erro ao abrir %s\n", argv[1]);
        exit(1);
    }
    int i;
    int qtd = 0;
    int *vetor;
    while( fscanf(fp, "%d\n", &i) != EOF){ //leia um numero inteiro, guarda o arqv e no final para 
    qtd++;
    } 
    vetor = malloc(sizeof(int)*qtd); //guardar valores

    rewind(fp); //volta o arqv pra posição 0
    i=0;
    while( fscanf(fp, "%d\n", &vetor[i]) != EOF){ //armazenar numeros dentro do vetor
    i++;
    } 

    fclose(fp);

    bubble_sort(vetor, qtd);

    FILE* arq_s = fopen("saida.txt", "w");
    if(arq_s == NULL){
        printf("erro");
        exit(1);
    }

    for (i = 0; i < qtd; i++){
        fprintf(arq_s, "%d", vetor[i]);
    }

    fclose(arq_s);

    exit(0);
}