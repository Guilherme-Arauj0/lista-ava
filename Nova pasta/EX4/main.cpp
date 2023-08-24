#include <stdio.h>
#include <string.h>

struct Pessoa {
    char nome[50];
    char telefone[20];
};

void adicionarNovaPessoa(struct Pessoa pessoas[], int *totalPessoas) {
    if (*totalPessoas < 100) {
        printf("Digite o nome da pessoa: ");
        scanf("%s", pessoas[*totalPessoas].nome);
        printf("Digite o número de telefone da pessoa: ");
        scanf("%s", pessoas[*totalPessoas].telefone);
        (*totalPessoas)++;
        printf("Pessoa adicionada com sucesso!\n");
    } else {
        printf("A lista de pessoas está cheia.\n");
    }
}

void listarPessoas(struct Pessoa pessoas[], int totalPessoas) {
    printf("Lista de pessoas:\n");
    for (int i = 0; i < totalPessoas; i++) {
        printf("Nome: %s, Telefone: %s\n", pessoas[i].nome, pessoas[i].telefone);
    }
}

void buscarPessoa(struct Pessoa pessoas[], int totalPessoas, char nomeProcurado[]) {
    int encontrada = 0;
    for (int i = 0; i < totalPessoas; i++) {
        if (strcmp(pessoas[i].nome, nomeProcurado) == 0) {
            printf("Pessoa encontrada:\nNome: %s, Telefone: %s\n", pessoas[i].nome, pessoas[i].telefone);
            encontrada = 1;
            break;
        }
    }
    if (!encontrada) {
        printf("Pessoa não encontrada.\n");
    }
}

int main() {
    struct Pessoa pessoas[100];
    int totalPessoas = 0, escolha;
    char nomeProcurado[50];

    while (1) {
        printf("\n1 - Adicionar pessoa\n2 - Listar pessoas\n3 - Buscar pessoa pelo nome\n4 - Sair\nEscolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1: adicionarNovaPessoa(pessoas, &totalPessoas); break;
            case 2: listarPessoas(pessoas, totalPessoas); break;
            case 3:
                printf("Digite o nome da pessoa a ser buscada: ");
                scanf("%s", nomeProcurado);
                buscarPessoa(pessoas, totalPessoas, nomeProcurado);
                break;
            case 4: printf("Encerrando o programa.\n"); return 0;
            default: printf("Opção inválida.\n");
        }
    }

    return 0;
}

