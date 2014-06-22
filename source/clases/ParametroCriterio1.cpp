/*
 * ParametroCriterio1.cpp
 *
 *  Created on: 21/06/2014
 *      Author: macaco
 */

#include "../../headers/dataTypes/FechaHora.h"
#include "../../headers/clases/ParametroCriterio1.h"

ParametroCriterio1::ParametroCriterio1(Fecha fecha,Hora hora,int x):
	fecha(fecha),
	hora(hora),
	x(x) { }

const int& ParametroCriterio1::getX() const {
	return x;
}

const Fecha& ParametroCriterio1::getFecha() const {
	return fecha;
}

const Hora& ParametroCriterio1::getHora() const {
	return hora;
}

void ParametroCriterio1::dummy() { }
