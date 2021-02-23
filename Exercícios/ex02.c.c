/*
2. Dada uma equação do segundo grau (ax2 + bx + c = 0), elabore um procedimento que calcule as raízes
desta equação de acordo com a Fórmula de Báskara e apresente o seu resultado na tela.

x = -b +- √▲      onde     ▲ = b2 – 4ac
       2a                  ▲ > 0: duas raízes reais e diferentes
			   ▲ = 0: duas raízes reais e iguais
			   ▲ < 0: não há raízes reais
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

//procedimento que apresenta as raízes de uma equação do 2o grau
void baskara(int a, int b, int c){
	int delta, x1, x2;
	
	delta = pow(b, 2) - 4*a*c;           // pow(a, b): a elevado a b. POT(a, b) em PORTUGOL
	
	if(delta > 0){
		x1 = (-b + sqrt(delta))/(2*a);   // sqrt(a): raiz quadrada de a. RAIZ(a) em PORTUGOL
		x2 = (-b - sqrt(delta))/(2*a);
		printf("Raízes diferentes: x1:%d x2:%d\n", x1, x2);   
	} else if(delta == 0){
		x1 = (-b + sqrt(delta))/(2*a);
		printf("Raízes iguais: x1:%d x2:%d\n", x1, x1);		
	} else {
		printf("Não há raízes reais");							
	}
}

// algoritmo principal
void main(){
	setlocale(LC_ALL, "Portuguese");// ajuste para o português
	int a, b, c;
	
	printf("Informe a: ");										
	fflush(stdin);
	scanf("%d", &a);											
	
	printf("Informe b: ");
	fflush(stdin);
	scanf("%d", &b);
	
	printf("Informe c: ");
	fflush(stdin);
	scanf("%d", &c);
	
	baskara(a, b, c);// chamada do procedimento baskara
}