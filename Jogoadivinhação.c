#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void clear(){
	system("cls");
}

int main(){
	setlocale(LC_ALL, "portuguese");
	
	printf("--------------------------------------\n");
	printf("- Bem Vindo Ao Jogo de Adivinhacao -\n");
	printf("--------------------------------------\n");
	printf("\n\n");
	int semente = time(0);
	srand(semente);
	
	int randon = rand();
	
	int numerosecreto = randon % 101;
	int chute;
	int tentativas = 1;
	double pontos = 1000;
	
	int acertou = 0;
	
	int nivel;
	printf("Qual o nivel de dificuldade?\n\n");
	printf("(1) Facil (2) Medio (3) Dificil\n\n");
	printf("--------------------------------------\n");
	printf("Escolha: ");
	scanf("%d", &nivel);
	
	int numero_de_tentativas;
	
	switch(nivel) {
		case 1:
			numero_de_tentativas = 20;
			break;
			
		case 2: 
			numero_de_tentativas = 15;
			break;
			
		default:
			numero_de_tentativas = 6;
			break;
	}
	
	clear();
	
	for(int i = 1; i <= numero_de_tentativas; i++) {
		
		printf("--------------------------------------\n");
		printf("Tentativa %d \n", tentativas);
		printf("--------------------------------------\n");
		printf("Qual e o seu chute? ");
		scanf("%d", &chute);
		printf("--------------------------------------\n");
		printf("Seu chute foi %d\n", chute);
		
		if(chute < 0){
			printf("Voce nao pode chutar numeros negativos!\n");
	
			continue;
		}
		
		acertou = (chute == numerosecreto);
		int maior = (chute > numerosecreto);
		
		if (acertou){
			break; // ou ganhou = 1;
		}
		else if (maior) {
			printf("\nO numero secreto e Menor\n");
		}
		else {
			printf("\nO numero secreto e Maior\n");
		}
	
		tentativas++;
		
		double pontosperdidos = abs(chute - numerosecreto) / 2.0;
		pontos = pontos - pontosperdidos;
	}
	
	clear();
	printf("--------------------------------------\n");
	printf("Fim de JOGO!\n");
	printf("--------------------------------------\n");
	
	if(acertou){
		printf("Voce acertou em %d tentativas\n", tentativas);
		printf("--------------------------------------\n");
		printf("Total de pontos: %.1lf\n", pontos);
	}else{
		printf("Voce perdeu, tente de novo!\n");
	}
	
	
	
	
	
}