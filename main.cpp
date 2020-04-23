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
	//Inicializamos los sistema del nivel 2

	Sistema ingenieria1(1, 0 ,0.5f, "Ingenieria1", "Ingenieria"), ingenieria2(1, 0 , 0.5f, "Ingenieria2", "Ingenieria"),
		matematica1(1, 0,  0.5f,"Matematicas1", "Matematicas"),
		matematica2(1, 0 , 0.5f, "Matematicas2", "Matematicas"),
		otros1(1, 0,  0.5f, "Otros1", "Otros"), otros2(1, 0 , 0.5f, "Otros2", "Otros");

	//lamdas y atributos

	ingenieria1.listaLamdas.push_back(0.5f);
	ingenieria1.listaLamdas.push_back(0.5f);
	ingenieria2.listaLamdas.push_back(0.5f);
	ingenieria2.listaLamdas.push_back(0.5f);
	matematica1.listaLamdas.push_back(0.5f);
	matematica1.listaLamdas.push_back(0.5f);
	matematica2.listaLamdas.push_back(0.5f);
	matematica2.listaLamdas.push_back(0.5f);
	otros1.listaLamdas.push_back(0.5f);
	otros1.listaLamdas.push_back(0.5f);
	otros2.listaLamdas.push_back(0.5f);
	otros2.listaLamdas.push_back(0.5f);

	ingenieria1.listaAtributos.push_back(1);
	ingenieria1.listaAtributos.push_back(0.625f);
	ingenieria2.listaAtributos.push_back(1);
	ingenieria2.listaAtributos.push_back(1);
	matematica1.listaAtributos.push_back(0.565f);
	matematica1.listaAtributos.push_back(0.125f);
	matematica2.listaAtributos.push_back(0.869f);
	matematica2.listaAtributos.push_back(0.375f);
	otros1.listaAtributos.push_back(0);
	otros1.listaAtributos.push_back(1);
	otros2.listaAtributos.push_back(0.478f);
	otros2.listaAtributos.push_back(1);

	//lista de sistemas nivel 2
	vector<Sistema> listaS2;
	listaS2.push_back(ingenieria1);
	listaS2.push_back(matematica1);
	listaS2.push_back(otros1);
	listaS2.push_back(ingenieria2);
	listaS2.push_back(matematica2);
	listaS2.push_back(otros2);

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