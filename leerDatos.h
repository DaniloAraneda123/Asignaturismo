#pragma once
#include "Sistema.h"
#include <vector>
#include "Nivel.h"
#include<fstream>
#include<windows.h>
#include <sstream>

using namespace std;


//lee los sistema del nivel n+1 y los retorna en un vector
vector<Sistema> leerSistemas(int n)
{
	//inializamos variable para lectura y abrir archivo
	vector<Sistema> listaSistemas;
	char delimitador = ';';
	string linea, campo;
	std::stringstream ss;
	ifstream fichero("datos/Sistemas Intermedios.csv");
	if (!fichero)
	{
		cout << "Archivo de Sistemas no encontrado, ERROR";
		exit(1); // terminate si no se encuentra el archivo
	}

	//deshechamos la primera linea
	getline(fichero, linea);


	
	int nivel;
	string nombre, nombrePadre;
	float miPonderacion, ponderacionTotal[2];
	//Revisa el fichero buscando los sistemas
	while (getline(fichero, linea))
	{
		ss = stringstream(linea);
		getline(ss, campo, delimitador);
		nivel= std::stoi(campo);

		//si el sistema pertenece al nivel que se esta recantando, lo guardara
		if (n+1 == nivel)
		{
			getline(ss, campo, delimitador);
			nombre = campo;
			getline(ss, campo, delimitador);
			nombrePadre = campo;
			getline(ss, campo, delimitador);
			miPonderacion= std::stof(campo);
			getline(ss, campo, delimitador);
			ponderacionTotal[0]= std::stof(campo);
			getline(ss, campo, delimitador);
			ponderacionTotal[1] = std::stof(campo);
			cout << nombre << " " << nombrePadre << " " << miPonderacion << " " << ponderacionTotal[0] << " " << ponderacionTotal[1] << endl;

			//una vez leido todos los campos, almacenamos el sistema
			listaSistemas.push_back(Sistema(ponderacionTotal[0], ponderacionTotal[1], miPonderacion, nombre, nombrePadre));
		}
	}
	return listaSistemas;
}


//lee los niveles, los cre y los devuelve en un vecto
void leerNivel(vector <Nivel>* niveles)
{
	//inializamos variable para lectura y abrir archivo
	char delimitador = ';';
	string linea,campo;
	std::stringstream ss;
	ifstream fichero("datos/Niveles y matriz Incidencia.csv");
	if (!fichero)
	{
		cout << "Archivo de niveles no encontrado, ERROR";
		exit(1); // terminate si no se encuentra el archivo
	}


	// Rescatamos el numero de niveles que hay
	getline(fichero,linea);
	ss = stringstream(linea);
	getline(ss, campo,delimitador);
	int numeroNiveles = std::stoi(campo);


	//Por cada nivel , rescatamos su matriz de incidencia
	int tamanoMatriz;
	float** matrizExperto;
	for (int n=0 ; n< numeroNiveles ; n++)
	{
		//obtenemos el Tamaño de la matriz de incidencia del nivel n
		getline(fichero, linea);
		ss = stringstream(linea);
		getline(ss, campo, delimitador);
		tamanoMatriz = std::stoi(campo);

		//creamos una matriz
		matrizExperto = new float* [tamanoMatriz];


		//Rescatamos la matriz de incidencia
		for (int i = 0; i < tamanoMatriz; i++)
		{
			matrizExperto[i] = new float[tamanoMatriz];

			getline(fichero, linea);
			ss = stringstream(linea);
			for (int j = 0; j< tamanoMatriz; j++)
			{
				getline(ss, campo, delimitador);
				matrizExperto[i][j] = std::stof(campo);
				//cout << matrizExperto[i][j] <<" ";
			}
			//cout << endl;
		}
		
		//Almacenamos la matriz en su correspondiente Nivel
		(*niveles).push_back(Nivel(tamanoMatriz, matrizExperto,leerSistemas(n)));
	}

}



vector<Nivel>leerDatos()
{
	vector<Nivel> niveles;
	leerNivel(&niveles);
	///Modulo Bryan
	return niveles;
}
