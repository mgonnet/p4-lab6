/*
 * DTUsuarioAR.cpp
 *
 *  Created on: 20/06/2014
 *      Author: matias
 */

#include "../../headers/dataTypes/DTUsuarioAR.h"

bool DTUsuarioAR::isActivo() const {
	return activo;
}

const string& DTUsuarioAR::getApellido() const {
	return apellido;
}

const string& DTUsuarioAR::getCi() const {
	return ci;
}

int DTUsuarioAR::getEdad() const {
	return edad;
}

const string& DTUsuarioAR::getNombre() const {
	return nombre;
}

const set<DTLineaRegistro>& DTUsuarioAR::getRegistros() const {
	return registros;
}
