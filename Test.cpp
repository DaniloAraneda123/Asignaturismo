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

	//niveles[0].imprimirNivel();
	//niveles[1].imprimirNivel(); 
	//niveles[2].imprimirNivel();
	vector<float> listaPonderacion(2);

	listaPonderacion[0] = 0.5;
	listaPonderacion[1] = 0.5;
	
	float desvio=algoritmo(niveles, listaPonderacion);
	cout << desvio;



	
	return 0;
}