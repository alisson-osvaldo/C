/*
02. Elabore um programa que leia uma matriz A(5 x 5) do teclado e crie uma matriz B onde 
cada elemento de B é o triplo do elemento correspondente de A.
									j
matA = {{1, 1, 1},			i	[0,0] [0,1] [0,2]
        {1, 1, 1},				[1,0] [1,1] [1,2]
        {1, 1, 1}};				[2,0] [2,1] [2,2]
      
matB = {{3, 3, 3},
        {3, 3, 3},
		{3, 3, 3}};       
*/

#include <stdio.h>
#include <stdlib.h>

#define LIN 5
#define COL 5

void main(){
	// declaração das variáveis
	int matA[LIN][COL], matB[LIN][COL];
	int i, j; //i: índice da linha; j: índice da coluna
	
	// ler a matA do teclado e produzir a matB
	for(i = 0; i < LIN; i++){
		for(j = 0; j < COL; j++){
			printf("Informe o elemento [%d,%d]: ", i, j);
			scanf("%i", &matA[i][j]);
			matB[i][j] = 3 * matA[i][j];
		}
	}
	
	// mostrar a matA
	printf("## Matriz A ##\n");
	// o for do i controla a linha
	for(i = 0; i < LIN; i++){
		// o for do j controla a coluna
		for(j = 0; j < COL; j++){
			printf("%i  ", matA[i][j]);
		}
		// trabalhei a última coluna - terminou a linha
		printf("\n");
	}
	// trabalhei a última linha - terminou a matriz
	
	// mostrar a matB
	printf("\n## Matriz B ##\n");
	for(i = 0; i < LIN; i++){
		for(j = 0; j < COL; j++){
			printf("%i  ", matB[i][j]);
		}
		// trabalhei a última coluna - terminou a linha
		printf("\n");
	}	
}