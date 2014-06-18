/*
 * Usuario.cpp
 *
 *  Created on: 03/05/2014
 *      Author: matias
 */

#include "../../headers/clases/Usuario.h"

//Constructores
Usuario::Usuario(string nombre,string apellido,string ci,Sexo sexo,Fecha fechaNac,bool activo, int edad, bool adminPorDefecto, bool primerLogueo):
	nombre(nombre),
	apellido(apellido),
	ci(ci),
	sexo(sexo),
	fechaNac(fechaNac),
	activo(activo),
	edad(edad),
	adminPorDefecto(adminPorDefecto),
	primerLogueo(primerLogueo)
{ }

//Getters
string	Usuario::getNombre() { return nombre; }
string	Usuario::getCi() { return ci; }
Sexo	Usuario::getSexo() { return sexo; }
Fecha	Usuario::getFechaNac() { return fechaNac; }
bool	Usuario::isActivo(){ return activo; }

//Setters
void	Usuario::setNombre(string nombre) { this->nombre=nombre; }
void	Usuario::setCi(string ci) { this->ci=ci; }
void	Usuario::setSexo(Sexo sexo) { this->sexo=sexo; }
void	Usuario::setFechaNac(Fecha fechaNac) { this->fechaNac=fechaNac; }
void	Usuario::setActivo(bool activo) { this->activo=activo; }
void	Usuario::setContrasenia(string contrasenia) { this->contrasenia=contrasenia; }

//Negocio
DTInfoLogueo	Usuario::getInfoLogueo() { return DTInfoLogueo(primerLogueo,adminPorDefecto,activo,true); }
