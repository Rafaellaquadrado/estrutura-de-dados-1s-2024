#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

int main(int argc, char* argv[]){

    No* n1 = no("A", NULL);
    No* n2 = no("B", NULL);

    printf("n1 = %d \t n2 = %c", n1->valor, n2->valor);

    exit(0);
}