#pragma once

#include"Sistema.h"
#include"MatrizIncidencia.h"
#include "ListaGenerica.h"

struct MatrizIncidencia {
	float** valorExperto;
	float** total;
} ;

class Nivel
{
	public:
		Lista<Sistema> listaSistemas;
		MatrizIncidencia matriz;

	public:
		Nivel(Lista<Sistema> listaS, float** M)
		{
			listaSistemas = listaS;
			matriz.valorExperto = M;
			matriz.total= new float* [listaS.longitud];
			for(int i=0;i<listaS.longitud;i++){
				matriz.total[i] = new float[listaS.longitud];
			}
		}

		Sistema getSistema(int i)
		{
			return listaSistemas.get(i);
		}

		void actualizarMatrizIncidencia()
		{
			for (int j = 0; j < listaSistemas.longitud ; j++)											  	//Vamos actualizando las influencias de los nodos uno a la vez.
			{
				for (int i = 0; i < listaSistemas.longitud; i++)
				{
					matriz.total[i][j] = matriz.valorExperto[i][j] * listaSistemas.get(j).factorAtributos;
				}
			}
		}
};