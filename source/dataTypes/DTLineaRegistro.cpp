/*
 * DTLineaRegistro.cpp
 *
 *  Created on: 20/06/2014
 *      Author: matias
 */

#include "../../headers/dataTypes/DTLineaRegistro.h"
#include "../../headers/dataTypes/FechaHora.h"

DTLineaRegistro::DTLineaRegistro(Fecha fecha,TipoOper tipoOper):fecha(fecha), tipoOper(tipoOper) {}

Fecha DTLineaRegistro::getFecha() {
	return fecha;
}

TipoOper DTLineaRegistro::getTipoOper() const {
	return tipoOper;
}

bool DTLineaRegistro::operator<(DTLineaRegistro otro) const
{
	return ( fecha.esMenorQue(otro.getFecha()) );
}

std::ostream &operator<<( std::ostream &stream,DTLineaRegistro imprimible)
{
	stream	<< "Fecha: " << imprimible.getFecha() << "Tipo de Operacion: ";
	if (imprimible.getTipoOper() == 0 ) stream << "ALTA";
	else if(imprimible.getTipoOper() == 1) stream << "REACTIVACION";
	return (stream);
}
