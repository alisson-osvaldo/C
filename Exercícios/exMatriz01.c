/*
01. Faça um programa que leia uma matriz de 10 x 8 e apresente na tela o maior e o menor elemento da matriz.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define LIN 10
#define COL 8

void main(){
	setlocale(LC_ALL, "");
	
	
	int mat[LIN][COL];
	int i, j, menor, maior, iMaior, jMaior, iMenor, jMenor;
	
	//ler matriz
	for(i = 0; i < LIN; i++){
		for(j = 0; j < COL; j++){
			printf("Informe o elemento [%d,%d]: ", i, j);
			scanf("%d", &mat[i][j]);
		}
	}
	
	//procurar o menor eo maior elemento
	menor = mat[0][0];
	maior = mat[0][0];
	
	for(i = 0; i < LIN; i++){
		for(j = 0; j < COL; j++){
		
			if(mat[i][j] < menor){
				menor = mat[i][j];
				iMenor = i;
				jMenor = j;
			}	
			else if(mat[i][j] > maior){
				maior = mat[i][j];
				iMaior = i;
				jMaior = j;
			}
		}
    }
		printf("Maior: %d\n", maior);
		printf("Menor: %d\n", menor);
		printf("Posição do Menor numero: LINHA:%d COLUNA:%d\n", iMenor, jMenor);
		printf("Posição do Maior numero: LINHA:%d COLUNA:%d\n", iMaior, jMaior);
}
