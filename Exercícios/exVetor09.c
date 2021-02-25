/*
9. Dados dois vetores A e B de 15 elementos, criar um vetor C que representa a junção de A e B. 
Ou seja, C contém os elementos de A seguidos dos elementos de B.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 10

//algoritmo principal
void main(){
	setlocale(LC_ALL, "portuguese");
	
	int i, vetA[TAM], vetB[TAM], vetC[2*TAM];
	int contA, contB, contC;
	
	//Elemento do vetA[]
	for(i = 0; i < TAM; i++){
		printf("Informe o elemento do indece A %i :", i);
		scanf("%i", &vetA[i]);
		vetC[i] = vetA[i];
	}
	printf("\n");
	//Elemento do vetB[]
	for(i = 0; i < TAM; i++){
		printf("Informe o elemento do indece b %i : ", i);
		scanf("%i", &vetB[i]);
		vetC[i+TAM] = vetB[i];
	}
	
	//Mostrar vetC 
	printf("\n");
	printf("vetC :\n");
	for(i = 0; i < 2 * TAM; i++){
		printf("%i\n", vetC[i]);
	}
	
}