/*
 * MedicoNotificable.cpp
 *
 *  Created on: 11/06/2014
 *      Author: matias
 */

#include "../../headers/clases/MedicoNotificable.h"
#include "../../headers/dataTypes/Parametro.h"
#include "../../headers/clases/Mensaje.h"
#include "../../headers/clases/Accion.h"

void	MedicoNotificable::addAccion(Accion* accion)
{
	accionesUpdate.insert(accion);
}

void	MedicoNotificable::rmAccion(Accion* accion)
{
	accionesUpdate.erase(accion);
}

void	MedicoNotificable::update(Subject* sujeto,Parametro* param)
{
	if(/*checkeo 12 meses*/ true )
	{
		set<Accion*>::iterator it;
		for(it=accionesUpdate.begin();it!=accionesUpdate.end();++it)
		{
			(*it)->performAction(this,param);
		}
	}
}

void	MedicoNotificable::addMensaje(Mensaje* mensaje)
{
	this->buzon.insert(mensaje);
}

set<Mensaje*>	MedicoNotificable::getMensajes()
{
	return this->buzon;
}


