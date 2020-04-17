#pragma once
#include"Sistema.h";

//////////////////////////////////////////////////////////////////////////////////////////////

class <Sistema> lista 
{

};



//////////////////////////////////////////////////////////////////////////////////////////////

Lista* crear_lista()
{
	Lista* aux;
	aux->ultimo = aux->primero = NULL;
	aux->longitud = 0;
	return(aux);
}

//////////////////////////////////////////////////////////////////////////////////////////////

void agregar_elemento(Lista* lista, Nodo* aux)
{
	if (lista == NULL)
	{
		printf("lista no existe");
		return;
	}
	if (lista->primero == NULL)
	{
		lista->primero = lista->ultimo = aux;
		lista->longitud++;
	}
	else
	{
		aux->siguiente = lista->primero;
		lista->primero = aux;
		lista->longitud++;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////

void agregar_elemento_final(Lista* lista, Nodo* aux)
{
	if (lista == NULL)
	{
		printf("lista no existe");
		return;
	}
	if (lista->ultimo == NULL)
	{
		lista->primero = lista->ultimo = aux;
		lista->longitud++;
	}
	else
	{
		aux->anterior = lista->ultimo;
		lista->ultimo = aux;
		lista->longitud++;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////
Nodo* eliminar_elemento_principio(Lista* lista)
{
	if (lista == NULL)
	{
		printf("lista no existe");
		return;
	}
	Nodo* aux;
	if (lista->longitud == 1)
	{
		aux = lista->primero;
		lista->primero = lista->ultimo = NULL;
		lista->longitud = 0;
	}
	else
	{
		aux = lista->primero;
		lista->primero = (lista->primero)->siguiente;
		lista->longitud = lista->longitud - 1;
	}
	return(aux);
}
//////////////////////////////////////////////////////////////////////////
void eliminar_elemento_final(Lista* lista)
{
	if (lista == NULL)
	{
		printf("lista no existe");
		return;
	}
	if (lista->longitud == 1)
	{
		free(lista->primero);
		lista->primero = lista->ultimo = NULL;
		lista->longitud = 0;
	}
	else
	{
		Nodo* aux;
		aux = lista->ultimo;
		lista->ultimo = (lista->ultimo)->anterior;
		free(aux);
		lista->longitud = lista->longitud - 1;
	}
}
