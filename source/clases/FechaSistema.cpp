/*
 * FechaSistema.cpp
 *
 *  Created on: 14/06/2014
 *      Author: macaco
 */

#include "../../headers/clases/FechaSistema.h"


FechaSistema* FechaSistema::instancia=NULL;

FechaSistema::FechaSistema() {}

FechaSistema::~FechaSistema() { instancia = NULL; }

FechaSistema* FechaSistema::getInstance(){
	if (instancia == NULL){
		instancia = new FechaSistema();
	}
	return instancia;

}

Fecha FechaSistema::getFechaSistema() { return fechaSis; }

Hora FechaSistema::getHoraSistema() { return horaSis; }
