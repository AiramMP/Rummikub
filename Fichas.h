//#pragma once
#ifndef FICHAS_H
#define FICHAS_H
#include <iomanip>  
#include <iostream>
#include <fstream>
#include <string>
#include "Colores.h"
using namespace std;



struct tFicha {
	int cardValue;
	tColor color;
};

//Costes:O(l) Es constantes.
void mostrar(const tFicha& ficha);  //Muestra la ficha : n�mero de la ficha
//ocupando dos posiciones de pantalla y en el color correspondiente, y dejando dos espacios
//a continuaci�n.


#endif // !FICHAS_H

