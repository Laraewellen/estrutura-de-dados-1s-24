#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash_h"

int main(int argc, char* argv[]){

    char** tabela = tabela_hash();

    put("DF", "Brasilia", tabela);
    put("SE", "Aracaju", tabela);
    put("PB", "Joao Pessoa", tabela);

    printf("%s\n", get("PB", tabela));
    printf("%s\n", get("SE", tabela));
    printf("%s\n", get("DF", tabela));

    exit(0);
}