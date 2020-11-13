/*

APS - Técnicas de Programação

Nome                             - RA
Danilo Dini de Melo Sá           - 6057183
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

//protótipo das funções.
void imprime(const char[], const char[], float); 
void pedeOpcaoConversao(int *opcao);
void imprimeCabecalho();
void conversaoComFloat(const char mensagem[], const char usual[], const char si[], void (*func)(float*));

int main(){

	// Configura o idioma para Portugês para que o compilador aceite caracteres desse idioma
	setlocale(LC_ALL, "Portuguese"); 

	imprimeCabecalho();

	int *opcao = (int*)malloc(sizeof(int));

	do {
		pedeOpcaoConversao(opcao);
		switch(*opcao) {
			case 1:
				// Chama uma função genérica que recebe a função de conversão como parâmetro e a executa
				conversaoComFloat("Digite o valor da quantidade em gramas:", 
							   "g", 
							   "kg", 
							   gramaParaKg);
				break;
			case 2:
				printf("{Não implementado}\n");
				break;
			case 3:
				conversaoComFloat("Digite o valor em centímetros quadrados:", 
							   "cm²", 
							   "m²", 
							   cmQuadradosParaMetrosQuadrados);
				break;
			case 4:
				printf("\nDigite o valor da quantidade em Litros: \n");
				int litros;
				scanf("%d", &litros);
				float *metrosCubicos = (float*)malloc(sizeof(float));

				litrosParaMetrosCubicos(litros, metrosCubicos);
				imprime("L", "m³", *metrosCubicos);
				break;
			case 5:
				printf("\nDigite o valor em Horas: \n");
				int horas;
				scanf("%d",&horas);
				
				int *minutos = (int*)malloc(sizeof(int));
				int *segundos = (int*)malloc(sizeof(int));

				horasParaMinSec(horas, minutos, segundos);
				printf("%d horas são %d minutos ou %d segundos\n", horas, *minutos, *segundos);
				break;
			case 6:
				conversaoComFloat("Digite o valor da Quantidade de calor em cal(calorias):", 
							   "cal", 
							   "J", 
							   caloriaParaJoule);
				break;
			case 7:
				conversaoComFloat("Digite o valor da Velocidade média em km/h:", 
							   "km/h", 
							   "m/s", 
							   kmHoraParaMetrosSegundo);
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

// Função genérica que exibe uma mensagem, le um float do usuário, converte usando a função passada
// por parâmetro e chama a função imprime
void conversaoComFloat(const char mensagem[], const char usual[], const char si[], void (*func)(float*)) {
		// Pergunta ao usuário o valor que deseja converter na unidade usual
		printf("\n%s\n", mensagem);
		// Declara o ponteiro do tipo float para receber o valor digitado pelo usuário
		float *valor = (float*)malloc(sizeof(float));
		// Armazena o valor digitado no ponteiro
		scanf("%f", valor);
		// Passa o ponteiro por referência para a função de conversão
		func(valor);
		// Imprime o valor convertido e informa as unidades
		imprime(usual, si, *valor);
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