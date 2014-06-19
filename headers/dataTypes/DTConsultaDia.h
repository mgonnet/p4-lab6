/*
 * DTConsultaDia.h
 *
 *  Created on: 14/06/2014
 *      Author: macaco
 */

#ifndef DTCONSULTADIA_H_
#define DTCONSULTADIA_H_

#include "FechaHora.h"
#include <string>
using namespace std;


class DTConsultaDia{

private:
	Fecha	fechaConsulta;
	Hora	horaConsulta;
	string	ciSocio;
public:
	DTConsultaDia(Fecha fechaConsulta, Hora horaConsulta, string ciSocio);

	const Fecha& getFechaConsulta() const;
	const Hora& getHoraConsulta() const;
	const string& getCiSocio() const;
};

#endif /* DTCONSULTADIA_H_ */
