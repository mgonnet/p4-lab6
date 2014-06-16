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
	Fecha getFecha();
	bool isNuevosDiagnosticos() const;
	bool isLeido();

	~Mensaje();

private:
	string	ciSocio;
	string	ciMedicoIntruso;
	Fecha	fecha;
	bool	nuevosDiagnosticos;
	bool	leido;
};


#endif /* MENSAJE_H_ */
