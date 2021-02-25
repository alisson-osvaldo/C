/*
8. Faça um programa que leia dois vetores de 10 elementos do teclado e verifique 
se eles são iguais ou não. Para serem iguais, todos os elementos dos dois vetores devem coincidir.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 5

//algoritmo principal
void main(){
	setlocale(LC_ALL, "portuguese");
	
	int i, vet1[TAM], vet2[TAM], iguais;
	
	//ler vet1[]
	for(i = 0; i < TAM; i++){
	printf("Informe o elemento do indice %i :", i);
	scanf("%i", &vet1[i]);
	}
	printf("\n");
	// ler vet2[]
	for(i = 0; i < TAM; i++){
	printf("Informe novamente o elemento do indice %i :", i);
	scanf("%i", &vet2[i]);
	}
	printf("\n");
	//comparar vet1[] e vet2[] e vêr se os elementos conincide
	iguais = 0;
	for(i = 0; i < TAM; i++){
		if(vet1[i] == vet2[i]){
			iguais++;
		}
	}
	
	if(iguais == TAM){
		printf("Os elementos são iguais\n");
		}
		else {
			printf("Os elementos não são iguais\n");
		}
	
	}
	
