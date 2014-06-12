/*
 * Mensaje.h
 *
 *  Created on: 11/06/2014
 *      Author: matias
 */

#ifndef MENSAJE_H_
#define MENSAJE_H_

#include <string>

#include "../../headers/dataTypes/FechaHora.h"

using namespace std;

class Mensaje
{
public:
	Mensaje(string ciSocio,string ciMedicoIntruso,Fecha fecha,bool nuevosDiagnosticos);

	const string& getCiMedicoIntruso() const;
	const string& getCiSocio() const;
	const Fecha& getFecha() const;
	bool isNuevosDiagnosticos() const;

private:
	string	ciSocio;
	string	ciMedicoIntruso;
	Fecha	fecha;
	bool	nuevosDiagnosticos;
};


#endif /* MENSAJE_H_ */
