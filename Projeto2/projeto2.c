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

    int option = 6;

    while (option != 0) {
        printf("===============================\n");
        printf("SISTEMA DE CONTROLE DE PRODUTOS\n");
        printf("===============================\n");
        printf("1 - Cadastrar Produtos \n");
        printf("2 - Consultar Produtos \n");
        printf("3 - Verificar Estoque \n");
        printf("4 - Calcular Total Estoque \n");
        printf("5 - Sair \n");

        printf("Selecione a opcao: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\n====================\n");
                printf("CADASTRAR PRODUTO\n");
                printf("====================\n");
                
                printf("\nProduto \n");
                printf("Nome: ");
                scanf("%s", &produtos[0].nome);

                printf("Codigo: ");
                scanf("%d", &produtos[0].codigo);

                printf("Preco: ");
                scanf("%f", &produtos[0].preco);

                printf("Quantidade: ");
                scanf("%d", &produtos[0].quantidade);

                produtos[0].valorTotal = produtos[0].preco * produtos[0].quantidade;
                
                option = 6;
				break;
				
            case 2:
                printf("\n====================\n");
                printf("CONSULTAR PRODUTO\n");
                printf("====================\n");
                
                printf("\nProduto \n");
                printf("Nome: ");
                printf("%s \n", produtos[0].nome);

                printf("Codigo: ");
                printf("%d \n", produtos[0].codigo);

                printf("Preco: ");
                printf("%f \n", produtos[0].preco);

                printf("Quantidade: ");
                printf("%d \n", produtos[0].quantidade);

 				option = 6;
                break;

            case 3:
                printf("\n====================\n");
                printf("VERIFICAR ESTOQUE\n");
                printf("====================\n");

                /*
                for(int i = 0, produtos.lenght <= i, i++){
                    printf("\nProduto \n");
                    printf("Codigo: %d\n", codigo);
                    printf("Produto: %s\n", nome);
                    printf("Preco: R$%.2f\n", preco);
                    printf("Quantidade: %d\n", quantidade);
                    printf("Valor em Estoque: R$%.2f\n", total);
                }
                */
                
				option = 6;
                break;

            case 4:
                printf("\n====================\n");
                printf(" TOTAL ESTOQUE \n");
                printf("====================\n");

                //float totalEstoque = total1;
                //printf("\nValor Total em Estoque: R$%.2f\n", totalEstoque);

				option = 6;
                break;

            case 5:
                printf("\n SAIDA \n");
                
                option = 6;
                break;
        }
    }

    return 0;
}