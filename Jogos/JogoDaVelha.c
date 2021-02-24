#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

char velha[3][3];    //variavel global ela visivel em qualquer sub-rotina do arquivo

 
//pr//procedimento inicializaVelha,sem parâmentro
//percarrer toda a matriz inserir ' ' em cada elemento
void inicializaVelha(){
	 int i, j;
	 
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			velha[i][j] = ' ';
		}
	}	
}

void mostraVelha(){
     int i, j;
     system("cls");                                //limpa a tela
	 printf("\n## JOGO DA VELHA ##\n\n");
	 printf("\n");
     printf("    0   1   2\n");
    // printf("-------------\n");
     for(i = 0; i < 3; i++){
        printf("%d  ", i);               //mostra o numero da linha
        for(j = 0; j < 3; j++){
           printf(" %c ", velha[i][j]);
           if(j < 2){
              printf("|");
           }
        }
        if(i < 2){
           printf("\n   -----------\n");
        }

     }
     printf("\n");
}

//função lePosição que retorna um int e recebe um vetor de caracteres que representa a mensagem que vai para tela
//enquanto o usuário informa uma posição (só a linha, só coluna) apresente e ler a posição
int lePosicao(char *msg){
	int n;
	
	do{
		printf("%s", msg);
		fflush(stdin);
		scanf("%d", &n);
	
	
	}while(n < 0 || n > 2);
	return n;

 }

//função sorteiaPrimeiroJogador () que retorna o caracter 'x' ou o caracter ' ' indicando
//o jogador que vai começar o jogo 
char sorteiaPrimeiroJogador(){     //sortear o número 0 ou 1
	int n = rand() % 2;            //se for 0, mostrar mensagem que o computador vai começar e retornar 'O'
	                               //senão, mostrar mensagem que o jogador vai começar e retornar x
	
	if(n == 0){
		printf("O computador vai começar\n\n");
		return 'O';
	}else{
		printf("Voçe vai começar\n\n");
		return 'X';
	}
}

//ver se a peça formaou um trio na linha e na coluna vertifacal, horizontal, diagonal principal ou na diagonal  secundaeria 
// verificar se a peça forma um trio na horizontal, na vertical, na diag. principal ou na diag. secundária
int avaliaVencedor(char peca){
	int i, j, cont;
	
	// testar as linhas (horizontal)
	for(i = 0; i < 3; i++){	
		cont = 0;
		for(j = 0; j < 3; j++){
			if(velha[i][j] == peca){
				cont++;
			}
		}
		if(cont == 3){
			return 1;
		}
	}
	
	// testar as colunas (vertical)
	for(j = 0; j < 3; j++){
		cont = 0;
		for(i = 0; i < 3; i++){
			if(velha[i][j] == peca){
				cont++;
			}
		}
		if(cont == 3){
			return 1;
		}
	}
	
	// testar a diagonal principal
	if(velha[0][0] == peca && velha[1][1] == peca && velha[2][2] == peca){
		return 1;
	}
	
	// testar a diagonal secundária
	if(velha[2][0] == peca && velha[1][1] == peca && velha[0][2] == peca){
		return 1;
	}
}

char lerOpcao(){
	char op;
	do{
		printf("Deseja continuar jogando (S/N)? ");
		fflush(stdin);
		scanf("%c", &op);
		op = toupper(op);
	}while(op != 'S' && op != 'N');
	return op;
}

void main(){
	setlocale(LC_ALL, "portuguese");
	srand(time(NULL));
	
	int i, j, cont, venc;
	char peca, op;
	
	do{
		inicializaVelha();
		mostraVelha();
		
		peca = sorteiaPrimeiroJogador();
		cont = 0;
		
		
		do{
			do{
				if(peca == 'X'){
					printf("\n");
					i = lePosicao("Informe a linha: ");
					j = lePosicao("Informe a coluna:");
				}else{
				  i = rand() % 3;
				  j = rand() % 3;
				  printf("\n O computador joga: %i, %i", i, j);
				  getch(); //espera receber um valor do teclado, segura a tela 
				}	
			}while(velha[i][j] != ' ');
			
			//Inserir 'x' na matriz na posição i,j
			velha[i][j] = peca;
			cont++;
			mostraVelha();
			
			venc = avaliaVencedor(peca);  //1 = Verdadeiro 0 = Falso
			if(venc == 1){
				break; //ele para do while
			}
			
			if(peca == 'X'){
				peca = 'O';
			}else{
				peca = 'X';
			}
		
		}while(cont < 9);
		
		if(venc == 1){
			if(peca == 'X'){
				printf("\n\nParabéns! Você venceu!!\n");
			} else {
				printf("\n\nO computador venceu!!\n");
			}
		} else {
			printf("\n\nVelha! Não há vencedor!\n\n");
		}
		
		
		op = lerOpcao();
	}while(op != 'N');
}