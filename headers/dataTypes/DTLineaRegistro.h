/*
 * DTLineaRegistro.h
 *
 *  Created on: 14/06/2014
 *      Author: Admin
 */

#ifndef DTLINEAREGISTRO_H_
#define DTLINEAREGISTRO_H_

#include "../../headers/dataTypes/TipoOper.h"
#include "../../headers/dataTypes/FechaHora.h"

class DTLineaRegistro {
public:
	Fecha getFecha();
	TipoOper getTipoOper() const;
	DTLineaRegistro(Fecha fecha,TipoOper tipoOper); //constructor del datatype
	bool operator<(DTLineaRegistro) const;


private:
	Fecha fecha;
	TipoOper tipoOper;
};

std::ostream &operator<<( std::ostream &stream,DTLineaRegistro imprimible);


#endif /* DTLINEAREGISTRO_H_ */
