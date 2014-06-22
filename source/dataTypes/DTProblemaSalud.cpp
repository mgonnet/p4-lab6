/*
 * DTProblemaSalud.cpp
 *
 *  Created on: 11/06/2014
 *      Author: matias
 */

#include "../../headers/dataTypes/DTProblemaSalud.h"

DTProblemaSalud::DTProblemaSalud(string codigo, string etiqueta):
	codigo(codigo),
	etiqueta(etiqueta) { }


const string& DTProblemaSalud::getCodigo() const {
	return codigo;
}

const string& DTProblemaSalud::getEtiqueta() const {
	return etiqueta;
}

bool DTProblemaSalud::operator<(DTProblemaSalud otro) const
{
	return this->codigo < otro.codigo;
}
