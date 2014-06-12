/*
 * SocioRobadoTest.cpp
 *
 *  Created on: 12/06/2014
 *      Author: matias
 */

#include <set>
#include <string>
#include <limits.h>
#include "gtest-1.7.0/include/gtest/gtest.h"

#include "../headers/clases/Accion.h"
#include "../headers/clases/AccionMensaje.h"
#include "../headers/dataTypes/ParametroAccionMensaje.h"
#include "../headers/clases/MedicoNotificable.h"
#include "../headers/clases/Mensaje.h"
#include "../headers/dataTypes/FechaHora.h"
#include "../headers/clases/Socio.h"

class SocioRobadoTest : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		accionMensaje=new AccionMensaje;
		medicoAlQueRoban=new MedicoNotificable;
		socioRobado=new Socio;

		//Voy a hacer que medicoAlQueRoban siga a socioRobado
		socioRobado->addObserver(medicoAlQueRoban);

		//Voy a agregarle esta accion al MedicoNotificable
		medicoAlQueRoban->addAccion(accionMensaje); // CUIDADO: #1
	}

	virtual void TearDown()
	{
		delete medicoAlQueRoban;
		delete socioRobado;
		delete accionMensaje;
	}

	MedicoNotificable* 	medicoAlQueRoban;
	Socio*				socioRobado;
	Accion*				accionMensaje; // CUIDADO: #1
};

TEST_F(SocioRobadoTest,MedicoRecibeMensajesAlNotificarlo)
{
	bool estaElMensaje=false;

	Fecha fecha(21,21,21);

	//Me voy a inventar un ParametroAccionMensaje
	ParametroAccionMensaje* parametroInventado = new ParametroAccionMensaje(false,fecha,"4855460","4855461");

	//Ahora voy a hacer que socio notifique a sus seguidores
	socioRobado->notifyAll(parametroInventado);

	//Hay que acordarse de borrar los Parametro dinámicos
	delete parametroInventado;

	//Ahora voy a verificar que haya un nuevo mensaje en el buzon de medicoAlQueRoban
	set<Mensaje*> buzon=medicoAlQueRoban->getMensajes();
	for (set<Mensaje*>::iterator it=buzon.begin(); it!=buzon.end(); ++it)
		if((*it)->getCiSocio()=="4855460")
			estaElMensaje=true;

	//Ahora hago la "ASSERT" que verifica que esté el mensaje
	ASSERT_TRUE(estaElMensaje);
}





