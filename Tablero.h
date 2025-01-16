//#pragma once
#ifndef TABLERO_H
#define TABLERO_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;



struct tTablero {
	tJugada tJugadas[NumFichas * 2];
	int numJugadas = 0;
};

//Costes:O(n^2) siendo n el numero total de fichas del soporte o si por el contrario el numero
//de fichas del tablero es mayor n seria el numero total de fichas del tablero
bool jugar(tTablero& tablero, tSoporte& soporte); /*Permite al usuario colocar
fichas de su soporte en el tablero, como nuevas series o escaleras, o fichas
independientes en jugadas que haya sobre el tablero.*/


//Costes:O(n) siendo n el tamaño del tablero
void mostrar(const tTablero& tablero); //Muestra las jugadas del tablero, numeradas desde 1.


#endif // !TABLERO_H

