/*
 * AccionMensaje.cpp
 *
 *  Created on: 11/06/2014
 *      Author: matias
 */

#include "../../headers/clases/MedicoNotificable.h"
#include "../../headers/clases/AccionMensaje.h"
#include "../../headers/dataTypes/ParametroAccionMensaje.h"
#include "../../headers/clases/Mensaje.h"

void AccionMensaje::performAction(MedicoNotificable* medico,Parametro* param)
{
	//Primero debo crear el mensaje
	ParametroAccionMensaje* pM=(ParametroAccionMensaje*)param; //Se que el parametro que voy a
																// recibir es de tipo ParametroAccionMensaje

	Mensaje* nuevoMensaje=new Mensaje(pM->getCiSocio(),pM->getCiMedicoIntruso(),pM->getFecha(),pM->isNuevosDiagnosticos());

	//Ahora se lo debo agregar al MedicoNotificable
	medico->addMensaje(nuevoMensaje);
}
