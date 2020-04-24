#include<iostream>
#include "Sistema.h"
#include "Nivel.h"
#include <vector>
#include "Algortimo.h"

using namespace std;

int main()
{
	vector<Sistema> niveles = leerdatos();
	vector<float> listaPonderacion;
	algoritmo(niveles, listaPonderacion);

	return 0;
}