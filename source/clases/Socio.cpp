/*
 * Socio.cpp
 *
 *  Created on: 10/05/2014
 *      Author: Emiliano
 */

#include "../../headers/clases/Socio.h"
#include "../../headers/clases/Usuario.h"

Socio::Socio(Usuario* u):
	usuario(u)
{}

string Socio::getCISocio() { return (this->usuario->getCi()); }



Socio::~Socio() {}
