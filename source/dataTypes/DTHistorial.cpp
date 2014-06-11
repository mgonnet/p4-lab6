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
