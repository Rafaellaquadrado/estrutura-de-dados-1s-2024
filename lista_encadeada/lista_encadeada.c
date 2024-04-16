#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

No* no(char valor, No* proximo_no){
    No* no = malloc(sizeof(No));
    no->valor = valor;
    no->proximo_no = proximo_no;
    return no;
}