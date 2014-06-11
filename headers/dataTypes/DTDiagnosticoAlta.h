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
public:
	DTDiagnosticoAlta(	string descripcion,
						string codigo,
						string etiqueta,
						set<DTTratamiento> tratamientos);

	const string& getCodigo() const;
	const string& getDescripcion() const;
	const string& getEtiqueta() const;
	const set<DTTratamiento>& getTratamientos() const;

private:
	string				descripcion;
	string				codigo;
	string				etiqueta;
	set<DTTratamiento>	tratamientos;
};


#endif /* DTDIAGNOSTICOALTA_H_ */
