/*
 * ParametroAccionMensaje.h
 *
 *  Created on: 11/06/2014
 *      Author: matias
 */

#ifndef PARAMETROACCIONMENSAJE_H_
#define PARAMETROACCIONMENSAJE_H_

#include <string>

#include "Parametro.h"
#include "FechaHora.h"

using namespace std;

class ParametroAccionMensaje
{
public:
	ParametroAccionMensaje(bool nuevosDiagnosticos,Fecha fecha, string ciSocio, string ciMedicoIntruso);

	const string& getCiMedicoIntruso() const;
	const string& getCiSocio() const;
	const Fecha& getFecha() const;
	bool isNuevosDiagnosticos() const;

private:
	bool	nuevosDiagnosticos;
	Fecha	fecha;
	string	ciSocio;
	string	ciMedicoIntruso;

	void dummy();
};

#endif /* PARAMETROACCIONMENSAJE_H_ */
