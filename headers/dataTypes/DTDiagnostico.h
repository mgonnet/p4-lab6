/*
 * DTDiagnostico.h
 *
 *  Created on: 09/06/2014
 *      Author: GRUPO_04
 */

#ifndef DTDIAGNOSTICO_H_
#define DTDIAGNOSTICO_H_

#include <string>
#include <set>

using namespace std;

class DTDiagnostico
{
private:
	string		descripcion;
	string		codigo;
	string		etiqueta;
	set<string>	tratamientos;
};


#endif /* DTDIAGNOSTICO_H_ */
