/*
4. Elabore um programa que leia um vetor de 50 posições do teclado e um número n qualquer. 
Mostre na tela o índice dos elementos que são inferiores a n.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//controla a quantida de valores que sera armazenado
#define TAM 50

//procedimento ler 50 números e reservar na memória
void lerVetor(int *vet, int tam){
	int i;
	for(i = 0; i < tam; i++){
		printf("informe %do valor do teclado: ", i+1);
		scanf("%i", &vet[i]);		
	}
}

//função mostrar vetor
int mostrarVetor(int *vet, int tam){
	int i;
	
	for(i = 0; i < tam; i++){
		printf("%d -", vet[i]);
	}
}

//Main Algoritmo principal
void main(){
	setlocale(LC_ALL, "portuguese");
	
	int i ,vet[TAM], num;
	
	lerVetor(vet, TAM);
	mostrarVetor(vet, TAM);
	
	printf("\n\n informe um número: ");
	scanf("%d", &num);
	
	printf("\n indices inferiores a %d : ", num);
	for(i = 0; i < TAM; i++){
		if(vet[i] < num){
			printf("%d - ", vet[i]);
		}
	}
}