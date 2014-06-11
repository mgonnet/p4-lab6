/*
 * DTReservaA.h
 *
 *  Created on: 09/06/2014
 *      Author: GRUPO_04
 */

#ifndef DTRESERVAA_H_
#define DTRESERVAA_H_

#include "FechaHora.h"

class DTReservaA
{
public:
	DTReservaA(Fecha fechaC,Hora horaC,Fecha fechaR);

	const Fecha& getFechaC() const;
	const Fecha& getFechaR() const;
	const Hora& getHoraC() const;

private:
	Fecha	fechaC;
	Hora	horaC;
	Fecha	fechaR;
};



#endif /* DTRESERVAA_H_ */
