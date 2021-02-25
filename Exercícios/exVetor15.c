/*
16. Elabore um programa que apresente na tela os 20 primeiros termos da seqüência de Fibonacci (1 1 2 3 5 8 13 21 ...).
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 20

//Algoritmo principal
void main(){
	setlocale(LC_ALL, "portuguese");
	
	int vet[TAM], result;
	int i;
	vet[0] = 1;
	vet[1] = 1;
	
	printf("Sequência de Fibonacci:\n");
	printf("%d\n\n", vet[0]);
	printf("%d\n\n", vet[1]);
	
	for(i = 2;  i < TAM; i++){
		vet[i] = vet [i-1] + vet[i-2];
		printf("%d\n\n", vet[i]);
			
	}
}