/*
11. Elabore um procedimento que leia do teclado um vetor de inteiros de qualquer tamanho. Faça a chamada
deste procedimento no algoritmo principal.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 3 //controla quantos valores será armazenado no vetor

int valor(){
	int x[TAM];
	int i;
	
	for(i = 0; i < TAM; i++){
		printf("\n");
		printf("Informe um valor:\n");
		scanf("%i", &x[i]);
		return x[i];
	}
}

void main(){
	setlocale(LC_ALL, "");
	int i, x[TAM];
	
	//receber o valor armazenado no indice do vetor
	for(i = 0; i < TAM; i++){
		x[i] = valor(i);
	}
	
	//Mostrar valor do vetor recebido da função valor();
	printf("\n");
	printf("valor informado:\n");
	for(i = 0; i < TAM; i++){
		printf("%i\t", x[i]);
	}
}