//#pragma once
#ifndef JUGADAS_H
#define JUGADAS_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MaxJugadas = NumFichas * 2;

typedef tFicha tJugada[NumFichas + 1];

//Costes:O(n),siendo n el numero de fichas que contiene la jugada en el caso peor.
//No se ha utilizado !!!,para que sesupone que lo utilizamos?
int buscar(const tJugada& jugada, const tFicha& ficha);

//Costes:O(n^2) siendo n el numero total de fichas del soporte.
int nuevaJugada(const tSoporte& soporte, tJugada& jugada);
//Permite al usuario crear una jugada con fichas que haya en su soporte.

//Costes:O(n^2) siendo n el numero total de fichas del soporte.
bool ponerFicha(tJugada& jugada, tFicha& ficha); /*Intenta colocar la ficha
en la jugada, sea esta una serie o una escalera, en cuyo caso lo intenta en ambos extremos.
Devuelve true si consigue colocar la ficha y false en caso contrario.*/

//Costes:O(n) siendo n el numero de fichas de la jugada
void mostrar(const tJugada& jugada);// Muestra en una l�nea las fichas de la jugada.

//Costes:O(n ^ 2) siendo n el numero de fichas en la jugada
bool esSerie(const tJugada& jugada);
//Costes:O(n ^ 2) siendo n el numero de fichas en la jugada
bool esEscalera(const tJugada& jugada);
//Costes:O(l) es constante

bool sePuedePonerFichaAux(const tJugada& jugada, const tFicha& ficha);

#endif // !JUGADAS_H
