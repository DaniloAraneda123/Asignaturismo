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
};

void imprimirMatriz(float** n, int tamano)
{
	cout << "Tamaño Matriz = " << tamano << endl;
	for (int i = 0; i < tamano; i++)
	{
		for (int j = 0; j < tamano; j++)
		{
			cout << n[i][j] << "  ";
		}
		cout << "\n";
	}
}




void imprimirNivel(Nivel n)
{
	for (int i = 0; i < n.matrizTamano; i++)
	{
		cout << "Nombre del Sistema: " << n.listaSistemas[i].nombreSistema << "  FT: " << n.listaSistemas[i].factorTotal
			<< "  FA: " << n.listaSistemas[i].factorArcos << "  FN: " << n.listaSistemas[i].factorAtributos << endl;
		cout << "Lista Atributos: ";
		for (int j=0 ; j< n.listaSistemas[i].listaAtributos.size() ; j++)
		{
			cout <<n.listaSistemas[i].listaAtributos[j]<<"*"<< n.listaSistemas[i].listaLamdas[j]<<"  -  ";
		}
		cout << endl;
	}
	imprimirMatriz(n.valorExperto, n.matrizTamano);
}