/*
10. Dados dois vetores A e B de tamanho igual a 10, crie um vetor C (do mesmo tamanho)
cujos elementos são a soma de cada um dos elementos de A e B.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 10

//procedimento para ler vetor
void lerVetor(int *vet, int tam){
	int i;
	
	for(i = 0; i < tam; i++){
		printf("Informe o valor indice %i: ", i);
		scanf("%d", &vet[i]);
	}
	
	//somar vetor A e B e colocar resultado no vetor C
	for(i = 0; i < tam; i++){
		
	}	 
}

//procedimento para mostrar Vetor
void mostrarVetor(int *vet, int tam){
	int i;
		
	for(i = 0; i < tam; i++){
		printf("%d - ", vet[i]);
	}
}

void main(){
	setlocale(LC_ALL, "");
	
	int vetA[TAM], vetB[TAM], vetC[TAM];
	int i;
	
	printf("Vetor A:\n");
	lerVetor(vetA, TAM);
	printf("\nVetor B:\n");
	lerVetor(vetB, TAM);
	
	printf("\n");
	printf("VetA:\n");
	mostrarVetor(vetA, TAM);
	printf("\n");
	printf("VetB:\n");
	mostrarVetor(vetB, TAM);
	
	//soma do vetA + vetB
	printf("\n\n");
	printf("Vetor C:\n")	;
	for(i = 0; i < TAM; i++){
		vetC[i] = vetA[i] + vetB[i];
		printf("%i - ", vetC[i]);
	}
	
}