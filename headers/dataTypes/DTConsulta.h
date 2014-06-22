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
	DTMedico		dtMedico;
	set<DTDiagnostico> diagnosticos;	// CUIDADO: creo que aca sería un conjunto

public:
	DTConsulta() {}
	DTConsulta(Fecha fechaConsulta, TipoConsulta tipo, DTMedico dtMedico, set<DTDiagnostico> diagnosticos);

	const set<DTDiagnostico>& getSetDiagnostico() const;
	const Fecha& getFechaConsulta() const;
	const DTMedico& getDTMedico() const;
	TipoConsulta getTipo() const;
};

#endif /* DTCONSULTA_H_ */
