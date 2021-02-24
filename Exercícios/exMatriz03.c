/*
03. Crie uma matriz para armazenar 3 notas de alunos e mostre a média. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
   	setlocale(LC_ALL, "");
   
   	float mat[2][4], soma, media;
   	int i, j;
   	
   
   	for(i = 0; i < 2; i++){   
   		printf("\n\n");
	   	printf("Informe as 3 notas do aluno %i\n", i+1);
	   	soma = 0;
	   	for(j = 0; j < 3; j++){
	      	printf("Informe a nota [%d,%d]: ", i, j);
	      	scanf("%f", &mat[i][j]);
	   	  	soma = soma + mat[i][j];
	   	}
	   	media = soma/3;
		mat[i][3] = media;
		printf("\n");	   
	   	printf("Média do aluno %d: %.2f\n\n", i, media);	
	}
	

   	printf("\n\nNotas armazenadas:\n");
   	for(i = 0; i < 2; i++){  
	   printf("Aluno %i:	", i+1); 
	   	for(j = 0; j < 3; j++){
	   	   	printf("%.2f\t", mat[i][j]);
	   	}
	   	printf(" -- %.2f", mat[i][3]);
	   	printf("\n");
	}
}  


