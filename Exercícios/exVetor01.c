/*
01. Construa um programa que leia um vetor de 15 posições e calcule a média destes valores. Na seqüência, 
apresente na tela os valores que são iguais ou superiores à média.
*/

//Biblioteca 
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//definição de constantes
#define TAM 15

//Algoritmo principal
void main(){
	setlocale(LC_ALL, "portuguese");
	int soma = 0;
	//Declarar variáveis
	int vet[TAM], media, i;
	
	//Ler vetor
	for(i = 0; i < TAM; i++){
		printf("Informe o limite do %i: ", i+1);
		//fflush(stdin); É obrigatório apenas para ler variaveis do tipo char 
		scanf("%i", &vet[i]);
		soma = soma + vet[i];
	}
	//Calcular a média
	media = soma / TAM;
	printf("\nmédia: %i\n\n", media);
	
	//mostrar na tela os lememntos maiores ou iguais a media
	for(i = 0; i < TAM; i++){
		if(vet[i] >= media){
		printf("%i\t", vet[i]);
		}
	}	
}