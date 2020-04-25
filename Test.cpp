#include<iostream>
#include "Sistema.h"
#include "Nivel.h"
#include <vector>
#include "Algortimo.h"
#include "leerDatos.h"

using namespace std;

int main()
{
	vector<Nivel> niveles = leerDatos();

	niveles[0].imprimirNivel();
	niveles[1].imprimirNivel();
	vector<float> listaPonderacion(3);

	listaPonderacion[0] = 0.333;
	listaPonderacion[1] = 0.333;
	listaPonderacion[2] = 0.333;
	float desvio=algoritmo(niveles, listaPonderacion);
	cout << (1 - desvio);
	
	return 0;
}