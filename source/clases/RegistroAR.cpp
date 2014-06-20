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

