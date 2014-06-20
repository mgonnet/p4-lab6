/*
 * Administrativo.cpp
 *
 *  Created on: 10/05/2014
 *      Author: Emiliano
 */

#include "../../headers/clases/Administrativo.h"
#include "../../headers/clases/RegistroAR.h"
#include "../../headers/clases/FechaSistema.h"

Administrativo::Administrativo(Usuario* u):
	usuario(u)
{}

void Administrativo::altaUsuario(Usuario *u)
{
	RegistroAR* rar=new RegistroAR(u,this);

	FechaSistema* fSis=FechaSistema::getInstance();
	rar->addLineaRegistroAR(fSis->getFechaSistema(),ALTA);

	registros.insert(rar);
}

void Administrativo::reactivarUsuario(Usuario *u)
{
	RegistroAR* rar;
	set<RegistroAR*>::iterator it;
	bool encontre=false;
	for ( it = registros.begin() ; it != registros.end() && !encontre ; ++it )
		if( (*it)->usuarioIs(u) )
		{
			encontre=true;
			rar = (*it);
		}

	if(!encontre)
		rar = new RegistroAR(u,this);

	FechaSistema* fSis=FechaSistema::getInstance();
	rar->addLineaRegistroAR(fSis->getFechaSistema(),REACTIVACION);

	if(!encontre)
		registros.insert(rar);
}
