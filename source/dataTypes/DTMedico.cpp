/*
 * DTMedico.cpp
 *
 *  Created on: 11/06/2014
 *      Author: matias
 */

#include "../../headers/dataTypes/DTMedico.h"

DTMedico::DTMedico(string nombre, string apellido, string ci):
	nombre(nombre),
	apellido(apellido),
	ci(ci) { }

const string& DTMedico::getApellido() const {
	return apellido;
}

const string& DTMedico::getCi() const {
	return ci;
}

const string& DTMedico::getNombre() const {
	return nombre;
}
