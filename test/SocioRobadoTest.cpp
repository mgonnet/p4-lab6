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

#include "../headers/clases/MedicoNotificable.h"
#include "../headers/clases/Mensaje.h"
#include "../headers/dataTypes/FechaHora.h"

class SocioRobadoTest : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		medicoAlQueRoban=new MedicoNotificable;
		socioRobado=new Socio;
	}

	virtual void TearDown()
	{
		set<Mensaje*> buzon=medico->getMensajes();
		for (set<Mensaje*>::iterator it=buzon.begin(); it!=buzon.end(); ++it)
		{
			delete (*it);
		}
		delete medico;
	}

	MedicoNotificable* 	medicoAlQueRoban;
	Socio*				socioRobado;
};





