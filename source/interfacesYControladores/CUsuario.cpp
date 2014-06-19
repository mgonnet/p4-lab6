/*
 * CUsuario.cpp
 *
 *  Created on: 18/06/2014
 *      Author: matias
 */

#include <set>
#include <stdexcept>

#include "../../headers/interfacesYControladores/CUsuario.h"

#include "../../headers/clases/Usuario.h"
#include "../../headers/interfacesYControladores/Almacen.h"
#include "../../headers/clases/Logueo.h"

CUsuario::CUsuario():
	logueante(NULL)
{}

DTInfoLogueo CUsuario::comienzoInicioSesion(string ci)
{
	Usuario* usuario;
	Almacen* alm=Almacen::getInstance();  // Consigo el almacen
	set<Usuario*> usuarios=alm->getUsuarios(); // Le pido la coleccion
	set<Usuario*>::iterator it;
	bool encontre=false;
	for ( it = usuarios.begin() ; it != usuarios.end() && !encontre ; ++it ) // Itero hasta que encuentro la cedula o se acabe
		if( (*it)->getCi() == ci ) // Como lo encontre, para la iteracion y me quedo con el usuario
		{
			encontre = true;
			usuario=(*it);
		}

	if(encontre)  // CUIDADO: Hay dos return
	{
		logueante=usuario;
		return usuario->getInfoLogueo();
	}
	else
		return DTInfoLogueo(false,false,false,false);
}

bool CUsuario::ingresarContrasenia(string contrasenia)
{
	if(logueante==NULL)
		throw invalid_argument("No existe ningún usuario con la CI indicada, no insista.");
	else
		return ( logueante->getCi() == contrasenia );
}

void CUsuario::asignarSesionUsuario()
{
	Logueo* logueo=Logueo::getInstance();
	logueo->logIn(logueante); // Hago el link con logueo
	logueante->setPrimerLogueo(false);  // Seteo como false primerLogueo, si ya era false no hace nada, si no, actualizo.
}

void CUsuario::crearContrasenia(string contrasenia) { logueante->setContrasenia(contrasenia); }

void CUsuario::cerrarSesion(){}
bool CUsuario::iniciarAltaReactivacion(string ci){}
void CUsuario::ingresarDatos(string nombre, string apellido, Sexo sexo, Fecha fNac, const set<Rol>& roles){}
void CUsuario::altaUsuario(){}
DTUser CUsuario::pedirDatos(){}
void CUsuario::reactivarUsuario(){}


