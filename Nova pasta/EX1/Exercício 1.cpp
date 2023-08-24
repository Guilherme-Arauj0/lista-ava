#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

	struct pessoa{
		
		char nome[20];
		int idade;
		float altura;
	};
	

int main(){
	setlocale(LC_ALL, "");
	

	//Entrada de dados
	struct pessoa pessoa_dados;
	
	printf("--------------------+++--------------------\n");
		
	printf("Qual seu Nome?\n");
	fgets(pessoa_dados.nome, 20, stdin);
		
	printf("Qual sua idade?\n");
	scanf("%d", &pessoa_dados.idade);
		
	printf("Qual sua altura?\n");
	scanf("%f", &pessoa_dados.altura);
		
	printf("--------------------+++--------------------\n");
		
	//Saída de dados	
	printf("Nome: %s\n", pessoa_dados.nome);
	printf("Idade: %d\n", pessoa_dados.idade);
	printf("Altura: %.2f\n", pessoa_dados.altura);
		

	return 0;
}
