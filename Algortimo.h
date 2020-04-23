#pragma once
#include "Sistema.h"
#include "Nivel.h"
#include <vector>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void revizarLvlFactorArcos(Nivel *nivel,int n)
{
	for (int i = 0; i < nivel->listaSistemas.size(); i++)
	{															//Vamos por todos los nodos o sistema de este nivel calculando FA
		nivel->listaSistemas[i].calcularFactorArcos(nivel->valorExperto, nivel->influenciaTotal, i, nivel->matrizTamano,n);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void revizarLvlFactorTotal(vector<Nivel> *niveles, int nivel)
{
	float resultado = 0;
	float miPonderacion = 0;
	if (nivel==0)
	{
		for (int i = 0 ; i< (*niveles)[nivel].listaSistemas.size() ; i++)
		{
			(*niveles)[nivel].listaSistemas[i].calcularFactorTotal();
		}
	}
	else
	{
		for (int i = 0; i < (*niveles)[nivel].listaSistemas.size(); i++)
		{
			resultado=(*niveles)[nivel].listaSistemas[i].calcularFactorTotal();
			miPonderacion= (*niveles)[nivel].listaSistemas[i].miPonderacionAlPadre;
			for (int j=0 ; j < (*niveles)[nivel - 1].listaSistemas.size(); j++ )
			{
				if ((*niveles)[nivel - 1].listaSistemas[j].nombreSistema == (*niveles)[nivel].listaSistemas[i].nombrePadre)
				{
					(*niveles)[nivel - 1].listaSistemas[j].listaAtributos.push_back(resultado);
					(*niveles)[nivel - 1].listaSistemas[j].listaLamdas.push_back(miPonderacion);
				}
			}
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

float calcularFactorDesvio(Nivel* n, vector <float> listaPonderacion)
{
	float resultado = 0;
	for (int i = 0; i < listaPonderacion.size(); i++)
	{
		resultado = resultado + listaPonderacion[i] * n->listaSistemas[i].factorTotal;
	}
	return resultado;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void revizarLvlFactorAtributos(Nivel *nivel)
{
	for (int i = 0; i < nivel->listaSistemas.size(); i++)											//Vamos por todos los sistemas de este nivel calculando los factores de  atributos
	{
		nivel->listaSistemas[i].calcularFactorAtributos();
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*
Procedimiento principal, este es el que hecha el algoritmo a correr y calcular todo lo que se requirere
INPUT:
niveles:			Contine todos los nivel del sistema
listaPonderacion:	contiene la ponderacion de los sistemas del nivel 1
*/
float algoritmo(vector<Nivel> niveles, vector<float> listaPonderacion)
{														//Partimos del ultimo nivel del sistema calculando 
	for (int i = niveles.size() - 1; i >= 0; i--) 					//Vamos calculando desde los niveles mas bajos a los mas altos
	{

		//cout <<endl<< "Estoy en el nivel: " << i<<endl;

		revizarLvlFactorAtributos(&niveles[i]);//Partimos calculando el FN primero

		/*cout <<endl<< "Factor Atributos "<< endl;
		for (int j = 0; j < niveles[i].listaSistemas.size(); j++)											//Vamos por todos los sistemas de este nivel calculando los factores de  atributos
		{
			cout<< "  "<< niveles[i].listaSistemas[j].factorAtributos<<endl;
		}*/

		niveles[i].actualizarMatrizIncidencia();//Una vez calculado el Fn de cada nodo en ese subsistema, hay que actualizar los pesos de los arcos que recodar que este se defino como Mu*Fn

		// Imprimir matriz expertos
		//cout << endl << " Matriz experto " <<endl;
		//imprimirMatriz(niveles[i].valorExperto, niveles[i].listaSistemas.size());

		//cout <<endl<< " Matriz Total " << endl;
		//Imprimir matriz Total
		//imprimirMatriz(niveles[i].influenciaTotal, niveles[i].listaSistemas.size());

		revizarLvlFactorArcos(&niveles[i],i);//Promedi ponderado simple conj Fn y Fa, y la ponderancia es cunato es afecto el sistema por el exterior y que tanto define un sistema sus atributos.

		/*cout << endl << "Factor Arcos " << endl;
		for (int j = 0; j < niveles[i].listaSistemas.size(); j++)											//Vamos por todos los sistemas de este nivel calculando los factores de  atributos
		{
			cout << "  " << niveles[i].listaSistemas[j].factorArcos << endl;
		}*/

		revizarLvlFactorTotal(&niveles, i);
		//imprimirNivel(niveles[i]);
	}
	return calcularFactorDesvio(&niveles[0], listaPonderacion);
}
