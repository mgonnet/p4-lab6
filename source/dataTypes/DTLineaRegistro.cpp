/*
 * DTLineaRegistro.cpp
 *
 *  Created on: 20/06/2014
 *      Author: matias
 */

#include "../../headers/dataTypes/DTLineaRegistro.h"

const Fecha& DTLineaRegistro::getFecha() const {
	return fecha;
}

TipoOper DTLineaRegistro::getTipoOper() const {
	return tipoOper;
}
