#pragma once

float funcionMembresia(float valorEvaluado, float a, float b, float c, float d)
{
	float resultado = 0;

	if (valorEvaluado <= a || valorEvaluado > d)
	{
		resultado = 0;
	}

	else if (valorEvaluado > a && valorEvaluado <= b) {
		resultado = ((valorEvaluado - a) / (b - a));
	}

	else if (valorEvaluado > b && valorEvaluado <= c) {
		resultado = 1;
	}

	else if (valorEvaluado > c && valorEvaluado <= d) {
		resultado = ((d - valorEvaluado) / (d - c));
	}

	return resultado;
}


float funcionMembresia(float valorEvaluado,float a, float b, float c)
{
	float resultado = 0;

	if (valorEvaluado <= a || valorEvaluado > c ){
		resultado = 0;
	}

	else if ( valorEvaluado > a && valorEvaluado <= b) {
		resultado = ((valorEvaluado-a)/(b-a));
	}

	else if (valorEvaluado > b && valorEvaluado <= c) {
		resultado = ((c - valorEvaluado) / (c - b));
	}

	return resultado;
}