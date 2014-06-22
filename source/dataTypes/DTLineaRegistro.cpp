/*
 * DTLineaRegistro.cpp
 *
 *  Created on: 20/06/2014
 *      Author: matias
 */

#include "../../headers/dataTypes/DTLineaRegistro.h"

DTLineaRegistro::DTLineaRegistro(Fecha fecha,TipoOper tipoOper):fecha(fecha), tipoOper(tipoOper) {}

const Fecha& DTLineaRegistro::getFecha() const {
	return fecha;
}

TipoOper DTLineaRegistro::getTipoOper() const {
	return tipoOper;
}

