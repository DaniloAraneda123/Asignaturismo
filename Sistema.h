#pragma once
#include"string"
#include<vector>


using namespace std;

class Sistema
{
public:
	string nombreSistema;
	float factorAtributos, factorArcos, factorTotal;
	vector<float> listaAtributos, listaLamdas;
	float ponderacionFactorTotal[2];
	Sistema* padre;
	float miPonderacionAlPadre;

public:
	Sistema(float ponderacionFactorAtributos, float ponderacionFactorArcos, string name, Sistema* padre)
	{
		nombreSistema = name;
		factorArcos = 0;
		factorAtributos = 0;
		factorTotal = 0;
		this->padre = padre;
		ponderacionFactorTotal[0] = ponderacionFactorAtributos;
		ponderacionFactorTotal[1] = ponderacionFactorArcos;

	}



	Sistema(float ponderacionFactorAtributos, float ponderacionFactorArcos, string name)
	{
		nombreSistema = name;
		ponderacionFactorTotal[0] = ponderacionFactorAtributos;
		ponderacionFactorTotal[1] = ponderacionFactorArcos;
	}



	void calcularFactorArcos(float** experto, float** influenciaTotal, int columna, int tamano,int nivel)
	{
		float pendiente = 0, influencia = 0;

		for (int i = 0; i < tamano; i++)
		{
			pendiente = pendiente + experto[i][columna];            						//Mu es el valor dado por el experto e influencia es la multiplicacion de Mu*Fn
			influencia = influencia + influenciaTotal[i][columna];
		}
		if (nivel!=1)
		{
			this->factorArcos = influencia * (1 / pendiente);
		}
		//cout << "Factor Arcos: " << factorArcos << "  " << endl;
	}


	void calcularFactorAtributos()
	{
		float sumaPonderada = 0;
		for (int i = 0; i < listaAtributos.size(); i++)
		{
			sumaPonderada = sumaPonderada + listaAtributos[i] * listaLamdas[i];
		}
		this->factorAtributos= sumaPonderada;
		//cout <<"Factor Atributos: " <<factorAtributos << "  "<<endl;
	}



	void calcularFactorTotal(bool ultimoNivel)
	{
		this->factorTotal = ponderacionFactorTotal[0] * factorAtributos + ponderacionFactorTotal[1] * factorArcos;
		if (ultimoNivel != true)
		{
			padre->listaAtributos.push_back(factorTotal);
			padre->listaLamdas.push_back(miPonderacionAlPadre);
		}
	}
};