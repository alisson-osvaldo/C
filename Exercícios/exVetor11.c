/*
11. Faça um programa que leia um vetor A de 30 números. Armazene em um vetor B o maior elemento de A,
o menor elemento de A, a soma dos elementos de A e a média dos elementos de A.
Apresente o vetor B na tela.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 10

//algoritmo principal
void main(){
	setlocale(LC_ALL, "");
	int vetA[TAM], vetB[TAM];
	int i, maior = 0, menor = 0, posicaoA = 0, posicaoB = 0, soma = 0, media = 0;
	
	//ler vetA
	for(i = 0; i < TAM; i++){
		printf("Informe o %io indice: ", i+1);
		scanf("%d", &vetA[i]);
		soma = soma + vetA[i];     //soma de todos os elementos do vetA
		media = soma/TAM;
		//para aparecer menor valor
		if(i==0){maior = vetA[i]; menor = vetA[i];}
		if(vetA[i] > maior){       //maior elemento do vetA
				maior = vetA[i]; 
				posicaoA = i;
						
		}
		if(vetA[i] < menor){      //menor elemento do vetA
			menor= vetA[i];
			posicaoB = i;				
		}		
	}
	
	//vetB recebe maior, menor, soma, media
	vetB[0] = maior; 
	vetB[1] = menor;
	vetB[2] = soma;
	vetB[3] = media;
	//mostrar vetB
	printf("\nvetB:\n ");
	printf("( 1:Maior valor - 2:Menor valor - 3:Soma de todos os valores - 4:É a média dos valores ):\n");
	for(i = 0; i < 4; i++){
		printf(" %i= %i\n", i+1, vetB[i]);
	}
	printf("\n");
	printf("Posição [i] do maior elemento: %i\n", posicaoA);
	printf("Posição [i] do menor elemento: %i", posicaoB);
}