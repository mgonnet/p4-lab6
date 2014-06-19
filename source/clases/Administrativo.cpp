/*
 * Administrativo.cpp
 *
 *  Created on: 10/05/2014
 *      Author: Emiliano
 */

#include "../../headers/clases/Administrativo.h"
#include "../../headers/clases/RegistroAR.h"

Administrativo::Administrativo(Usuario* u):
	usuario(u)
{}

void Administrativo::altaUsuario(Usuario *u)
{
	RegistroAR* rar=new RegistroAR(u,this);

	FechaSistema* fSis;
	rar->addLineaRegistroAR(fSis->getFecha(),ALTA);
}

