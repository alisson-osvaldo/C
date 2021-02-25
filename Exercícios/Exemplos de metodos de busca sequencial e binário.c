/*
Exemplos de metodos de buscas
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int buscaSequencial(int *vet, int tamanho, int num){
	int i;
	
	for(i = 0; i < tamanho; i++){
		if(vet[i] == num){
			return i;
		} 
	}
	return -1;
}

int buscaBinaria(int *vet, int tamanho, int num){
	int esq, dir, central;			// índices
	
	esq = 0;
	dir = tamanho-1;
	
	while(esq <= dir){
		central = (esq + dir)/2;
		
		if(num == vet[central]){				
			return central;
		}
		
		if(num > vet[central]){
			esq = central+1;
		} else {
			dir = central-1;
		}		
	}
	return -1;
}


// mostrar um vetor de qualquer tamanho na tela
void mostraVetor(int *vet, int tam){
	int i;
	for(i = 0; i < tam; i++){
		printf("%i ", vet[i]);
	}
	printf("\n");
}


void main(){
	setlocale(LC_ALL, "");
	
	int vetA[5] = {10, 20, 30, 40, 50};
	int vetD[10] = {100, 80, 20, 30, 50, 60, 70, 90, 10, 40};
	
	int i;
	
	printf("vetA: vetor menor, elementos ordenados\n");
	mostraVetor(vetA, 5);
	
	printf("\nvetD: vetor maior, elementos desordenados\n");
	mostraVetor(vetD, 10);
	
	
	printf("\nTestes com a busca sequencial\n");
		
	i = buscaSequencial(vetA, 5, 50);	
	printf("Busca número 50 no vetA: funciona, retorna a posição %i\n", i);
		
	i = buscaSequencial(vetA, 5, 55);
	printf("Busca número 55 no vetA: funciona, retorna o código de erro %i\n", i);
	
	i = buscaSequencial(vetD, 10, 30);
	printf("Busca número 30 no vetD: funciona, retorna a posição %i\n", i);
	
	i = buscaSequencial(vetD, 10, 15);
	printf("Busca número 15 no vetD: funciona, retorna o código de erro %i\n", i);
	
	//////////////////////////////////////////
	
	printf("\n\nTestes com a busca binária\n");
	i = buscaBinaria(vetA, 5, 50);	
	printf("Busca número 50 no vetA: funciona, retorna a posição %i\n", i);
	
	i = buscaBinaria(vetA, 5, 55);
	printf("Busca número 55 no vetA: funciona, retorna o código de erro %i\n", i);
	
	i = buscaBinaria(vetD, 10, 30);
	printf("Busca número 30 no vetD: não há garantia que funciona, o vetor está desordenado: %i\n", i);
	
	i = buscaBinaria(vetD, 10, 15);
	printf("Busca número 15 no vetD: não há garantia que funciona, o vetor está desordenado: %i\n", i);
}