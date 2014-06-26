/*
 * DTHistorial.cpp
 *
 *  Created on: 11/06/2014
 *      Author: matias
 */

#include "../../headers/dataTypes/DTHistorial.h"

DTHistorial::DTHistorial(DTSocio socio, set<DTConsulta> consultas):
socio(socio),
consultas(consultas) { }

const set<DTConsulta>& DTHistorial::getConsultas() const {
	return consultas;
}

const DTSocio& DTHistorial::getSocio() const {
	return socio;
}

std::ostream &operator<<( std::ostream &stream,DTHistorial imprimible) {
	stream << "Datos del Socio: " << endl << imprimible.getSocio()
		<< "Datos de las consultas: " << endl;
	set<DTConsulta>::iterator it;
	set<DTConsulta> consultas = imprimible.getConsultas();
	for (it = consultas.begin(); it != consultas.end(); ++it) {
		stream << (*it);
	}
	return (stream);
}
