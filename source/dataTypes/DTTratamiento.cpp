/*
 * DTTratamiento.cpp
 *
 *  Created on: 11/06/2014
 *      Author: matias
 */

#include "../../headers/dataTypes/DTTratamiento.h"

DTTratamiento::DTTratamiento(TipoTratamiento tipo, string descripcion, Fecha fecha, set<DTMedicamento> medicamentos):
	tipo(tipo),
	descripcion(descripcion),
	fecha(fecha),
	medicamentos(medicamentos) { }

const string& DTTratamiento::getDescripcion() const {
	return descripcion;
}

const Fecha& DTTratamiento::getFecha() const {
	return fecha;
}

const set<DTMedicamento>& DTTratamiento::getMedicamentos() const {
	return medicamentos;
}

TipoTratamiento DTTratamiento::getTipo() const {
	return tipo;
}
