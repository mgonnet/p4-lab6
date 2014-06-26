/*
 * DTDiagnostico.cpp
 *
 *  Created on: 10/06/2014
 *      Author: matias
 */

#include <string>
#include <set>

#include <iostream>

#include "../../headers/dataTypes/DTDiagnostico.h"

DTDiagnostico::DTDiagnostico(	string descripcion,
		string codigo,
		string etiqueta,
		set<string> tratamientos):

		descripcion(descripcion),
		codigo(codigo),
		etiqueta(etiqueta),
		tratamientos(tratamientos) { }


const string& DTDiagnostico::getCodigo() const {
	return codigo;
}

const string& DTDiagnostico::getDescripcion() const {
	return descripcion;
}

const string& DTDiagnostico::getEtiqueta() const {
	return etiqueta;
}

const set<string>& DTDiagnostico::getTratamientos() const {
	return tratamientos;
}

bool DTDiagnostico::operator<(DTDiagnostico otro) const
{
	return this->codigo < otro.getCodigo();
}

std::ostream &operator<<(std::ostream &stream,DTDiagnostico imprimible) {
	stream << "C?digo: " << imprimible.getCodigo() << endl
			<< "Etiqueta: " << imprimible.getEtiqueta() << endl
			<< "Descripci?n: " << imprimible.getDescripcion() << endl;
	set<string>::iterator it;
	set<string> tratamientos = imprimible.getTratamientos();
	for (it = tratamientos.begin(); it != tratamientos.end(); ++it) {
		stream << (*it);
	}
	return (stream);
}

