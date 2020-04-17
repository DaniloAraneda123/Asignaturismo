#pragma once
#define NULL 0
#include<iostream>

template<class TIPOD>
class Nodo
{
	public:

		TIPOD objeto;
		Nodo<TIPOD>* siguiente, *anterior;

	public:

		Nodo(TIPOD o)
		{
			objeto = o;
			siguiente = anterior = NULL;
		}

		TIPOD getObjeto()
		{
			return objeto;
		}

};

template<class TIPOD>
class Lista
{
public:
	int longitud;
	Nodo<TIPOD> *primero;
	Nodo<TIPOD> *ultimo;
	//////////////////////////////////////////////////////////////////////////////////////////////
public:

	Lista()
	{
		longitud = 0;
		primero = NULL;
		ultimo = NULL;
	}

	//////////////////////////////////////////////////////////////////////////////////////////////

	void add(TIPOD dato)
	{
		Nodo<TIPOD>* aux = new Nodo<int>(dato);
		if (primero == NULL)
		{
			primero = aux;
			ultimo = aux;
		}
		else
		{
			aux->siguiente = primero;
			primero->anterior = aux;
			primero = aux;
		}
		longitud++;
	}

	//////////////////////////////////////////////////////////////////////////////////////////////

	TIPOD get(int numero)
	{
		if (numero >=longitud || numero<0)
		{
			return NULL;
		}
		Nodo<TIPOD>* aux = primero;
		for (int i=0;i < numero; i++)
		{
			aux = aux->siguiente;
		}
		return aux->getObjeto();
	}
};
