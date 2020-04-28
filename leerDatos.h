#pragma once
#include "Sistema.h"
#include <vector>
#include "Nivel.h"
#include<fstream>
#include<windows.h>
#include <sstream>
#include "funcionesMembresia.h"

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
			//cout << nombre << " " << nombrePadre << " " << miPonderacion << " " << ponderacionTotal[0] << " " << ponderacionTotal[1] << endl;

			//una vez leido todos los campos, almacenamos el sistema
			listaSistemas.push_back(Sistema(ponderacionTotal[0], ponderacionTotal[1], miPonderacion, nombre, nombrePadre));
		}
	}
	return listaSistemas;
}
vector<Sistema> leerSistemaUltimoNivel()
{
	//inializamos variable para lectura y abrir archivo
	vector<Sistema> listaSistemas;
	char delimitador = ';';
	string linea, campo;
	std::stringstream ss;
	//membresia
	std::stringstream membresia;
	ifstream fichero("datos/Ultimo Nivel.csv");
	if (!fichero)
	{
		cout << "Archivo de Ultimo Nivel no encontrado, ERROR";
		exit(1); // terminate si no se encuentra el archivo
	}

	//deshechamos la primera linea
	getline(fichero, linea);

	int nivel = 0;
	string nombre, nombrePadre;
	float miPonderacion, ponderacionTotal[2];
	int cantidadInputs = 0;

	//Incicialisando variables para leer Inputs
	std::stringstream ssInputs;
	string LineaInputs;
	ifstream ficheroInputs("datos/Inputs.csv");
	if (!ficheroInputs)
	{
		cout << "Archivo de Inputs no encontrado, ERROR";
		exit(1); // terminate si no se encuentra el archivo
	}
	//deshechamos la primera linea
	getline(ficheroInputs, LineaInputs);


	//Revisa el fichero buscando los sistemas
	while (getline(fichero, linea))
	{
		ss = stringstream(linea);
		//getline(ss, campo, delimitador);
		// nivel = std::stoi(campo);

		//si el sistema pertenece al nivel que se esta recantando, lo guardara
		//Recatamos los datos en Iniciales
		getline(ss, campo, delimitador);
		nombre = campo;
		getline(ss, campo, delimitador);
		nombrePadre = campo;
		getline(ss, campo, delimitador);
		//cout << campo << endl;
		miPonderacion = std::stof(campo);
		getline(ss, campo, delimitador);
		ponderacionTotal[0] = std::stof(campo);
		getline(ss, campo, delimitador);
		ponderacionTotal[1] = std::stof(campo);

		//una vez leido todos los campos, almacenamos el sistema
		Sistema sistema(ponderacionTotal[0], ponderacionTotal[1], miPonderacion, nombre, nombrePadre);

		// Numero de atributos
		getline(ss, campo, delimitador);
		cantidadInputs = std::stof(campo);

		float atributo;
		float lambda;
		float input;
		// funciones de membresia;
		int a;
		int b;
		int c;
		int d;
		string tipoFuncion;
		stringstream membresia;

		//leer lineas del inputs
		getline(ficheroInputs, LineaInputs);
		ssInputs = stringstream(LineaInputs);
		getline(ssInputs, campo, delimitador);//sacamos el nombre

		for (int i = 0; i < cantidadInputs; i++) {

			// Que tipo de funcion de membresia
			getline(ss, campo, delimitador);
			tipoFuncion = campo;
			// Almacenamos valores inputs
			getline(ssInputs, campo, delimitador);
			input = std::stof(campo);
			// Funciones de membresia
			getline(ss, campo, delimitador);
			//cout << campo << endl;
			membresia = stringstream(campo);

			// Almacenamos los valores de la función de membresia
			getline(membresia, campo, ':');
			a = std::stof(campo);
			getline(membresia, campo, ':');
			b = std::stof(campo);
			getline(membresia, campo, ':');
			c = std::stof(campo);
			getline(membresia, campo, ':');
			d = std::stof(campo);

			// Valores de lista atributos
			//cout << a << b << c << d << endl;
			// Valores de lista atributos
			if (tipoFuncion == "TrapezoidalI") {
				atributo = funcionTrapezoidalABInfinitoNegativo(input, c, d);
			}
			else if (tipoFuncion == "TrapezoidalD") {
				atributo = funcionTrapezoidalCDInfinitoPositivo(input, a, b);
			}
			else if (tipoFuncion == "Trapezoidal") {
				atributo = funcionTrapezoidal(input, a, b, c, d);
			}
			else if (tipoFuncion == "Triangular") {
				atributo = funcionTriangular(input, a, b, c);
			}

			// Valores de lista lambda
			getline(ss, campo, delimitador);
			lambda = std::stof(campo);

			//cout << "Valor Atributo:" <<atributo <<  endl;
			sistema.listaAtributos.push_back(atributo);
			sistema.listaLamdas.push_back(lambda);


		}
		listaSistemas.push_back(sistema);
		
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
	getline(ss, campo, delimitador);
	int numeroNiveles = std::stoi(campo);

	//Saltamos Linea
	getline(fichero, linea);


	//Por cada nivel , rescatamos su matriz de incidencia
	int tamanoMatriz;
	string nombreArchivo;
	float** matrizExperto;
	ifstream ficheroMatriz;
	for (int n=0 ; n< numeroNiveles ; n++)
	{
		//obtenemos el Tamaño de la matriz de incidencia del nivel n y el nombre del archivo que la contiene
		getline(fichero, linea);
		ss = stringstream(linea);
		getline(ss, campo, delimitador);
		tamanoMatriz = std::stoi(campo);//tamano
		getline(ss, campo, delimitador);
		nombreArchivo = campo;// nombre archivo

		ficheroMatriz=ifstream("datos/"+nombreArchivo);


		//Abrimos la matriz
		cout << tamanoMatriz<<" "<< nombreArchivo<<endl;
		if (!ficheroMatriz)
		{
			cout << "Archivo : "<< nombreArchivo <<" no encontrado,ERROR";
			exit(1); // terminate si no se encuentra el archivo
		}

		//creamos una matriz
		matrizExperto = new float* [tamanoMatriz];
		//Rescatamos la matriz de incidencia
		for (int i = 0; i < tamanoMatriz; i++)
		{
			matrizExperto[i] = new float[tamanoMatriz];

			getline(ficheroMatriz, linea);
			cout << linea << endl;
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
	niveles[niveles.size()-1].listaSistemas=leerSistemaUltimoNivel();
	return niveles;
}

void generarInforme(vector<Nivel >niveles,float desvio) 
{
	ofstream archivo;
	archivo.open("datos/reporte.csv");
	archivo<< "Factore de desvio: "<<";"<<desvio<<"%\n";
	archivo << "Nombre del sistemas;Estado del sistema;Factor Atributos;Factor Arcos\n";
	for (int i = 0;i<niveles.size();i++) {
		for (int j = 0; j < niveles[i].listaSistemas.size(); j++) 
		{
			archivo << niveles[i].listaSistemas[j].nombreSistema << ";" << niveles[i].listaSistemas[j].factorTotal << ";" <<
				niveles[i].listaSistemas[j].factorAtributos << ";" << niveles[i].listaSistemas[j].factorArcos << "\n";
		}

	}
}
