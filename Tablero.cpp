#include "Tablero.h"
#include <iostream>
#include "Jugadas.h"
#include "Fichas.h"
#include "Soporte.h"
#include "Colores.h"
#include <vector>
using namespace std;

bool jugar(tTablero& tablero, tSoporte& soporte) {
	int aux;
	int jugadaSeleccionada;
	vector<int> posDondeSePuedeMeterJugada;
	tJugada jugada;
	tFicha cent;
	cent.cardValue = -1;
	cent.color = tColor::blanco;
	mostrar(soporte);
	cout << "        ";
	for (int i = 1; i <= soporte.numFichas; i++) {
		cout << setw(4);
		cout << i;
	}
	cout << endl;
	int numCartasJugada = nuevaJugada(soporte, jugada);
	bool jugadaCorrecta = false;
	if (numCartasJugada == 1) {
		for (int i = 0; i < tablero.numJugadas; i++) {
			if (sePuedePonerFichaAux(tablero.tJugadas[i], jugada[0]) == true) {
				posDondeSePuedeMeterJugada.push_back(i);
			}
		}
		if (posDondeSePuedeMeterJugada.size() > 1) {
			cout << "Jugadas del tablero donde se pueden poner la ficha: " << endl;
			for (int j = 0; j < posDondeSePuedeMeterJugada.size(); j++) {
				cout << " " << posDondeSePuedeMeterJugada[j] + 1 << ":";
				mostrar(tablero.tJugadas[j]);
				std::cout << endl;
			}
			bool posValida = false;
			while (!posValida) {
				cout << "Jugada(Escriba la posicion de la jugada donde quiere meter la ficha):   ";
				cin >> jugadaSeleccionada;
				for (int t = 0; t < posDondeSePuedeMeterJugada.size(); t++) {
					if (jugadaSeleccionada == posDondeSePuedeMeterJugada[t] + 1) {
						posValida = true;
					}
				}if (!posValida) {
					cout << "Posicion introducida no valida" << endl;
				}
			}
			ponerFicha(tablero.tJugadas[jugadaSeleccionada - 1], jugada[0]);
			eliminaFichas(soporte, jugada);
			jugadaCorrecta = true;
		}
		else if (posDondeSePuedeMeterJugada.size() == 1) {
			ponerFicha(tablero.tJugadas[posDondeSePuedeMeterJugada[0]], jugada[0]);
			eliminaFichas(soporte, jugada);
			cout << "Jugada:";
			mostrar(jugada[0]);
			cout << endl;
			cout << "Jugadas del tablero donde poner la ficha: " << posDondeSePuedeMeterJugada[0] + 1 << "-> Colocada!" << endl;
			cout << endl;
			jugadaCorrecta = true;
		}
		else {
			cout << "No se puede colocar en el Tablero la Ficha indicada por el Jugador" << endl;
		}
	}
	else if (numCartasJugada >= 3) {
		if (esEscalera(jugada) || esSerie(jugada)) {
			int i = 0;
			while (jugada[i].cardValue != -1) {
				tablero.tJugadas[tablero.numJugadas][i] = jugada[i];
				i++;
			}
			tablero.tJugadas[tablero.numJugadas][i].cardValue = -1;
			tablero.tJugadas[tablero.numJugadas][i].color = tColor::blanco;
			tablero.numJugadas++;
			eliminaFichas(soporte, jugada);
			jugadaCorrecta = true;
			cout << "Jugada:";
			mostrar(jugada);
			if (esEscalera(jugada)) {
				cout << " - Escalera correcta!" << endl;
			}
			else {
				cout << " - Serie correcta!" << endl;
			}
		}
		else {
			cout << "La Jugada no corresponde con una Serie ni con una Escalera" << endl;
		}

	}
	else {
		cout << "Jugada Incorrecta (el Numero de Fichas de la Jugada es INCORRECTO O las posiciones introducidas por el usuario son incorrectas.)" << endl;
	}
	return jugadaCorrecta;
}

void mostrar(const tTablero& tablero) {
	cout << "Tablero: ";
	if (tablero.numJugadas != 0) {
		for (int i = 0; i < tablero.numJugadas; i++) {
			cout << endl;
			cout << " " << i + 1 << ":" << "   ";
			mostrar(tablero.tJugadas[i]);
		}
	}
	else {
		std::cout << "No hay jugadas" << endl;
	}

}