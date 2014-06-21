/*
 * IDiagnostico.h
 *
 *  Created on: Jun 11, 2014
 *      Author: eacosta
 */

#ifndef IDIAGNOSTICO_H_
#define IDIAGNOSTICO_H_

//class DTReprEstandarizada;
#include "../dataTypes/DTReprEstandarizada.h"
#include "../dataTypes/DTCategoriaPS.h"

#include <set>

class IDiagnostico{
public:

	virtual set<DTCategoriaPS> obtenerCategorias()=0;
	virtual void agregarCategoria(string,string)=0;
	virtual void seleccionarCategoria(string)=0;
	virtual const set<DTReprEstandarizada>& getReprEstandarizadas() = 0;

	virtual ~IDiagnostico() {}
};



#endif /* IDIAGNOSTICO_H_ */
