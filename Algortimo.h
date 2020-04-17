#pragma once
#include "listaGenerica.h"
#include "Sistema.h"
#include "Nivel.h"

using namespace std;

float DFCDS(Nivel niveles[], int L)
{
	int i = L;									//Partimos del ultimo nivel del sistema calculando 
	for (i = L; i >= 1; i--) 					//Vamos calculando desde los niveles mas bajos a los mas altos
	{
		revizarLvlFactorAtributos(niveles[i]);				//Partimos calculando el FN primero
		niveles[i].actualizarMatrizIncidencia();	//Una vez calculado el Fn de cada nodo en ese subsistema, hay que actualizar los pesos de los arcos que recodar que este se defino como Mu*Fn
		revizarLvlFactorArcos(niveles[i]);
		calcularFt(LNlvl[i]);   //Promedi ponderado simple conj Fn y Fa, y la ponderancia es cunato es afecto el sistema por el exterior y que tanto define un sistema sus atributos.
	}
	return calcularFactorDesvio();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void revizarLvlFactorAtributos(Nivel nivel)
{
	for (int i = 0 ; i < nivel.listaSistemas.size(); i++)											//Vamos por todos los sistemas de este nivel calculando los factores de lso atributos
	{
		nivel.getSistema(i).calcularFactorAtributos();
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void revizarLvl_Fa(Lista listaNodos, Matriz matrizIncidencia)
{
	for (int i = 0, i < listaNodos.TamanoLista, i++)											//Vamos por todos los nodos de este sistema calculando el Fa
	{
		calcularFa(listaNodos[i], i, matrizIncidencia);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CalcularFa(Nodo Ni, int columna, Matriz matrizIncidencia)
{
	float pendiente = 0, influencia = 0;

	for (int i = 0, i < matrizIncidencia.matrizTamano, i++)
	{
		pendiente = pendiente + matrizIncidencia[i, columna].Mu;            		//Mu es el valor dado por el experto e influencia es la multiplicacion de Mu*Fn
		influencia = influencia + matrizIncidencia[i, columna].influencia;
	}
	Ni.Fa = influencia * (1 / pendiente);											//Es es como una funcion de membresia, y se asigne la lineal ya que  permite que los valores no se distorcionen y asi aportan mas en terminos de influencia
}																			//aquellos arcos en donde el experto haya determinado un Mu mas alto.
																			//Lo hice con esta funcion de membresia lineal ya que me di cuenta que en caso de tener los sistemas perfecto en cuanto atributo, tambien se loggrareia una
																			//influencia completa.
////////////////////////////////////////////////////////////////////////////////////////////////////////////

float calcularFactorDesvio()
{

}
