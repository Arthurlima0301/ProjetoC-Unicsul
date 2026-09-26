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
    int ultimoProduto = 0;

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
                printf("\n\n====================\n");
                printf("CADASTRAR PRODUTO\n");
                printf("====================\n");
                printf("Informacoes do Produto\n");

                // Capturar Código antes
                int codigo;
                bool codigoExiste = false;

                printf("Codigo: ");
                scanf("%d", &codigo);

                // Verificar se Código Existe
                for(int i = 0; i <= ultimoProduto; i++){
                    if(produtos[i].codigo == codigo){
                        printf("\nCodigo ja existe\n");
                        codigoExiste = true;
                        break;
                    }
                }
                
                // Parar o Case se código existir
                if(codigoExiste == true){
                    codigoExiste = false;
                    codigo = 0;
                    break;
                }else{
                    produtos[ultimoProduto].codigo = codigo;
                }

                printf("Nome: ");
                scanf("%s", &produtos[ultimoProduto].nome);

                printf("Preco: ");
                scanf("%f", &produtos[ultimoProduto].preco);

                printf("Quantidade: ");
                scanf("%d", &produtos[ultimoProduto].quantidade);

                produtos[ultimoProduto].valorTotal = produtos[ultimoProduto].preco * produtos[ultimoProduto].quantidade;

                ultimoProduto++;
                
				break;
            case 2:
                printf("\n====================\n");
                printf("CONSULTAR PRODUTO\n");
                printf("====================\n");

                int codigoConsulta;
                bool produtoEncontrado = false;

                printf("Digite o codigo do produto: ");
                scanf ("%d", &codigoConsulta);
                
                for (int i = 0; i < ultimoProduto ; i++) {

                    if (codigoConsulta == produtos[i].codigo) {
                        printf("Nome: %s\n", produtos[i].nome);
                        printf ("Codigo: %d\n", produtos[i].codigo);
                        printf("Preco: %.2f\n", produtos[i].preco);
                        printf ("Quantidade: %d\n", produtos[i].quantidade);
                        printf ("Valor total: %.2f\n", produtos[i].valorTotal);
                        produtoEncontrado = true;
                    }
                }
                
                if (produtoEncontrado == false ) {
                    printf ("Produto Nao encontrado!\n");
                }  

 			
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
                option = 0;
                break;
        }
    }

    return 0;
}