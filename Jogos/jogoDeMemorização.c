#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <ctype.h>
//constante
#define TAM 5

//variavael global
int mat[TAM][TAM];

//procedimento para limpar a matriz(preencher todas as casas com zero)
void inicializaMatriz(){
	int i,j;
	for(i = 0; i < TAM; i++){		//indice que controla a linha
		for(j = 0; j < TAM; j++){	//indice que controla a coluna
			mat[i][j] = 0;
		}
	}
}

//procedimento para mostrar matriz - com os indices
void mostraMat(){
	int i, j;
	
	//mostrar o indice das colunas
	printf("   ");   //mostrar 3 espaços
	for(j = 0; j < TAM; j++){
		printf("%i  ", j);
	}
	printf("\n");
	
	//mostrar o indice das linhas e os elementos da matriz
	for(i = 0; i < TAM; i++){
		printf("%i  ", i);
		for(j = 0; j < TAM; j++){
			printf("%i  ", mat[i][j]);
		}
		printf("\n");
	}
		
}

//procedimento para posicionar os elementos de i a TAM na matriz
void sorteiaPosicao(){
	int n = 1;
	int i, j;
	
	do{
		//sortear linha e coluna
		do{
			i = rand() % TAM;	
			j = rand() % TAM;
		}while(mat[i][j] != 0);
		
		mat[i][j]= n;
		n++;
		
	}while(n <= TAM);
}

int lePosicao(char *msg){
	int n;
	do{
		printf("%s", msg);
		scanf("%d", &n);
		if(n > 5){
			printf("\n");
			printf("Os números são de 1 á 5!\nEscolha novamente:\n");
			printf("\n");
		}	
	}while(n < 0 || n > TAM-1);
	return n;

 }

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
	srand(time(NULL));         //ajustar a semente do randomizador
	
	int n;                     //Número de sequencia de 1 a TAM q o usuario deve achar na matriz
	int i, j;
	char op;
	do{
	//inicio de jogo
	inicializaMatriz();
	sorteiaPosicao();
	system("cls");            //limpar a tela   
	printf("Encontre a sequencia de números de 1 a %i.\n\n", TAM );   
	mostraMat();
	Sleep(3000);              //conta 3 segundos, Usar o S em maiusculo (Sleep)
	//system("pause");           // pausar o Sleep(3000) para testar durante a programação depois apagar

	n = 1;
	
	do{
		system("cls");              //limpar tela
		
		while(1){                  //looping infinito
		printf("\n");
		printf("onde está o número %i?\n\n ", n);
		i = lePosicao("Informe a linha: ");
		j = lePosicao("Informe a coluna: ");
		
			if(mat[i][j] == n){
				printf("\n");
				printf("Acertou o número na sequencia certa\n");
				n++;
				
				if(n > TAM){
					printf("\n");
					printf("Parabéns vc encontrou a sequencia de números corretamente! ");
					break;
				}
				
				printf("onde está o número %i?\n\n", n);
				mostraMat();
				Sleep(3000);
				//system("pause");    //pausa para teste
				break;
				
				}else if(mat[i][j] == 0){
					printf("\n");
					printf("Posição vazia, tente novamente!\n\n");
				}else{
					printf("\n");
					printf("Não é este número procurado, tente novamente!\n");
				}
			}
	
		}while(n <= TAM);
			op = leOpcao();
		
	}while(op == 'S');
}