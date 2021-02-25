/*
!Exercício incompleto!

*fazer todas as opçoes que estão na função (menu).
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <windows.h>

#define TAM 5                               //terminar 6.

//Registro dados para cadastro de aluno;
struct cadastro_aluno{
	int matricula;
	 
};
//armazenando a struct em um vetor para armazenar mais de um aluno
struct cadastro_aluno cad_aluno[TAM];

//definindo variavel global
int cabeca = 0;
int cauda  = 0;
int caudaM = 0;
int cabecaM = 0;
int posicao[TAM];

int menu(){
	int op;
		
	do{
		system("cls");
		printf("## Cadastro de alunos ##\n");
		printf(" 1.Checar se a lista está cheia.\n");
		printf(" 2.Checar se a lista está vazia.\n");
		printf(" 3.Limpar a lista.\n");
		printf(" 4.Inserir um elemento no começo (cabeça da lista).\n");
		printf(" 5.Inserir um elemento no fim (cauda da lista).\n");
		printf(" 6.Inserir um elemento em uma posição específica.\n");
		printf(" 7.Inserir um elemento após outro elemento.\n");
		printf(" 8.Verificar se um elemento pertence à lista.\n");
		printf(" 9.Consultar a posição de um elemento.\n");
		printf("10.Consultar o elemento de uma posição específica.\n");
		printf("11.Remover o elemento do começo.\n");
		printf("12.Remover o elemento do fim.\n");
		printf("13.Remover o elemento de uma posição específica.\n");
		printf("14.Remover um elemento.\n");
		printf("15.Remover todas as ocorrências de um elemento.\n");
		printf("16.Listar todos os elementos.\n");
		printf("17.Sair\n");
		printf("Opção: ");
		scanf("%i", &op);	
	}while(op < 1 || op > 17);
	return op;
}

//4. Função para inserir um elemento no começo (cabeça da lista);
void inserir_inicio(int x, int i, int aux){	
		
	if(cauda < TAM){
		if(i == 0){
			cad_aluno[cabeca].matricula = x;
			cauda ++; 
		}
		if(i > 0){
			cad_aluno[cabeca].matricula = x;
			cad_aluno[cauda].matricula = cad_aluno[cabeca].matricula;
			cauda++;
			cad_aluno[cabeca].matricula = aux;
		}
		
		if(i+1 == TAM){
			cad_aluno[cabeca].matricula = aux;
		}
	}else{
		printf("\n");
		printf("<<lista está cheia!>>\n");
	}
}

//5 e 7. Procedimento para inserir um elemento no fim(cauda);
void inserir_fim(int x, int ativador6, int k){
	int i;
	cauda = k;
	
	printf("*cauda*: %i\n", cauda);
	printf("x: %i\n", x);
		if(cad_aluno[cauda].matricula == 0){
			cad_aluno[cauda].matricula = x;
			printf("6cad_aluno[%i] = %i\n", cauda, x);
		}else{
			cauda++;
		}			
}

//6. Procedimento para inserir um elemento em uma posição especifica;
void inserir_posicaox(int posicao, int x, int k){
	printf("\n");
	printf("x: %i\n", x);
	printf("posicao: %i\n", posicao);
	printf("cadaluno[%i] = %i\n", posicao, x);
	
	if(k <= TAM){
		cad_aluno[posicao].matricula = x;  
	}else{
	printf("<<lista está cheia!>>\n");
	}
	
}

//função para gerar número da matricula(sem repetição);
int n_matricula(int i, int k, int auxK, int posicao, int ativador6){ //auxK = posicao do primeiro elemento em que o K=0 recebeu(posicao[0])
	int num;
	printf("k = %i\n", k);
	printf("auxK: %i\n", auxK);
	printf("posicao: %i\n", posicao);
	if(k < TAM){
	
		if(i == 0 && k == 0){
			num = 102021;
			return num;
			printf("num: %i\n", num);
		}
	}
	
	if(ativador6 >= 1){
		if(i > 0 || k > 0){
			num = cad_aluno[posicao].matricula + 100000;
			printf("\n");
			printf("Ativador6\n");
			printf("Num = posicao cad_aluno[%i]: %i\n", posicao, cad_aluno[posicao].matricula + 100000);             
		return num;
		}
	}else{
		if(i > 0 || k > 0){
			num = cad_aluno[i-1].matricula + 100000; 
			printf("*posicao cad_aluno[%i]: %i\n", i, cad_aluno[i-1].matricula + 100000);             
		return num;
		}
	}
		
}

//16.Procedimento para listar todos os alunos matriculados
void mostra_lista(int i){
		printf("\n");
		printf(" Aluno: %i\n ", i);
		printf("Matricula: %i\n", cad_aluno[i].matricula);	
}

// função de leitura com validação - apresenta mensagem "Deseja continuar (S/N): " 
char leOpcao(){
	char op;
	do{
		printf("\n\n");
		printf("Deseja continuar (S/N)? ");
		fflush(stdin);
		scanf("%c", &op);
		op = toupper(op);
	}while(op != 'S' && op != 'N');
	return op;
}

//verificar se o valor recebido em posicao[k] não é repetido;
int verificar_repeticao(int verificar, int k){
	int i;
	printf("\n");
	printf("<<verificar_repeticao>>\n");
	printf("verificar: %i\n", verificar);
	
	
	for(i = 0; i < k; i++){
		if(verificar == posicao[i]){
			printf("\n");
			printf("verificar_repeticao\n");
			printf("Indice repetido!!!\n");
			printf("posicao[%i]: %i\n", i, posicao[i]);
		return -1;
		}
	}
}

void main(){
	setlocale(LC_ALL, "");
	int x, j, l, n, inserir, aux, qtd, q;
	int op;
	int i = 0;
	int k = 0;	
	int auxK = 0;
	int verificar;
	int ativador6 = 0;
	
	do{	
		//chamar menu;
		op = menu();
		switch(op){
			case 1:	
				//1.Checar se a lista está cheia; 
				if(i > TAM-1){
					printf("Lista cheia");
				}else{
					printf("\n");
					printf("Ainda restam %i vagas.\n", TAM - i);
				}
			getch();
			break;
			
			case 2:	
				if(k == 0){
					printf("Lista vazia");
				}else{
					printf("\n");
					printf("A lista contem %i cadastros.\n", k);
				}
			getch();
			break;
			
			case 3:	
			printf("Apagar todos os cadastros da lista?");
			if(i > 0){
				for(i = 0; i < TAM; i++){
					cad_aluno[i].matricula = 0;
				}
				i = 0;
				k = 0;
				auxK = 0;
				cabeca = 0;
				cauda  = 0;
				caudaM = 0;
				cabecaM = 0;
			}else{
				printf("Alista já está vazia");
			}
			getch();
			break;
			
			case 4:
				printf("\n");
				printf("<<Gerando número da matricula do aluno:>>\n");
				if(i < TAM){
						
					//chamar função que gera Número da matricula;
					x = n_matricula(i, k, auxK, posicao[k-1], ativador6);
					if(i == 0){//receber valor do indice 0 e guardar na variavel aux;
						aux = x;
					}
					printf("Posicao[k]: %i\n", posicao[k]);
					for(l = 0; l < k; l++){
						if(i == posicao[k]){ //Verificar se o indice de i já foi ocupado por inserir_posicaox();
							i++;
						
							printf("i: %i\n", i);
						}
					}
					//chamar função que adiciona elemento no inicio(cabeça);
					inserir_inicio(x, i, aux);
					printf("Número da matricula do aluno: %i\n", cad_aluno[i].matricula);
					i++;
					k++;
				}else{
				printf("Lista de matriculas cheia!");
				}
			getch();
			break;
			
			case 5:	
				if(i < TAM){
					printf("\n");
					printf("<<Gerando número da matricula do aluno:>>\n");
					//chamar função que gera Número da matricula;
					x = n_matricula(i, k, auxK, posicao[k-1], ativador6);
					//chamar função que adiciona elemento no fim(cauda);
					inserir_fim(x, ativador6, k);
					printf("Número da matricula do aluno %i: %i\n", i , cad_aluno[i].matricula);
					i++;
					k++;
					printf("i: %i\n", i);
					printf("ativador6 = %i\n", ativador6);
					if(ativador6 >= 1){
						ativador6 = ativador6 - 1;
					}
				}else{
					printf("<<lista está cheia!>>\n");
				}
			getch();	
			break;
			
			case 6:	
				ativador6 = 1;
				printf("\n");
				printf("<<Gerando número da matricula do aluno:>>\n");
				if(k < TAM){
					do{
						do{
							printf("Informe a posição para adicionar a matricula do aluno: (de 0 á %i).\n", TAM-1);
							scanf("%i", &posicao[k]);
							printf("*posicaoK[%i]: %i\n", k, posicao[k]);
						}while(posicao[k] > TAM-1);
						
						
						//chamar funcao para verificar se o indice não é repetido;
						for(l = 0; l < k; l++){
							printf("\n");
							printf("*l: %i\n");
							printf("posicaoL[l]: %i\n", posicao[l]);
							verificar = verificar_repeticao(posicao[k], k);
							printf("Verificar: %i\n", verificar);
						}
					}while(verificar == -1);
					
					//variavel auxK recebe o primeiro elemento informado para calcular 2021 + 100000 e mandar para n_matricul
					auxK = posicao[k];
					printf("auxK: %i\n", auxK);
					
					//chamar função que gera Número da matricula;
					x = n_matricula(i, k, auxK, posicao[k-1], ativador6);
					printf("x: %i\n", x);
					
					//chamar procedimento que adiciona um elemento no indice sugerido;
					inserir_posicaox(posicao[k], x, k);
					printf("Posicao[%i]: %i\n", k, posicao[k]);
					k++;
					i++;
				}else{
					printf("Essa posição já foi preenchida\nTente um número maior...");
				}
				
			getch();
			break;
			
			case 7:
			if(ativador6 == 0){
				if(i < TAM){
					do{
						printf("\n");
						printf("Deseja adicionar quantos alunos na sequencia (Máx: %i)?\n", TAM-i);
						scanf("%i", &qtd);
					}while(qtd > TAM - i);
					
					printf("<<Gerando número da matricula do aluno:>>\n");
					
					//chamar função que gera Número da matricula;
					for(q = 0; q < qtd; q++){
						//chamar função para gerar matricula;
						x = n_matricula(i, k, auxK, posicao[k-1], ativador6);
						//Função para adicio o elemento
							inserir_fim(x, ativador6, k);
						i++;
						k++;
					}
				}printf("Lista cheia");
			}printf("Não é possivel cadastrar um após o outro.");
			getch();
			break;
	
			case 8:	
			break;
			
			case 9:	
			break;
			
			case 10:	
			break;
			
			case 11:	
			break;
			
			case 12:	
			break;
			
			case 13:	
			break;
			
			case 14:	
			break;
			
			case 15:	
			break;
			
			case 16:
				printf("\n");
				printf("Todos os alunos cadastrados:\n");
				for(j = 0; j < i; j++){
					mostra_lista(j);	
				}
			getch();
			break;
			
			case 17:
			break;
		}
		
	}while(op != 17);
	//chamar função para (S/N) repetir processo;
	op = leOpcao();
}