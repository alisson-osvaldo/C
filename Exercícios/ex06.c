/*
6. Faça um algoritmo que leia 3 notas de um aluno e um quarto número que representa o modelo de média a
ser calculada. Caso o modelo seja igual a 1, calcular a média aritmética; caso seja igual a 2, calcular a
média ponderada com pesos iguais a 5, 3 e 2; caso seja igual a 3, calcular a média harmônica. Repetir este
procedimento até que uma das notas informadas seja menor que 0.


Pond = nota1*peso1 + nota2*peso2 + nota3*peso3      Harm =        3
			 peso1 + peso2 + peso3                         1   +   1   +  1
			                                              nota1  nota2  nota3
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

#define TAM 1

//struct para receber uma string nome do aluno e sua 3 notas float;
struct boletin_aluno{
	char nome[30];
	float n1, n2, n3;
};

//armazenando a struct em um vetor para armazenar mais de um aluno
struct boletin_aluno cad_aluno[TAM];

//menu
int menu(){
	int op;
		
	do{
		system("cls");
		printf("## Calcular m�dia ##\n");
		printf("1.M�dia aritm�tica\n");
		printf("2.M�dia ponderada\n");
		printf("3.M�dia harmonica\n");
		printf("4.Sair\n");
		printf("Op��o:/n");
		scanf("%i", &op);	
	}while(op < 1 || op > 4);
	return op;
}

//procedimento para ler notas
void notas(){	 
	int i;

	for(i = 0; i < TAM; i++){
		printf("Informe o nome do aluno:\n");
		scanf("%s", &cad_aluno[i].nome);
		printf("Informe nota %i:\n", i+1);
		scanf("%f", &cad_aluno[i].n1);
		printf("Informe nota %i:\n", i+2);
		scanf("%f", &cad_aluno[i].n2);
		printf("Informe nota %i:\n", i+3);
		scanf("%f", &cad_aluno[i].n3);	
	}			
}

//Procedimento para mostrar Aluno
void mostraAluno(){
	int i;
	 
	for(i = 0; i < TAM; i++){
		printf("\n");
		printf("Aluno: %s\n", cad_aluno[i].nome);
		printf(" Nota 1: %0.1f\n Nota 2: %0.1f\n Nota 3: %0.1f\n", cad_aluno[i].n1, cad_aluno[i].n2, cad_aluno[i].n3);
		printf("\n");
	}
}

//funçâo para calcular a média aritmética
float aritmetica(){
	int i;
	float media = 0;
	
	for(i = 0; i < TAM; i++){
		media = (cad_aluno[i].n1 + cad_aluno[i].n2 + cad_aluno[i].n3)/3;
	}
	return media;
}

//funçâo para calcular a média ponderada
float ponderada(int x){
	int i;
	float ponderada[TAM];
	int peso1 = 5;
	int peso2 = 3;
	int peso3 = 2;
	//for para calcular a média de cada aluno
	for(i = 0; i < TAM; i++){
		ponderada[i]= (cad_aluno[i].n1*peso1 + cad_aluno[i].n2*peso2 + cad_aluno[i].n3*peso3) / (peso1 + peso2 + peso3);	
	}
	
	//for para retornar a média de cada aluno
	for(i = 0; i < TAM; i++){
		return ponderada[x];// retornando a posição do indice da main(*para não repetir mesmo valor, já q não foi possivel retornar um vetor para main)
	}	
}

//função para calcular a média harmonica
float harmonica(int x){
	int i;
	float harmonica[TAM];
	
	for(i = 0; i < TAM; i++){
		harmonica[i] = 3 /(1/cad_aluno[i].n1 + 1/cad_aluno[i].n2 + 1/cad_aluno[i].n3);
	}
	
	for(i = 0; i < TAM; i++){
		return harmonica[x];
	}
}

//funçâo para perguntar se deseja calcular novamente?
char leOpcao(){
	char op;
	do{
		printf("\n\nDeseja Calcular Novamente (S/N)? ");
		fflush(stdin);
		scanf("%c", &op);
		op = toupper(op);
	}while(op != 'S' && op != 'N');
	return op;
}

void main(){
	setlocale(LC_ALL, "");
	int op, i;
	float aux, x;
	
	do{
		notas();
		mostraAluno();
		getch();
												
		do{
			op = menu();
			switch(op){
				case 1:
					 aux = aritmetica();
					 printf("\n");
					 printf("M�dia Aritm�tica: %.1f\n", aux);
				getch();
				break;
							
				case 2: 
					for(i = 0; i < TAM; i++){
						x = ponderada(i); //enviando a posição do indice para a funçâo(*para retornar a média de cada aluno)
						printf("\n");
						printf("Média Ponderada: %.1f\n", x);
					}
				getch();
				break;
							
				case 3: 
					for(i = 0; i < TAM; i++){
						x = harmonica(i);
						printf("\n");
						printf("Média Harmonica: %.1f\n", x);
					}
				getch();			
				break;								
			}                                
		}while(op != 4);
		
		op = leOpcao();	
	}while(op == 'S');	
}
