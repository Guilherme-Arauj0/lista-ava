#include <stdio.h>

struct Moeda {
    float dolares;
    float euros;
};

void converterDolaresParaEuros(struct Moeda *moeda, float taxa) {
    moeda->euros = moeda->dolares * taxa;
}

void converterEurosParaDolares(struct Moeda *moeda, float taxa) {
    moeda->dolares = moeda->euros / taxa;
}

int main() {
    struct Moeda moeda;
    float taxaDolarParaEuro = 0.85; 

    printf("Digite um valor em dólares: ");
    scanf("%f", &moeda.dolares);

    printf("\nEscolha a operação:\n");
    printf("1 - Converter de dólares para euros\n");
    printf("2 - Converter de euros para dólares\n");
    int escolha;
    scanf("%d", &escolha);

    if (escolha == 1) {
        converterDolaresParaEuros(&moeda, taxaDolarParaEuro);
        printf("Valor convertido para euros: %.2f euros\n", moeda.euros);
    } else if (escolha == 2) {
        printf("Digite um valor em euros: ");
        scanf("%f", &moeda.euros);
        converterEurosParaDolares(&moeda, taxaDolarParaEuro);
        printf("Valor convertido para dólares: %.2f dólares\n", moeda.dolares);
    } else {
        printf("Escolha inválida.\n");
    }

    return 0;
}

