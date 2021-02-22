/*
1. A expressão an = a1 + (n ? 1) * r ? denominada termo geral da PA. Nesta fórmula, temos que an é o termo
de ordem n (n-ésimo termo) , r é a razão e a1 é o primeiro termo da Progressão Aritmética. Elabore uma
função que retorne o n-ésimo termo de uma progressão aritmética.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//função que retorno o e-nésimo termo de uma PA
int pa(int al,int n ,int r){
	int an = al + (n-1) * r;
	return an;
}

void main(){
	setlocale(LC_ALL, "portuguese");
	
	//declaração de váriaves
	int al, n, r, an;
	
	
	 //ler dados
	 printf("Informe o 1o termo: ");
	 fflush(stdin);
	 scanf("%i", &al);
	 
	 printf("Informe n: ");
	 fflush(stdin);
	 scanf("%i", &n);
	 
	 printf("Informe a razão: ");
	 fflush(stdin);
	 scanf("%i", &r);
	 
	 //chamar função result
	 an = pa(al, n, r);
	 printf("N-ésimo termo da PA: %i\n", an);
	 	 
}
