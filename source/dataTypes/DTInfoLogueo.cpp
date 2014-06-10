/*
 * DTInfoLogueo.cpp
 *
 *  Created on: 10/05/2014
 *      Author: Emiliano
 */


#include "../../headers/dataTypes/DTInfoLogueo.h"

//Constructoras
DTInfoLogueo::DTInfoLogueo(): primerLogueo(false), adminPorDefecto(false), activo(false), usuarioExiste(false) { }
DTInfoLogueo::DTInfoLogueo(bool primerLogueo, bool adminPorDefecto, bool activo, bool usuarioExiste): primerLogueo(primerLogueo), adminPorDefecto(adminPorDefecto),activo(activo), usuarioExiste(usuarioExiste) { }

//Sobrecarga de operadores
DTInfoLogueo DTInfoLogueo::operator=(DTInfoLogueo original)
{
	this->primerLogueo=original.primerLogueo;
	this->adminPorDefecto=original.adminPorDefecto;
	this->activo=original.activo;
	this->usuarioExiste=original.usuarioExiste;

	return (*this);
}

//Getters
bool DTInfoLogueo::getExistencia() { return this->usuarioExiste; }
bool DTInfoLogueo::getPrimerLogueo(){ return this->primerLogueo; }

bool DTInfoLogueo::getAdminPorDefecto(){ return this->adminPorDefecto; }

bool DTInfoLogueo::isActivo() { return activo; }

