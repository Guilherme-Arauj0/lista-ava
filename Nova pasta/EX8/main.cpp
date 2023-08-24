#include <stdio.h>
#include <string.h>

struct Produto {
    char nome[50];
    float preco;
    int quantidadeEstoque;
};

void comprarProduto(struct Produto *produto, int quantidade) {
    if (quantidade <= produto->quantidadeEstoque) {
        float totalCompra = quantidade * produto->preco;
        produto->quantidadeEstoque -= quantidade;
        printf("Compra realizada com sucesso!\n");
        printf("Total da compra: %.2f\n", totalCompra);
    } else {
        printf("Estoque insuficiente para realizar a compra.\n");
    }
}

int main() {
    struct Produto produtos[3];
    strcpy(produtos[0].nome, "Produto A");
    produtos[0].preco = 10.0;
    produtos[0].quantidadeEstoque = 5;

    strcpy(produtos[1].nome, "Produto B");
    produtos[1].preco = 15.0;
    produtos[1].quantidadeEstoque = 10;

    strcpy(produtos[2].nome, "Produto C");
    produtos[2].preco = 20.0;
    produtos[2].quantidadeEstoque = 8;

    int codigo, quantidade;
    int numProdutos = sizeof(produtos) / sizeof(produtos[0]);

    while (1) {
        printf("\nEstoque de produtos:\n");
        for (int i = 0; i < numProdutos; i++) {
            printf("Código: %d, Nome: %s, Preço: %.2f, Estoque: %d\n", i, produtos[i].nome, produtos[i].preco, produtos[i].quantidadeEstoque);
        }

        printf("\nDigite o código do produto que deseja comprar (ou -1 para sair): ");
        scanf("%d", &codigo);

        if (codigo == -1) {
            printf("Saindo do programa.\n");
            break;
        }

        if (codigo >= 0 && codigo < numProdutos) {
            printf("Digite a quantidade que deseja comprar: ");
            scanf("%d", &quantidade);
            comprarProduto(&produtos[codigo], quantidade);
        } else {
            printf("Código de produto inválido.\n");
        }
    }

    return 0;
}

