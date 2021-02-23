/*
7.Faça um algoritmo para um programa de apostas da LOTO. O algoritmo deverá ler, inicialmente, as cinco
dezenas sorteadas e, a seguir, as apostas dos jogadores contendo:

a. Número da aposta
b. Quantidade de dezenas apostadas (no máximo 10)
c. As dezenas apostadas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

struct aposta
{
	int	numero_da_aposta;	  //Números da aposta do jogador
	int quantidade_apostadas; //Quantidades de dezenas apostadas(máx 10)
};
struct aposta vetJogador[5]; //vetor para armazenar dados do jogo de cada jogador

struct dezenas_apostadas
{
	int dezenas;	//Dezenas apostadas pelo jogador 
};
struct dezenas_apostadas vetDezenas[10];
	
//função para sortear 5 números aleaórios entre 0 e 99
int sorteio(int x){
	int i, numero[5];
	
	for(i = 0; i < 5; i++){
		numero[i] = 10 + (rand() % 90); //Gerar valor aleatório( min 10, máx 99)
	}
	
	for(i = 0; i < 5; i++){
		return numero[x];
	}
}

//função perguntar quantas dezenas deseja jogar?
int quantidade(){
	int x;
	
	printf("\n");
	//Quantidades de dezenas apostadas(máx 10)
	do{
		printf("Quantas dezenas deseja jogar (Máximo 10)?\n");
		scanf("%i", &x);
	}while(x > 10);
	return x;
}
	
//função para escolher as dezenas
int escolherDezenas(){
	int i;
	int dezenas;
	
	//escolha as dezenas 
	scanf("%i", &dezenas);	
	return dezenas;		
}
	

void main(){
	setlocale(LC_ALL, "");
	srand(time(NULL)); //ajustar a semente do randomizador
	int i, x, z;
	int aux = 0;
	int numerosSorteados[5];
	
	for(i = 0; i < 5; i++){
		aux = i;
		
		//Números da aposta do jogador
		printf("jogo N-%i", i+1);
		vetJogador[i].numero_da_aposta = i;
		
		//Chamar função quantidade()
		x = quantidade();
		vetJogador[i].quantidade_apostadas = x;
		
		//Chamar função escolherDezenas()
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
	
	//Números sorteados
	printf("\n");
	printf("---Números sorteados---\n");
	for(i = 0; i < 5; i++){
		x = sorteio(i);
		numerosSorteados[i] = x;
		
		printf("%i\t", numerosSorteados[i]);	
	}
			
}



