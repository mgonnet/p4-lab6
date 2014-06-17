/*
 * Mensaje.cpp
 *
 *  Created on: 11/06/2014
 *      Author: matias
 */

#include "../../headers/clases/Mensaje.h"
#include "../../headers/dataTypes/FechaHora.h"

Mensaje::Mensaje(string ciSocio,string ciMedicoIntruso,Fecha fecha,bool nuevosDiagnosticos):
	ciSocio(ciSocio),
	ciMedicoIntruso(ciMedicoIntruso),
	fecha(fecha),
	nuevosDiagnosticos(nuevosDiagnosticos) { }

const string& Mensaje::getCiMedicoIntruso() const {
	return ciMedicoIntruso;
}

const string& Mensaje::getCiSocio() const {
	return ciSocio;
}

Fecha Mensaje::getFecha(){
	return fecha;
}

bool Mensaje::isNuevosDiagnosticos() const {
	return nuevosDiagnosticos;
}

bool Mensaje::isLeido() { return leido; }


void Mensaje::marcarComoLeido() { leido=true; }

Mensaje::~Mensaje()
{
}


