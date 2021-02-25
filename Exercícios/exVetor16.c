/*
18.	Elabore um programa que leia 30 números do teclado e preencha um vetor de acordo com a 
seguinte regra: com exceção do 1º número, só é permitido armazenar um número se ele for maior 
que o anterior.
Ex.: se o primeiro valor lido for 5, o próximo valor lido só poderá ser maior que 5. 
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 30

//procedimento que recebe o endereço de memória de um vetor e o seu tamanho e faz a leitura do vetor
void leVetorCrescente(int *vet, int tam){
	int i;
	
	// leitura do 1o elemento do vetor
	printf("Informe o elemento 0: ");
	scanf("%i", &vet[0]);
		
	for(i = 1; i < TAM; i++){
		do{
			printf("Informe o elemento %i: ", i);
			scanf("%i", &vet[i]);	
			if(vet[i] <= vet[i-1]){
				printf("Informe um valor maior que o anterior!\n\n");
			}			
		}while(vet[i] <= vet[i-1]);
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

void main(){
	int vet[TAM];
	leVetorCrescente(vet, TAM);
	mostraVetor(vet, TAM);
}