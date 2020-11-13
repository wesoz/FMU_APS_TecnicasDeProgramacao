#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include "convmed.h"
#include "scan.h"

//prot�tipo das fun��es.
void imprime(const char[], const char[], float); 
void pedeOpcaoConversao(int *opcao);
void imprimeCabecalho();

int main(){

	setlocale(LC_ALL, "Portuguese"); 

	imprimeCabecalho();

	int *opcao = malloc(sizeof(int));

	do {
		pedeOpcaoConversao(opcao);
		switch(*opcao) {
			case 1:
				printf("{N�o implementado}\n");
				break;
			case 2:
				printf("{N�o implementado}\n");
				break;
			case 3:
				printf("{N�o implementado}\n");
				break;
			case 4:
				printf("\nDigite o valor da quantidade em Litros: \n");
				int litros;
				scanf("%d", &litros);
				float *metrosCubicos = malloc(sizeof(float));

				litrosParaMetrosCubicos(litros, metrosCubicos);
				imprime("L", "m�", *metrosCubicos);
				break;
			case 5:
				printf("\nDigite o valor em Horas: \n");
				int horas;
				scanf("%d",&horas);
				
				int *minutos = malloc(sizeof(int));
				int *segundos = malloc(sizeof(int));

				horasParaMinSec(horas, minutos, segundos);
				printf("%d horas s�o %d minutos ou %d segundos\n", horas, *minutos, *segundos);
				break;
			case 6:
				// Pergunta ao usu�rio o valor que deseja converter na unidade usual
				printf("\nDigite o valor da Quantidade de calor em cal(calorias): \n");
				float *calorias = malloc(sizeof(float));
				scanf("%f", calorias);
				caloriaParaJoule(calorias);
				imprime("cal", "J", *calorias);
				break;
			case 7:
				// Pergunta ao usu�rio o valor que deseja converter na unidade usual
				printf("\nDigite o valor da Velocidade m�dia em km/h: \n");
				float *km = malloc(sizeof(float));
				scanf("%f", km);
				kmHoraParaMetrosSegundo(km);
				imprime("km/h", "m/s", *km);
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
	//scanf("%d", opcao);
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