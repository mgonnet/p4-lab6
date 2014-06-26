/*
 * DTMensaje.h
 *
 *  Created on: 26/06/2014
 *      Author: matias
 */

#ifndef DTMENSAJE_H_
#define DTMENSAJE_H_

#include <string>
#include "FechaHora.h"

class DTMensaje
{
private:
	string	ciSocio;
	string	ciMedicoIntruso;
	Fecha	fecha;
	bool	nuevosDiagnosticos;
	bool	leido;
public:

	DTMensaje(string ciSocio,string ciMedicoIntruso,Fecha fecha,bool nuevosDiagnosticos, bool leido);

	string getCiMedicoIntruso() const;
	string getCiSocio() const;
	const Fecha& getFecha() const;
	bool isLeido() const;
	bool isNuevosDiagnosticos() const;

	bool operator<(DTMensaje) const;
};

std::ostream &operator<<( std::ostream &stream,DTMensaje imprimible);

#endif /* DTMENSAJE_H_ */
