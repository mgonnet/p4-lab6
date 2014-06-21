/*
 * DTMedico.cpp
 *
 *  Created on: 11/06/2014
 *      Author: matias
 */

#include "../../headers/dataTypes/DTMedico.h"
#include <iostream>

using namespace std;

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


std::ostream &operator<<( std::ostream &stream,DTMedico imprimible)
{
	stream	<< "Nombre: " << imprimible.getNombre() << endl
			<< "Apellido: " << imprimible.getApellido() << endl
			<< "CI: " << imprimible.getCi() << endl;
	return (stream);
}
