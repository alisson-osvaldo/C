/*
12.Elabore uma função que apresente um menu qualquer na tela. Faça a chamada desta função no algoritmo
principal. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Função menu
int menu(){
	int genero;
	
	do{
		printf("Escolha um genero musical:\n");
		printf("1.Rock\n");
		printf("2.Sertanejo\n");
		printf("3.Pagode\n");
		scanf("%i", &genero);
	}while(genero < 1 || genero > 3);
	return genero;
	
}

void main(){
	setlocale(LC_ALL, "");
	int op;
	
	op = menu();
	switch(op){
		case 1: 
			printf("\n");
			printf("você escolheu Rock\n");
		break;
		
		case 2:
			printf("\n");
			printf("você escolheu Sertanejo\n");
		break;
		
		case 3:
			printf("\n");
			printf("você escolheu Pagode\n");
		break;
	}
}