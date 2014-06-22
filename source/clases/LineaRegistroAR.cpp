/*
 * LineaRegistroAR.cpp
 *
 *  Created on: 19/06/2014
 *      Author: matias
 */

#include "../../headers/clases/LineaRegistroAR.h"

LineaRegistroAR::LineaRegistroAR(Fecha fecha, TipoOper tipoOper):
	fecha(fecha),
	tipoOper(tipoOper)
{}

DTLineaRegistro* LineaRegistroAR::getDatosRegistro() {
	Fecha fechaNuevoDT =    this->getFecha();
	TipoOper tipoOperNuevoDT = this->getTipoOper();
	DTLineaRegistro* nuevoDTLineaRegistro = new DTLineaRegistro(fechaNuevoDT,tipoOperNuevoDT);
	return nuevoDTLineaRegistro;
}

Fecha	 LineaRegistroAR::getFecha() { return this->fecha; }
TipoOper LineaRegistroAR::getTipoOper() { return this->tipoOper; }
