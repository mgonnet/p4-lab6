/*
 * DTConsulta.cpp
 *
 *  Created on: 10/06/2014
 *      Author: matias
 */

#include "../../headers/dataTypes/DTConsulta.h"

DTConsulta::DTConsulta(	Fecha fechaConsulta,
						TipoConsulta tipo,
						DTMedico medico,
						DTDiagnostico diagnostico):
	fechaConsulta(fechaConsulta),
	tipo(tipo),
	medico(medico),
	diagnostico(diagnostico) { }

inline const DTDiagnostico& DTConsulta::getDiagnostico() const {
	return diagnostico;
}

inline const Fecha& DTConsulta::getFechaConsulta() const {
	return fechaConsulta;
}

inline const DTMedico& DTConsulta::getMedico() const {
	return medico;
}

inline TipoConsulta DTConsulta::getTipo() const {
	return tipo;
}



