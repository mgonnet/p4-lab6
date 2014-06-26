/*
 * DTMensaje.cpp
 *
 *  Created on: 26/06/2014
 *      Author: matias
 */

#include "../../headers/dataTypes/DTMensaje.h"

DTMensaje::DTMensaje(string ciSocio,string ciMedicoIntruso,Fecha fecha,bool nuevosDiagnosticos, bool leido):
	ciSocio(ciSocio),
	ciMedicoIntruso(ciMedicoIntruso),
	fecha(fecha),
	nuevosDiagnosticos(nuevosDiagnosticos),
	leido(leido)
{}

string DTMensaje::getCiMedicoIntruso() const {
	return ciMedicoIntruso;
}

string DTMensaje::getCiSocio() const {
	return ciSocio;
}

const Fecha& DTMensaje::getFecha() const {
	return fecha;
}

bool DTMensaje::isLeido() const {
	return leido;
}

bool DTMensaje::isNuevosDiagnosticos() const {
	return nuevosDiagnosticos;
}

bool DTMensaje::operator<(DTMensaje otro) const
{
	return ( fecha.esMenorQue(otro.getFecha()));
}

std::ostream &operator<<( std::ostream &stream,DTMensaje imprimible)
{
	if ( !imprimible.isLeido() ) stream << "NEW!!" << endl;
	stream	<< "El socio : " << imprimible.getCiSocio() << " fue atendido por el medico " << imprimible.getCiMedicoIntruso() << " el dia " << imprimible.getFecha() << endl;
	if ( imprimible.isNuevosDiagnosticos() ) stream << "Se realizaron nuevos diagnosticos" << endl;
	else stream << "No se realizaron nuevos diagnosticos" << endl;
	return (stream);
}
