#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include "convmed.h"
#include "scan.h"

//protótipo das funções.
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
				printf("{Não implementado}\n");
				break;
			case 2:
				printf("{Não implementado}\n");
				break;
			case 3:
				printf("{Não implementado}\n");
				break;
			case 4:
				printf("\nDigite o valor da quantidade em Litros: \n");
				int litros;
				scanf("%d", &litros);
				float *metrosCubicos = malloc(sizeof(float));

				litrosParaMetrosCubicos(litros, metrosCubicos);
				imprime("L", "m³", *metrosCubicos);
				break;
			case 5:
				printf("\nDigite o valor em Horas: \n");
				int horas;
				scanf("%d",&horas);
				
				int *minutos = malloc(sizeof(int));
				int *segundos = malloc(sizeof(int));

				horasParaMinSec(horas, minutos, segundos);
				printf("%d horas são %d minutos ou %d segundos\n", horas, *minutos, *segundos);
				break;
			case 6:
				// Pergunta ao usuário o valor que deseja converter na unidade usual
				printf("\nDigite o valor da Quantidade de calor em cal(calorias): \n");
				float *calorias = malloc(sizeof(float));
				scanf("%f", calorias);
				caloriaParaJoule(calorias);
				imprime("cal", "J", *calorias);
				break;
			case 7:
				// Pergunta ao usuário o valor que deseja converter na unidade usual
				printf("\nDigite o valor da Velocidade média em km/h: \n");
				float *km = malloc(sizeof(float));
				scanf("%f", km);
				kmHoraParaMetrosSegundo(km);
				imprime("km/h", "m/s", *km);
				break;
			case 0:
				printf("Programa encerrado.\n");
				break;
			default:
				printf("\nOpção inválida!\n");
				break;
		}
		system("pause");
	// Executa o laço até que o usuário digite 0
	} while(*opcao > 0);
	
	return 0;
}

// Função que imprime recebendo duas strings e o resultado do calculo
void imprime(const char usual[], const char si[], float conversao) {
	printf("\nDe acordo com o Sistema Internacional de medidas, \n");
	printf("O valor digitado em %s convertido para %s é %2.2f %s. \n\n", usual, si, conversao, si);
}

// Função para pedir uma opção digitada pelo usuário
void pedeOpcaoConversao(int *opcao) {
	printf("");
	printf("\nDigite o número da unidade de medida(Unidade Usual) que deseja converter para o Sistema Internacional de Unidades(SI): \n\n");
	printf("|=======================================================|\n");
	printf("| # | Grandeza       | SI | Un. Usual | Correspondência |\n");
	printf("|=======================================================|\n");
	printf("| 1 | Massa          | g  | kg        | 1kg = 1000g     |\n");
	printf("| 2 | Comprimento    | m  | km        | 1km = 1000 m    |\n");
	printf("| 3 | Área           | m² | cm²       | 1m² = 10 000 cm²|\n");
	printf("| 4 | Volume         | m³ | L         | 1m³ = 1000 L    |\n");
	printf("| 5 | Tempo          | s  | h         | 1h = 3600 s     |\n");
	printf("| 6 | Quant. de Calor| J  | cal       | 1 cal = 4,18 J  |\n");
	printf("| 7 | Veloc. média   | m/s| km/h      | 1m/s = 3,6 km/h |\n");
	printf("|=======================================================|\n\n");
	printf("-> Digite 0 para sair\n\n");
	scanInt(opcao, 0, 7);
	//scanf("%d", opcao);
}

// Função para imprimir o cabeçalho do programa
void imprimeCabecalho() {
	printf("\n");
	printf("     _________\n");
	printf("    / ======= \\\n");
	printf("   / __________\\\n");
	printf("  | ___________ |\n");
	printf("  | |Conversor| |\n");
	printf("  | |-        | |\n");
	printf("  | |_________| |________________________\n");
	printf("  \\=____________/Técnicas de Programação )\n");
	printf("  / \"\"\"\"\"\"\"\"\"\"\" \\                       /\n");
	printf(" / ::::::::::::: \\                  =D-'\n");
	printf("(_________________)\n\n");
}