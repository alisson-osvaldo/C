/*
13. Crie um programa que leia um vetor A de 10 posições do teclado e, ao final da leitura, 
copie os elementos de A em B de forma invertida. Ou seja, o primeiro elemento de A é o último 
elemento de B, o segundo elemento de A é o penúltimo elemento de B, e assim por diante.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 10

//procedimento que recebe o endereço de memória de um vetor e o seu tamanho e faz a leitura do vetor
void leVetor(int *vet, int tam){
	int i;
	for(i = 0; i < tam; i++){
		printf("Informe o elemento %i: ", i);
		scanf("%i", &vet[i]);
	}	
}

// procedimento que recebe o endereço de memória de um vetor e o seu tamanho e faz a amostragem do vetor
void mostraVetor(int *vet, int tam){
	int i;
	for(i = 0; i < tam; i++){
		printf("%i - ", vet[i]);
	}
	printf("\n");	
}

//Algoritmo principal
void main(){
	setlocale(LC_ALL, "portuguese");
	
	int vetA[TAM], vetB[TAM], i, j;
	
	leVetor(vetA, TAM);
	
	for(i = 0, j = TAM-1; i < TAM; i++, j--){
		vetB[j] = vetA[i];
	}
	
	printf("\n");
	printf("Vetor A: ");
	mostraVetor(vetA, TAM);	
	printf("\nVetor B: ");
	mostraVetor(vetB, TAM);
}