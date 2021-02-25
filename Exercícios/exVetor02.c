/*
02. Faça um programa que leia a nota de 15 alunos, calcule a média entre elas e apresente 
a diferença entre cada nota e a média.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 15

//Procedimento para ler e armazenar na memória vetor
void lerVetor(int *vet, int tam){
	int i;
	for(i = 0; i < tam; i++){
		printf("Informe a nota do aluno %i: ", i+1);
		scanf("%i", &vet[i]);
	}	
}

//Procedimento Mostrar vetor e calcula média
 int mostrarVetor(int *vet, int tam){
 	int i, soma, media;
 	
 	soma = 0;
	for(i = 0; i < TAM; i++){
		printf(" \nNota do aluno %d : %d \n", i+1 ,vet[i]);
		soma = soma + vet[i];
		media = soma / tam;
	}
	printf("\n");
	printf("\nMédia: %d", media);
	printf("\n\n");
	return media;
 }

//procedimento para calcular a diferença
void diferenca(int nota, int media, int i){
	int diferenca;

	diferenca = nota - media;
	printf("\n");
	printf("Aluno %i:\n", i);
	printf("Diferença: %i\n", diferenca);
	printf("\n");
	
}

//Main Algoritmo principal
void main(){
	setlocale(LC_ALL, "portuguese");
	
	int i, soma, m, vet[TAM];
	
	lerVetor(vet, TAM);
	m = mostrarVetor(vet, TAM);

	for(i = 0; i < TAM; i++){
		diferenca(vet[i], m, i);
	}
				
}