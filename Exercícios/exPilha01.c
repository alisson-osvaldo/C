/*
Elabore um programa que represente uma pilha de números inteiros com armazenamento estático de no máximo
10 elementos. Deve ser permitido ao usuário:
1. PUSH
2. POP
3. PEEK
4. Apresentar a pilha
5. Sair

Observações: o programa deve apresentar mensagens de erro caso o usuário tente remover elementos de uma 
pilha vazia ou inserir elementos em uma pilha cheia.

LIFO: LAST IN, FIRST OUT
*/
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

#define TAM 3

// variáveis globais
int pilha[TAM];
int topo = -1;

//subir topo
// push(x): empilhar o valor x no topo da pilha
// se a pilha não estiver cheia, subir o topo e inserir o elemento no topo
// senão, sinalizar erro
void push(int x){
	if(topo < TAM-1){
		topo++;
		pilha[topo] = x;
	} else {
		printf("Pilha cheia.\n\n");
	}
	
}

// x = pop( ): desempilhar o valor do topo da pilha e descer o topo
// se a pilha não estiver vazia, descer o topo e retornar o elemento acima do topo
// senão, sinalizar erro (printf, retornar -1)
int pop(){
	int x;
	if(topo != -1){
		x = pilha[topo];
		topo--;
		return x;
	} else {
		printf("Pilha vazia.\n\n");
		return -1;
	}
}

// x = peek(): consulta o elemento do topo - sem mexer no topo
// se a pilha não estiver vazia, retornar o elemento do topo
// senão, sinalizar erro (printf, retornar -1)
int peek(){
	if(topo != -1){
		return pilha[topo];
	} else {
		printf("Pilha vazia.\n\n");
		return -1;
	}
}

// licença poética: não se deve mostrar os elementos de uma pilha, visto que se deve ter acesso unicamente ao elemento topo
// uso esse procedimento apenas para facilitar a visualização da manipulação da pilha.
void mostraPilha(){
	int i;
	for(i = topo; i >= 0; i--){
		printf("%i\n", pilha[i]);
	}
	printf("\n");
}

//Menu
int menu(){
	int op;
		
	do{
		system("cls");
		printf("## PILHA ##\n");
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Peek\n");
		printf("4.Mostrar\n");
		printf("5.Sair\n");
		printf("Opção: ");
		scanf("%i", &op);	
	}while(op < 1 || op > 5);
	return op;
}

/*
## PILHA ##
1. Push							Push: ler um número do teclado e empilhar
2. Pop							Pop: desempilhar e apresentar o número na tela
3. Peek							Peek: consultar e apresentar o número na tela
4. Mostrar						Mostrar: mostra toda a pilha na tela
5. Sair
Opção: _
*/

void main(){
	setlocale(LC_ALL, "");
	
	int op, aux;
	
	do{
		op = menu();
		switch(op){
				case 1: 
					printf("Digite um número: ");
					scanf("%i", &aux);
					push(aux);
					getch();
					break;
						
				case 2: 
					aux = pop();
					if(aux != -1){
						printf("Número desempilhado: %i\n", aux);	
					}
					getch();    //system pause
					break;
						
				case 3: 
					aux = peek();
					if(aux != -1){
						printf("Número do topo da pilha: %i\n", aux);	
					}
					getch();   //system pause
					break;
						
				case 4:
					mostraPilha();
					getch();   //system pouse
					break;										
		}
	}while(op != 5);
	
}