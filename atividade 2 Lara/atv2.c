#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Função para verificar se um número é primo
bool ehPrimo(int num) {
    if (num <= 1) {
        return false; // Números menores ou iguais a 1 não são primos
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false; // Se o número for divisível por algum número até a raiz quadrada dele, não é primo
        }
    }
    return true; // Se não foi encontrado nenhum divisor até a raiz quadrada do número, então é primo
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <numero>\n", argv[0]);
        return 1;
    }

    int numero = atoi(argv[1]);

    if (ehPrimo(numero)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
