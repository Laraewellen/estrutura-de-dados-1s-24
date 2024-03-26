#include <stdim.h>
#include <stdlib.h>
#include <stdbool.h> //bibloteca para adc a função booleana que vamos usar para saber se é 0 ou 1(verdadeiro ou falso)

bool P(int num) { //função para ver se é primo
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false; 
        }
    }
    return true; 
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <numero>\n", argv[0]);
        return 1;
    }

    int numero = atoi(argv[1]);

    if (P(numero)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
