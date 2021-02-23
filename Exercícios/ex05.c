/*
5. Elabore um metodo que efetue a exponenciacao de um numero x por um expoente y.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

//Algoritmo principal
void main(){
	setlocale(LC_ALL, "portuguese");
	
	int i, iN, x;
	float exponenciacao, expoenteNegativo, num, expoente, n2 ;
	
	i= 1;
	iN = 0;
	n2 = 0;
	exponenciacao = 0;
	
	printf("Informe um valor da base: ");
	fflush(stdin);
	scanf("%f", &num);
	
	printf("Informe o valor do expoente: ");
	fflush(stdin);
	scanf("%f", &expoente);
	
	
	n2 = num;
	
	//se o expoente  1 ou 0
	if(expoente == 1){
			x = num * expoente;
			printf("resultado da exponenciação: %d\n\n", x);
		}
	if(expoente == 0){
		printf("Resultado é zero\n\n");
	}
	
	do{
		//exponenciação de x por y
		
		exponenciacao = n2 * num;
		n2 = exponenciacao;
		
		if(expoente < 0){
		expoenteNegativo = 1 / exponenciacao;
		}
				
		i++;
		iN--;
							
	}while(i != expoente && iN != expoente );// (-2) calculos que foram feitos fora do (do while)
	
		if(expoente > 0){
		printf("resultado da exponenciação: %.1f\n\n", exponenciacao);
		}
		if(expoente < 0){
		printf("resultado da exponenciação: %.1f\n\n", expoenteNegativo);
		}		
}
