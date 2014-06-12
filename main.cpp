/*
 * main.cpp
 *
 *  Created on: 10/06/2014
 *      Author: matias
 */

#include <iostream>
#include <set>
#include <string>
#include <stdlib.h>


#include "headers/dataTypes/ParametroAccionMensaje.h"
#include "headers/clases/MedicoNotificable.h"
#include "headers/clases/Mensaje.h"
#include "headers/dataTypes/FechaHora.h"
#include "headers/clases/Socio.h"

using namespace std;

int main()
{
	MedicoNotificable* 	medicoAlQueRoban;
	Socio*				socioRobado;

	medicoAlQueRoban=new MedicoNotificable;
	socioRobado=new Socio;

	//Voy a hacer que medicoAlQueRoban siga a socioRobado
	socioRobado->addObserver(medicoAlQueRoban);

	bool estaElMensaje=false;

	//Me voy a inventar un ParametroAccionMensaje
	ParametroAccionMensaje* parametroInventado = new ParametroAccionMensaje(false,Fecha(21,21,21),"4855460","4855461");

	//Ahora voy a hacer que socio notifique a sus seguidores
	socioRobado->notifyAll(parametroInventado);

	//Ahora voy a verificar que haya un nuevo mensaje en el buzon de medicoAlQueRoban
	set<Mensaje*> buzon=medicoAlQueRoban->getMensajes();
	for (set<Mensaje*>::iterator it=buzon.begin(); it!=buzon.end(); ++it)
		if((*it)->getCiSocio()=="4855460")
			estaElMensaje=true;

	//Ahora hago la "ASSERT" que verifica que esté el mensaje
	//ASSERT_TRUE(estaElMensaje);

	delete medicoAlQueRoban;
	delete socioRobado;

	return 0;
}

