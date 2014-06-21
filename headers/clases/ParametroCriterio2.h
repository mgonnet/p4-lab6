/*
 * ParametroCriterio2.h
 *
 *  Created on: 21/06/2014
 *      Author: macaco
 */

#ifndef PARAMETROCRITERIO2_H_
#define PARAMETROCRITERIO2_H_

#include <string>

#include "../../headers/dataTypes/Parametro.h"
#include "../../headers/dataTypes/FechaHora.h"

using namespace std;

class ParametroCriterio2 : public Parametro
{
public:
	ParametroCriterio2(Fecha fecha,Hora hora,string ciPaciente);

	const Hora& getHora() const;
	const Fecha& getFecha() const;
	const string& getCIPaciente() const;

	virtual ~ParametroCriterio2() { }

private:
	Fecha	fecha;
	Hora 	hora;
	string	ciPaciente;

	void dummy();
};



#endif /* PARAMETROCRITERIO2_H_ */
