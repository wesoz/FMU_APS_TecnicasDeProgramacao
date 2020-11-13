#include <stdio.h>
#include <stdlib.h>

// Funções de conversão de Unidade Usual para Sistema Internacional de Unidades

//Função que converte horas para minutos e segundos
void horasParaMinSec(int hr, int *min, int *seg){
	*min = hr*60;
	*seg = hr*3600;
}

//Função que converte kilometros por hora para metros por segundo.
void kmHoraParaMetrosSegundo(float *vel_media) {
	*vel_media = *vel_media / 3.6;	        // Calculo da função.
}

//Função que converte caloria para Joule
void caloriaParaJoule(float *qua_calor) {
	*qua_calor = *qua_calor * 4.18;	        // Calculo da função.
}

//Função que converte Litros para Metros Cúbicos
void litrosParaMetrosCubicos(int litros, float *metros3) {
	*metros3 = litros / 1000.0;
}

//Função que converte gramas para quilogramas
void gramaParaKg(float *conversao) {
	*conversao = *conversao / 1000.0;
}

//Função que converte centímetros quadrados para para metros quadrados
void cmQuadradosParaMetrosQuadrados(float *valor) {
	*valor = *valor / 10000.0;
}