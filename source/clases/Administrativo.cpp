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

	registrosAR.insert(rar);
}

void Administrativo::reactivarUsuario(Usuario *u)
{
	RegistroAR* rar;
	set<RegistroAR*>::iterator it;
	bool encontre=false;
	for ( it = registrosAR.begin() ; it != registrosAR.end() && !encontre ; ++it )
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
		registrosAR.insert(rar);
}

set<DTUsuarioAR*> Administrativo::listarUsuariosAR() {
	set<DTUsuarioAR*> datosRegistros; //conjunto de elementos que quiero listar
	set<RegistroAR*> registros = (this)->getRegistrosAR(); //coleccion de punteros a RegistroAR
	set<RegistroAR*>::iterator it; //iterar sobre la coleccion de punteros a RegistroAR
	for (it = registros.begin(); it != registros.end(); ++it) {
		RegistroAR* registro = (*it); //elemento de la coleccion. Puntero a RegistroAR
		datosRegistros.insert(registro->getDatosUsuarioAR()); //insertar un datatype de DTUsuarioAR a datosRegistro
	}
	return datosRegistros;
}

Administrativo::~Administrativo()
{
	//Debo eliminar los registros
	set<RegistroAR*>::iterator it;
	for ( it = registrosAR.begin() ; it != registrosAR.end() ; ++it)
		delete (*it);
}
