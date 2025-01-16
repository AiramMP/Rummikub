#include "Bolsa.h"
#include <iostream>
#include "Soportes.h"
#include "Random.h"
#include "Colores.h"

using namespace std;


void inicializarBolsa(tBolsa& bolsa) {
	tFicha fichaActual;
	for (int i = 0; i < MaxJuegoTotalCol; i++) {
		for (int j = 0; j < NumFichas; j++) {
			fichaActual.cardValue = j + 1;
			fichaActual.color = colorFicha(i);// si no entiendes como hemos asignado esta linea mirae colorFicha(i)
			bolsa.bolsaArray[i][j] = fichaActual;
		}
	}
}

tFicha robar(tBolsa& bolsa) {
	int posX = getRand(MaxJuegoTotalCol);
	int posY = getRand(NumFichas);
	tFicha ficha;
	ficha.cardValue = -1;
	ficha.color = tColor::blanco;
	int posXAct = posX;
	int posYAct = posY;
	bool encontrado = false;
	if (bolsa.cont != 0) {
		do {
			do {
				if (bolsa.bolsaArray[posXAct][posYAct].cardValue != -1 && bolsa.bolsaArray[posXAct][posYAct].color != tColor::blanco) {
					ficha = bolsa.bolsaArray[posXAct][posYAct];
					bolsa.bolsaArray[posXAct][posYAct].cardValue = -1;
					bolsa.bolsaArray[posXAct][posYAct].color = tColor::blanco;
					bolsa.cont--;
					encontrado = true;
				}
				posYAct = (posYAct + 1) % NumFichas;
			} while (posYAct != 0 && !encontrado);
			posXAct = (posXAct + 1) % MaxJuegoTotalCol;
		} while ((posXAct != posX && posYAct != posY) && !encontrado);
	}
	return ficha;
}


void repartir(tBolsa& bolsa, tSoportes& soportes) {
	for (int i = 0; i < NumJugadores; i++) {
		for (int j = 0; j < IniFichas; j++) {
			soportes.soporteArray[i].soporteArray[j] = robar(bolsa);
			soportes.soporteArray[i].numFichas++;
		}
	}
}

void mostrar(const  tBolsa& bolsa) {
	cout << "Bolsa: " << endl;
	for (int i = 0; i < NumFichas; i++) {
		cout << i + ":";
		for (int j = 0; j < MaxJuegoTotalCol; j++) {
			colorTexto(bolsa.bolsaArray[i][j].color);
			cout << setw(3);
			cout << bolsa.bolsaArray[i][j].cardValue;
		}
		cout << endl;
		colorTexto(tColor::blanco);
	}
	cout << endl;
	colorTexto(tColor::blanco);
}