/*
 * ProblemaSalud.cpp
 *
 *  Created on: 03/05/2014
 *      Author: matias
 */

#include "../../headers/clases/ProblemaSalud.h"

//Creadores
ProblemaSalud::ProblemaSalud(int codigoPS,string etiqueta): codigoPS(codigoPS), etiqueta(etiqueta) { }

//Getters
int		ProblemaSalud::getCodigoPS() { return codigoPS; }
string	ProblemaSalud::getEtiqueta() { return etiqueta; }

//Setters
void	ProblemaSalud::setCodigoPS(int codigoPS) { this->codigoPS=codigoPS; }
void	ProblemaSalud::setEtiqueta(string etiqueta) { this->etiqueta=etiqueta; }
