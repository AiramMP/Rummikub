//#pragma once
#ifndef RUMMIKUB_H
#define RUMMIKUB_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Costes:O(1),es constante porque solo realizan operaciones de costes constantes.
int menu();

//Costes:O(n^3)
void resuelveCaso();


#endif // !RUMMIKUB_H

