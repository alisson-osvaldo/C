/*
03. Faça um programa que leia 20 números do teclado e os armazene em um vetor. 
Crie um segundo vetor de 20 posições que armazene o dobro de cada um dos números do 
primeiro vetor e apresente este vetor.
*/

//Biblioteca 
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 20

//Algoritmo principal
void main(){
	setlocale(LC_ALL,"portuguese");
	int vet1[TAM], vet2[TAM], num, i;
	
	//vet1 para armazenar 20 números
	for(i = 0; i < TAM; i++){
		printf("Informe um número: ");
		scanf("%d", &vet1[i]);
		vet2[i] = 2*vet1[i];
	}
	 //vetor para armazenar o dobro dos 20 números do vet1
	for(i = 0; i< TAM; i++){
		printf("%d\t", vet2[i]);
	}
}