#include "Colores.h"

using namespace std;

void colorTexto(tColor color) {
	switch (color) {
	case amarillo:
		cout << "\033[1m\033[33m";
		break;
	case azul:
		cout << "\033[1m\033[34m";
		break;
	case rojo:
		cout << "\033[1m\033[31m";
		break;
	case verde:
		cout << "\033[1m\033[32m";
		break;
	case blanco:
		cout << "\033[1m\033[37m";
		break;
	}
}

tColor colorFicha(int i) {
	switch (i % 4) {
	case 0:
		return tColor::rojo;
		break;
	case 1:
		return tColor::verde;
		break;
	case 2:
		return tColor::azul;
		break;
	case 3:
		return tColor::amarillo;
		break;
	}


}