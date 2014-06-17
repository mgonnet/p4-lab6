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



#include "headers/clases/Accion.h"
#include "headers/clases/AccionMensaje.h"
#include "headers/dataTypes/ParametroAccionMensaje.h"
#include "headers/clases/MedicoNotificable.h"
#include "headers/clases/Mensaje.h"
#include "headers/dataTypes/FechaHora.h"
#include "headers/clases/Socio.h"
#include "headers/clases/StockAcciones.h"

using namespace std;

int main()
{
	MedicoNotificable* 	medicoAlQueRoban;
		Socio*				socioRobado;
		Accion*				accionMensaje; // CUIDADO: #1
		StockAcciones*		stockAcciones;


	//Primero creo las acciones y las cargo
			accionMensaje=new AccionMensaje;
			stockAcciones=StockAcciones::getInstance();

			stockAcciones->addAccion(accionMensaje);

			medicoAlQueRoban=new MedicoNotificable;
			socioRobado=new Socio;

			//Voy a hacer que medicoAlQueRoban siga a socioRobado
			socioRobado->addObserver(medicoAlQueRoban);

	Fecha fecha(21,21,21);

	//Me voy a inventar un ParametroAccionMensaje
	ParametroAccionMensaje* parametroInventado = new ParametroAccionMensaje(false,fecha,"4855460","4855461");

	//Ahora voy a hacer que socio notifique a sus seguidores
	socioRobado->notifyAll(parametroInventado);

	//Hay que acordarse de borrar los Parametro dinámicos
	delete parametroInventado;

	cout << medicoAlQueRoban->cantMensajesNoLeidos() << "Solo hay un mensaje y esta sin leer";

	set<Mensaje*> buzon=medicoAlQueRoban->getMensajes();
	for (set<Mensaje*>::iterator it=buzon.begin(); it!=buzon.end(); ++it)
		(*it)->marcarComoLeido();

	cout << medicoAlQueRoban->cantMensajesNoLeidos() << "Marqué todos los mensajes como leidos";

	//Envio dos mensajes seguidos
	parametroInventado = new ParametroAccionMensaje(false,fecha,"4855461","4855461");
	socioRobado->notifyAll(parametroInventado);
	delete parametroInventado;
	parametroInventado = new ParametroAccionMensaje(false,fecha,"4855462","4855461");
	socioRobado->notifyAll(parametroInventado);
	delete parametroInventado;

	cout << medicoAlQueRoban->cantMensajesNoLeidos() << "Hay dos mensajes sin leer";

	for (set<Mensaje*>::iterator it=buzon.begin(); it!=buzon.end(); ++it)
		if((*it)->getCiSocio()=="4855462")
			(*it)->marcarComoLeido();

	cout << medicoAlQueRoban->cantMensajesNoLeidos() << "Marque el segundo mensaje como leido";

	delete medicoAlQueRoban;
	delete socioRobado;
	delete stockAcciones;

	return 0;
}

