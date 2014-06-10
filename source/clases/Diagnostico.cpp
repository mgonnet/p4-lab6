/*
 * Diagnostico.cpp
 *
 *  Created on: 03/05/2014
 *      Author: matias
 */

#include "../headers/Diagnostico.h"

//Creadoras
Diagnostico::Diagnostico(string descripcion): descripcion(descripcion) { }

//Getters
string	Diagnostico::getDescripcion() { return descripcion; }

//Setters
void	Diagnostico::setDescripcion() { this->descripcion=descripcion; }

