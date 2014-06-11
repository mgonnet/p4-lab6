/*
 * DTMedicamento.cpp
 *
 *  Created on: 11/06/2014
 *      Author: matias
 */

#include "../../headers/dataTypes/DTMedicamento.h"

DTMedicamento::DTMedicamento(string nombre):nombre(nombre) { }

const string& DTMedicamento::getNombre() const {
	return nombre;
}
