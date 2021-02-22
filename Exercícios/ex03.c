/*
3. Elabore uma função que verifica se um número é perfeito ou não. Número perfeito é um número natural
cuja soma dos seus divisores próprios (excluído o próprio número) coincide com o número.

Número 	   Divisores 	                           Soma dos divisores
6 		   1, 2, 3                                 1 + 2 + 3 = 6
28         1, 2, 4, 7, 14                          1 + 2 + 4 + 7 + 14 = 28
496        1, 2, 4, 8, 16, 31, 62, 124, 248        1 + 2 + 4 + 8 + 16 + 31 + 62 + 124 + 248 = 496
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// em C, 0 representa FALSO, qualquer outro número representa VERDADEIRO
//Funão para verificar se o número é perfeito
int perfeito(int n){
	int cont, soma;
	soma = 0;
	
	for(cont = 1; cont <= n/2; cont++){
		if(n%cont == 0){
			soma = soma + cont;
		}
	}
	
	if(soma == n){
		return 1;// 1 significa VERDADEIRO
	} else {
		return 0;// 0 significa FALSO
	}
}


// algoritmo principal
void main(){
	setlocale(LC_ALL, "Portuguese");			// ajuste para o idioma português
	
	int n, result;
	
	printf("Informe um número: ");				// ESCREVA
	fflush(stdin);								// limpar o buffer do teclado
	scanf("%d", &n);							// LEIA
	
	result = perfeito(n);						// chamada da função perfeito e armazenamento do resultado na variável result
	
	if(result == 1){							
		printf("O número %d é perfeito.\n", n);
	} else {
		printf("O número %d não é perfeito.\n", n);
	}
}
