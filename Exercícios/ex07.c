/*
7. Fa�a um algoritmo para um programa de apostas da LOTO. O algoritmo dever� ler, inicialmente, as cinco
dezenas sorteadas e, a seguir, as apostas dos jogadores contendo:

a. N�mero da aposta
b. Quantidade de dezenas apostadas (no m�ximo 10)
c. As dezenas apostadas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

struct aposta
{
	int	numero_da_aposta;	  //N�meros da aposta do jogador
	int quantidade_apostadas; //Quantidades de dezenas apostadas(m�x 10)
};
struct aposta vetJogador[5]; //vetor para armazenar dados do jogo de cada jogador


struct dezenas_apostadas
{
	int dezenas;	//Dezenas apostadas pelo jogador 
};
struct dezenas_apostadas vetDezenas[10];
	
//fun��o para sortear 5 n�meros alea�rios entre 0 e 99
int sorteio(int x){
	int i, numero[5];
	
	for(i = 0; i < 5; i++){
		numero[i] = 10 + (rand() % 90); //Gerar valor aleat�rio( min 10, m�x 99)
	}
	
	for(i = 0; i < 5; i++){
		return numero[x];
	}
}

//fun��o perguntar quantas dezenas deseja jogar?
int quantidade(){
	int x;
		
		printf("\n");
		//Quantidades de dezenas apostadas(m�x 10)
		do{
			printf("Quantas dezenas deseja jogar (M�ximo 10)?\n");
			scanf("%i", &x);
		}while(x > 10);
		return x;
}
	
//fun��o para escolher as dezenas
int escolherDezenas(){
	int i;
	int dezenas;
	
		//escolha as dezenas 
		scanf("%i", &dezenas);	
		return dezenas;		
}
	

void main(){
	setlocale(LC_ALL, "");
	srand(time(NULL));         //ajustar a semente do randomizador
	int i, x, z;
	int aux = 0;
	int numerosSorteados[5];
	
	for(i = 0; i < 5; i++){
		aux = i;
		
		//N�meros da aposta do jogador
			printf("jogo N-%i", i+1);
			vetJogador[i].numero_da_aposta = i;
		
		//Chamar fun��o quantidade()
			x = quantidade();
			vetJogador[i].quantidade_apostadas = x;
		
		//Chamar fun��o escolherDezenas()
			printf("Escolha %i dezenas:\n", vetJogador[i].quantidade_apostadas);
			for(i = 0; i < x; i++){
				z = escolherDezenas();
				vetDezenas[i].dezenas = z;
			}
			printf("Dezenas escolhidas:\n");
			for(i = 0; i < x; i++){
				printf("(%i)\t", vetDezenas[i].dezenas);
			}
			
			printf("\n\n\n");
		
		i = aux;// acertar indice do primeiro for()
	}
	
	//N�meros sorteados
	printf("\n");
	printf("---N�meros sorteados---\n");
	for(i = 0; i < 5; i++){
		x = sorteio(i);
		numerosSorteados[i] = x;
		
		printf("%i\t", numerosSorteados[i]);	
	}
			
}




