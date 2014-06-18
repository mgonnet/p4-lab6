/*
 * Logueo.cpp
 *
 *  Created on: 10/05/2014
 *      Author: Emiliano
 */

#include "../../headers/clases/Logueo.h"

#include <stdio.h>

Logueo* Logueo::instancia=NULL;

Logueo::Logueo() { logueado = NULL; }

Logueo* Logueo::getInstance()
{
	if(instancia==NULL)
		instancia = new Logueo;
	return instancia;
}

void Logueo::logIn(Usuario* logueante) { logueado = logueante; }
void Logueo::logOut() { logueado = NULL; }

Usuario* Logueo::getUsuario() { return logueado; }

Logueo::~Logueo() { instancia = NULL; }
