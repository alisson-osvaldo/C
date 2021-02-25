/*
07. Elabore um programa que leia um vetor com 5 notas de um aluno e um outro vetor
com 5 pesos e calcule a média ponderada do aluno.

Ex.: notas: 7.5, 9.2 pesos: 6, 4 média ponderada: (7.5 * 6 + 9.2 * 4) / (6 + 4)
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

#define TAM 2

//variavel global
int vet2[TAM];	
float vet1[TAM];

//procedimento para ler notas 
void lerVetorN(){
	int i;
	for(i = 0; i < TAM; i++){
		printf("Informe a %d nota:\n", i+1);
		scanf("%f", &vet1[i]);
	}
	printf("\n");
}

//procedimento para ler o peso
void lerVetorP(){
	int i;
	for(i = 0; i < TAM; i++){
		printf("Informe o %d Peso:\n", i+1);
		scanf("%i", &vet2[i]);
	}
}

//mostrar vetor
void mostrarVetor(){
	int i;
	
	printf("\n");
	printf("Notas:\n");
	for(i = 0; i < TAM; i++){
		printf("%0.1f\n", vet1[i]);
	}
	
	printf("\n");
	printf("Peso:\n");
	for(i = 0; i < TAM; i++){
		printf("%i\n", vet2[i]);
	}
}

int mediaPonderada(){
	int i;
	float result;
	int somaPeso = 0;
	int soma = 0;
	
	for(i = 0; i < TAM; i++){
		soma = vet1[i] * vet2[i] + soma;//soma de todas as nota* peso;
		somaPeso = somaPeso + vet2[i];  //soma dos pesos
	}
	result = soma / somaPeso;// média ponderada
	printf("result: %.1f\n", result);  
	return result;
}

//Main Algoritmo principal
void main(){
	setlocale(LC_ALL, "portuguese");
	float result;
	
	lerVetorN();// chamar procedimento para lê as notas
	lerVetorP();// chamar procedimento para lê os pesos
	mostrarVetor();// chamar procedimento para mostrar as notas e pesos

	result = mediaPonderada();// chamar função que calcula a média ponderada
	printf("Média ponderada do aluno: %.1f\n", result);
	
}