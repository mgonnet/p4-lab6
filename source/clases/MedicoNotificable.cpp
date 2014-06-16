/*
 * MedicoNotificable.cpp
 *
 *  Created on: 11/06/2014
 *      Author: matias
 */

#include <stdexcept>

#include "../../headers/clases/MedicoNotificable.h"
#include "../../headers/dataTypes/Parametro.h"
#include "../../headers/clases/Mensaje.h"
#include "../../headers/clases/Accion.h"
#include "../../headers/clases/Socio.h"
#include "../../headers/clases/Subject.h"
#include "../../headers/clases/StockAcciones.h"

using namespace std;

void	MedicoNotificable::update(Subject* sujeto,Parametro* param)
{
	Socio* socioRobado=dynamic_cast<Socio*>(sujeto);

	if(socioRobado!=NULL)
	{
		if(/*checkeo 12 meses*/ true )
		{
			StockAcciones* stockAcciones=StockAcciones::getInstance();
			stockAcciones->performActions(this,param);
		}
	}
	else
		throw invalid_argument("Medico Notificable solamente observa objetos de tipo Socio");
}

void	MedicoNotificable::addMensaje(Mensaje* mensaje)
{
	this->buzon.insert(mensaje);
}

set<Mensaje*>	MedicoNotificable::getMensajes()
{
	return this->buzon;
}

//Destructor
MedicoNotificable::~MedicoNotificable()
// Hay que destruir todos los mensajes primero
{
	set<Mensaje*> buzon=this->getMensajes();
	for (set<Mensaje*>::iterator it=buzon.begin(); it!=buzon.end(); ++it)
	{
		delete (*it);
	}
}


