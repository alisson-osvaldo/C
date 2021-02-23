/*
8. Escrever uma fun��o que receba dois n�meros inteiros, positivos, e determine o produto dos mesmos,
utilizando o seguinte m�todo de multiplica��o:

a. Dividir, sucessivamente, o primeiro n�mero por 2 at� que se obtenha 1 como quociente.
b. Paralelamente, dobrar sucessivamente o segundo n�mero.
c. Somar os n�meros da segunda coluna que tenham um n�mero �mpar na primeira coluna. O

total obtido � o produto procurado.

Ex.: 9 * 6 = 54        9	6         6 + 48 = 54
					   4	12
					   2	24
					   1	48

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct 
	{
		int n1;
		int n2;
	
	}valoresInteiros;
 	valoresInteiros valor; 
 	
//procedimento para receber valores do teclado
void receberValores(){
	
	
	printf("Informe n1: ");
	scanf("%i", &valor.n1);
	printf("Informe n2: ");
	scanf("%i", &valor.n2);
}

//Fun��o para dividir n1 e dobrar o valor de n2
int produto(){
	int soma;
	int x = 0;
	int aux = valor.n1;
	int cont = 0;
	
//dividir n1 por 2 at� resultado for 1
	do{
		x = aux / 2;
		aux = x;
		cont++;
	}while(x != 1);
		
//somar o valor de n2 por ele mesmo (cont vezes)
	int auxN2 = valor.n2; 
	int y = 0;
	int i;
	
	printf("\n");
	
	for(i = 0; i < cont; i++){ 
		y = auxN2;
		auxN2 = auxN2 + y;
	}
	
	//Soma n1 + n2
	soma = valor.n2 + auxN2;
	return soma;
}

void main(){
	setlocale(LC_ALL, "");
	int a;

	receberValores();
	// mostrar valores de n1 e n2
	printf("\n");
	printf("Informe n1: %i\n", valor.n1);
	printf("Informe n2: %i\n", valor.n2);
	printf("\n");
	
	//Resultado
	a = produto();
	printf("Resultado = %i", a);
	
	
}

