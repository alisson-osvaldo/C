/*
13. Elabore uma função que efetue a leitura de uma matriz de qualquer dimensão de acordo com os seguintes
formatos:
a. ler toda a matriz
b. ler apenas os elementos da diagonal principal e da diagonal secundária
c. ler apenas os elementos das bordas (primeira linha, primeira coluna, última linha, última
coluna)
Elabore um procedimento que apresente a matriz na tela.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define LIN 3
#define COL 3

//menu
int menu(){
	int op;
		
	do{
		system("cls");
		printf("## Escolha a opção para ler a matriz: ##\n");
		printf("1.Ler toda a matriz.\n");
		printf("2.Ler apenas os elementos da diagonal principal e da diagonal secundária.\n");
		printf("3.Ler apenas os elementos das bordas (primeira linha, primeira coluna, última linha, última coluna).\n");
		printf("4.Sair\n");
		printf("Opção: ");
		scanf("%i", &op);	
	}while(op < 1 || op > 4);
	return op;
}

//Procedimento para receber valores do teclado
int lerMatriz(int i, int j){
	int matA;
	
		printf("\n");
		printf("Informe o valor da Linha [%i] coluna [%i]:\n", i, j);
		scanf("%i", &matA);

		return matA;
}

//Procedimento para mostrar matriz 
void mostraMatriz(int i, int j, int x, int op){
	
	if(op == 1){
		printf("Matriz [%i, %i]: %i\n", i, j, x);	
	}
	if(op == 2){
		printf("Matriz [%i, %i]: %i\n", i, j, x);
			
	}
	
	if(op == 3){
		printf("\n");
		printf("Matriz [%i, %i]: %i\n", i, j, x);
		printf("\n");
	}
}

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
	setlocale(LC_ALL, "");
	int i, j, op;
	int mat[LIN][COL];
	
	do{
		op = menu();
		
		switch(op){
			case 1:
				//Lê toda a matriz
				printf("<<Lê toda a matriz>>\n");
				for(i = 0; i < LIN; i++){
					for(j = 0; j < COL; j++){
						mat[i][j] = lerMatriz(i, j); //armazena o valor recebido na matriz
					}
				}
				
				//Chamar procedimento que mostra toda matriz 
				printf("\n");
				printf("Toda a matriz:\n");	
				for(i = 0; i < LIN; i++){
					for(j = 0; j < COL; j++){
						mostraMatriz(i, j, mat[i][j], op); //passando parâmetro de i, j, matriz.
					}
				}
			break;
				
			case 2: 
				//Lê diagonal principal 
				printf("\n");
				printf("<<Diagonal principal>>\n");
				for(i = 0, j = 0; i < LIN, j < COL; i++, j++){
					mat[i][j] = lerMatriz(i, j);
				}
				
				//ler diagonal secundaria
				printf("\n");
				printf("<<Diagonal secundária>>\n");
				for(i = LIN - 1, j = 0; i > 0, j < COL; i--, j++){
					mat[i][j] = lerMatriz(i, j);
				}
			
				//mostra diagonal principal 
				printf("\n");
				printf("<<Diagonal principal>>\n");	
				for(i = 0, j = 0; i < LIN, j < COL; i++, j++){
					mostraMatriz(i, j, mat[i][j], op);
				}
			
				//mostra diagonal secundaria
				printf("\n");
				printf("<<Diagonal secundária>>\n");
				for(i = LIN - 1, j = 0; i > 0, j < COL; i--, j++){
					mostraMatriz(i, j, mat[i][j], op);
				}
			break;
			
			case 3:
				//Ler elementos das bordas
				for(i = 0; i <= LIN; i++){
					for(j = 0; j <= COL; j++){
						//ler primeira linha e primeira coluna
						if(i == 0 & j == 0){
							mat[i][j] = lerMatriz(i, j);
							
						}
						if(i == LIN - 1 & j == COL - 1){ // Obs. -1 pq i e j inicia em 0.
							mat[i][j] = lerMatriz(i, j);	
						}
					}
				}
				
				//Mostrar os elementos das bordas
				for(i = 0; i <= LIN; i++){
					for(j = 0; j <= COL; j++){
						//ler primeira linha e primeira coluna
						if(i == 0 & j == 0){
							printf("<<primeiro elemento da borda>>");
							mostraMatriz(i, j, mat[i][j], op);
						}
						//ler Ultima linha e ultima coluna
						if(i == LIN - 1 & j == COL - 1){ // Obs. -1 pq i e j inicia em 0.
							printf("<<Ultimo elemento da borda>>");
							mostraMatriz(i, j, mat[i][j], op);		
						}
					}
				}
			break;	
		}
		
		op = leOpcao();
	}while(op != 'N');
} 