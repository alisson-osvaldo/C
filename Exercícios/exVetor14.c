/*
14. Elabore um método que calcule o produto escalar entre dois vetores de inteiros de tamanho igual a 5.
Exemplo: {0, 2, 4, 6, 8} • {1, 3, 5, 7, 9} = 0*1 + 2*3 + 4*5 + 6*7 + 8*9 = 140
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 5

//procedimento para ler o *vet
void lerVetor(int *vet, int tam){
	int i;
	for(i = 0; i < tam; i++){
		printf("informe o valor do indice %i: ", i+1);
		scanf("\n%i", &vet[i]);
	}
	printf("\n");
}
	
//procedimento para mostrar e calcular o produto escalar do *vet
void mostrarVetor(int *vet , int tam){
	int i;
	for(i = 0; i < tam; i++){
		printf("%i -", vet[i]);
	}
	printf("\n");
}

int prodEscalar(int *vet1, int *vet2, int tam){
	int i, soma;
	
	soma = 0;
	
	for(i = 0; i < TAM; i++){
		soma = soma + vet1[i] * vet2[i];
	}
	return soma;
}


//Algoritmo principal
void main(){
	setlocale(LC_ALL, "portuguese");
	
	int vet1[TAM], vet2[TAM], result;
	
	lerVetor(vet1, TAM);
	lerVetor(vet2, TAM);
	
	result = prodEscalar(vet1 , vet2, TAM);
	
	printf("1o vetor\n");
	mostrarVetor(vet1, TAM);
	printf("2o vetor\n");
	mostrarVetor(vet2, TAM);
	printf("Produto escalar: %i", result); 
		
}