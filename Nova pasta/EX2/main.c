#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct tipos{
	
	float ponto_flutuante;
	int inteiro;
	char letra;
};

int main() {
	setlocale(LC_ALL, "");
	
	struct tipos variaveis;
	
	variaveis.ponto_flutuante = 17.6;
	variaveis.letra = 'a';
	variaveis.inteiro = 20;
	
	printf("Vari�vel de ponto flutuante: %.2f \n", variaveis.ponto_flutuante);
	printf("Vari�vel de tipo inteiro: %d \n", variaveis.inteiro);
	printf("Vari�vel de tipo letras: %c \n", variaveis.letra);
	
	
	
	return 0;
}
