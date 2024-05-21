#include <stdio.h>
#include <stdlib.h>

typedef struct{
    double x;
    double y;
} Ponto;

void regressaoLinear(Ponto *pontos, int n) {
    double soma_X = 0.0, soma_Y = 0.0;
    double soma_XY = 0.0, soma_XQuadrado = 0.0;
    double media_X, media_Y;

    for (int i = 0; i < n; i++) {
        soma_X += pontos[i].x;
        soma_Y += pontos[i].y;
        soma_XY += pontos[i].x * pontos[i].y;
        soma_XQuadrado += pontos[i].x * pontos[i].x;
    }

    media_X = soma_X / n;
    media_Y = soma_Y / n;

    
    double inclinacao = ((n * soma_XY) - (soma_X * soma_Y)) / ((n * soma_XQuadrado) - (soma_X * soma_X));

    double interceptacao = media_Y - inclinacao * media_X;

    printf("Inclinação (Coeficiente Angular): %lf\n", inclinacao);
    printf("Interceptação (Coeficiente Linear): %lf\n", interceptacao);

    printf("Equação da regressão linear: y = %.2lfx + %.2lf\n", inclinacao, interceptacao);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <dados.csv>\n", argv[0]);
        exit(1);
    }

    FILE *arquivo = fopen(argv[1], "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", argv[1]);
        exit(1);
    }

    int num_pontos = 0;
    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        num_pontos++;
    }

    Ponto *pontos = (Ponto *)malloc(num_pontos * sizeof(Ponto));
    if (pontos == NULL) {
        printf("Erro ao alocar memória\n");
        fclose(arquivo);
        exit(1);
    }

    fseek(arquivo, 0, SEEK_SET);

    for (int i = 0; i < num_pontos; i++) {
        fscanf(arquivo, "%lf,%lf", &pontos[i].x, &pontos[i].y);
    }
  
    fclose(arquivo);

    regressaoLinear(pontos, num_pontos);

    free(pontos);

    exit(0);
}