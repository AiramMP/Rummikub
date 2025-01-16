#include "Fichas.h"
#include <iostream>
#include "Colores.h"

using namespace std;

void mostrar(const tFicha& ficha) {
	colorTexto(ficha.color);
	cout << setw(2);
	cout << ficha.cardValue << "  ";
	colorTexto(tColor::blanco);
}