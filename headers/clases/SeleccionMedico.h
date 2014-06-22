/*
 * SeleccionMedico.h
 *
 *  Created on: 21/06/2014
 *      Author: macaco
 */

#ifndef SELECCIONMEDICO_H_
#define SELECCIONMEDICO_H_

#include "../../headers/dataTypes/Parametro.h"
#include <string>
using namespace std;

class SeleccionMedico
{

public:
	virtual string seleccionarMedico(Parametro* parametro) = 0;
	virtual ~SeleccionMedico();
};


#endif /* SELECCIONMEDICO_H_ */
