/*
 * Tratamiento.cpp
 *
 *  Created on: 10/05/2014
 *      Author: Emiliano
 */


#include "../../headers/clases/Tratamiento.h"


Tratamiento::Tratamiento(string descripcion){
	this->descripcion = descripcion;
}

//Getters
string	Tratamiento::getDescripcion() { return this->descripcion; }

//Setters
void Tratamiento::setDescripcion(string descripcion) { this->descripcion = descripcion; }

//Destructor
Tratamiento::~Tratamiento() { }


