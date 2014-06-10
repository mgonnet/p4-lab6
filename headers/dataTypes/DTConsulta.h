/*
 * DTConsulta.h
 *
 *  Created on: 09/06/2014
 *      Author: GRUPO_04
 */

#ifndef DTCONSULTA_H_
#define DTCONSULTA_H_

#include "FechaHora.h"
#include "DTMedico.h"
#include "DTDiagnostico.h"
#include "TipoConsulta.h"

class DTConsulta
{
private:
	Fecha			fechaConsulta;
	TipoConsulta	tipo;
	DTMedico		medico;
	DTDiagnostico	diagnostico;	// CUIDADO: creo que aca sería un conjunto
};

#endif /* DTCONSULTA_H_ */
