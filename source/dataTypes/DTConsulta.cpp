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

std::ostream &operator<<( std::ostream &stream,DTConsulta imprimible) {
	stream << "Fecha de Consulta: " << imprimible.getFechaConsulta() << endl
			<< "Tipo de Consulta: ";
	if (imprimible.getTipo() == 0)
		stream << "COMUN" << endl;
	else
		stream << "EMERGENCIA" << endl;
	stream << "Datos del medico: " << endl
			<< imprimible.getDTMedico();
	set<DTDiagnostico>::iterator it;
	set<DTDiagnostico> diagnosticos = imprimible.getSetDiagnostico();
	for (it = diagnosticos.begin(); it != diagnosticos.end(); ++it) {
		stream << (*it);
	}
	return (stream);
}

bool DTConsulta::operator<(DTConsulta otro) const
{
	return fechaConsulta.esMenorQue(otro.getFechaConsulta());
}

