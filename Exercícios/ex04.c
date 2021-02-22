/*
4. Elabore uma função que calcule o Máximo Divisor Comum entre dois números pelo Método de Euclides.
30/21  ->  21/9   ->  9/3  ->  3/0
9  1       3  2       0 3      - -
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

void main(){
	setlocale(LC_ALL, "portuguese");
	
	int n1, n2, divisao, resto;
	
	n1 = 0;
	n2 = 0;
	
	//ler valores
	printf("Informe um valor: ");
	fflush(stdin);
	scanf("%d", &n1);
	
	printf("Informe o divisor: ");
	fflush(stdin);
	scanf("%d", &n2);
	
	//divisão
	if(n2 == 0){
		printf("Não é possivel dividir por zero");
	}
	
	do{
	
	divisao = n1 / n2;
	printf("resultado da divisão: %d / %d : %d\n", n1, n2, divisao);
		
	resto = n1 % n2;
	printf("Resto da divisão: %d\n\n", resto);
	
	n1 = n2;
	n2 = resto;
	
	 	
	}while(divisao != 0);	
}
