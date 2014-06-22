/*
 * DTConsulta.cpp
 *
 *  Created on: 10/06/2014
 *      Author: matias
 */

#include "../../headers/dataTypes/DTConsulta.h"

DTConsulta::DTConsulta(	Fecha fechaConsulta,
						TipoConsulta tipo,
						DTMedico dtMedico,
						set<DTDiagnostico> diagnosticos):
	fechaConsulta(fechaConsulta),
	tipo(tipo),
	dtMedico(dtMedico),
	diagnosticos(diagnosticos) { }

inline const set<DTDiagnostico>& DTConsulta::getSetDiagnostico() const {
	return diagnosticos;
}

inline const Fecha& DTConsulta::getFechaConsulta() const {
	return fechaConsulta;
}

inline const DTMedico& DTConsulta::getDTMedico() const {
	return dtMedico;
}

inline TipoConsulta DTConsulta::getTipo() const {
	return tipo;
}



