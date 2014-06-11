/*
 * DTReservaA.cpp
 *
 *  Created on: 11/06/2014
 *      Author: matias
 */

#include "../../headers/dataTypes/DTReservaA.h"

DTReservaA::DTReservaA(Fecha fechaC,Hora horaC,Fecha fechaR):
	fechaC(fechaC),
	horaC(horaC),
	fechaR(fechaR) { }

const Fecha& DTReservaA::getFechaC() const {
	return fechaC;
}

const Fecha& DTReservaA::getFechaR() const {
	return fechaR;
}

const Hora& DTReservaA::getHoraC() const {
	return horaC;
}
