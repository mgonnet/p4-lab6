/*
 * DTDiagnosticoAlta.cpp
 *
 *  Created on: 11/06/2014
 *      Author: matias
 */

#include "../../headers/dataTypes/DTDiagnosticoAlta.h"

DTDiagnosticoAlta::DTDiagnosticoAlta(string descripcion,
									string codigo,
									string etiqueta,
									set<DTTratamiento> tratamientos):
	descripcion(descripcion),
	codigo(codigo),
	etiqueta(etiqueta),
	tratamientos(tratamientos) { }

const string& DTDiagnosticoAlta::getCodigo() const {
	return codigo;
}

const string& DTDiagnosticoAlta::getDescripcion() const {
	return descripcion;
}

const string& DTDiagnosticoAlta::getEtiqueta() const {
	return etiqueta;
}

const set<DTTratamiento>& DTDiagnosticoAlta::getTratamientos() const {
	return tratamientos;
}
