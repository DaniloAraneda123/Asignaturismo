#pragma once
#include "Sistema.h"
#include "Nivel.h"
#include <vector>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void revizarLvlFactorArcos(Nivel nivel)
{
	for (int i = 0; i < nivel.listaSistemas.size(); i++)
	{															//Vamos por todos los nodos o sistema de este nivel calculando FA
		nivel.listaSistemas[i].calcularFactorArcos(nivel.valorExperto, nivel.influenciaTotal, i, nivel.matrizTamano);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void revizarLvlFactorTotal(Nivel nivel, int i)
{
	bool ultimoNivel = false;
	if (i == 0)
	{
		ultimoNivel = true;
	}
	for (int i = 0; i < nivel.listaSistemas.size(); i++)
	{															//Vamos por todos los nodos o sistema de este nivel calculando FA
		nivel.listaSistemas[i].calcularFactorTotal(ultimoNivel);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

float calcularFactorDesvio(Nivel n, vector <float> listaPonderacion)
{
	float resultado = 0;
	for (int i = 0; i < listaPonderacion.size(); i++)
	{
		resultado = resultado + listaPonderacion[i] * n.listaSistemas[i].factorTotal;
	}
	return resultado;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void revizarLvlFactorAtributos(Nivel nivel)
{
	for (int i = 0; i < nivel.listaSistemas.size(); i++)											//Vamos por todos los sistemas de este nivel calculando los factores de  atributos
	{
		nivel.listaSistemas[i].calcularFactorAtributos();
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

float algoritmo(vector<Nivel> niveles, vector<float> listaPonderacion)
{														//Partimos del ultimo nivel del sistema calculando 
	for (int i = niveles.size() - 1; i >= 0; i--) 					//Vamos calculando desde los niveles mas bajos a los mas altos
	{
		cout << i<<"\n";
		revizarLvlFactorAtributos(niveles[i]);				//Partimos calculando el FN primero
		niveles[i].actualizarMatrizIncidencia();	//Una vez calculado el Fn de cada nodo en ese subsistema, hay que actualizar los pesos de los arcos que recodar que este se defino como Mu*Fn
		revizarLvlFactorArcos(niveles[i]);   //Promedi ponderado simple conj Fn y Fa, y la ponderancia es cunato es afecto el sistema por el exterior y que tanto define un sistema sus atributos.
		revizarLvlFactorTotal(niveles[i], i);
		imprimirNivel(niveles[i]);
	}
	return calcularFactorDesvio(niveles[0], listaPonderacion);
}
