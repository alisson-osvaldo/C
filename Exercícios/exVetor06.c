/*
06. Crie um programa que leia o vetor com 1000 números e some apenas
 os elementos positivos que estão nas posições pares.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 10

//procedimento para ler vetor
void lerVetor(int *vet, int tam){
	int i;
	for(i = 0; i < tam; i++){
		printf("Informe o valor do indice %d: ", i+1);
		scanf("%d", &vet[i]);
	}
}

//mostrar vetor e somar indices pares positivos 
void mostrarVetor(int *vet, int tam){
	int i, soma;

	soma = 0;
	
	printf("\n indice par com valor positivo: ");
	
	for(i = 1; i < tam; i = i + 2){
		soma = soma + vet[i];
		
		if(vet[i] > 0){
		printf("%d - ", vet[i]);
		}
	}
	printf("\n soma dos indices pares positivos: %d", soma);
}

//Main Algoritmo principal
void main(){
	setlocale(LC_ALL, "portuguese");
	
	int vet[TAM];
	
	lerVetor(vet, TAM);
	mostrarVetor(vet, TAM);
	
}