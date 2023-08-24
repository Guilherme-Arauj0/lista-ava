#include <stdio.h>
#include <string.h>

struct Livro {
    char titulo[100];
    char autor[50];
    int ano;
};

void adicionarLivro(struct Livro livros[], int *totalLivros) {
    if (*totalLivros < 100) {
        printf("Digite o t�tulo do livro: ");
        scanf("%s", livros[*totalLivros].titulo);
        printf("Digite o autor do livro: ");
        scanf("%s", livros[*totalLivros].autor);
        printf("Digite o ano de publica��o do livro: ");
        scanf("%d", &livros[*totalLivros].ano);
        (*totalLivros)++;
        printf("Livro adicionado com sucesso!\n");
    } else {
        printf("A lista de livros est� cheia.\n");
    }
}

void listarLivros(struct Livro livros[], int totalLivros) {
    printf("Lista de livros:\n");
    for (int i = 0; i < totalLivros; i++) {
        printf("T�tulo: %s, Autor: %s, Ano: %d\n", livros[i].titulo, livros[i].autor, livros[i].ano);
    }
}

void buscarLivroPorAutor(struct Livro livros[], int totalLivros, char autorProcurado[]) {
    int encontrado = 0;
    for (int i = 0; i < totalLivros; i++) {
        if (strcmp(livros[i].autor, autorProcurado) == 0) {
            printf("Livro encontrado:\nT�tulo: %s, Autor: %s, Ano: %d\n", livros[i].titulo, livros[i].autor, livros[i].ano);
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("Nenhum livro encontrado para o autor especificado.\n");
    }
}

int main() {
    struct Livro livros[100];
    int totalLivros = 0, escolha;
    char autorProcurado[50];

    while (1) {
        printf("\n1 - Adicionar livro\n2 - Listar livros\n3 - Buscar livro por autor\n4 - Sair\nEscolha uma op��o: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1: adicionarLivro(livros, &totalLivros); break;
            case 2: listarLivros(livros, totalLivros); break;
            case 3:
                printf("Digite o autor para buscar livros: ");
                scanf("%s", autorProcurado);
                buscarLivroPorAutor(livros, totalLivros, autorProcurado);
                break;
            case 4: printf("Encerrando o programa.\n"); return 0;
            default: printf("Op��o inv�lida.\n");
        }
    }

    return 0;
}

