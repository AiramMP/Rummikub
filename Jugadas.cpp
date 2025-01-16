#include "Jugadas.h"
#include <iostream>
#include "Soporte.h"
#include "Bolsa.h"
#include "Fichas.h"
#include "Colores.h"
using namespace std;

int buscar(const tJugada& jugada, const tFicha& ficha) {
	int i = 0;
	bool ok = false;
	while (jugada[i].cardValue != -1 && !ok) {
		if (jugada[i].cardValue == ficha.cardValue && jugada[i].color == ficha.color) {
			ok = true;
		}
		i++;
	}
	if (ok) {
		return i - 1;
	}
	else {
		return -1;
	}
}

int nuevaJugada(const tSoporte& soporte, tJugada& jugada) {
	int aux;
	tSoporte auxOrdenarJugada;
	int j = 0;
	cout << "Fichas (0 al final): ";
	cin >> aux;
	while (aux != 0 && j < NumFichas) {
		if (aux <= soporte.numFichas && aux > 0) {
			jugada[j] = soporte.soporteArray[aux - 1];
			auxOrdenarJugada.soporteArray[j] = jugada[j];
			cin >> aux;
			auxOrdenarJugada.numFichas++;
			j++;
		}
		else {
			return 0;
		}
	}
	ordenarPorNum(auxOrdenarJugada);
	for (int i = 0; i < soporte.numFichas; i++) {
		jugada[i] = auxOrdenarJugada.soporteArray[i];
	}
	jugada[j].cardValue = -1;
	jugada[j].color = tColor::blanco;
	return j;
}

bool ponerFicha(tJugada& jugada, tFicha& ficha) {
	int j = 0;
	if (esSerie(jugada) && ficha.cardValue == jugada[0].cardValue) {
		while (jugada[j].cardValue != -1 && ficha.color != jugada[j].color) { j++; }
		mostrar(jugada[j]);
		if (jugada[j].cardValue == -1 && j < NumFichas && j >= 3) {
			tFicha aux = jugada[j];
			mostrar(aux);
			jugada[j] = ficha;
			jugada[++j] = aux;
			return true;
		}
		else {
			return false;
		}
	}
	else if (esEscalera(jugada)) {
		int iniValue = 0;
		int finValue = 0;
		while (jugada[finValue].cardValue != -1 && ficha.color == jugada[j].color) { finValue++; }
		//la condicion de finValue>0 sobra,ya que si es una escalera,tiene al menos tres cartas,pero sin embargo he puesto esa función para que no me queje en el lugar indicado:
		//puedes quitar esa condicion y funciona igual ☺.
		if (finValue < NumFichas&& finValue >= 3) {
			if (jugada[0].cardValue - ficha.cardValue == 1) {
				for (int i = finValue + 1; i > iniValue; i--) {
					jugada[i] = jugada[i - 1];
				}
				jugada[iniValue] = ficha;
				return true;
			}//lugar indicado,al no poner la condicion de finValue>0,se me queja con "C6385:Leyendo datos no validos de 'jugada'."en el else if de abajo.
			else if (ficha.cardValue - jugada[--finValue].cardValue == 1) {
				tFicha aux = jugada[++finValue];
				jugada[finValue] = ficha;
				jugada[++finValue] = aux;
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}

	}
}

void mostrar(const tJugada& jugada) {
	int j = 0;
	while (jugada[j].cardValue != -1 && jugada[j].color != tColor::blanco) {
		mostrar(jugada[j]);
		cout << setw(1);
		j++;
	}
}

bool esSerie(const tJugada& jugada) {
	int j = 0;
	bool esSerie = true;
	while (jugada[j].cardValue != -1) { j++; }
	for (int i = 0; i < j - 1 && esSerie; i++) {
		if (jugada[i].cardValue != jugada[i + 1].cardValue || jugada[i].color == jugada[i + 1].color) {
			esSerie = false;
		}
	}
	return esSerie && j > 2;
}

bool esEscalera(const tJugada& jugada) {
	int j = 0;
	bool esEscalera = true;
	while (jugada[j].cardValue != -1) { j++; }
	for (int i = 0; i < j - 1 && esEscalera; i++) {
		if (jugada[i + 1].cardValue - jugada[i].cardValue != 1 || jugada[i].color != jugada[i + 1].color) {
			esEscalera = false;
		}
	}
	return j > 2 && esEscalera;
}

bool sePuedePonerFichaAux(const tJugada& jugada, const tFicha& ficha) {
	int j = 0;
	if (esSerie(jugada) && ficha.cardValue == jugada[0].cardValue) {
		while (jugada[j].cardValue != -1 && ficha.color != jugada[j].color) { j++; }
		if (jugada[j].cardValue == -1 && j < NumFichas) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (esEscalera(jugada)) {
		int iniValue = 0;
		int finValue = 0;
		while (jugada[finValue].cardValue != -1) { finValue++; }
		if (finValue < NumFichas && finValue > 0) {
			if (jugada[0].cardValue - ficha.cardValue == 1 && ficha.color == jugada[j].color) {
				return true;
			}
			else if (ficha.cardValue - jugada[finValue - 1].cardValue == 1 && ficha.color == jugada[j].color) {
				return true;
			}
			else {
				return false;
			}
		}

	}

}