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
public:
	DTDiagnostico(	string descripcion,
					string codigo,
					string etiqueta,
					set<string> tratamientos );

	const string& getCodigo() const;
	const string& getDescripcion() const;
	const string& getEtiqueta() const;
	const set<string>& getTratamientos() const;

	bool operator<(DTDiagnostico) const;
private:
	string		descripcion;
	string		codigo;
	string		etiqueta;
	set<string>	tratamientos;
};


#endif /* DTDIAGNOSTICO_H_ */
