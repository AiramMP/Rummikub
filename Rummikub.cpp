// Autor/a: ZhiPeng Gao y Airam Mart�n Peraza 
// email: zhipengg@ucm.es y airammar@ucm.es
// Compilador y S.O. utilizado
// Nombre del problema: Rummikub (Pr�ctica 1)
// Comentario general sobre la soluci�n:
// los costes estan inicialmente en las declaraciones de las funciones.!!!
// explicando como se resuelve el problema

#include <iostream>
#include <fstream>
#include <time.h>
#include <iomanip>  
#include<stdlib.h>
#include <string>
#include "Colores.h"
#include "Fichas.h"
#include "Bolsa.h"
#include "Random.h"
#include "Soporte.h"
#include "Soportes.h"
#include "Jugadas.h"
#include "Tablero.h"
#include "Rummikub.h"

using namespace std;



int main() {

	/*
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("datos.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	std::ofstream out("datos.out");
	auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif*/

	resuelveCaso();

	// para dejar todo como estaba al principio
/*#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	std::cout.rdbuf(coutbuf);
	system("PAUSE");
#endif*/
	return 0;
}


// resuelve el caso de prueba, leyendo de la entrada la
// configuraci�n, y escribiendo la respuesta
void resuelveCaso() {
	//INICIALIZACIONES:
	srand(time(NULL));
	int menuOP;
	tBolsa bolsa;
	tSoportes soportes;
	tTablero tablero;
	inicializarBolsa(bolsa);
	repartir(bolsa, soportes);
	int turn = getRand(NumJugadores);
	bool haJugado;
	int op;
	int contNumSaltoSeguido = 0;
	bool noMeQuedaFichas = false;
	bool heJugadoErr = false;
	//EMPIEZA EL JUEGO:
	cout << "Bienvenido al juego del Rummikub ver_1" << endl;
	cout << endl;
	while (bolsa.cont != 0 && contNumSaltoSeguido < NumJugadores && !noMeQuedaFichas) {
		turn = (turn + 1) % NumJugadores;
		op = -1;
		haJugado = false;
		heJugadoErr = false;
		cout << "Turno para el jugador " << turn + 1 << " ..." << endl;
		cout << endl;
		mostrar(tablero);
		cout << endl;
		while (op != 0) {
			mostrar(soportes.soporteArray[turn]);
			op = menu();
			switch (op) {
			case 1:
				ordenarPorNum(soportes.soporteArray[turn]);
				break;
			case 2:
				ordenarPorColor(soportes.soporteArray[turn]);
				break;
			case 3:
				mostrarSeries(soportes.soporteArray[turn]);
				mostrarEscaleras(soportes.soporteArray[turn]);
				break;
			case 4:
				if (jugar(tablero, soportes.soporteArray[turn])) {
					cout << endl;
					mostrar(tablero);
					cout << endl;
					cout << endl;
					haJugado = true;
				}
				if (soportes.soporteArray[turn].numFichas == 0) {
					noMeQuedaFichas = true;
				}
				break;
			case 0:
				if (soportes.soporteArray[turn].numFichas < MaxFichas && !haJugado) {
					soportes.soporteArray[turn].soporteArray[soportes.soporteArray[turn].numFichas] = robar(bolsa);
					soportes.soporteArray[turn].numFichas++;
					contNumSaltoSeguido++;
				}
				else {
					contNumSaltoSeguido = 0;
				}
				break;
			default:
				cout << "Opcion no valida, vuelve a introducir una opcion entre el intervalo [0-4] :" << endl;
				break;
			}
		}
		cout << endl;
		cout << "ronda terminada" << endl;
		cout << endl;
	}
	//TRATAR LOS CASOS FINALES
	cout << endl;
	if (noMeQuedaFichas) {
		cout << "Ha ganado el jugador : " << turn + 1 << "!!! ;D" << endl;
	}
	else {
		int valorTotalFichas = valorSumTotalSoporteAux(soportes.soporteArray[turn]);
		int posJugadorGanador = turn;
		int currentTurn = (turn + 1) % NumJugadores;
		int currentTotalValue = 0;
		while (currentTurn != turn) {
			currentTotalValue = valorSumTotalSoporteAux(soportes.soporteArray[currentTurn]);
			if (valorTotalFichas > currentTotalValue) {
				valorTotalFichas = currentTotalValue;
				posJugadorGanador = currentTurn;
			}
			currentTurn = (currentTurn + 1) % NumJugadores;
		}
		cout << "Situacion de bloqueo : ";
		if (bolsa.cont == 0) {
			cout << "Debido a que la bolsa esta vacia" << endl;
		}
		else {
			cout << "Debido a que todos los jugadores han saltado su ronda sin haber jugado ninguna/as ficha/fichas" << endl;
		}
		cout << "Ha ganado el jugador : " << posJugadorGanador + 1 << " , con un suma total de valor de : " << valorTotalFichas << " !!! :D" << endl;
		cout << "Soporte de los jugadores:" << endl;
		for (int i = 0; i < NumJugadores; i++) {
			cout << "Jugador " << i + 1 << ":" << endl;
			mostrar(soportes.soporteArray[i]);
		}
	}
}

int menu() {
	string op;
	cout << "1: Ordenar por num., 2: Ordenar por color, 3: Sugerir, 4: Poner, 0: Fin >>> ";
	cin >> op;
	if (op.size() == 1) {
		switch (op[0]) {
		case '0':
			return 0;
			break;
		case '1':
			return 1;
			break;
		case '2':
			return 2;
			break;
		case '3':
			return 3;
			break;
		case '4':
			return 4;
			break;
		default:
			return -1;
			break;
		}
	}
	else {
		return -1;
	}

}

