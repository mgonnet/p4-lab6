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
		if(/*checkeo 12 meses*/ true )  // CUIDADO: Falta crear la operacion que haga el chequeo.
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

int MedicoNotificable::cantMensajesNoLeidos()
{
	set<Mensaje*>::iterator it;
	int cantMensajes=0;
	for(it=buzon.begin();it!=buzon.end();++it)
	{
		if( !( (*it) -> isLeido() ) ) // Si no fue leido
			cantMensajes++; //sumo 1
	}
	return cantMensajes;

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


