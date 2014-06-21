/*
 * Diagnostico.cpp
 *
 *  Created on: 03/05/2014
 *      Author: matias
 */

#include "../../headers/clases/Diagnostico.h"

//Creadoras
Diagnostico::Diagnostico(string descripcion,  set<DTTratamiento> datosTratamientos): descripcion(descripcion) { }

//Getters
string	Diagnostico::getDescripcion() { return descripcion; }

//Setters
void	Diagnostico::setDescripcion() { this->descripcion=descripcion; }

//Negocio
DTDiagnostico	Diagnostico::getHistorial(){


}
