/*
 * Quirurgico.cpp
 *
 *  Created on: 10/05/2014
 *      Author: Emiliano
 */

#include "../../headers/dataTypes/FechaHora.h"
#include "../../headers/clases/Quirurgico.h"
#include "../../headers/clases/Diagnostico.h"

Quirurgico::Quirurgico(string descripcion, Fecha fecha, Diagnostico* diag): Tratamiento(descripcion) { }

//Getters
Fecha Quirurgico::getFecha() { return this->fecha; }

//Setters
void Quirurgico::setFecha(Fecha fecha) { this->fecha = fecha; }

//Destructor
Quirurgico::~Quirurgico() { }



