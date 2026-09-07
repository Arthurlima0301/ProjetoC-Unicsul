#include <stdio.h>

int main(){
	int codigo1,codigo2,codigo3,codigo4,codigo5;
	float preco1,preco2,preco3,preco4,preco5;
	int quantidade1,quantidade2,quantidade3,quantidade4,quantidade5;

	char nome1[50], nome2[50], nome3[50], nome4[50], nome5[50];
	float total1, total2, total3, total4, total5;
	
	printf("===============================\n");
	printf("SISTEMA DE CONTROLE DE PRODUTOS\n");
	printf("===============================\n");
	
	printf("Produto 1\n");
	printf("Nome: ");
	scanf("%s",nome1);
	
	printf("Codigo: ");
	scanf("%d", &codigo1);
	
	printf("Preco: ");
	scanf("%f", &preco1);
	
	printf("Quantidade: ");
	scanf("%d", &quantidade1);
	
	
	total1 = preco1 * quantidade1;

	printf ("\n");
	printf ("Produto 2\n");
	printf ("Nome: ");
	scanf ("%s",nome2);

	printf("Codigo: ");
	scanf("%d", &codigo2);

	printf("Preco: ");
	scanf ("%f", &preco2);

	printf ("Quantidade: ");
	scanf ("%d", &quantidade2);

	total2 = preco2 *quantidade2;

	printf ("\n");
	printf ("Produto 3\n");
	printf ("Nome: ");
	scanf ("%s", nome3);

	printf("Codigo: ");
	scanf("%d", &codigo3);
	
	printf("Preco: ");
	scanf ("%f", &preco3);
	
	printf ("Quantidade: ");
	scanf ("%d", &quantidade3);

	total3 = preco3 * quantidade3;


	
	printf("\n================\n");
	printf("RESUMO DO ESTOQUE\n");
	printf("==================\n");
	
	
	printf("Codigo: %d \n", codigo1);
	printf("Produto: %s \n",nome1);
	printf("Valor em Estoque: R$%.2f \n",total1);
	printf ("\n");


	printf ("Codigo: %d \n", codigo2);
	printf ("Produto: %s \n", nome2);
	printf ("Valor em Estoque: R$%.2f \n", total2);
	printf ("\n");

	printf ("Codigo: %d \n", codigo3);
	printf ("Produto: %s \n", nome3);
	printf ("Valor em Estoque: R$%.2f \n", total3);
	printf ("\n");

	
	
	return 0;
}
