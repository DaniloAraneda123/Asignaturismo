#include<iostream>
#include "Sistema.h"
#include "Nivel.h"
#include <vector>
#include "Algortimo.h"

using namespace std;

int main()
{
	vector<Nivel> niveles;

	niveles.push_back(Nivel(3));
	niveles.push_back(Nivel(6));

	// inicializamos los sistema del nivel 1
	Sistema ingenieria(0.5, 0.5, "Ingenieria"), matematica(0.5, 0.5, "Matematicas"), otro(0.5, 0.5, "Otros");




	/// Lista de sistemas del nivel 1
	niveles[0].listaSistemas.push_back(ingenieria);
	niveles[0].listaSistemas.push_back(matematica);
	niveles[0].listaSistemas.push_back(otro);

	//matriz incidencia nivel 1
	float** matrizIncidencia1 = new float* [3];
	for (int i = 0; i < 3; i++) matrizIncidencia1[i] = new float[3];
	matrizIncidencia1[0][0] = 0;
	matrizIncidencia1[0][1] = 0.7f;
	matrizIncidencia1[0][2] = 0.5f;
	matrizIncidencia1[1][0] = 0.3f;
	matrizIncidencia1[1][1] = 0;
	matrizIncidencia1[1][2] = 0.7f;
	matrizIncidencia1[2][0] = 0.1f;
	matrizIncidencia1[2][1] = 0.55f;
	matrizIncidencia1[2][2] = 0;

	//creamos nivel 1
	niveles[0].valorExperto = matrizIncidencia1;


	/////////////////////////////////////////////////////////////////////////////////////////////////////
	cout << "nivel 2\n";
	//Inicializamos los sistema del nivel 2
	Sistema ingenieria1(1, 0, "Ingenieria1", &ingenieria), ingenieria2(1, 0, "Ingenieria2", &ingenieria),
		matematica1(1, 0, "Matematicas1", &matematica), matematica2(1, 0, "Matematicas2", &matematica),
		otros1(1, 0, "Otros", &otro), otros2(1, 0, "Otros", &otro);

	//lista de sistemas nivel 2
	vector<Sistema> listaS2;
	listaS2.push_back(ingenieria1);
	listaS2.push_back(matematica1);
	listaS2.push_back(otros1);
	listaS2.push_back(ingenieria2);
	listaS2.push_back(matematica2);
	listaS2.push_back(otros2);
	cout << "Hola\n";
	//matriz incidencia nivel 2
	float** matrizIncidencia2 = new float* [6];
	for (int i = 0; i < 6; i++) matrizIncidencia2[i] = new float[6];
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			matrizIncidencia2[i][j] = 0;
		}
	}

	niveles[1] = Nivel(6, matrizIncidencia2, listaS2);

	/////////////////////////////////////////////////////////////////////////////////////////////////////
	/// Asignamos lamdas y atributo del ultimo nivel


	vector<float> lista;
	lista.push_back(0.333f);
	lista.push_back(0.333f);
	lista.push_back(0.333f);
	float resultado = 0;
	resultado = algoritmo(niveles, lista);
	cout << "El resultado es: " << resultado;


	return 0;
}