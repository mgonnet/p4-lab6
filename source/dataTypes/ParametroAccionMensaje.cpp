/*
 * ParametroAccionMensaje.cpp
 *
 *  Created on: 11/06/2014
 *      Author: matias
 */

#include "../../headers/dataTypes/FechaHora.h"
#include "../../headers/dataTypes/ParametroAccionMensaje.h"

ParametroAccionMensaje::ParametroAccionMensaje(bool nuevosDiagnosticos,Fecha fecha, string ciSocio, string ciMedicoIntruso):
	nuevosDiagnosticos(nuevosDiagnosticos),
	fecha(fecha),
	ciSocio(ciSocio),
	ciMedicoIntruso(ciMedicoIntruso) { }

const string& ParametroAccionMensaje::getCiMedicoIntruso() const {
	return ciMedicoIntruso;
}

const string& ParametroAccionMensaje::getCiSocio() const {
	return ciSocio;
}

const Fecha& ParametroAccionMensaje::getFecha() const {
	return fecha;
}

bool ParametroAccionMensaje::isNuevosDiagnosticos() const {
	return nuevosDiagnosticos;
}

void ParametroAccionMensaje::dummy() { }
