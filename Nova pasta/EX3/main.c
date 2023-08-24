#include <stdio.h>
#include <math.h>
#include <conio.h>

struct Ponto {
    float x;
    float y;
};

float calcularDistancia(struct Ponto pontoA, struct Ponto pontoB) {
    return sqrt(pow(pontoB.x - pontoA.x, 2) + pow(pontoB.y - pontoA.y, 2));
}

float calcularInclinacao(struct Ponto pontoA, struct Ponto pontoB) {
    if (pontoB.x - pontoA.x != 0) {
        return (pontoB.y - pontoA.y) / (pontoB.x - pontoA.x);
    } else {
        return INFINITY;  
    }
}

int main() {
    struct Ponto ponto1, ponto2;

    printf("---------------------------CÁLCULOS COM PONTOS----------------------------");
    printf("\nInforme as coordenadas do Ponto 1:\n");
    printf("Coordenada x: ");
    scanf("%f", &ponto1.x);
    printf("Coordenada y: ");
    scanf("%f", &ponto1.y);

    printf("\nInforme as coordenadas do Ponto 2:\n");
    printf("Coordenada x: ");
    scanf("%f", &ponto2.x);
    printf("Coordenada y: ");
    scanf("%f", &ponto2.y);

    printf("----------------------Resultados-------------------------------------");
    printf("\nDistância entre os pontos: %.2f", calcularDistancia(ponto1, ponto2));

    float inclinacao = calcularInclinacao(ponto1, ponto2);
    if (isinf(inclinacao)) {
        printf("\nA inclinação é infinita (reta vertical).");
    } else {
        printf("\nInclinação da reta: %.2f", inclinacao);
    }

    getch();
    return 0;
}
