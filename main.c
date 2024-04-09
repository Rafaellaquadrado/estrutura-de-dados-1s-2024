#include <stdio.h>
#include <stdlib.h>


int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s arquivo_entrada\n", argv[0]);
        return 1;
    }

    FILE *arquivo_entrada = fopen(argv[1], "r");
    if (arquivo_entrada == NULL) {
        printf("Não foi possível abrir o arquivo de entrada.\n");
        return 1;
    }

    int *numeros = NULL;
    int tamanho = 0;
    int capacidade = 10; 

    numeros = (int *)malloc(capacidade * sizeof(int));
    if (numeros == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    
    int num;
    while (fscanf(arquivo_entrada, "%d", &num) == 1) {
        if (tamanho >= capacidade) {
            capacidade *= 2; 
            numeros = (int *)realloc(numeros, capacidade * sizeof(int));
            if (numeros == NULL) {
                printf("Erro de realocação de memória.\n");
                return 1;
            }
        }
        numeros[tamanho++] = num;
    }

    fclose(arquivo_entrada);

   
    qsort(numeros, tamanho, sizeof(int), comparar);

    FILE *arquivo_saida = fopen("saida.txt", "w");
    if (arquivo_saida == NULL) {
        printf("Não foi possível abrir o arquivo de saída.\n");
        return 1;
    }

    
    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo_saida, "%d\n", numeros[i]);
    }

    fclose(arquivo_saida);
    free(numeros);

    printf("Arquivo de saída gerado com sucesso.\n");

    return 0;
}