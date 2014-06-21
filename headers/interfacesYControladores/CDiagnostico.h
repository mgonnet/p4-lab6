/*
 * CDiagnostico.h
 *
 *  Created on: Jun 11, 2014
 *      Author: eacosta
 */

#ifndef CDIAGNOSTICO_H_
#define CDIAGNOSTICO_H_

#include <set>
#include "IDiagnostico.h"
#include "../dataTypes/DTReprEstandarizada.h"
#include "IDiagnostico.h"

class CDiagnostico : public IDiagnostico
{
public:
	set<DTCategoriaPS> obtenerCategorias();
	void agregarCategoria(string,string);
	void seleccionarCategoria(string);
	set <DTReprEstandarizada> getReprEstandarizadas();

	~CDiagnostico();
};


#endif /* CDIAGNOSTICO_H_ */
