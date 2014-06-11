/*
 * DTCategoriaPS.cpp
 *
 *  Created on: 10/06/2014
 *      Author: matias
 */

#include "../../headers/dataTypes/DTCategoriaPS.h"

DTCategoriaPS::DTCategoriaPS(string codigoCPS, string etiqueta) :
	codigoCPS(codigoCPS),
	etiqueta(etiqueta)
{ }

//Getters
string	DTCategoriaPS::getCodigoCPS() { return this->codigoCPS; }
string	DTCategoriaPS::getEtiqueta() { return this->etiqueta; }


