/*
 * DTTratamiento.h
 *
 *  Created on: 09/06/2014
 *      Author: GRUPO_04
 */

#ifndef DTTRATAMIENTO_H_
#define DTTRATAMIENTO_H_

#include <string>
#include <set>

#include "TipoTratamiento.h"
#include "DTMedicamento.h"
#include "FechaHora.h"

class DTTratamiento
{
public:
	DTTratamiento(TipoTratamiento tipo, string descripcion, Fecha fecha, set<DTMedicamento> medicamentos);

	const string& getDescripcion() const;
	const Fecha& getFecha() const;
	const set<DTMedicamento>& getMedicamentos() const;
	TipoTratamiento getTipo() const;

private:
	TipoTratamiento		tipo;
	string				descripcion;
	Fecha				fecha;
	set<DTMedicamento>	medicamentos;
};


#endif /* DTTRATAMIENTO_H_ */
