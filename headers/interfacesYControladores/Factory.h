/*
 * Factory.h
 *
 *  Created on: Jun 10, 2014
 *      Author: eacosta
 */

#ifndef FACTORY_H_
#define FACTORY_H_

#include "IUsuario.h"
#include "IConsulta.h"
#include "IDiagnostico.h"

class Factory {

public:

	static IUsuario* getIUsuario();
	static IConsulta* getIConsulta();
	static IDiagnostico* getIDiagnostico();
};


#endif /* FACTORY_H_ */
