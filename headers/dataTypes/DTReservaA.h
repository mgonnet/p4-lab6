/*
 * DTReservaA.h
 *
 *  Created on: 09/06/2014
 *      Author: GRUPO_04
 */

#ifndef DTRESERVAA_H_
#define DTRESERVAA_H_

#include "FechaHora.h"
#include "DTMedico.h"

class DTReservaA
{
public:
	DTReservaA(Fecha fechaC,Hora horaC,Fecha fechaR, DTMedico dtMed);

	const Fecha& getFechaC() const;
	const Fecha& getFechaR() const;
	const Hora& getHoraC() const;
	const DTMedico& getDTMedico() const;

private:
	Fecha	fechaC;
	Hora	horaC;
	Fecha	fechaR;
	DTMedico dtMed;
};



#endif /* DTRESERVAA_H_ */
