/*
 * MedicoNotificable.cpp
 *
 *  Created on: 11/06/2014
 *      Author: matias
 */

#include "../../headers/clases/MedicoNotificable.h"
#include "../../headers/dataTypes/Parametro.h"
#include "../../headers/clases/Mensaje.h"


void	MedicoNotificable::addAccion(Accion*) { }
void	MedicoNotificable::rmAccion(Accion*) { }

void	MedicoNotificable::update(Parametro* param) { delete param; }

void	MedicoNotificable::addMensaje(Mensaje* mensaje)
{
	this->buzon.insert(mensaje);
}

set<Mensaje*>	MedicoNotificable::getMensajes()
{
	return this->buzon;
}


