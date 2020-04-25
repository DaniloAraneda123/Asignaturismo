#pragma once
#include "iostream"
#include"Sistema.h"
#include<vector>


using namespace std;

class Nivel
{
public:
	float** valorExperto, ** influenciaTotal;
	vector<Sistema> listaSistemas;
	int matrizTamano;


public:
	Nivel(int tamano, float** valorExperto, vector<Sistema> list)
	{
		listaSistemas = list;
		this->valorExperto = valorExperto;
		matrizTamano = tamano;
		influenciaTotal = new float* [tamano];
		for (int i = 0; i < tamano; i++) {
			influenciaTotal[i] = new float[tamano];
			for (int j = 0; j < tamano; j++)
			{
				influenciaTotal[i][j] = 0;
			}
		}
	}
	Nivel(int tamano) // Creamos el el nivel de sistemas, donde listaS  es la entrada y M es un areglo bidimencional defloars, que contienen los valores asignados por el experto
	{
		matrizTamano = tamano;
		influenciaTotal = new float* [tamano];
		for (int i = 0; i < tamano; i++) {
			influenciaTotal[i] = new float[tamano];
			for (int j = 0; j < tamano; j++)
			{
				influenciaTotal[i][j] = 0;
			}
		}
	}

	void actualizarMatrizIncidencia()
	{
		for (int j = 0; j < listaSistemas.size(); j++)											  	//Vamos actualizando las influencias de los nodos uno a la vez.
		{
			for (int i = 0; i < listaSistemas.size(); i++)
			{
				influenciaTotal[i][j] = valorExperto[i][j] * listaSistemas[j].factorAtributos;
			}
		}
	}


	void imprimirMatrizValorExperto()
	{
		cout << "Tamanio Matriz = " << matrizTamano << endl;
		for (int i = 0; i < matrizTamano; i++)
		{
			for (int j = 0; j < matrizTamano; j++)
			{
				cout << valorExperto[i][j] << "  ";
			}
			cout << listaSistemas[i].nombreSistema;
			cout << "\n";
		}
	}

	void imprimirMatrizValorTotal()
	{
		cout << "Tamanio Matriz = " << matrizTamano << endl;
		for (int i = 0; i < matrizTamano; i++)
		{
			for (int j = 0; j < matrizTamano; j++)
			{
				cout << influenciaTotal[i][j] << "  ";
			}
			cout<<listaSistemas[i].nombreSistema;
			cout << "\n";
		}
	}

	void imprimirNivel()
	{
		for (int i = 0; i < matrizTamano; i++)
		{
			if (listaSistemas.size()>0) {
				cout << "Nombre del Sistema: " << listaSistemas[i].nombreSistema << "  FT: " << listaSistemas[i].factorTotal
					<< "  FA: " << listaSistemas[i].factorArcos << "  FN: " << listaSistemas[i].factorAtributos << endl;
				cout << "Lista Atributos: ";
				for (int j = 0; j < listaSistemas[i].listaAtributos.size(); j++)
				{
					cout << listaSistemas[i].listaAtributos[j] << "*" << listaSistemas[i].listaLamdas[j] << "  -  ";
				}
				cout << endl;
			}
		}
		imprimirMatrizValorExperto();
	}
};




