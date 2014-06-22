/*
 * ParametroCriterio1.h
 *
 *  Created on: 21/06/2014
 *      Author: macaco
 */

#ifndef PARAMETROCRITERIO1_H_
#define PARAMETROCRITERIO1_H_

#include <string>

#include "../../headers/dataTypes/Parametro.h"
#include "../../headers/dataTypes/FechaHora.h"

using namespace std;

class ParametroCriterio1 : public Parametro
{
public:
	ParametroCriterio1(Fecha fecha,Hora hora,int x);

	const int& getX() const;
	const Hora& getHora() const;
	const Fecha& getFecha() const;

	virtual ~ParametroCriterio1() { }

private:
	Fecha	fecha;
	Hora 	hora;
	int		x;

	void dummy();
};



#endif /* PARAMETROCRITERIO1_H_ */
