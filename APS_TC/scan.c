#include "scan.h"
#include <stdio.h>
#include <stdlib.h>

#define SCANINT_REQUEST_INPUT "Digite:"
#define SCANINT_POST_VALIDATION "Pressione enter para continuar\n"
#define SCANINT_INVALID_ENTRY "Digite apenas números\n"
#define SCANINT_MAX_VIOLATION "O número deve ser até %d\n"
#define SCANINT_MIN_VIOLATION "O número deve ser igual ou maior que %d\n"

// Faz a leitura de uma entrada e valida se é um número inteiro e se está dentro dos limites especificados pelos
// parametros minValue e maxValue
void scanInt(int *value, int minValue, int maxValue) {
	int invalid = 1;
	char term;
	
	// Verifica se a função recebeu algo em minValue e maxValue e valida se
	// maxValue é maior que minValue
	if (minValue > -1 && maxValue > -1 && maxValue <= minValue) {
		printf("Invalid parameters.\nMin: %d\nMax: %d", minValue, maxValue);
		return;
	}

	while (invalid == 1) {
		printf(SCANINT_REQUEST_INPUT);
		// Verifica se recebeu um número inteiro
		if(scanf("%d%c", value, &term) != 2 || term != '\n') {
			// Exibe mensagem caso não tenha recebido um número
		    printf("%s\n", SCANINT_INVALID_ENTRY);
		    printf("%s\n", SCANINT_POST_VALIDATION);
		    scanf("%c");
		}
		else if(minValue > -1 && *value < minValue) {
			// Exibe mensagem caso valor seja menor que o mínimo(minValue)
			printf(SCANINT_MIN_VIOLATION, maxValue);
			printf("%s\n", SCANINT_POST_VALIDATION);
		    scanf("%c");
		} else if(maxValue > -1 && *value > maxValue) {
			// Exibe mensagem caso valor seja maior que o máximo(maxValue)
			printf(SCANINT_MAX_VIOLATION, maxValue);
			printf("%s\n", SCANINT_POST_VALIDATION);
		    scanf("%c");
		} else {
		    invalid = 0;
		}
	}
}

