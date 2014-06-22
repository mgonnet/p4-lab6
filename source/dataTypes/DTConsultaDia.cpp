/*
 * DTConsultaDia.cpp
 *
 *  Created on: 19/06/2014
 *      Author: matias
 */

#include "../../headers/dataTypes/DTConsultaDia.h"

DTConsultaDia::DTConsultaDia(Fecha fechaConsulta, Hora horaConsulta, string ciSocio):
fechaConsulta(fechaConsulta),
horaConsulta(horaConsulta),
ciSocio(ciSocio)
{}

Fecha DTConsultaDia::getFechaConsulta() { return fechaConsulta; }
Hora DTConsultaDia::getHoraConsulta() { return horaConsulta; }
string DTConsultaDia::getCiSocio() { return ciSocio; }

