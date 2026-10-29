#include <stdio.h>
#include <stdbool.h>

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

/*
* Validar se é inteiro
 */
bool validarTipo(int campo){
    if (campo != 1) {   
        printf("Entrada inválida!\n");

        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        return false;
    }

    return true;
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

    if(!validarTipo(scanf("%d", &codigo))){
        return;
    }
    
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
    if(!validarTipo(scanf("%f", &produtos[*quantidadeProdutos].preco))){
        return;
    }

    printf("Quantidade: ");
    if(!validarTipo(scanf("%d", &produtos[*quantidadeProdutos].quantidade))){
        return;
    }

    // Realiza a Multiplicação para obter o Valor Total
    produtos[*quantidadeProdutos].valorTotal = produtos[*quantidadeProdutos].preco * produtos[*quantidadeProdutos].quantidade;

    // Adiciona mais um a quantidade de produtos
    (*quantidadeProdutos)++;


    printf("Produto Cadastrado com sucesso!\n");
    return;
}

/**
* Alterar Produto
*/
void alterarProduto(struct Produto produtos[], int *quantidadeProdutos)
{
        int codigoProduto;
        int indice;
        int confirma;

        printf("Digite o Código do Produto que deseja Alterar: ");
        scanf("%d", &codigoProduto);

        for(int i = 0; i < *quantidadeProdutos; i++){
            if(codigoProduto == produtos[i].codigo){
                printf("Nome: %s\n", produtos[i].nome);
                printf("Codigo: %d\n", produtos[i].codigo );
                printf("Preco: %.2f\n", produtos[i].preco);
                printf("Quantidade: %d\n", produtos[i].quantidade);
                printf("Valor total: %.2f\n", produtos[i].valorTotal);
                indice = i;

                printf("\nDeseja alterar o produto acima?\n");
                printf("1 - Sim\n");
                printf("2 - Não\n");
                printf("Digite a opção: ");
                scanf("%d", &confirma);
                break;
            }else{
                confirma = 0;
            }
        }

        if(confirma == 1){
            printf("Código: %d\n", produtos[indice].codigo);

            printf("Nome: ");
            scanf("%s", &produtos[indice].nome);

            printf("Preco: ");
            if(!validarTipo(scanf("%f", &produtos[indice].preco))){
                return;
            }

            printf("Quantidade: ");
            if(!validarTipo(scanf("%d", &produtos[indice].quantidade))){
                return;
            }

            // Realiza a Multiplicação para obter o Valor Total
            produtos[indice].valorTotal = produtos[indice].preco * produtos[indice].quantidade;

            printf("Produto Alterado!\n");
            return;
            
        }else if(confirma = 0){
            printf("Produto não encontrado!\n");
            return;
        }else {
            printf("Operação cancelada!\n");
            return;
        }
}

/**
 *  Consultar Produto
 */
void consultarProduto(struct Produto produtos[], int quantidadeProdutos)
{
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
}

/**
 *  Listar Produtos
 */
void verificarEstoque(struct Produto produtos[], int quantidadeProdutos)
{
    if (quantidadeProdutos == 0)
    {
        printf("Nenhum produto cadastrado.\n");
        return;
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

    return;
}

/**
 * Calcular Valor do Estoque
 */
void valorEstoque(struct Produto produtos[], int quantidadeProdutos)
{

    float totalEstoque = 0;
    if (quantidadeProdutos == 0)
    {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    for (int i = 0; i < quantidadeProdutos; i++)
    {
        totalEstoque = totalEstoque + produtos[i].valorTotal;
    }

    printf("\nValor Total em Estoque: R$ %.2f\n", totalEstoque);

    return;
}

/**
 * Salvar Produtos
 */
void salvarProdutos(struct Produto produtos[], int quantidadeProdutos) {
    
    FILE *arquivo = fopen("produtos.txt", "w");

    
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    // Percorre todos os produtos cadastrados no array.
    for (int i = 0; i < quantidadeProdutos; i++) 
    {
        fprintf(arquivo, "%d;%s;%.2f;%d\n",
        produtos[i].codigo,
        produtos[i].nome,
        produtos[i].preco,
        produtos[i].quantidade);
    }
    fclose(arquivo);
    printf("Produtos salvos com sucesso!\n");

}
    
/**
 *  Carregar Produtos
 */    
void carregarProdutos(struct Produto produtos[], int *quantidadeProdutos)
{
    FILE *arquivo = fopen("produtos.txt", "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    // Reinicia a quantidade antes de carregar os produtos.
    *quantidadeProdutos = 0;


    while (*quantidadeProdutos < MAX_PRODUTOS &&
           fscanf(arquivo, "%d;%49[^;];%f;%d",
                  &produtos[*quantidadeProdutos].codigo,
                  produtos[*quantidadeProdutos].nome,
                  &produtos[*quantidadeProdutos].preco,
                  &produtos[*quantidadeProdutos].quantidade) == 4)
    {
        // Calcula o valor total do produto.
        produtos[*quantidadeProdutos].valorTotal =
            produtos[*quantidadeProdutos].preco *
            produtos[*quantidadeProdutos].quantidade;

        (*quantidadeProdutos)++;
    }

    fclose(arquivo);

    printf("Produtos carregados com sucesso!\n");
}

int main()
{
    // Array de Structs
    struct Produto produtos[MAX_PRODUTOS];

    int option = 0;
    int quantidadeProdutos = 0;

    while (option != 13)
    {
        printf("===============================\n");
        printf("SISTEMA DE CONTROLE DE PRODUTOS\n");
        printf("===============================\n");
        printf("1 - Cadastrar Produtos\n");
        printf("2 - Listar Produtos\n");
        printf("3 - Consultar Produtos\n");
        printf("4 - Alterar Produtos\n");
        printf("7 - Calcular Total Estoque\n");
        printf("11 - Salvar Produtos\n");
        printf("12 - Carregar Produtos\n");
        printf("13 - Sair\n");

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
            printf("LISTAR PRODUTOS\n");
            printf("====================\n");

            verificarEstoque(produtos, quantidadeProdutos);
            break;

        case 3:
            printf("\n====================\n");
            printf("CONSULTAR PRODUTOS\n");
            printf("====================\n");

            consultarProduto(produtos, quantidadeProdutos);
            break;     

        case 4:
            printf("\n====================\n");
            printf("ALTERAR PRODUTO\n");
            printf("====================\n");

            alterarProduto(produtos, &quantidadeProdutos);
            break;     
        case 7:
            printf("\n====================\n");
            printf("TOTAL DO ESTOQUE \n");
            printf("\n====================\n");
            valorEstoque(produtos, quantidadeProdutos);
            break;

        case 11:
        
            printf("\n====================\n");
            printf("SALVAR PRODUTOS\n");
            printf("====================\n");

            salvarProdutos(produtos, quantidadeProdutos);
            break;
        
       case 12:
            printf("\n====================\n");
            printf("CARREGAR PRODUTOS \n");
            printf("====================\n");

            carregarProdutos(produtos, &quantidadeProdutos);
            break;
       
        case 13:
            printf("\n====================\n");
            printf("SAIDA\n");
            printf("====================\n");

            printf("Programa encerrado.\n");
            break;

        default:
            printf("\nOpcao invalida!\n");
            printf("Escolha uma opcao de 1 a 7.\n");
            break;
        }
    }

    return 0;
}