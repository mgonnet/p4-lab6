/*
 * DTCategoriaPS.cpp
 *
 *  Created on: 10/06/2014
 *      Author: matias
 */

#include "../../headers/dataTypes/DTCategoriaPS.h"
#include <iostream>

using namespace std;

DTCategoriaPS::DTCategoriaPS(string codigoCPS, string etiqueta) :
	codigoCPS(codigoCPS),
	etiqueta(etiqueta)
{ }

//Getters
string	DTCategoriaPS::getCodigoCPS() { return this->codigoCPS; }
string	DTCategoriaPS::getEtiqueta() { return this->etiqueta; }

std::ostream &operator<<( std::ostream &stream,DTCategoriaPS imprimible)
{
	stream	<< "CodigoCPS: " << imprimible.getCodigoCPS() << endl
			<< "Etiqueta: " << imprimible.getEtiqueta() << endl;

	return (stream);
}
