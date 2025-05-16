#include <stdio.h>
#include <string.h>

// Variáveis globais
float saldo = 1000.0;
char senha_correta[] = "1234";
char cpf_correto[] = "14800717604";

// Função de login com CPF
int login() {
    char senha[20];
    char cpf[20];
    int tentativas = 3;

    while (tentativas > 0) {
        printf("Digite o CPF: ");
        scanf("%s", cpf);
        printf("Digite a senha: ");
        scanf("%s", senha);

        if (strcmp(cpf, cpf_correto) == 0 && strcmp(senha, senha_correta) == 0) {
            printf("Login realizado com sucesso!\n\n");
            return 1;
        } else {
            tentativas--;
            printf("CPF ou senha incorretos! Tentativas restantes: %d\n", tentativas);
        }
    }

    printf("Número máximo de tentativas excedido. Saindo...\n");
    return 0;
}

// Menu principal
void mostrar_menu() {
    printf("\n===== MENU PRINCIPAL =====\n");
    printf("1 - Consultar Saldo\n");
    printf("2 - Realizar Depósito\n");
    printf("3 - Realizar Saque\n");
    printf("4 - Sair\n");
    printf("Escolha uma opção: ");
}

// Consultar saldo
void consultar_saldo() {
    printf("Seu saldo atual é: R$ %.2f\n", saldo);
}

// Realizar depósito
void realizar_deposito() {
    float valor;
    printf("Digite o valor a depositar: ");
    scanf("%f", &valor);

    if (valor <= 0) {
        printf("Valor inválido! O depósito deve ser positivo.\n");
    } else {
        saldo += valor;
        printf("Depósito de R$ %.2f realizado com sucesso!\n", valor);
    }
}

// Realizar saque
void realizar_saque() {
    float valor;
    printf("Digite o valor a sacar: ");
    scanf("%f", &valor);

    if (valor <= 0) {
        printf("Valor inválido! O saque deve ser positivo.\n");
    } else if (valor > saldo) {
        printf("Saldo insuficiente para saque.\n");
    } else {
        int notas[] = {100, 50, 20, 10, 5, 2};
        int i, qtd;
        int restante = (int)valor;

        printf("Notas entregues:\n");
        for (i = 0; i < 6; i++) {
            qtd = restante / notas[i];
            if (qtd > 0) {
                printf("%d nota(s) de R$ %d\n", qtd, notas[i]);
                restante %= notas[i];
            }
        }

        if (restante > 0) {
            printf("Valor restante de R$ %d não pode ser sacado por falta de notas disponíveis.\n", restante);
        }

        saldo -= valor;
        printf("Saque de R$ %.2f realizado com sucesso!\n", valor);
    }
}

// Função principal
int main() {
    int opcao;

    if (!login()) {
        return 0;
    }

    do {
        mostrar_menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                consultar_saldo();
                break;
            case 2:
                realizar_deposito();
                break;
            case 3:
                realizar_saque();
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }

    } while (opcao != 4);

    return 0;
}
