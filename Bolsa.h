//#pragma once
#ifndef BOLSA_H
#define BOLSA_H
#include <fstream>
#include <iostream>
#include <string>
#include "Fichas.h"
#include "Soportes.h"
using namespace std;



//Variables Globales:
const int MaxJuegoTotalCol = 8;
const int NumFichas = 13;


typedef tFicha tBolsaArray[NumFichas];
//Baraja inicial
struct tBolsa {
	tBolsaArray bolsaArray[MaxJuegoTotalCol];
	int cont = MaxJuegoTotalCol * NumFichas;
};

//Costes:O(tam),siendo tam el tamaño de la bolsa.
void inicializarBolsa(tBolsa& bolsa);//inicializa la bolsa,recorriendo todos los huecos de la bolsa y inicializando su valor y color;

//Costes:O(n),siendo n el tamaño de la bolsa,en el caso peor,ya que puede recorrer circularmente desde una posicion random de la bolsa y solo queda un unico ficha al
//final de su recorrido.
tFicha robar(tBolsa& bolsa);

//Costes:(numJugadores*initFichas),ya que se inicializa para cada jugador robando initFichas.
void repartir(tBolsa& bolsa, tSoportes& soportes);

//Costes:O(n^2) n siendo el numero de fichas de la bolsa.
void mostrar(const  tBolsa& bolsa);// Muestra el estado de la bolsa(array
//bidimensional con las fichas disponibles y con las ya obtenidas).


#endif // !BOLSA_H

