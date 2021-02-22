/*
3. Elabore uma fun��o que verifica se um n�mero � perfeito ou n�o. N�mero perfeito � um n�mero natural
cuja soma dos seus divisores pr�prios (exclu�do o pr�prio n�mero) coincide com o n�mero.

N�mero 	   Divisores 	                           Soma dos divisores
6 		   1, 2, 3                                 1 + 2 + 3 = 6
28         1, 2, 4, 7, 14                          1 + 2 + 4 + 7 + 14 = 28
496        1, 2, 4, 8, 16, 31, 62, 124, 248        1 + 2 + 4 + 8 + 16 + 31 + 62 + 124 + 248 = 496
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// em C, 0 representa FALSO, qualquer outro n�mero representa VERDADEIRO
//Fun�o para verificar se o n�mero � perfeito
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
	setlocale(LC_ALL, "Portuguese");			// ajuste para o idioma portugu�s
	
	int n, result;
	
	printf("Informe um n�mero: ");				// ESCREVA
	fflush(stdin);								// limpar o buffer do teclado
	scanf("%d", &n);							// LEIA
	
	result = perfeito(n);						// chamada da fun��o perfeito e armazenamento do resultado na vari�vel result
	
	if(result == 1){							
		printf("O n�mero %d � perfeito.\n", n);
	} else {
		printf("O n�mero %d n�o � perfeito.\n", n);
	}
}
