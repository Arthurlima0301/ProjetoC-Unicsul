#include <stdio.h>

int main() {

    int codigo1, codigo2, codigo3, codigo4, codigo5;
    float preco1, preco2, preco3, preco4, preco5;
    int quantidade1, quantidade2, quantidade3, quantidade4, quantidade5;
    char nome1[50], nome2[50], nome3[50], nome4[50], nome5[50];
    float total1, total2, total3, total4, total5;

    printf("===============================\n");
    printf("SISTEMA DE CONTROLE DE PRODUTOS\n");
    printf("===============================\n");
    printf("\nProduto 1\n");

    printf("Nome: ");
    scanf("%s", nome1);

    printf("Codigo: ");
    scanf("%d", &codigo1);

    printf("Preco: ");
    scanf("%f", &preco1);

    printf("Quantidade: ");
    scanf("%d", &quantidade1);

    total1 = preco1 * quantidade1;

    printf("\nProduto 2\n");

    printf("Nome: ");
    scanf("%s", nome2);

    printf("Codigo: ");
    scanf("%d", &codigo2);

    printf("Preco: ");
    scanf("%f", &preco2);

    printf("Quantidade: ");
    scanf("%d", &quantidade2);

    total2 = preco2 * quantidade2;

    printf("\nProduto 3\n");

    printf("Nome: ");
    scanf("%s", nome3);

    printf("Codigo: ");
    scanf("%d", &codigo3);

    printf("Preco: ");
    scanf("%f", &preco3);

    printf("Quantidade: ");
    scanf("%d", &quantidade3);

    total3 = preco3 * quantidade3;

    printf("\nProduto 4\n");

    printf("Nome: ");
    scanf("%s", nome4);

    printf("Codigo: ");
    scanf("%d", &codigo4);

    printf("Preco: ");
    scanf("%f", &preco4);

    printf("Quantidade: ");
    scanf("%d", &quantidade4);

    total4 = preco4 * quantidade4;

    printf("\nProduto 5\n");

    printf("Nome: ");
    scanf("%s", nome5);

    printf("Codigo: ");
    scanf("%d", &codigo5);

    printf("Preco: ");
    scanf("%f", &preco5);

    printf("Quantidade: ");
    scanf("%d", &quantidade5);

    total5 = preco5 * quantidade5;

    printf("\n====================\n");
    printf("RESUMO DO ESTOQUE\n");
    printf("====================\n");

    printf("\nProduto 1\n");
    printf("Codigo: %d\n", codigo1);
    printf("Produto: %s\n", nome1);
    printf("Preco: R$%.2f\n", preco1);
    printf("Quantidade: %d\n", quantidade1);
    printf("Valor em Estoque: R$%.2f\n", total1);

    printf("\nProduto 2\n");
    printf("Codigo: %d\n", codigo2);
    printf("Produto: %s\n", nome2);
    printf("Preco: R$%.2f\n", preco2);
    printf("Quantidade: %d\n", quantidade2);
    printf("Valor em Estoque: R$%.2f\n", total2);

    printf("\nProduto 3\n");
    printf("Codigo: %d\n", codigo3);
    printf("Produto: %s\n", nome3);
    printf("Preco: R$%.2f\n", preco3);
    printf("Quantidade: %d\n", quantidade3);
    printf("Valor em Estoque: R$%.2f\n", total3);

    printf("\nProduto 4\n");
    printf("Codigo: %d\n", codigo4);
    printf("Produto: %s\n", nome4);
    printf("Preco: R$%.2f\n", preco4);
    printf("Quantidade: %d\n", quantidade4);
    printf("Valor em Estoque: R$%.2f\n", total4);

    printf("\nProduto 5\n");
    printf("Codigo: %d\n", codigo5);
    printf("Produto: %s\n", nome5);
    printf("Preco: R$%.2f\n", preco5);
    printf("Quantidade: %d\n", quantidade5);
    printf("Valor em Estoque: R$%.2f\n", total5);

    return 0;
}