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

class CDiagnostico : public IDiagnostico
{
public:
	const set <DTReprEstandarizada>& getReprEstandarizadas() {}
};


#endif /* CDIAGNOSTICO_H_ */
