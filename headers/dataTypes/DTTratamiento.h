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

class DTTratamiento
{
private:
	TipoTratamiento		tipo;
	string				descripcion;
	Fecha				fecha;
	set<DTMedicamento>	medicamentos;
};


#endif /* DTTRATAMIENTO_H_ */
