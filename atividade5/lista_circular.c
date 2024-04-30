#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

void inserir_no(No** H, char valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;

    if (*H == NULL) {
        novo_no->proximo = novo_no;
        *H = novo_no;
    } else {
        novo_no->proximo = (*H)->proximo;
        (*H)->proximo = novo_no;
    }
}

void imprimir_lista(No* H) {
    if (H == NULL) {
        printf("Lista vazia");
        return;
    }

    No* atual = H;
    do {
        printf("%c ", atual->valor);
        atual = atual->proximo;
    } while (atual != H);
}

void remover_no(No** H, char valor) {
    if (*H == NULL) return;

    No* atual = *H;
    No* anterior = NULL;

    while (atual->valor != valor && atual->proximo != *H) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual->valor == valor) {
        if (anterior != NULL)
            anterior->proximo = atual->proximo;
        else
            *H = atual->proximo;
        
        free(atual);
    }
}

void liberar_lista(No** H) {
    if (*H == NULL) return;

    No* atual = *H;
    No* proximo;

    do {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    } while (atual != *H);

    *H = NULL;
}