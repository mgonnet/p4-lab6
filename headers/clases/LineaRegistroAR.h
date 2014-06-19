/*
 * LineaRegistroAR.h
 *
 *  Created on: 11/06/2014
 *      Author: sac
 */

#ifndef LINEAREGISTROAR_H_
#define LINEAREGISTROAR_H_

#include "../../headers/dataTypes/TipoOper.h"
#include "../../headers/dataTypes/FechaHora.h"
#include "../../headers/dataTypes/DTLineaRegistro.h"

#include <string>
using namespace std;

class LineaRegistroAR {

private:
		Fecha fecha;
		TipoOper tipoOper;

public:

		//Getters
		Fecha	getFecha();
		TipoOper getTipoOper();

		//Setters
		void	setFechaNac(Fecha fechaNac);
		void	setTipoOper(TipoOper tipo);

		LineaRegistroAR create(Fecha fecha, TipoOper tipoOper);
		DTLineaRegistro crearDTRegistro();
};

#endif /* LINEAREGISTROAR_H_ */