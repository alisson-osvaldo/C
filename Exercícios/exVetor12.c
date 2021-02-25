/*
12. Elabore um programa que leia os vetores A e B de 15 elementos e gere um vetor C de acordo com a seguinte regra:
a. Os elementos das posições pares de C são os elementos das posições pares de A;
b. Os elementos das posições ímpares de C são os elementos das posições ímpares de B;
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 15

void main(){
	setlocale(LC_ALL, "");
	
	int vetA[TAM], vetB[TAM], vetC[TAM];
	int i;
	
	//ler A
	for(i = 0; i < TAM; i++){
		printf("Informe o %io valor do indice A: ", i+1);
		scanf("%i", &vetA[i]);
	
	}
	printf("\n");
	//ler B
	for(i = 0; i < TAM; i++){
		printf("Informe o %io valor do indice B: ", i+1);
		scanf("%i", &vetB[i]);
		
	}
	
	//jogar par de A = par C, e impar de B = impar C 
	for(i = 0; i < TAM; i++){
		//se indice for impar armazena impar do vetB no vetC
		if(i%2 == 1){
			vetC[i] = vetB[i];
		}
		//se indice for par armazena par do vetA no vetC
		if(i%2 == 0){
			vetC[i] = vetA[i];
		}
	}
	
	//mostrar vetA
	printf("\n\n");
	printf("A: \n");
	for(i = 0; i < TAM; i++){
		printf("%i - ", vetA[i]);		
	}
	
	//mostrar vetB
	printf("\n\n");
	printf("B: \n");
	for(i = 0; i < TAM; i++){	
		printf("%i - ", vetB[i]);	
	}
	
	//mostrar vetC
	printf("\n\n");
	printf("C: \n");
	for(i = 0; i < TAM; i++){	
		printf("%i - ", vetC[i]);	
	}
	
}