/*
Elabore um programa que leia 50 números do teclado e os armazene em um vetor.
Em seguida, leia um número n qualquer e apresente na tela a quantidade de vezes 
que o número n aparece no vetor.
*/

#//Biblioteca 
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 10

//Algoritmo principal
void main(){

	setlocale(LC_ALL, "portuguese");
	
	// declaração de variáveis
	int vet[TAM], i, n, cont;
	
	cont = 0;
	
	// ler o vetor
	for(i = 0; i < TAM; i++){
		printf("Informe o elemento do índice %i: ", i);
		scanf("%i", &vet[i]);
	}
	
	// ler o número n
	printf("\nInforme n: ");
	scanf("%i", &n);
	
	// percorrer o vetor e comparar elemento por elemento com a variável n
	for(i = 0; i < TAM; i++){
		if(vet[i] == n){
			cont++;
		}
	}
	
	printf("\n Quantidade de repetições: %i", cont);	
}
