//#pragma once
#ifndef COLORES_H
#define COLORES_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

typedef enum { rojo, verde, azul, amarillo, blanco } tColor;

void colorTexto(tColor color);
//funcion auxiliar
tColor colorFicha(int i);//Devuelve el color a las fichas(Utilizado en :inicializarBolsa())
//Costes:O(n^2) siendo n el numero de fichas en el soporte

#endif // !TCOLOR_H

