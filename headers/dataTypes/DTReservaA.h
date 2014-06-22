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
	DTReservaA(int codigoC,Fecha fechaC,Hora horaC,Fecha fechaR,DTMedico dtMed);

	int getCodigoC();
	Fecha getFechaC();
	Fecha getFechaR();
	Hora getHoraC();
	DTMedico getDTMedico();

	bool operator<(DTReservaA) const;

private:
	int		codigoC;
	Fecha	fechaC;
	Hora	horaC;
	Fecha	fechaR;
	DTMedico dtMed;
};



#endif /* DTRESERVAA_H_ */
