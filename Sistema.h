#pragma once
#include"listaGenerica.h";

using namespace std;

class Sistema
{
	public : 
		string nombreSistema;
		float factorAtributos,factorArcos,factorTotal;
		Lista<float> listaAtributos, listaLamdas;
		float ponderacionFactorTotal[2];

	public:
		Sistema(float ponderacionFactorAtributos, float ponderacionFactorArcos, Lista<float> listaA, Lista<float> listaL,string name) 
		{
			nombreSistema = name;
			factorArcos = 0;
			factorAtributos = 0;
			factorTotal = 0;
			listaAtributos = listaA;
			listaLamdas = listaL;
			ponderacionFactorTotal[0] = ponderacionFactorAtributos;
			ponderacionFactorTotal[1] = ponderacionFactorArcos;

		 }

		void calcularFactorArcos(MatrizIncidencia M)
		{

		}

		void calcularFactorAtributos()
		{
			float sumaPonderada=0,atributo,lamda;
			for (int i=0 ; i<listaAtributos.longitud ; i++)
			{
				sumaPonderada = sumaPonderada + listaAtributos.get(i)*listaLamdas.get(i);
			}
		}

		void calcularFactorTotal() 
		{
			factorTotal = ponderacionFactorTotal[0] * factorAtributos + ponderacionFactorTotal[1] * factorArcos;
		}

};

