#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

    int a = 2;
    int b = a;
    int *p = &a; //declarando ponteiro, p aponta para a variável a

    printf("a = %d \t b = %d\n", a, b);
    printf("&a = %p \t &b = %p\n", &a, &b);

    b = 3;
    printf(" a= %d b = %d\n", a, b);
    
    a = 4;
    printf(" a= %d b = %d\n", a, b);

    printf("&p = %p \t p = %p  \t *p = %d\n", &p, p, *p); //(p também é uma váriavel) (*p usa o endereço de memoria que o p ta guardando)

    *p = 5;
    printf(" a= %d b = %d\n", a, b);

    p = malloc(sizeof(int)*5); //alocação de memória 
    p[0] = 3;
    p[1] = 55;

     printf("&p = %p \t p = %p  \t *p = %d\n", &p, &p[1], p[1]);

    exit (0);
}