/*
 * ProblemaSalud.cpp
 *
 *  Created on: 03/05/2014
 *      Author: matias
 */

#include "../../headers/clases/ProblemaSalud.h"

//Creadores
ProblemaSalud::ProblemaSalud(string codigoPS,string etiqueta): codigoPS(codigoPS), etiqueta(etiqueta) { }

//Getters
string	ProblemaSalud::getCodigoPS() { return codigoPS; }
string	ProblemaSalud::getEtiqueta() { return etiqueta; }
CategoriaPS * ProblemaSalud::getCategoriaPS()
{
	return categoriaPS;
}

//Setters
void	ProblemaSalud::setCodigoPS(string codigoPS) { this->codigoPS=codigoPS; }
void	ProblemaSalud::setEtiqueta(string etiqueta) { this->etiqueta=etiqueta; }
void    ProblemaSalud::setCategoriaPS(CategoriaPS* categoriaPS) { this->categoriaPS = categoriaPS;}

DTProblemaSalud ProblemaSalud::obtenerDTProblemaSalud() {
	string codPS = codigoPS;
	string etiq = etiqueta;
	DTProblemaSalud probSal = DTProblemaSalud(codPS,etiq);
	return probSal;
}
