#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int qtd_n = argc -1;   //usando o -1 pois o argc conta o nome do programa como um número
    int soma_n = 0;
    float med = 0;
    int menor = atoi(argv[1]);
    int maior = atoi(argv[1]);

    int vt_n[qtd_n]; //vetor e quantidade de n

    if(argc <=1){
        printf("Erro!!!!");
        return 1;
    }

    for(int i=1; i <= qtd_n; i++){
        int n=atoi(argv[i]);
        vt_n[i-1] = n; //copiar os valores doa agrv (menos 1 pois o argv tem 1 numero a mais)
        soma_n += n;

        if(menor > n){
            menor = n; // se for menor o meu n passa a ser o menor numero
        }

        if (n > maior){ // se for maior o meu n passa a ser o maior numero
            maior = n;
        }

    }
    
    med = (float) soma_n/qtd_n;  //dizer pro compilador olhar para soma como float

    printf("Quantidade de numeros recebidos: %d\n", qtd_n);

    printf("Valor dos numeros: %.2f\n", med);

    printf("Menor numero: %d\n", menor);

    printf("Maior numero: %d\n", maior);

    for(int i =0; i < qtd_n-1; i++){ //começa na primeira posição, compara todo mundo e vai pro proximo
    for(int j= i; j < qtd_n; j++){
        if(vt_n[i] > vt_n[j]){
            int aux = vt_n[j]; //recebe o valor da posição j
            vt_n[j] = vt_n[i];
            vt_n[i] = aux; //recebe o valor que ta em n
        }
    }

    }

    for(int i =0; i < qtd_n; i++){
        printf("%d", vt_n[i]); //é só para a mostrar a copia
    }

    exit (0);
}