/*
 * RegistroAR.cpp
 *
 *  Created on: 19/06/2014
 *      Author: matias
 */

#include "../../headers/clases/RegistroAR.h"

RegistroAR::RegistroAR(Usuario* u, Administrativo* adm):
	usuario(u),
	adm(adm)
{}

void RegistroAR::addLineaRegistroAR(Fecha fecha,TipoOper tipo)
{
	LineaRegistroAR* nuevaLinea=new LineaRegistroAR(fecha,tipo);
	this->lineas.insert(nuevaLinea);
}

bool RegistroAR::usuarioIs(Usuario* u) { return this->usuario==u; }

RegistroAR::~RegistroAR()
{
	set<LineaRegistroAR*>::iterator it;
	for ( it = lineas.begin() ; it != lineas.end() ; ++it)
		delete (*it);
}
