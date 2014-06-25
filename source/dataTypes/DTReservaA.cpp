/*
 * DTReservaA.cpp
 *
 *  Created on: 11/06/2014
 *      Author: matias
 */

#include "../../headers/dataTypes/DTReservaA.h"

DTReservaA::DTReservaA(int codigoC,Fecha fechaC,Hora horaC,Fecha fechaR, DTMedico dtMed):
	codigoC(codigoC),
	fechaC(fechaC),
	horaC(horaC),
	fechaR(fechaR),
	dtMed(dtMed)
	{ }

Fecha DTReservaA::getFechaC(){
	return fechaC;
}

int DTReservaA::getCodigoC(){
	return codigoC;
}

Fecha DTReservaA::getFechaR(){
	return fechaR;
}

Hora DTReservaA::getHoraC(){
	return horaC;
}

DTMedico DTReservaA::getDTMedico(){
	return dtMed;
}

bool DTReservaA::operator<(DTReservaA otro) const
{
	return this->codigoC < otro.codigoC;
}

std::ostream &operator<<( std::ostream &stream,DTReservaA imprimible)
{
	stream	<< "El Codigo es: " << imprimible.getCodigoC() << endl
			<< "El Medico es: " << imprimible.getDTMedico() << endl
			<< "La Fecha es: " << imprimible.getFechaC() << endl
			<< "La Hora es: " << imprimible.getHoraC() << endl
			<< "La Fecha Reserva es: " << imprimible.getFechaR() << endl;
	return (stream);
}
