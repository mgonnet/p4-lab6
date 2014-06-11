/*
 * DTReprEstandarizada.cpp
 *
 *  Created on: 11/06/2014
 *      Author: matias
 */

#include "../../headers/dataTypes/DTReprEstandarizada.h"
#include "../../headers/dataTypes/DTProblemaSalud.h"

DTReprEstandarizada::DTReprEstandarizada(string codigoCPS,string nombre,set<DTProblemaSalud> problemasSalud):
	codigoCPS(codigoCPS),
	nombre(nombre),
	problemasSalud(problemasSalud) { }


const string& DTReprEstandarizada::getCodigoCps() const {
	return codigoCPS;
}

const string& DTReprEstandarizada::getNombre() const {
	return nombre;
}

const set<DTProblemaSalud>& DTReprEstandarizada::getProblemasSalud() const {
	return problemasSalud;
}
