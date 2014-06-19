/*
 * Usuario.cpp
 *
 *  Created on: 03/05/2014
 *      Author: matias
 */

#include "../../headers/clases/Usuario.h"
#include <stdexcept>

//Constructores
Usuario::Usuario(string nombre,string apellido,string ci,Sexo sexo,Fecha fechaNac,bool activo, int edad, bool adminPorDefecto, bool primerLogueo, set<Rol> roles):
	nombre(nombre),
	apellido(apellido),
	ci(ci),
	sexo(sexo),
	fechaNac(fechaNac),
	activo(activo),
	edad(edad),
	adminPorDefecto(adminPorDefecto),
	primerLogueo(primerLogueo),
	administrativo(NULL),
	medico(NULL),
	socio(NULL)
{
	if( (roles.find(ADMIN) != roles.end() ) && (roles.find(MEDICO) != roles.end() ) )
		throw invalid_argument("Se seleccionaron roles ADMIN y MEDICO");
	else
	{
		if (roles.find(ADMIN) != roles.end() )
			this->administrativo=new Administrativo(this);
		if (roles.find(SOCIO) != roles.end() )
			this->socio=new Socio(this);
		if (roles.find(MEDICO) != roles.end() )
			this->medico=new Medico(this);
	}
}

//Getters
string	Usuario::getNombre() { return nombre; }
string	Usuario::getCi() { return ci; }
Sexo	Usuario::getSexo() { return sexo; }
Fecha	Usuario::getFechaNac() { return fechaNac; }
bool	Usuario::isActivo(){ return activo; }
string	Usuario::getContrasenia() { return contrasenia; }
bool	Usuario::getPrimerLogueo() { return primerLogueo; }

//Setters
void	Usuario::setNombre(string nombre) { this->nombre=nombre; }
void	Usuario::setCi(string ci) { this->ci=ci; }
void	Usuario::setSexo(Sexo sexo) { this->sexo=sexo; }
void	Usuario::setFechaNac(Fecha fechaNac) { this->fechaNac=fechaNac; }
void	Usuario::setActivo(bool activo) { this->activo=activo; }
void	Usuario::setContrasenia(string contrasenia) { this->contrasenia=contrasenia; }
void	Usuario::setPrimerLogueo(bool pL) { primerLogueo = pL; }

//Negocio
DTInfoLogueo	Usuario::getInfoLogueo() { return DTInfoLogueo(primerLogueo,adminPorDefecto,activo,true); }
