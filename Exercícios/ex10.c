/*
10. Elabore uma função que apresente uma mensagem na tela, leia um inteiro do teclado e o retorne somente
se este valor for positivo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//função para retornar um valor positivo
int returnPositivo(){
	int positivo;
	
	printf("Informe um valor positivo:\n");
	
	do{
		scanf("%i", &positivo);
		if(positivo < 0){
			printf("O valor não é positivo!!!");
		}
	}while(positivo < 0);
	return positivo;
}

void main(){
	setlocale(LC_ALL, "");
	int p;
	
	p = returnPositivo();
	printf("Valor informado: %i", p);	
}