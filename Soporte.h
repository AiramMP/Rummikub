//#pragma once
#ifndef SOPORTE_H
#define SOPORTE_H
#include <iostream>
#include <fstream>
#include <string>
#include "Jugadas.h"
using namespace std;



//Variables Globales:
const int MaxFichas = 50;
const int IniFichas = 14;
const int NumFichas = 13;
//se utiliza en el mostrar series
const int MaxNumSeries = 4;


//Soporte
typedef tFicha tSoporteArray[MaxFichas]; // Inicializar el tama�o o no??????

//Cartas del jugador 
struct tSoporte {
	tSoporteArray soporteArray;
	int numFichas = 0;
};


//Costes:O(total^2),siendo total NumFichas*(el numero de fichas del soporte).
void ordenarPorNum(tSoporte& soporte);

//Costes:O(total^2),siendo total NumFichas*(el numero de fichas del soporte).
void ordenarPorColor(tSoporte& soporte);

//Costes:O(n^2)siendo n el numero de fichas que contiene el soporte en caso peor.
void eliminaFichas(tSoporte& soporte, const tJugada& jugada);
//Elimina del soporte las fichas que hay en la jugada.

//Coste:O(n) siendo n el numero de fichas del soporte
void mostrar(const tSoporte& soporte); //Muestra las fichas que hay en el soporte.

//Costes:O(n^2) siendo n el numero de fichas del soporte
void mostrarSeries(const tSoporte& soporte);// Muestra las posibles series que
//se pueden crear con las fichas del soporte.

//Costes:O(n^2) siendo n el numero de fichas del soporte
void mostrarEscaleras(const tSoporte& soporte);// Muestra las posibles
//escaleras que se pueden crear con las fichas del soporte

void ordenar_aux_num(tSoporte& soporte, int ini, int fin);
//Costes:O(n ^ 2) siendo n el numero de fichas en el soporte
void ordenar_aux_color(tSoporte& soporte, int ini, int fin);
//Costes:O(n) siendo n el numero de fichas en el soporte
void swapAux(tSoporte& soporte, int posElemUno, int posElemDos);

//Costes: O(n) siendo n el numero de fichas en el soporte
int valorSumTotalSoporteAux(const tSoporte& soporte);

#endif // !SOPORTE_H

