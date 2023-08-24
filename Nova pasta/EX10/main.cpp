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

    printf("Digite um valor em d�lares: ");
    scanf("%f", &moeda.dolares);

    printf("\nEscolha a opera��o:\n");
    printf("1 - Converter de d�lares para euros\n");
    printf("2 - Converter de euros para d�lares\n");
    int escolha;
    scanf("%d", &escolha);

    if (escolha == 1) {
        converterDolaresParaEuros(&moeda, taxaDolarParaEuro);
        printf("Valor convertido para euros: %.2f euros\n", moeda.euros);
    } else if (escolha == 2) {
        printf("Digite um valor em euros: ");
        scanf("%f", &moeda.euros);
        converterEurosParaDolares(&moeda, taxaDolarParaEuro);
        printf("Valor convertido para d�lares: %.2f d�lares\n", moeda.dolares);
    } else {
        printf("Escolha inv�lida.\n");
    }

    return 0;
}

