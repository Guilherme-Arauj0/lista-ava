#include <stdio.h>
#include <string.h>

struct ContaBancaria {
    char titular[50];
    char numeroConta[20];
    float saldo;
};

void depositar(struct ContaBancaria *conta, float valor) {
    conta->saldo += valor;
    printf("Depósito de %.2f realizado com sucesso!\n", valor);
}

void sacar(struct ContaBancaria *conta, float valor) {
    if (valor <= conta->saldo) {
        conta->saldo -= valor;
        printf("Saque de %.2f realizado com sucesso!\n", valor);
    } else {
        printf("Saldo insuficiente para saque.\n");
    }
}

void verificarSaldo(struct ContaBancaria conta) {
    printf("Saldo da conta de %s: %.2f\n", conta.titular, conta.saldo);
}

int main() {
    struct ContaBancaria conta;
    strcpy(conta.titular, "João");
    strcpy(conta.numeroConta, "123456");
    conta.saldo = 1000.0;

    int opcao;
    float valor;

    while (1) {
        printf("\n1 - Depositar\n");
        printf("2 - Sacar\n");
        printf("3 - Verificar saldo\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser depositado: ");
                scanf("%f", &valor);
                depositar(&conta, valor);
                break;
            case 2:
                printf("Digite o valor a ser sacado: ");
                scanf("%f", &valor);
                sacar(&conta, valor);
                break;
            case 3:
                verificarSaldo(conta);
                break;
            case 4:
                printf("Saindo do programa.\n");
                return 0;
            default:
                printf("Opção inválida.\n");
        }
    }

    return 0;
}

