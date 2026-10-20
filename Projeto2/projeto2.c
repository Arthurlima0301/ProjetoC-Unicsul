
#include <stdio.h>

int main() {
    struct Produto {
        char nome[50];
        int codigo;
        float preco;
        int quantidade;
        float valorTotal;
    };

    struct Produto produtos[10];

    int option = 0;
    int quantidadeProdutos = 0;

    while (option != 5) {
        printf("===============================\n");
        printf("SISTEMA DE CONTROLE DE PRODUTOS\n");
        printf("===============================\n");
        printf("1 - Cadastrar Produtos\n");
        printf("2 - Consultar Produtos\n");
        printf("3 - Verificar Estoque\n");
        printf("4 - Calcular Total Estoque\n");
        printf("5 - Sair\n");

        printf("\nSelecione a opcao: ");
        scanf("%d", &option);

        switch (option) {
            case 1: {
                int quantidadeCadastrar;

                printf("\n====================\n");
                printf("CADASTRAR PRODUTOS\n");
                printf("====================\n");

                if (quantidadeProdutos >= 10) {
                    printf("Limite de produtos atingido!\n");
                    break;
                }

                printf("Quantos produtos deseja cadastrar? ");
                scanf("%d", &quantidadeCadastrar);

                if (quantidadeCadastrar <= 0) {
                    printf("Quantidade invalida!\n");
                    break;
                }

                if (quantidadeProdutos + quantidadeCadastrar > 10) {
                    printf(
                        "Voce pode cadastrar apenas %d produto(s).\n",
                        10 - quantidadeProdutos
                    );
                    break;
                }

                for (int i = 0; i < quantidadeCadastrar; i++) {
                    printf("\nProduto %d\n", quantidadeProdutos + 1);

                    printf("Nome: ");
                    scanf("%s", produtos[quantidadeProdutos].nome);

                    printf("Codigo: ");
                    scanf("%d", &produtos[quantidadeProdutos].codigo);

                    printf("Preco: ");
                    scanf("%f", &produtos[quantidadeProdutos].preco);

                    printf("Quantidade: ");
                    scanf("%d", &produtos[quantidadeProdutos].quantidade);

                    if (produtos[quantidadeProdutos].quantidade < 0) {
                        printf("Quantidade invalida!\n");
                        continue;
                    }

                    produtos[quantidadeProdutos].valorTotal =
                        produtos[quantidadeProdutos].preco *
                        produtos[quantidadeProdutos].quantidade;

                    quantidadeProdutos++;

                    printf("Produto cadastrado com sucesso!\n");
                }

                break;
            }

            case 2: {
                int codigoBusca;
                int encontrado = 0;

                printf("\n====================\n");
                printf("CONSULTAR PRODUTO\n");
                printf("====================\n");

                if (quantidadeProdutos == 0) {
                    printf("Nenhum produto cadastrado.\n");
                    break;
                }

                printf("Digite o codigo do produto: ");
                scanf("%d", &codigoBusca);

                for (int i = 0; i < quantidadeProdutos; i++) {
                    if (produtos[i].codigo == codigoBusca) {
                        printf("\nProduto encontrado!\n");
                        printf("Nome: %s\n", produtos[i].nome);
                        printf("Codigo: %d\n", produtos[i].codigo);
                        printf("Preco: R$ %.2f\n", produtos[i].preco);
                        printf("Quantidade: %d\n", produtos[i].quantidade);
                        printf(
                            "Valor em Estoque: R$ %.2f\n",
                            produtos[i].valorTotal
                        );

                        encontrado = 1;
                        break;
                    }
                }

                if (encontrado == 0) {
                    printf("Produto nao encontrado.\n");
                }

                break;
            }

            case 3: {
                printf("\n====================\n");
                printf("VERIFICAR ESTOQUE\n");
                printf("====================\n");

                if (quantidadeProdutos == 0) {
                    printf("Nenhum produto cadastrado.\n");
                    break;
                }

                for (int i = 0; i < quantidadeProdutos; i++) {
                    printf("\nProduto: %s\n", produtos[i].nome);
                    printf("Codigo: %d\n", produtos[i].codigo);
                    printf("Preco: R$ %.2f\n", produtos[i].preco);
                    printf("Quantidade: %d\n", produtos[i].quantidade);
                    printf(
                        "Valor em Estoque: R$ %.2f\n",
                        produtos[i].valorTotal
                    );

                    if (produtos[i].quantidade == 0) {
                        printf("ESTOQUE ESGOTADO\n");
                    } else if (produtos[i].quantidade <= 5) {
                        printf("ESTOQUE BAIXO\n");
                    } else {
                        printf("ESTOQUE NORMAL\n");
                    }
                }

                break;
            }

            case 4: {
                float totalEstoque = 0;

                printf("\n====================\n");
                printf("TOTAL ESTOQUE\n");
                printf("====================\n");

                if (quantidadeProdutos == 0) {
                    printf("Nenhum produto cadastrado.\n");
                    break;
                }

                for (int i = 0; i < quantidadeProdutos; i++) {
                    totalEstoque =
                        totalEstoque + produtos[i].valorTotal;
                }

                printf(
                    "\nValor Total em Estoque: R$ %.2f\n",
                    totalEstoque
                );

                break;
            }

            case 5:
                printf("\n====================\n");
                printf("SAIDA\n");
                printf("====================\n");
                printf("Programa encerrado.\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
                printf("Escolha uma opcao de 1 a 5.\n");
                break;
        }
    }

    return 0;
}
