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
	string nombrePadre;
	float miPonderacionAlPadre;

public:
	Sistema(float ponderacionFactorAtributos, float ponderacionFactorArcos, string name, string p)
	{
		nombreSistema = name;
		factorArcos = 0;
		factorAtributos = 0;
		factorTotal = 0;
		nombrePadre = p;
		ponderacionFactorTotal[0] = ponderacionFactorAtributos;
		ponderacionFactorTotal[1] = ponderacionFactorArcos;

	}

	Sistema(float ponderacionFactorAtributos, float ponderacionFactorArcos, float mp, string name, string p)
	{
		miPonderacionAlPadre = mp;
		nombreSistema = name;
		factorArcos = 0;
		factorAtributos = 0;
		factorTotal = 0;
		nombrePadre = p;
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
		if (pendiente == 0) {
			this->factorArcos = 0;
		}
		else {
			this->factorArcos = influencia * (1 / pendiente);
		}
			
		
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



	float calcularFactorTotal()
	{
		factorTotal = ponderacionFactorTotal[0] * factorAtributos + ponderacionFactorTotal[1] * factorArcos;
		/*cout << nombreSistema << endl;
		cout << factorAtributos << " - " << factorArcos<< endl;
		cout << factorTotal<<endl;
		getchar();*/
		return factorTotal;
	}
};