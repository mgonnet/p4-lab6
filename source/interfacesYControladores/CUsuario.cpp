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
#include "../../headers/clases/Administrativo.h"
#include "../../headers/interfacesYControladores/Almacen.h"
#include "../../headers/clases/Logueo.h"
#include "../../headers/clases/FechaSistema.h"

CUsuario::CUsuario():
ci(""),
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
		return !( logueante->getContrasenia() == contrasenia );
}

void CUsuario::asignarSesionUsuario()
{
	Logueo* logueo=Logueo::getInstance();
	logueo->logIn(logueante); // Hago el link con logueo
	logueante->setPrimerLogueo(false);  // Seteo como false primerLogueo, si ya era false no hace nada, si no, actualizo.
}

void CUsuario::crearContrasenia(string contrasenia)
{
	logueante->activar();
	logueante->setContrasenia(contrasenia);
}

void CUsuario::cerrarSesion()
{
	Logueo* log=Logueo::getInstance();
	log->logOut();
}

bool CUsuario::iniciarAltaReactivacion(string ci)
{
	Almacen* alm=Almacen::getInstance();
	set<Usuario*> usuarios=alm->getUsuarios();  // Consigo el conjunto de usuarios
	set<Usuario*>::iterator it;

	this->ci=ci;  // Guardo la ci

	bool encontre=false;
	for( it=usuarios.begin() ; it != usuarios.end() && !encontre ; ++it )
		if ( (*it)->getCi() == ci )
			encontre = true;

	return encontre;
}


void CUsuario::ingresarDatos(string nombre, string apellido, Sexo sexo, Fecha fNac, const set<Rol>& roles)
{
	this->nombre=nombre;
	this->apellido=apellido;
	this->sexo=sexo;
	this->fNac=fNac;
	this->roles=roles;

	//this->edad=fNac->calcularEdad(); // CUIDADO: Agregar Fecha Sistema y descomentar Fecha::calcularEdad
}

void CUsuario::altaUsuario()
{
	Usuario* nuevoUsuario = new Usuario (nombre,apellido,ci,sexo,fNac,false,edad,false,true,roles);
	// CUIDADO: No se si activo debe ir en TRUE

	Logueo* log=Logueo::getInstance();
	Usuario* creador=log->getUsuario();
	Administrativo* adm=creador->getAdministrativo(); // CUIDADO: Tal vez debería mandar el mensaje directamente al usuario en vez de pedirle el Administrativo

	adm->altaUsuario(nuevoUsuario);

	Almacen* alm=Almacen::getInstance();
	alm->addUsuario(nuevoUsuario);
}

DTUser CUsuario::pedirDatos()
{
	if ( ci == "" )
		throw invalid_argument("En IUsuario::pedirDatos: No se está recordando ninguna ci");
	else
	{
		Usuario* usuario;
		Almacen* alm=Almacen::getInstance();
		set<Usuario*> usuarios = alm->getUsuarios();
		set<Usuario*>::iterator it;
		bool encontre=false;
		for ( it = usuarios.begin() ; it != usuarios.end() && !encontre ; ++it )
			if ( (*it)->getCi() == ci)
			{
				encontre=true;
				usuario = (*it);
			}

		if(!encontre)
			throw invalid_argument("En IUsuario::pedirDatos: No existe usuario con la ci indicada");
		else
			return DTUser(usuario->getNombre(),usuario->getApellido(),usuario->getSexo(),usuario->getEdad(),usuario->getActivo(),usuario->getRoles());
	}
}

void CUsuario::reactivarUsuario()
{
	Almacen* alm=Almacen::getInstance();  // DC 1

	set<Usuario*> usuarios = alm->getUsuarios(); // DC 2
	set<Usuario*>::iterator it;
	Usuario* usuario;
	bool encontre=false;
	for ( it = usuarios.begin() ; it != usuarios.end() && !encontre ; ++it )
		if ( (*it)->getCi() == ci)
		{
			encontre=true;
			usuario = (*it);
		}

	usuario->activar(); //DC 3

	Logueo* log=Logueo::getInstance(); // DC 4

	Administrativo* adm = log->getUsuario()->getAdministrativo(); // DC 5

	adm->reactivarUsuario(usuario); // DC 6
}

void CUsuario::crearAdminPorDefecto()
{
	Almacen* alm=Almacen::getInstance();
	Fecha fecha;
	set<Rol> roles;
	roles.insert(ADMIN);
	Usuario* adminPorDefecto = new Usuario("ROOT","ROOT","ROOT",MASCULINO,fecha,true,0,true,false,roles);
	adminPorDefecto->setContrasenia("123");
	alm->addUsuario(adminPorDefecto);
}

set<Rol> CUsuario::rolesDelLogueado()
{
	Logueo* log=Logueo::getInstance();
	Usuario* u=log->getUsuario();
	if( u == NULL )
		throw invalid_argument("No hay nadie logueado actualmente.");
	else
		return u->getRoles();
}

void CUsuario::liberarMemoria()
{
	Almacen* alm=Almacen::getInstance();
	delete alm;
	Logueo* log=Logueo::getInstance();
	delete log;
	FechaSistema* fSis=FechaSistema::getInstance();
	delete fSis;
}

set<DTUsuarioAR> CUsuario::listarUsuariosAR() {
	Logueo* logueo = Logueo::getInstance();
	Usuario* usuario = logueo->getUsuario();
	Administrativo* administrativo = usuario->getAdministrativo();
	set<DTUsuarioAR> usuariosAR=administrativo->listarUsuariosAR();
	return usuariosAR;
}

int CUsuario::cantMensajesNoLeidos()
{
	Logueo* log=Logueo::getInstance();
	return log->getUsuario()->getCantNoLeidos();
}
