/*

APS - T�cnicas de Programa��o

Nome                             - RA
Danilo Dini de Melo S�           - 6057183
Renan Franco Pelisson            - 6988291
Rodrigo de Lima Bispo            - 6371717
Suellen Cristina Duarte De Souza - 7442861
Wesley de Oliveira de Paula      - 7503397

*/
#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include "convmed.h"
#include "scan.h"

//prot�tipo das fun��es.
void imprime(const char[], const char[], float); 
void pedeOpcaoConversao(int *opcao);
void imprimeCabecalho();
void conversaoComFloat(const char mensagem[], const char usual[], const char si[], void (*func)(float*));

int main(){

	// Configura o idioma para Portug�s para que o compilador aceite caracteres desse idioma
	setlocale(LC_ALL, "Portuguese"); 

	imprimeCabecalho();

	int *opcao = (int*)malloc(sizeof(int));

	do {
		pedeOpcaoConversao(opcao);
		switch(*opcao) {
			case 1:
				// Chama uma fun��o gen�rica que recebe a fun��o de convers�o como par�metro e a executa
				conversaoComFloat("Digite o valor da quantidade em gramas:", 
							   "g", 
							   "kg", 
							   gramaParaKg);
				break;
			case 2:
				printf("{N�o implementado}\n");
				break;
			case 3:
				conversaoComFloat("Digite o valor em cent�metros quadrados:", 
							   "cm�", 
							   "m�", 
							   cmQuadradosParaMetrosQuadrados);
				break;
			case 4:
				printf("\nDigite o valor da quantidade em Litros: \n");
				int litros;
				scanf("%d", &litros);
				float *metrosCubicos = (float*)malloc(sizeof(float));

				litrosParaMetrosCubicos(litros, metrosCubicos);
				imprime("L", "m�", *metrosCubicos);
				break;
			case 5:
				printf("\nDigite o valor em Horas: \n");
				int horas;
				scanf("%d",&horas);
				
				int *minutos = (int*)malloc(sizeof(int));
				int *segundos = (int*)malloc(sizeof(int));

				horasParaMinSec(horas, minutos, segundos);
				printf("%d horas s�o %d minutos ou %d segundos\n", horas, *minutos, *segundos);
				break;
			case 6:
				conversaoComFloat("Digite o valor da Quantidade de calor em cal(calorias):", 
							   "cal", 
							   "J", 
							   caloriaParaJoule);
				break;
			case 7:
				conversaoComFloat("Digite o valor da Velocidade m�dia em km/h:", 
							   "km/h", 
							   "m/s", 
							   kmHoraParaMetrosSegundo);
				break;
			case 0:
				printf("Programa encerrado.\n");
				break;
			default:
				printf("\nOp��o inv�lida!\n");
				break;
		}
		system("pause");
	// Executa o la�o at� que o usu�rio digite 0
	} while(*opcao > 0);
	
	return 0;
}

// Fun��o gen�rica que exibe uma mensagem, le um float do usu�rio, converte usando a fun��o passada
// por par�metro e chama a fun��o imprime
void conversaoComFloat(const char mensagem[], const char usual[], const char si[], void (*func)(float*)) {
		// Pergunta ao usu�rio o valor que deseja converter na unidade usual
		printf("\n%s\n", mensagem);
		// Declara o ponteiro do tipo float para receber o valor digitado pelo usu�rio
		float *valor = (float*)malloc(sizeof(float));
		// Armazena o valor digitado no ponteiro
		scanf("%f", valor);
		// Passa o ponteiro por refer�ncia para a fun��o de convers�o
		func(valor);
		// Imprime o valor convertido e informa as unidades
		imprime(usual, si, *valor);
}

// Fun��o que imprime recebendo duas strings e o resultado do calculo
void imprime(const char usual[], const char si[], float conversao) {
	printf("\nDe acordo com o Sistema Internacional de medidas, \n");
	printf("O valor digitado em %s convertido para %s � %2.2f %s. \n\n", usual, si, conversao, si);
}

// Fun��o para pedir uma op��o digitada pelo usu�rio
void pedeOpcaoConversao(int *opcao) {
	printf("");
	printf("\nDigite o n�mero da unidade de medida(Unidade Usual) que deseja converter para o Sistema Internacional de Unidades(SI): \n\n");
	printf("|=======================================================|\n");
	printf("| # | Grandeza       | SI | Un. Usual | Correspond�ncia |\n");
	printf("|=======================================================|\n");
	printf("| 1 | Massa          | g  | kg        | 1kg = 1000g     |\n");
	printf("| 2 | Comprimento    | m  | km        | 1km = 1000 m    |\n");
	printf("| 3 | �rea           | m� | cm�       | 1m� = 10 000 cm�|\n");
	printf("| 4 | Volume         | m� | L         | 1m� = 1000 L    |\n");
	printf("| 5 | Tempo          | s  | h         | 1h = 3600 s     |\n");
	printf("| 6 | Quant. de Calor| J  | cal       | 1 cal = 4,18 J  |\n");
	printf("| 7 | Veloc. m�dia   | m/s| km/h      | 1m/s = 3,6 km/h |\n");
	printf("|=======================================================|\n\n");
	printf("-> Digite 0 para sair\n\n");
	scanInt(opcao, 0, 7);
}

// Fun��o para imprimir o cabe�alho do programa
void imprimeCabecalho() {
	printf("\n");
	printf("     _________\n");
	printf("    / ======= \\\n");
	printf("   / __________\\\n");
	printf("  | ___________ |\n");
	printf("  | |Conversor| |\n");
	printf("  | |-        | |\n");
	printf("  | |_________| |________________________\n");
	printf("  \\=____________/T�cnicas de Programa��o )\n");
	printf("  / \"\"\"\"\"\"\"\"\"\"\" \\                       /\n");
	printf(" / ::::::::::::: \\                  =D-'\n");
	printf("(_________________)\n\n");
}