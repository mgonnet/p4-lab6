/*
 * ParametroCriterio2.cpp
 *
 *  Created on: 21/06/2014
 *      Author: macaco
 */

#include "../../headers/dataTypes/FechaHora.h"
#include "../../headers/clases/ParametroCriterio2.h"

ParametroCriterio2::ParametroCriterio2(Fecha fecha,Hora hora,string ciPaciente):
	fecha(fecha),
	hora(hora),
	ciPaciente(ciPaciente) { }

const string& ParametroCriterio2::getCIPaciente() const {
	return ciPaciente;
}

const Fecha& ParametroCriterio2::getFecha() const {
	return fecha;
}

const Hora& ParametroCriterio2::getHora() const {
	return hora;
}

void ParametroCriterio1::dummy() { }


