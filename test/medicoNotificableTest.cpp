/*
 * medicoNotificableTest.cpp
 *
 *  Created on: 11/06/2014
 *      Author: matias
 */

#include <set>
#include <string>
#include <limits.h>
#include "gtest-1.7.0/include/gtest/gtest.h"

#include "../headers/clases/MedicoNotificable.h"
#include "../headers/clases/Mensaje.h"
#include "../headers/dataTypes/FechaHora.h"

class MedicoNotificableTest : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		medico=new MedicoNotificable;
		Fecha fecha(21,21,21);
		Mensaje* mensajito=new Mensaje("socio","ladron",fecha,false);
		medico->addMensaje(mensajito);
		mensajito=new Mensaje("artigas","ansina",fecha,false);
		medico->addMensaje(mensajito);
	}

	virtual void TearDown()
	{
		delete medico;
	}

	MedicoNotificable* medico;
};

TEST_F(MedicoNotificableTest,funcionaBuzon)
{
	bool estaSocio=false;
	bool estaArtigas=false;

	set<Mensaje*> buzon=medico->getMensajes();
	for (set<Mensaje*>::iterator it=buzon.begin(); it!=buzon.end(); ++it)
	{
		if((*it)->getCiSocio()=="socio")
			estaSocio=true;
		else if((*it)->getCiSocio()=="artigas")
			estaArtigas=true;
	}

	ASSERT_TRUE(estaSocio);
	ASSERT_TRUE(estaArtigas);
}
