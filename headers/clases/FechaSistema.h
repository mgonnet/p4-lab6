/*
 * FechaSistema.h
 *
 *  Created on: 14/06/2014
 *      Author: macaco
 */

#ifndef FECHASISTEMA_H_
#define FECHASISTEMA_H_

#include <string>
using namespace std;
#include "../../headers/dataTypes/FechaHora.h"


class FechaSistema{

private:
	static FechaSistema* instancia;

	Fecha fechaSis;
	Hora horaSis;

	FechaSistema();
public:
	static FechaSistema* getInstance();

	Fecha getFechaSistema();
	Hora getHoraSistema();

	void setFechaSistema(Fecha);
	void setHoraSistema(Hora);
	~FechaSistema();

};


#endif /* FECHASISTEMA_H_ */
