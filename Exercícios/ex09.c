/*
09.Elabore um algoritmo que cadastre 1000 palavras em inglês e sua tradução em português. Em seguida, leia
do teclado uma letra (I ou P) e uma palavra a ser traduzida e apresente na tela a sua tradução. Desta
forma, podem ser efetuadas traduções do inglês para o português (se for informada a letra I) ou do
português para o inglês (se for informada a letra P). Repetir este processamento até que seja informada
uma letra diferente de I ou de P.
*/

// *armazenar N palavras em ingles e em portugues
// *ler do teclado (I ou P) e uma palavra a ser traduzida
// I = Inglês para Português
// P = Português para Inglês

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>

#define TAM 5 //TAM para controlar quantidade de palavras poderam ser cadastradas

typedef struct 
{
	char i[10];
	char p[10];	
}ing_ptr;
 ing_ptr vet_palavras[TAM];
 
 // função perguntar se atradução será (I ou P)
char i_ou_p(){
	char traduzir;
 	
 	do{	
 		printf("\n");
	 	printf("traduzir Inglês precione    : (i)\n");
	 	printf("traduzir português precione : (p)\n");
	 	fflush(stdin);
	 	scanf("%c", &traduzir);
	}while(traduzir != 'i' && traduzir != 'p' && traduzir != 'I' && traduzir != 'P'); //se traduzir for diferente de i ou I, p ou P, repita.
	
 	return traduzir;
 }
 
// procedimento para ler e armazenar palavras em inglês e português
void cadastrar_palavra(){
	int i;
	
	for(i = 0; i < TAM; i++){
		printf("\n");
		printf("Cadastrar palavras:\n");
		printf("Inglês.....");
		fflush(stdin);
		fgets(vet_palavras[i].i,10,stdin);
		printf("Português.....");
		fflush(stdin);
		fgets(vet_palavras[i].p,10,stdin);
	}	
}

// procedimento para mostrar indice de (I e P)
void mostra_indice(){
	int i;
	
	for(i = 0; i < TAM; i++){
		printf("\n");
		printf("Inglês    : %s", vet_palavras[i].i);
		printf("Português : %s\n", vet_palavras[i].p);
	}	
}

//busca sequencial(elementos desordenados desordenados)
char buscaSequencial(char *texto, char x){
	int i;
	
	for(i = 0; i < TAM; i++){
		if(x == 'i' || x == 'I'){ //Pesquisa em Inglês retorna resultado em pt
			if(strcmp(texto, vet_palavras[i].i) == 0){
				return i;
			}
		}else{
			if(x == 'p' || x == 'P'){ //Pesquisa em pt retorna resultado em Inglês
				if(strcmp(texto, vet_palavras[i].p) == 0){ 
					return i;
				}
			}
		}
	}
	return -1;
}

// função para perguntar se deseja ver as traduções
char ver_cadastrados(){
	char op;
	do{
		printf("Ver traduções cadastradas (S/N)?\n");
		fflush(stdin);
		scanf("%c", &op);
		op = toupper(op);
	}while(op != 'S' && op != 'N');
	return op;
}

// função de leitura com validação - apresenta mensagem "Deseja continuar (S/N): " 
// retorna 'S' ou 'N'
char leOpcao(){
	char op;
	do{
		printf("Deseja continuar (S/N)? ");
		fflush(stdin);
		scanf("%c", &op);
		op = toupper(op);
	}while(op != 'S' && op != 'N');
	return op;
}

void main(){
	setlocale(LC_ALL, "portuguese");
	
	char traduzir, op, repetition;
	char busca;
	char buscando[30];
	char pesquisa[10];
	int i;
	char aux;
	//ler palavras
	cadastrar_palavra();
	
	do{
		//traduzir em I ou P?
		traduzir = i_ou_p();
		
		//palavra a ser pesquisada?
		printf("\n");
		printf("Informe a palavra........\n");
		fflush(stdin);
		fgets(buscando,30,stdin);
		
		//busca Sequencial
		busca = buscaSequencial(buscando, traduzir);
		if(busca == -1){
			printf("Não encontrado\n");
		}else{	
			i = busca;
			printf("\n\n");
			printf("Tradução  :\n");	
			printf("Inglê     : %s", vet_palavras[i].i);
			printf("Português : %s\n", vet_palavras[i].p);
		}
		
		// mostrar palavras cadastradas?
		printf("\n\n");
		op = ver_cadastrados();	
		if(op == 'S'){
			printf("\n");
			printf("palavras cadastradas:\n");
			mostra_indice();
		}
		
		// repetir processo?
		printf("\n\n");
		repetition = leOpcao();
	}while(repetition != 'N');
}