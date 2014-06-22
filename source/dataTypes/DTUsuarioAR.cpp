/*
 * DTUsuarioAR.cpp
 *
 *  Created on: 20/06/2014
 *      Author: matias
 */

#include "../../headers/dataTypes/DTUsuarioAR.h"

DTUsuarioAR::DTUsuarioAR(string nombre, string apellido, string ci, int edad, bool activo, set<DTLineaRegistro*> registros):
nombre(nombre), apellido(apellido), ci(ci), edad(edad), activo(activo), registros(registros) {}

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

set<DTLineaRegistro*> DTUsuarioAR::getRegistros(){
	return registros;
}

bool DTUsuarioAR::operator<(DTUsuarioAR dtu) const {
	return(this->ci < dtu.getCi());
}

