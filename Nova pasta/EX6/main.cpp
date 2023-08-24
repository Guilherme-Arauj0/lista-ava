#include <stdio.h>

struct Estudante {
    char nome[50];
    int matricula;
    float nota1, nota2, nota3;
};

float calcularMedia(float nota1, float nota2, float nota3) {
    return (nota1 + nota2 + nota3) / 3;
}

int estaAprovado(float media) {
    return media >= 7.0;
}

int main() {
    struct Estudante aluno;

    printf("Informe o nome do estudante: ");
    scanf("%s", aluno.nome);
    printf("Informe a matrícula do estudante: ");
    scanf("%d", &aluno.matricula);
    printf("Informe as notas nas três disciplinas: ");
    scanf("%f %f %f", &aluno.nota1, &aluno.nota2, &aluno.nota3);

    float media = calcularMedia(aluno.nota1, aluno.nota2, aluno.nota3);

    printf("\nMédia das notas: %.2f\n", media);

    if (estaAprovado(media)) {
        printf("O estudante está aprovado!\n");
    } else {
        printf("O estudante não está aprovado.\n");
    }

    return 0;
}

