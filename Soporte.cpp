#include "Soporte.h"
#include <iostream>
#include "Fichas.h"
#include "Jugadas.h"
#include "Tablero.h"
#include "Colores.h"
using namespace std;


void ordenarPorNum(tSoporte& soporte) {
	ordenar_aux_num(soporte, 0, soporte.numFichas);
	int init = 0;
	int end = 0;
	for (int i = 1; i < NumFichas + 1; i++) {
		while (soporte.soporteArray[end].cardValue == i) { end++; }
		ordenar_aux_color(soporte, init, end);
		init = end;
	}
	
}

//no esta preservando el orden
void ordenarPorColor(tSoporte& soporte) {
	ordenar_aux_color(soporte, 0, soporte.numFichas);
	int ini = 0;
	int iterador = 0;
	while (soporte.soporteArray[iterador].color == tColor::rojo && iterador < soporte.numFichas) { iterador++; }
	ordenar_aux_num(soporte, ini, iterador);
	ini = iterador;
	while (soporte.soporteArray[iterador].color == tColor::verde && iterador < soporte.numFichas) { iterador++; }
	ordenar_aux_num(soporte, ini, iterador);
	ini = iterador;
	while (soporte.soporteArray[iterador].color == tColor::azul && iterador < soporte.numFichas) { iterador++; }
	ordenar_aux_num(soporte, ini, iterador);
	ini = iterador;
	while (soporte.soporteArray[iterador].color == tColor::amarillo && iterador < soporte.numFichas) { iterador++; }
	ordenar_aux_num(soporte, ini, iterador);

}

void eliminaFichas(tSoporte& soporte, const tJugada& jugada) {
	int j = 0;
	int i;
	bool encontrado;

	while (jugada[j].cardValue != -1) {
		encontrado = false;
		i = 0;
		while (i < soporte.numFichas && !encontrado) {
			if (soporte.soporteArray[i].cardValue == jugada[j].cardValue && jugada[j].color == soporte.soporteArray[i].color) {
				for (int m = i + 1; m < soporte.numFichas; m++) {
					soporte.soporteArray[m - 1] = soporte.soporteArray[m];
				}
				soporte.numFichas--;
				encontrado = true;
			}
			i++;
		}
		j++;
	}
}

void mostrar(const tSoporte& soporte) {
	cout << "Soporte:  ";
	for (int i = 0; i < soporte.numFichas; i++) {
		mostrar(soporte.soporteArray[i]);
	}
	cout << endl;
	colorTexto(tColor::blanco);
}

void mostrarSeries(const tSoporte& soporte) {
	tSoporte soporteAux = soporte;
	ordenarPorNum(soporteAux);
	tTablero serie;
	int contSer = 1;
	int numSerieA_Mostrar = 0;
	int initPosAux;
	int numColorSerieRepetido = 0;
	tFicha prev = soporteAux.soporteArray[0];
	for (int i = 1; i < soporteAux.numFichas; i++) {
		if (prev.cardValue == soporteAux.soporteArray[i].cardValue && prev.color != soporteAux.soporteArray[i].color) {
			contSer++;

		}
		else if (prev.cardValue == soporteAux.soporteArray[i].cardValue && prev.color == soporteAux.soporteArray[i].color) {
			contSer++;
			numColorSerieRepetido++;
		}
		else {
			if (contSer - numColorSerieRepetido >= 3) {
				initPosAux = 0;
				serie.tJugadas[numSerieA_Mostrar][initPosAux] = soporteAux.soporteArray[i - contSer];
				initPosAux++;
				for (int j = i - contSer + 1; j < i; j++) {
					if (soporteAux.soporteArray[j - 1].color != soporteAux.soporteArray[j].color) {
						serie.tJugadas[numSerieA_Mostrar][initPosAux] = soporteAux.soporteArray[j];
						initPosAux++;
					}
				}
				tFicha centFicha;
				centFicha.cardValue = -1;
				centFicha.color = tColor::blanco;
				serie.tJugadas[numSerieA_Mostrar][initPosAux] = centFicha;
				serie.numJugadas++;
				numSerieA_Mostrar++;
			}
			contSer = 1;
			numColorSerieRepetido = 0;
		}
		prev = soporteAux.soporteArray[i];
	}
	if (contSer - numColorSerieRepetido >= 3) {
		initPosAux = 0;
		serie.tJugadas[numSerieA_Mostrar][initPosAux] = soporteAux.soporteArray[soporteAux.numFichas - contSer];
		initPosAux++;
		for (int j = soporteAux.numFichas - contSer + 1; j < soporteAux.numFichas; j++) {
			if (soporteAux.soporteArray[j - 1].color != soporteAux.soporteArray[j].color) {
				serie.tJugadas[numSerieA_Mostrar][initPosAux] = soporteAux.soporteArray[j];
				initPosAux++;
			}
		}
		tFicha centFicha;
		centFicha.cardValue = -1;
		centFicha.color = tColor::blanco;
		serie.tJugadas[numSerieA_Mostrar][initPosAux] = centFicha;
		serie.numJugadas++;
		numSerieA_Mostrar++;
	}
	for (int i = 0; i < serie.numJugadas; i++) {
		mostrar(serie.tJugadas[i]);
		cout << endl;
	}
}

void mostrarEscaleras(const tSoporte& soporte) {
	tSoporte soporteAux = soporte;
	ordenarPorColor(soporteAux);
	tTablero escaleras;
	int contEsc = 1;
	int numEscaleraA_Mostrar = 0;
	int numNumeroEscaleraRepetido = 0;
	tFicha prev = soporteAux.soporteArray[0];
	for (int i = 1; i < soporteAux.numFichas; i++) {
		if (prev.color == soporteAux.soporteArray[i].color && (soporteAux.soporteArray[i].cardValue - prev.cardValue) == 1) {
			contEsc++;
		}
		else if (prev.color == soporteAux.soporteArray[i].color && (soporteAux.soporteArray[i].cardValue - prev.cardValue) == 0) {
			contEsc++;
			numNumeroEscaleraRepetido++;
		}
		else {
			if (contEsc - numNumeroEscaleraRepetido >= 3) {
				int initPosAux = 0;
				escaleras.tJugadas[numEscaleraA_Mostrar][initPosAux] = soporteAux.soporteArray[i - contEsc];
				initPosAux++;
				for (int j = i - contEsc + 1; j < i; j++) {
					if (soporteAux.soporteArray[j].cardValue - soporteAux.soporteArray[j - 1].cardValue == 1 && soporteAux.soporteArray[j].color == soporteAux.soporteArray[j - 1].color) {
						escaleras.tJugadas[numEscaleraA_Mostrar][initPosAux] = soporteAux.soporteArray[j];
						initPosAux++;
					}
				}
				tFicha centFicha;
				centFicha.cardValue = -1;
				centFicha.color = tColor::blanco;
				escaleras.tJugadas[numEscaleraA_Mostrar][initPosAux] = centFicha;
				escaleras.numJugadas++;
				numEscaleraA_Mostrar++;
			}
			contEsc = 1;
			numNumeroEscaleraRepetido = 0;
		}
		prev = soporteAux.soporteArray[i];
	}
	if (contEsc - numNumeroEscaleraRepetido >= 3) {
		int initPosAux = 0;
		escaleras.tJugadas[numEscaleraA_Mostrar][initPosAux] = soporteAux.soporteArray[soporteAux.numFichas - contEsc];
		initPosAux++;
		for (int j = soporteAux.numFichas - contEsc + 1; j < soporteAux.numFichas; j++) {
			if (soporteAux.soporteArray[j].cardValue - soporteAux.soporteArray[j - 1].cardValue == 1 && soporteAux.soporteArray[j].color == soporteAux.soporteArray[j - 1].color) {
				escaleras.tJugadas[numEscaleraA_Mostrar][initPosAux] = soporteAux.soporteArray[j];
				initPosAux++;
			}
		}
		tFicha centFicha;
		centFicha.cardValue = -1;
		centFicha.color = tColor::blanco;
		escaleras.tJugadas[numEscaleraA_Mostrar][initPosAux] = centFicha;
		escaleras.numJugadas++;
		numEscaleraA_Mostrar++;
	}
	for (int i = 0; i < escaleras.numJugadas; i++) {
		mostrar(escaleras.tJugadas[i]);
		cout << endl;
	}
}

//funci�n auxiliar
void ordenar_aux_num(tSoporte& soporte, int ini, int fin) {
	int i = 0;
	int menor;
	tFicha tmp;

	for (i = ini; i < fin; i++) {
		// La lista[0 … i-1] está ordenada y todos sus elementos son 
		//menores(o iguales) que los de lista[i … N - 1]
			// 1. Buscamos el menor de lista[i … N-1].
		menor = i;
		for (int j = i + 1; j < fin; j++)
			if (soporte.soporteArray[j].cardValue < soporte.soporteArray[menor].cardValue) menor = j;
		if (menor > i) { //2. Intercambiarlo con lista[i] 
			tmp = soporte.soporteArray[i];
			soporte.soporteArray[i] = soporte.soporteArray[menor];
			soporte.soporteArray[menor] = tmp;
		} //Así obtenemos ordenada lista[0 … i]
	}
}

//funci�n auxiliar
void ordenar_aux_color(tSoporte& soporte, int ini, int fin) {
	int i = 0;
	int menor;
	tFicha tmp;

	for (i = ini; i < fin; i++) {
		// La lista[0 … i-1] está ordenada y todos sus elementos son 
		//menores(o iguales) que los de lista[i … N - 1]
			// 1. Buscamos el menor de lista[i … N-1].
		menor = i;
		for (int j = i + 1; j < fin; j++)
			if (soporte.soporteArray[j].color < soporte.soporteArray[menor].color) menor = j;
		if (menor > i) { //2. Intercambiarlo con lista[i] 
			tmp = soporte.soporteArray[i];
			soporte.soporteArray[i] = soporte.soporteArray[menor];
			soporte.soporteArray[menor] = tmp;
		} //Así obtenemos ordenada lista[0 … i]
	}
}

//funci�n auxiliar
void swapAux(tSoporte& soporte, int posElemUno, int posElemDos) {
	tFicha aux = soporte.soporteArray[posElemDos];
	for (int i = posElemDos; i > posElemUno; i--) {
		soporte.soporteArray[i] = soporte.soporteArray[i - 1];
	}
	soporte.soporteArray[posElemUno] = aux;
}

int valorSumTotalSoporteAux(const tSoporte& soporte) {
	int sum = 0;
	for (int i = 0; i < soporte.numFichas; i++) {
		sum += soporte.soporteArray[i].cardValue;
	}
	return sum;
}