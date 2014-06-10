/*
 * DTHistorial.h
 *
 *  Created on: 09/06/2014
 *      Author: GRUPO_04
 */

#ifndef DTHISTORIAL_H_
#define DTHISTORIAL_H_

#include <set>

#include "DTConsulta.h"
#include "DTSocio.h"

using namespace std;

class DTHistorial
{
private:
	DTSocio			socio;
	set<DTConsulta>	consultas;
};

#endif /* DTHISTORIAL_H_ */
