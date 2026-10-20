#include <stdio.h>

/**
 * Sructs de Produto
 */
struct Produto
{
    char nome[50];
    int codigo;
    float preco;
    int quantidade;
    float valorTotal;
};

#define MAX_PRODUTOS 10

/**
 * Validar Código
 */
bool validarCodigo(int codigoConsulta, struct Produto produtos[], int quantidadeProdutos)
{
    // Percorre os Array de produtos e se encontrar imprime as informações
    for (int i = 0; i < quantidadeProdutos; i++)
    {
        if (codigoConsulta == produtos[i].codigo)
        {
            return true;
        }
    }

    return false;
}

/**
 * Cadastrar Produtos
 */
void cadastrarProduto(struct Produto produtos[], int *quantidadeProdutos)
{
    // Capturar Código
    int codigo;
    bool codigoExiste = false;

    printf("Codigo: ");
    scanf("%d", &codigo);

    // Verifica se o código existe
    codigoExiste = validarCodigo(codigo, produtos, *quantidadeProdutos);

    if (codigoExiste == true)
    {
        printf("Código Já Existe!\n");
        return;
    }

    // Cadastrar Infomações
    produtos[*quantidadeProdutos].codigo = codigo;

    printf("Nome: ");
    scanf("%s", &produtos[*quantidadeProdutos].nome);

    printf("Preco: ");
    scanf("%f", &produtos[*quantidadeProdutos].preco);

    printf("Quantidade: ");
    scanf("%d", &produtos[*quantidadeProdutos].quantidade);

    // Realiza a Multiplicação para obter o Valor Total
    produtos[*quantidadeProdutos].valorTotal = produtos[*quantidadeProdutos].preco * produtos[*quantidadeProdutos].quantidade;

    // Adiciona mais um a quantidade de produtos
    (*quantidadeProdutos)++;

    return;
}

/**
 *  Consultar Produto
 */
void consultarProduto() {}

/**
 *  Listar Produtos
 */
void verificarEstoque() {}

/**
 * Calcular Valor do Estoque
 */
void valorEstoque() {}

/**
 * Salvar Produtos
 */
void salvarProdutos() {}

/**
 *  Carregar Produtos
 */
void carregarProdutos() {}

int main()
{
    // Array de Structs
    struct Produto produtos[MAX_PRODUTOS];

    int option = 0;
    int quantidadeProdutos = 0;

    while (option != 5)
    {
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

        switch (option)
        {
        case 1:
            printf("\n\n====================\n");
            printf("CADASTRAR PRODUTO\n");
            printf("====================\n");
            printf("Informacoes do Produto\n");

            cadastrarProduto(produtos, &quantidadeProdutos);
            break;
        case 2:
            printf("\n====================\n");
            printf("CONSULTAR PRODUTO\n");
            printf("====================\n");

            int codigoConsulta;
            bool produtoEncontrado = false;

            printf("Digite o codigo do produto: ");
            scanf("%d", &codigoConsulta);

            for (int i = 0; i < quantidadeProdutos; i++)
            {

                if (codigoConsulta == produtos[i].codigo)
                {
                    printf("Nome: %s\n", produtos[i].nome);
                    printf("Codigo: %d\n", produtos[i].codigo);
                    printf("Preco: %.2f\n", produtos[i].preco);
                    printf("Quantidade: %d\n", produtos[i].quantidade);
                    printf("Valor total: %.2f\n", produtos[i].valorTotal);
                    produtoEncontrado = true;
                }
            }

            if (produtoEncontrado == false)
            {
                printf("Produto Nao encontrado!\n");
            }

            break;

        case 3:
        {
            printf("\n====================\n");
            printf("VERIFICAR ESTOQUE\n");
            printf("====================\n");
            if (quantidadeProdutos == 0)
            {
                printf("Nenhum produto cadastrado.\n");
                break;
            }
            for (int i = 0; i < quantidadeProdutos; i++)
            {
                printf("\nProduto: %s\n", produtos[i].nome);
                printf("Codigo: %d\n", produtos[i].codigo);
                printf("Preco: R$ %.2f\n", produtos[i].preco);
                printf("Quantidade: %d\n", produtos[i].quantidade);
                printf("Valor em Estoque: R$ %.2f\n", produtos[i].valorTotal);
                if (produtos[i].quantidade == 0)
                {
                    printf("ESTOQUE ESGOTADO\n");
                }
                else if (produtos[i].quantidade <= 5)
                {
                    printf("ESTOQUE BAIXO\n");
                }
                else
                {
                    printf("ESTOQUE NORMAL\n");
                }
            }
            break;
        }
        case 4:
        {
            float totalEstoque = 0;
            printf("\n====================\n");
            printf("TOTAL ESTOQUE\n");
            printf("====================\n");
            if (quantidadeProdutos == 0)
            {
                printf("Nenhum produto cadastrado.\n");
                break;
            }
            for (int i = 0; i < quantidadeProdutos; i++)
            {
                totalEstoque = totalEstoque + produtos[i].valorTotal;
            }
            printf("\nValor Total em Estoque: R$ %.2f\n", totalEstoque);
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