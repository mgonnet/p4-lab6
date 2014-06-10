/*
 * DTDiagnosticoAlta.h
 *
 *  Created on: 09/06/2014
 *      Author: GRUPO_04
 */

#ifndef DTDIAGNOSTICOALTA_H_
#define DTDIAGNOSTICOALTA_H_

#include <string>
#include <set>

#include "DTTratamiento.h"

using namespace std;

class DTDiagnosticoAlta
{
	string				descripcion;
	string				codigo;
	string				etiqueta;
	set<DTTratamiento>	tratamientos;
};


#endif /* DTDIAGNOSTICOALTA_H_ */
