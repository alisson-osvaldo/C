/*
Elabore um programa que represente uma fila de números inteiros com armazenamento estático de no máximo 10 elementos. Deve ser permitido ao usuário:
1. ENQUEUE
2. DEQUEUE
3. PEEK
4. Apresentar a fila
5. Sair
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

#define TAM 10

typedef struct {
	char nome[50];
	int mat;
} tipoAluno;

//variaveis globais
int fila[TAM];
int cauda = 0;

//procedimento (enquete) adicionar um elemento no final da fila
void enqueue(int x){
	
	if(cauda < TAM){
		fila[cauda] = x;
		cauda++;
	}else{
		printf("\n");
		printf("A fila está cheia\n");
	}
}

//função (dequeue) para remover o elemento do inicio da fila
int dequeue(){
	int i, aux;
	
	if(cauda > 0){
		aux = fila[0];
		for(i = 0; i < cauda-1; i++){
			fila[i]= fila[i+1];
		}		
	cauda--;
	return aux;
	}else{
		printf("fila vazia...\n");
		return -1;
	}	
}

//função para (peek) mostrar o elemento do inicio da fila
int peek(){
	
	if(cauda > 0){
		return fila[0];
	}else{
		printf("fila vazia...\n");
		return -1;
	}
}

//procedimento para mostrar fila
void mostraFila(){
	int i;
	
	if(cauda > 0){
		for(i = 0; i < cauda; i++){
			printf("%i\t", fila[i]);
		}
		printf("\n\n");
	} else {
		printf("Fila vazia\n");
	}
}

//Menu
int menu(){
	int op;
		
	do{
		system("cls");
		printf("## Fila ##\n");
		printf("1.(enqueue) Adicionar um elemento na fila.\n");
		printf("2.(Peek) Mostrar o primeiro da fila:\n");
		printf("3.(dequeue) Remover o primeiro elemento da fila.\n");
		printf("4.Mostrar a fila inteira.\n");
		printf("5.Sair.\n");
		printf("Opção: ");
		scanf("%i", &op);	
	}while(op < 1 || op > 5);
	return op;
}


void main(){
	setlocale(LC_ALL, "");
	int x, i, op;
	int vetenqueue[TAM];
	
	do{
		op = menu();
		switch(op){
			case 1:	//Adicionar elemento	
					printf("informe o valor:\n");
					scanf("%i", &vetenqueue[i]);
						
					enqueue(vetenqueue[i]);
					mostraFila();
					i++;
				
			getch();//pausa System CLS
			break;
							
			case 2: //consultar o primeiro elemento da fila 	
				x = peek();
				printf("Consulta 1o da fila: %i\n", x);
				
			getch();			
			break;
							
			case 3: //Deletar o primeiro elemento da fila
				x = dequeue();
							
			break;
							
			case 4:
				mostraFila();
			getch();			
			break;
											
			}                
	}while(op != 5);

}