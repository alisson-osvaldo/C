/*

exemplo metetodos de ordenação: BubbleSort(Bolha), SelectionSort (Seleção Direta),

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// procedimento que mostra o vetor na tela
void mostraVetor(int *vet, int tamanho){
	int i;
	for(i = 0; i < tamanho; i++){
		printf("%i ", vet[i]);
	}
	printf("\n");
}

// procedimento que ordena um vetor pelo método BubbleSort (Bolha)
void bubbleSort(int *vet, int tamanho){
	int i, aux, limDir, troca;
	
	
	for(limDir = tamanho - 1; limDir > 0; limDir--){
		printf("Limite da Direita: %i\n", limDir);
		troca = 0;
		for(i = 0; i < limDir; i++){			
			if(vet[i] > vet[i+1]){	//se o elemento do indice [i] do vetor for maior que o [i+1] 		
				aux = vet[i];		//o aux guarda o valor de vet[i]	
				vet[i] = vet[i+1];	//e vet[i] recebe o valor do [i+1] 	
				vet[i+1] = aux;	    //e vet[i+1] recebe valor do aux 
				troca = 1;
			}
			mostraVetor(vet, tamanho);
		}
		
		if(troca == 0){
			break;
		}
	}	
}

// procedimento que ordena um vetor pelo método SelectionSort (Seleção Direta)
void selectionSort(int *vet, int tamanho){
	int i, j, jMenor, menor;
	
	for(i = 0; i < tamanho-1; i++){	
		menor = vet[i];
		jMenor = i;
		for(j = i+1; j < tamanho; j++){
			if(vet[j] < menor){
				menor = vet[j];
				jMenor = j;
			}
		}		
		vet[jMenor] = vet[i];
		vet[i] = menor;
		mostraVetor(vet, tamanho);
	}
}


void main(){
	int vetA[5] = {40, 50, 30, 10, 20};
	int vetB[10] = {80, 70, 50, 30, 10, 20, 60, 99, 40, 90};
	
	printf("BubbleSort - vetor original:\n");
	mostraVetor(vetA, 5);
	printf("\n");
	bubbleSort(vetA, 5);
	
	printf("\n\nBubbleSort - vetor original:\n");
	mostraVetor(vetB, 10);
	printf("\n");
	bubbleSort(vetB, 10);
	
	printf("\n\nSelectionSort - vetor original:\n");
	mostraVetor(vetA, 5);
	printf("\n");
	selectionSort(vetA, 5);
	
	printf("\n\nSelectionSort - vetor original:\n");
	mostraVetor(vetB, 10);
	printf("\n");
	selectionSort(vetB, 10);
	
}
