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
	const Fecha& getFecha() const;
	TipoOper getTipoOper() const;
	DTLineaRegistro(Fecha fecha,TipoOper tipoOper); //constructor del datatype

private:
	Fecha fecha;
	TipoOper tipoOper;
};



#endif /* DTLINEAREGISTRO_H_ */
