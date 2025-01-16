//#pragma once
#ifndef SOPORTES_H
#define SOPORTES_H
#include <string>
#include <iostream>
#include <fstream>
#include "Soporte.h"
using namespace std;


//Variables Globales:
const int NumJugadores = 4;

//soporte de todos los jugadores
typedef tSoporte tSoportesArray[NumJugadores];
//conjunto de las cartas de los jugadores
struct tSoportes {
	tSoportesArray soporteArray;
	int numJugadores = NumJugadores;
};

#endif // !SOPORTES_H
