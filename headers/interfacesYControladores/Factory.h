/*
 * Factory.h
 *
 *  Created on: 09/06/2014
 *      Author: GRUPO_04
 */

#ifndef FACTORY_H_
#define FACTORY_H_

#include "IUsuario.h"
#include "IConsulta.h"
#include "IDiagnostico.h"

class Factory
{
public:
	IUsuario		getIUsuario();
	IConsulta		getIConsulta();
	IDiagnostico	getIDiagnostico();
};


#endif /* FACTORY_H_ */
